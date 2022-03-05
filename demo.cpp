#include <bits/stdc++.h>
using namespace std;

int gcd1(int A, int B)
{
    if(B==0)
        return A;
    else
        return gcd1(B, A % B);
}

int longestLength(vector<int>& arr,int n){
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        int gcd = 0;
        for (int j = i; j < n; j++) {
            gcd = gcd1(gcd, arr[j]);
            if (gcd > 1)
                maxLength = max(maxLength, j - i + 1);
            else
                break;
        }
    }
    return maxLength-1;
}


int main() {
    // Write C++ code here
    cout<<"---------program started---------"<<endl;
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(8);


    cout<<longestLength(arr,arr.size())<<endl;



    return 0;
}
