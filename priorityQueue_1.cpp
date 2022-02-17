#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
    vector<int> pq;
public:
    //constructor
    PriorityQueue(){

    }

    bool isEmpty(){
        return pq.size()==0;
    }

    int getSize(){
        return pq.size();
    }

    int getMin(){
        if(isEmpty())
            return 0;
        return pq[0];
    }

    //insert
    void insert(int element){
        pq.push_back(element); //sbse pehle element ko insert kr lenge vector me

        int childIndex = pq.size()-1; //jis index pr push hua hai wo index calculate kr liye

        while(childIndex>0){
            int parentIndex = (childIndex-1)/2; //parent index calculte kr liye
            //coz parent index pr jo element hai usi se compare krna hota hai ki
            //element shi jagah hai ya swapping krna prega
            if(pq[childIndex]<pq[parentIndex]){ //agar childindex wala element chhota hai
                    //means galat jagah hai hme use parent index wale element se swap krna hoga
                    int temp = pq[childIndex];
                    pq[childIndex]=pq[parentIndex];
                    pq[parentIndex]=temp;

            }else{ //agar child element chhota nhi hai means swap krne ki jaroorat nhi
                break;
            }
            childIndex=parentIndex;
        }

    }

    //remove
    int removeMin(){
        if(isEmpty()){
            return 0;
        }
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();

        //now maintaining the complete binary tree
        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex+1;
        int rightChildIndex = 2*parentIndex+2;

        while(leftChildIndex<pq.size()){
            int minIndex = parentIndex;
            if(pq[minIndex]>pq[leftChildIndex]){
                minIndex=leftChildIndex;
            }
            if(rightChildIndex<pq.size()&&pq[rightChildIndex]<pq[minIndex]){
                minIndex=rightChildIndex;
            }
            if(minIndex==parentIndex){
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex]=pq[parentIndex];
            pq[parentIndex]=temp;

            parentIndex=minIndex;
            leftChildIndex = 2*parentIndex+1;
            rightChildIndex = 2*parentIndex+2;
        }

        return ans;
    }
};

int main()
{
    cout<<"-------------Program started-------------"<<endl;
    PriorityQueue p;
    p.insert(10);
    p.insert(30);
    p.insert(50);
    p.insert(80);
    p.insert(40);
    p.insert(20);
    p.insert(60);
    p.insert(70);

    cout<<p.getSize()<<endl;
    cout<<p.getMin()<<endl;

    while(!p.isEmpty()){
        cout<<"Element Removed: "<<p.removeMin()<<endl;
    }

    return 0;
}

