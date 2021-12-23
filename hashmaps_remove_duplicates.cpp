#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> removeDuplicates(int* a, int n){
    vector<int> output;
    unordered_map<int,bool> seen;
    for(int i=0;i<n;i++){
        if(seen.count(a[i])>0){
            continue;
        }
        seen[a[i]]=true;
        output.push_back(a[i]);
    }
    return output;
}

int main()
{
    cout<<"-------------Program started-------------"<<endl;
    int arr[]={2,3,5,4,3,8,3,5};
    vector<int> output = removeDuplicates(arr,8);
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<endl;
    }
    return 0;
}

