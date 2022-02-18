#include <iostream>
#include <queue>
/*inbuilt priority queue bhi queue me hi rehta hai
bs class me hm priority_queue<datatype> is trah initiate krenge
by default max priority queue bnta hai means
functions:
empty()
size()
push(element)
T top()
pop() - lekin isse element return nhi hoga
*/

using namespace std;

int main()
{
    priority_queue<int> pq;
    pq.push(167);
    pq.push(78);
    pq.push(87);
    pq.push(56);
    pq.push(45);
    pq.push(20);

    cout<<"size: "<<pq.size()<<endl;
    cout<<"Top: "<<pq.top()<<endl;

    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
    return 0;
}
