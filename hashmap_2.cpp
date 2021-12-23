#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    cout<<"-------------Program started-------------"<<endl;
    unordered_map<string,int> ourmap;
    ourmap["abc"]=1;
    ourmap["def"]=2;
    ourmap["ghi"]=3;
    ourmap["jkl"]=4;
    ourmap["mno"]=5;
    ourmap["pqr"]=6;

    //iteration over unordered map
    unordered_map<string,int>::iterator it=ourmap.begin();
    while(it != ourmap.end()){
        cout<<"key: "<<it->first<<" value: "<<it->second<<endl;
        it++;
    }
    //yahan output koi sorted order me nhi aayega koi bhi pehle print ho jayega
    //bt if we have used normal map then sb sorted order me print hota

    //find function this will return iterator
    unordered_map<string,int>::iterator it2=ourmap.find("abc");
    cout<<it2->second<<endl;

    //erasing from the unordered map
    //ourmap.erase(it2,it2+4);
    //it2 ke starting se it2+3 tk delete ho jayega

    return 0;
}
