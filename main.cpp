//
//  main.cpp
//  CiftBaglantili
//
//  Created by Kemal on 25.11.2018.
//  Copyright © 2018 Kemal. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;



typedef struct student{
    string student_number;
    string name;
    string surname;
    string program;
}STUDENT;

class Node{
public:
    student data;
    // Sonraki Adres
    Node* next;
    // Önceki Adres
    Node* prev;
};

void alert(string data, string type){
    string color;
    if(type == "info"){
        color = "34";
    }else if(type == "danger"){
        color = "31";
    }else if(type == "success"){
        color = "32";
    }else if(type == "warning"){
        color = "33";
    }else{
        // Beyaz renk kodu
        color = "37";
    }
    cout << " ";
    for(int i = 0; i < data.length()-2; i++){
        cout << "\033[1;"+color+"m-\033[0m";
    }
    cout << endl << "\033[1;"+color+"m| " + data + " |\033[0m" << endl;
    cout << " ";
    for(int i = 0; i < data.length()-2; i++){
        cout << "\033[1;"+color+"m-\033[0m";
    }
    cout << endl;

}

class List{
    public:
        List(void){ head = NULL; }
        ~List(void){
            {
                /* Node* currNode = head, *nextNode = NULL;
                while (currNode != NULL)
                {
                    nextNode    =    currNode->next;
                    delete currNode;
                    currNode    =    nextNode;
                } */
            }
        };

        bool IsEmpty(){ return head == NULL; }

        Node* InsertNode(int index, student student){
            if (index < 0) return NULL;

            int currIndex  = 1;
            Node* currNode = head;
            while (currNode && index > currIndex) {
                currNode = currNode->next;
                currIndex++;
            }
            if (index > 0 && currNode == NULL) return NULL;

            Node* newNode = new Node;
            newNode->data = student;
            if (index == 0) {
                newNode->next = head;
                newNode->prev = NULL;
                head = newNode;
            } else {
                newNode->next = currNode->next;
                newNode->prev = currNode;
                // eğer son halkaya eklendiyse, devamı olmayacağı için prev değeri atamasına gerek yok.
                if(newNode->next != NULL){
                    currNode->next->prev = newNode;
                }
                currNode->next = newNode;
            }

            alert("Öğrenci Başarıyla Kayıt Edildi","success");
            return newNode;
        };

        int FindNode(string student_number){
            Node* currNode = head;
            int currIndex = 1;
            while (currNode && currNode->data.student_number != student_number) {
                currNode = currNode->next;
                currIndex++;
            }
            if (currNode) return currIndex;
            return 0;
        };

        int DeleteNode(string student_number){
            Node* prevNode = NULL;
            Node* currNode = head;
            Node* nextNode = NULL;
            int currIndex = 1;
            while (currNode && currNode->data.student_number != student_number) {
                prevNode = currNode;
                currNode = currNode->next;
                // Silinecek node'dan sonraki node'u alıp prev değeri değiştirilecek.
                nextNode = currNode->next;
                currIndex++;
            }
            if (currNode) {
                if (prevNode) {
                    prevNode->next = currNode->next;
                    // Silinen node için önceki değerini, sonraki node 'a aktardık.
                    nextNode->prev = currNode->prev;
                    delete currNode;
                }
                else {
                    head = currNode->next;
                    nextNode = currNode->next;
                    // sonraki adresin prev adresini NULL yapıyoruz. Çünkü artık ilk node.
                    nextNode->prev =  NULL;
                    delete currNode;
                }
                alert("Öğrenci Başarıyla Silindi","warning");
                return currIndex;
            }
            alert("Öğrenci Bulunamadı","danger");
            return 0;

        };

        void DisplayList(void){
            Node* currNode = head;
            alert("Bilgisayar Programlama Dersi Öğrencileri","info");
            while(currNode != NULL){
                cout << currNode->data.student_number + " - " + currNode->data.name + " " + currNode->data.surname + " - " + currNode->data.program<< endl;
                currNode = currNode->next;
            }
            cout << " ----------------- " << endl;
        };

    private:
        Node* head;
};

List list;

void programmingLesson(int operatingType){

    switch (operatingType) {
        case 1:{
            student new_student;
            student new_st;
            int sira;

            cout << "Öğrenci Numarası : ";
            cin >> new_student.student_number;
            cout << "Öğrenci Adı : ";
            cin >> new_student.name;
            cout << "Öğrenci Soyadı : ";
            cin >> new_student.surname;
            cout << "Öğrenci Programı : ";
            cin >> new_student.program;
            cout << "Kaçıncı Sıraya Eklenecek : ";
            cin >> sira;
            list.InsertNode(sira, new_student);
            break;
        }
        case 2:{
            string student_number;
            cout << "Silinecek Öğrencinin Numarası : ";
            cin >> student_number;
            list.DeleteNode(student_number);
            break;
        }

        case 3:{
            string student_number;
            cout << "Aranacak Öğrenci Numarası : ";
            cin >> student_number;
            int sonuc = list.FindNode(student_number);
            if(sonuc != 0){
                cout << "Oğrenci bulundu. Sıra : " << sonuc << endl;
            }else{
                cout << student_number + " numaralı öğrenci bulunamadı " << endl;
            }
            cout << " --------- " << endl;
        }
        case 4:{

            list.DisplayList();
            break;
        }

        default:{
            alert("Hatalı İşlem Seçtiniz","danger");
            break;
        }
    }
}

int main(int argc, const char * argv[]) {
    int operatingType = NULL;
    int lessonType = NULL;
    student deneme;
    deneme.student_number = "1030516799";
    deneme.name = "Kemal";
    deneme.surname = "Aydın";
    deneme.program = "Bilgisayar Müh";
    list.InsertNode(0, deneme);
    list.DisplayList();
    do{
        cout << "İşlem Yapmak İstediğiniz Dersi Seçiniz ; " << endl;
        cout << "1 - Bilgisayar Programlama" << endl << "2 - Veritabanı Yönetim Sistemleri" << endl << "3- Çıkış" << endl;
        cout << "Seçilen Ders : ";
        cin >> lessonType;
        switch (lessonType) {
            case 1:
                cout << "----------" << endl << "Bilgisayar Programlama Dersi İçin Yapmak İstediğiniz İşlemi Seçiniz ; "
                     << endl;
                cout << "1- Öğrenci Ekle" << endl << "2- Öğrenci Sil" << endl << "3- Öğrenci Bul" << endl
                     << "4- Öğrencileri Listele" << endl;
                cout << "Seçilen İşlem : ";
                cin >> operatingType;
                programmingLesson(operatingType);
                break;

            case 2:
                cout << "----------" << endl;
                break;

            case 3:
                alert("İyi Çalışmalar","warning");
                break;
            default:
                alert("Geçersiz İşlem Lütfen Tekrar Deneyin","danger");
                break;
        }
    }while(lessonType != 3);
    /*
    List list;
    student deneme;
    deneme.student_number = "1030516799";
    deneme.name = "Kemal";
    deneme.surname = "Aydın";
    deneme.program = "Bilgisayar Müh";
    
    student deneme2;
    deneme2.student_number = "1030516798";
    deneme2.name = "Mehmet";
    deneme2.surname = "Kaynak";
    deneme2.program = "Bilgisayar Mühendisliği";
    
    student deneme3;
    deneme3.student_number = "1030516797";
    deneme3.name = "Ali";
    deneme3.surname = "Çolak";
    deneme3.program = "Bil. Müh.";
    
    student deneme4;
    deneme4.student_number = "00000";
    deneme4.name = "Ali";
    deneme4.surname = "Çolak";
    deneme4.program = "Bil. Müh.";
    
    student deneme5;
    deneme5.student_number = "11111";
    deneme5.name = "Ali";
    deneme5.surname = "Çolak";
    deneme5.program = "Bil. Müh.";
    
    list.InsertNode(0, deneme);
    list.InsertNode(1, deneme2);
    list.InsertNode(2, deneme3);
    list.DisplayList();
    cout << "/////////" << endl;
    list.InsertNode(1, deneme4);
    list.DisplayList();
    cout << " /////////// " << endl;
    list.InsertNode(4, deneme5);
    list.DisplayList();
    cout << " ____SİLİNDİ_____ " << endl;
    list.DeleteNode("1030516798");
    list.DisplayList();
    cout << " ___ SİLİNDİ 2 " << endl;
    list.DeleteNode("1030516799");
    list.DisplayList();
    
    cout << list.FindNode("11111") << endl; */
    return 0;
}
