#include <bits/stdc++.h>
using namespace std;


//factorial
int factorial(int n)
{
    if(n==0){   //base case
        return 1;
    }
    int smalloutput = factorial(n-1);  //assume this gives true results we don't have to question this
    return n*smalloutput;  //using n-1 we can find n
}

//fibonacci series
int fibonacci(int n){
    if(n==1 || n==2){
        return 1;
    }
    int smalloutput = fibonacci(n-1);
    return smalloutput+n;

}

//fibonacci series little bit different
int fibonacciDiff(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int smalloutput1=fibonacciDiff(n-1);
    int smalloutput2=fibonacciDiff(n-2);
    return smalloutput1+smalloutput2;
}

//checking if array is sorted
bool is_sorted(int a[],int size){
    if(size==0 || size==1){
        return true;
    }
    if(a[0]>a[1]){
        return false;
    }
    bool smaller_sorted = is_sorted(a+1,size-1);
    if(smaller_sorted){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    // Write C++ code here
    cout<<"---------program started---------"<<endl;
    int n;
    cin>>n;
    int output = factorial(n);
    cout<<output<<endl;
    //cout<<fibonacci(n);
    cout<<fibonacciDiff(n)<<endl;
    int a[]={1,2,3,4,5};
    int sizeofarray = sizeof(a)/sizeof(a[0]);
    cout<<is_sorted(a,sizeofarray)<<endl;
    return 0;
}

