#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        next=NULL;
    }

};

Node* takeInput()
{
    int data;
    cin>>data;
    Node* head=NULL;
    //ek head pointer banake value NULL rakh liye
    while(data != -1){
        //jb tk inputted value -1 na ho tb tk ye loop chalega
        //now ek naya node banayenge
        Node* newNode = new Node(data);

        //agaar head ki valude null hai means sbse pehle node create ho rha hai
        //so head me new node ke value daal denge
        if(head==NULL){
             head=newNode;
        }
       else{
        //agar head ki value null nhi hui means hm dusra node ya usse aage ka node
        //bna rhe hain to hme nodes ko link bhi krna hai
        Node* temp=head;
        //temp node bana lenge and temp ko traverse krke last wale node tk le jayenge

        while(temp->next!=NULL){
            temp=temp->next;
        }
        //and then temp ke  address me new node daal denge
        temp->next=newNode;
       }
        cin>>data;
    }
    return head;
}
//this function takes O(n^2) time complexity so will improve its efficiency
//jo ek extra whhile loop chal rha hai to find out last node uske jagah hm
//ek tail pointer rakhlenge jo last node ka address constant time me bata dega

Node* takeInput1()
{
    int data;
    cin>>data;
    Node* head=NULL;
    Node* tail=NULL;
    while(data != -1){

        Node* newNode = new Node(data);


        if(head==NULL){
             head=newNode;
             tail=newNode;
        }
       else{

        tail->next=newNode;
        tail=tail->next;
        //OR
        //tail=newNode;
       }
        cin>>data;
    }
    return head;
}


void print(Node* head)
{
    //direct head node ko use nhi krenge pehle ek temp node bna lenge
        //so that operation ke baad bhi head ka value change nhi ho
        Node* temp = head;
        while(temp!=NULL){

        //pehle data print krenge
        cout<<temp->data<<endl;
        //ab temp ka value aage kr denge means temp me temp ka next value dal denge
        temp=temp->next;
        //aisa tb tk krenge jab tk temp null na ho jaye
    }
}

int main()
{
    //we will make linked list according to user inputted value
    Node* head=takeInput1();
    print(head);

    return 0;
}

