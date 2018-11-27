//
//  ProgrammingLesson.cpp
//  CiftBaglantili
//
//  Created by Kemal on 26.11.2018.
//  Copyright © 2018 Kemal. All rights reserved.
//

#include "ProgrammingLesson.hpp"

#include <iostream>
#include <string>
#include "StudentStruct.hpp"
#include "LinkedList.cpp"


using namespace std;

void programmingLesson(int operatingType){
    List list;
    switch (operatingType) {
        case 1:{
            student new_student;
            cout << "Öğrenci Numarası : ";
            cin >> new_student.student_number;
            cout << "Öğrenci Adı : ";
            cin >> new_student.name;
            cout << "Öğrenci Soyadı : ";
            cin >> new_student.surname;
            cout << "Öğrenci Programı : ";
            cin >> new_student.program;
            list.InsertNode(0, new_student);
            break;
        }
        case 4:{
            list.DisplayList();
            break;
        }
            
        default:{
            cout << "Hatalı İşlem Seçtiniz" << endl;
            break;
        }
    }
}
