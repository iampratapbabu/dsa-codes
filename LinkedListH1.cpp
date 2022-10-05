#include <bits/stdc++.h>
#include "header/linkedList.h"
using namespace std;

void printLinkedList(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}


int main() {
    // Write C++ code here
    cout<<"---------program started---------"<<endl;
    Node n1(1);
    Node n2(2);
    Node n3(3);

    n1.next = &n2;
    n2.next = &n3;

    Node* head = &n1;
    printLinkedList(head);

    return 0;
}

