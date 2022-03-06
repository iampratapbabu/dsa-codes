/* spanning tree- it is a tree which contain all the vertices but it is undirected
aise graph jisme vertex to n rehte hain lekin edges n-1
means if vertex = 6 then edges should be 6-1=5
and cycle create nhi hone chahiye hmare mst me (minimum spanning tree)
bahut sare spanning trees me edges me weight diye rehte hain we have to calculte
*/

/*krushkal's algorithms
it is an algorithm that helps us to find mst of a given graph
vertex = n
edge=n-1
*/

#include <iostream>
using namespace std;

//edge name ka class bana liye to store ki kahan se kahan tk edge ja rha hai
//and kitna weight hai edge ka
class Edge
{
public:
    int source;
    int dest;
    int weight;
};

bool compare(Edge e1,Edge e2){
    return e1.weight < e2.weight;
}

//kruskals algorithm calling
void kruskals(Edge* input, int n, int E)
{
    //sbse pehle input array ko sort kr lenge taki apne weight ke hisab se ho jaye edges
    sort(input,input+E,compare);

    //output array of type edge bana lenge size will be n-1
    Edge* output = new Edge[n-1];

    //ek parent array maintain krenge so to check the parent of an element to avoid cycle
    int* parent = new int[n];
    //starting me element khud apne parents rahenge
    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    int count=0; //ye variable batayega ki currently hmne apne mst me kitne edges rakh chuke
    //coz edges always n-1 hone chahiye to use monitor karne ke liye ise bana lenge
    int i=0; //ye varible batayega ki currently hm kaun se edge pr kaam kr rhe hain

    //now tb tk kaam krenge means loop chalayenge jb tk ki count ki value n-1 na ho jaye
    while(count!=n-1){
        //ek ek krke edgeclass ka object banayenge and usme edge datatype ke array se
        //element nikal ke edgeclass ke object me assign krenge
        Edge currentEdge = input[i];
        //now check krenge ki is edge ko add krna safe hai ki nhi apne mst me
        //i mean cycle to nhi create ho rha
        int sourceParent = findParent(currentEdge.source,parent); //is function se parent find kr lenge
        int destParent = findParent(currentEdge.dest,parent);
        //agar source and dest ka parent different hai means is edge ko apne mst me
        //add kr skte hain
        if(sourceParent!=destParent){
            output[count]=currentEdge;
            count++;
        }
        i++;
    }

}

int main()
{
    cout<<"-------------Program started-------------"<<endl;
    int n,E;  //no. of vertices(n) and no. of edges(E) input le rhe hain
    cin>>n>>E;
    Edge* input = new Edge[E];  //input name ka array banaye hain jo edge type ka hai and dynamic hai
    //now is edge type array me input lenge
    for(int i=0;i<E,i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].dest=d;
        input[i].weight=w;

    }

    //now kruskals algorithm call krenge and vertices and  edge pass krenge
    kruskals(Edge,n,E);



    return 0;
}
