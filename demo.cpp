#include <bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3;
        ListNode* p1=list1;
        ListNode* p2=list2;
        if(list1 == NULL || list2 == NULL){
            return NULL;
        }
        while(p1!=NULL && p2!=NULL){
            if(p1->val==p2->val){
                list3=p1;
                list3->next=p2;
                list3=list3->next;
                p1=p1->next;
                p2=p2->next;
            }
            else if(p1->val<p2->val){
                list3=p1;
                list3=list3->next;
                p1=p1->next;
            }
            else if(p2->val<p1->val){
                list3=p2;
                list3=list3->next;
                p2=p2->next;
            }
        }
        return list3;
    }

ListNode* takeInput1()
{
    int val;
    cin>>val;
    ListNode* head=NULL;
    ListNode* tail=NULL;
    while(val != -1){
        ListNode* newListNode = new ListNode(val);
        if(head==NULL){
             head=newListNode;
             tail=newListNode;
        }
       else{
        tail->next=newListNode;
        tail=tail->next;
        //OR
        //tail=newListNode;
       }
        cin>>val;
    }
    return head;
}

int main() {
    // Write C++ code here

   ListNode* list1=takeInput1();
   ListNode* list2=takeInput1();
    return 0;
}
