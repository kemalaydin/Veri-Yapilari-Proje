#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

typedef struct student{
    string student_number;
    string name;
    string surname;
    string program;
}STUDENT;

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

class Node{
public:
    student data;
    // Sonraki Adres
    Node* next;
    // Önceki Adres
    Node* prev;
};

class LinkedList{
public:
    LinkedList(void){ head = NULL; }
    ~LinkedList(void){
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
            newNode->next = NULL;
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

    int TotalNode(){
        Node* currNode = head;
        int index;
        while(currNode){
            currNode = currNode->next;
            index++;
        }
        return index;
    }

    void DisplayList(void){
        Node* currNode = head;
        alert("Bilgisayar Programlama Dersi Öğrencileri","info");
        while(currNode != NULL){
            string selected_program;
            if(currNode->data.program  == "1"){
                selected_program = "Bilgisayar Mühendisliği";
            }else if(currNode->data.program == "2"){
                selected_program = "Makine Mühendisliği";
            }else if(currNode->data.program == "3"){
                selected_program = "Gıda Mühendisliği";
            }else{
                selected_program = "Tanımlı Olmayan Program";
            }
            cout << currNode->data.student_number + " - " + currNode->data.name + " " + currNode->data.surname + " - " + selected_program << endl;
            currNode = currNode->next;
        }
        cout << " ----------------- " << endl;
    };

    void heapSort(){
        Node* tmp;
        Node* currNode = head;
        Node* newList;
        while(currNode != NULL){

        }
    }
private:
    Node* head;
};

LinkedList list;

void programmingLesson(int operatingType){

    switch (operatingType) {
        case 1:{
            student new_student;
            int total_node = list.TotalNode()-1;
            int sira = total_node;

            cout << "Öğrenci Numarası : ";
            cin >> new_student.student_number;
            cout << "Öğrenci Adı : ";
            cin >> new_student.name;
            cout << "Öğrenci Soyadı : ";
            cin >> new_student.surname;
            cout << "Öğrenci Programı (1 : Bilgisayar Müh. , 2 : Makine Müh. , 3 : Gıda Müh. ) : ";
            cin >> new_student.program;
            cout << "Kaçıncı Sıraya Eklenecek ( Sıra = " << total_node << " ) : ";
            cin >> sira;
            if(sira == NULL){
                sira = total_node;
            }
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

        case 5:{
            student new_student;

            string auto_student[5][4] = {
                    {"1030516799","Kemal","Aydın","1"},
                    {"1030516787","Mehmet","Kaynak","1"},
                    {"1030516785","Ali","Çolak","1"},
                    {"1030516687","Salih Berat","Ulutürk","1"},
                    {"1030516710","Aykut","Kocaman","1"},

            };

            for(int i = 0; i < 5; i++){
                new_student.student_number = auto_student[i][0];
                new_student.name = auto_student[i][1];
                new_student.surname = auto_student[i][2];
                new_student.program = auto_student[i][3];
                list.InsertNode(i,new_student);
            }

            alert("5 Adet Öğrenci Bilgisayar Programlama Dersine Eklendi","success");
            break;
        }

        default:{
            alert("Hatalı İşlem Seçtiniz","danger");
            break;
        }
    }
}

class sortingAlgorithms{
public:
    void selectedAlgorithm(int type){
        switch (type){
            case 1:{
                break;
            }
            case 4:{
                list.heapSort();
            }
        }
    }

};

void sortingMenu(){
    int selected_sorting;
    cout << "Sıralama İşlemi Seçiniz" << endl << "-------------" << endl;
    cout << "1-) Hızlı Sıralama ( Bilgisayar Programlama )" << endl;
    cout << "2-) Hızlı Sıralama ( Veritabanı Yönetim Sistemleri )" << endl;
    cout << "3-) Radiks Sıralama ( Veritabanı Yönetim Programlama )" << endl;
    cout << "4-) Kümeleme Sıralama ( Bilgisayar Programlama )" << endl;
    cout << "Seçiminiz : ";
    cin >> selected_sorting;
    sortingAlgorithms sorting;
    sorting.selectedAlgorithm(selected_sorting);
}


int main(int argc, const char * argv[]) {

    int operatingType = NULL;
    int lessonType = NULL;
    student deneme;
    deneme.student_number = "1030516799";
    deneme.name = "Kemal";
    deneme.surname = "Aydın";
    deneme.program = "1";
    list.InsertNode(0, deneme);
    list.DisplayList();
    do{
        cout << "İşlem Yapmak İstediğiniz Dersi Seçiniz ; " << endl;
        cout << "1 - Bilgisayar Programlama" << endl << "2 - Veritabanı Yönetim Sistemleri" << endl << "3- Karşılaştırma" << endl << "4- Sıralama" << endl << "5- Çıkış" << endl;
        cout << "Seçilen Ders : ";
        cin >> lessonType;
        switch (lessonType) {
            case 1:
                cout << "----------" << endl << "Bilgisayar Programlama Dersi İçin Yapmak İstediğiniz İşlemi Seçiniz ; "
                << endl;
                cout << "1- Öğrenci Ekle" << endl << "2- Öğrenci Sil" << endl << "3- Öğrenci Bul" << endl
                << "4- Öğrencileri Listele" << endl << "5- Otomatik Öğrenci Ekle" << endl;
                cout << "Seçilen İşlem : ";
                cin >> operatingType;
                programmingLesson(operatingType);
                break;

            case 2:
                cout << "----------" << endl;
                break;

            case 3:
                cout << "Karşılaştırmalar Yapılacak" << endl;
                break;

            case 4:
                    sortingMenu();
                break;
            case 5:
                alert("İyi Çalışmalar","warning");
                break;
            default:
                alert("Geçersiz İşlem Lütfen Tekrar Deneyin","danger");
                break;
        }
    }while(lessonType != 3);

    return 0;
}
