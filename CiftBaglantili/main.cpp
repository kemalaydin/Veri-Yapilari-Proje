//
//  main.cpp
//  CiftBaglantili
//
//  Created by Kemal on 25.11.2018.
//  Copyright © 2018 Kemal. All rights reserved.
//

#include <iostream>
#include <string>
#include "ProgrammingLesson.cpp"


using namespace std;


int main(int argc, const char * argv[]) {
    int operatingType = NULL;
    int lessonType = NULL;
    
    cout << "İşlem Yapmak İstediğiniz Dersi Seçiniz ; " << endl;
    cout << "1 - Bilgisayar Programlama" << endl << "2 - Veritabanı Yönetim Sistemleri" << endl;
    cout << "Seçilen Ders : ";
    cin >> lessonType;
    switch (lessonType) {
        case 1:
            cout << "----------" << endl << "Bilgisayar Programlama Dersi İçin Yapmak İstediğiniz İşlemi Seçiniz ; " << endl;
            cout << "1- Öğrenci Ekle" << endl << "2- Öğrenci Sil" << endl << "3- Öğrenci Bul" << endl << "4- Öğrencileri Listele" << endl;
            cout << "Seçilen İşlem : ";
            cin >> operatingType;
            programmingLesson(operatingType);
            break;
            
        case 2:
            cout << "----------" << endl;
            break;
        default:
            cout << "Geçersiz Ders" << endl;
            break;
    }
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
