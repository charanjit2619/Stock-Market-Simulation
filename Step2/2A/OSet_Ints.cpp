#include <iostream>
#include "OSet_Ints.h"
#include "OSetExceptions.h"

using namespace std;

OSet_Ints::OSet_Ints():head(nullptr){};

OSet_Ints::~OSet_Ints(){
  struct Node * current = head;
  while (current != nullptr) {
    struct Node* next = current->next;
    delete current;
    current = next;
  }
}

//Methods
void OSet_Ints::insert(int i){
    if (!head){
        head = new Node{i, nullptr};
        return;
        }

    struct Node *current = head, *prev = nullptr;
    while(current){
        if (current->item < i){
            prev = current;
            current = current->next;
        }
        else if (current->item > i){
            struct Node* newNode = new Node{i, nullptr};
            newNode->next = current;
            if (!prev){
                head = newNode;
                return;
            }
            else{
                prev->next = newNode;
                newNode->next = current;
                return;
            }
        }
        else {
            throw DuplicateException{};
        }
    }

    if (!current){
        prev->next = new Node{i, nullptr};
    }
}

void OSet_Ints::remove(int i){
    struct Node *current = head, *prev=nullptr;
    while(current && current->item!=i){
        prev = current;
        current = current->next;  
    }
    
    if(!current){
        throw RemoveException{};
        return ;
    } //if the element is not in the list.
    if(!prev)head = current->next; /*Deleting the first item*/
    else prev->next = current->next;/*Deleting any other item but the first one*/
    delete current;
}

bool OSet_Ints::contains(int i ){
    struct Node *temp = head;
    while(temp){
        if(temp->item == i)return true;
        temp = temp->next;
    }
    return false;
}

void OSet_Ints::display(){
    struct Node* temp = head;
    if (!temp){
        cout << "empty list" << endl ;
        return;
    }
    while(temp){
        cout <<  temp->item;
        if(temp->next)
            cout << ", ";
        temp = temp->next;
    }
    cout << endl;
}    	//Display all elements of the set on a stream.