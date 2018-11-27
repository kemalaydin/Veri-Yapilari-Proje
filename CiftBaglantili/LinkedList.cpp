//
//  LinkedList.cpp
//  CiftBaglantili
//
//  Created by Kemal on 26.11.2018.
//  Copyright © 2018 Kemal. All rights reserved.
//

#include <iostream>
#include <string>
#include "StudentStruct.hpp"


using namespace std;

class Node{
public:
    student data;
    // Sonraki Adres
    Node* next;
    // Önceki Adres
    Node* prev;
};

class List{
public:
    List(void){ head = NULL; }
    ~List(void){
        {
            Node* currNode = head, *nextNode = NULL;
            while (currNode != NULL)
            {
                nextNode    =    currNode->next;
                delete currNode;
                currNode    =    nextNode;
            }
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
            return currIndex;
        }
        return 0;
        
    };
    void DisplayList(void){
        Node* currNode = head;
        while(currNode != NULL){
            if(currNode->prev == NULL){
                cout << "Kendi : " << currNode->data.student_number << endl <<"Sonraki : " << currNode->next->data.student_number << endl;
            }else if(currNode->next == NULL){
                cout << "Kendi : " << currNode->data.student_number << endl <<"Önceki : " << currNode->prev->data.student_number << endl;
            }else{
                cout << "Kendi : " << currNode->data.student_number << endl <<"Sonraki : " <<  currNode->next->data.student_number << endl <<"Önceki : " << currNode->prev->data.student_number <<endl;
            }
            currNode = currNode->next;
            cout << "---------" << endl;
        }
    };
private:
    Node* head;
};
