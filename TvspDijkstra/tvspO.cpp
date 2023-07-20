#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
/*
del=4/5 user input
1. which vetex splits
2. New weight of i


TVSP.txt
U V C
U to V cost C

1 2 4
1 3 3
2 4 2
4 7 1 
4 8 4
3 5 1
3 6 3
6 9 2
6 10 4

*/

map<ll,vector<ll> >graph;
// node ,vector of it's childs

llu tolerance;
set<llu>boosterPlacement;
ll weight[200][200]={-1};
//node u to v weight[u][v];

ll depthFirstSeach(llu node, llu par){
    if(graph.find(node)==graph.end()){
        return 0;
        //node is not found in graph.Hence dalay is zero.
    }
    ll d = 0;//let there is no delay
    for(auto it:graph[node]){
        d = max(weight[node][it]+depthFirstSeach(it, node) , d);
        //graph[node] -> vector consisting of node's childs.
        //for each child of graph[node]
        //=> delay= max of ( weight of this node to it's childs+childs delay, current dealy);
    }
    // if the node has parent && (delay+weight of parent to node) > tolerance
    //place boster in that node.Hence dalay of the node becomes zero as signal regenerates.
    if(par!=-1 && (d + weight[par][node]>tolerance)) {
        boosterPlacement.insert(node);
        d=0;
    }
    cout<<"Vertex:"<<node<<" Delay after tvsp:"<<d<<endl;
    return d;
}
int main()
{
    ll u,v,w;
    ifstream in("tvsp.txt");
    // any number of lines having
    // u v w
    //where: edge weight from U to V is W
    while(in>>u>>v>>w){
        graph[u].push_back(v);
        weight[u][v] = w;
    }
    in.close();

    tolerance=5;
    cout<<"Enter Tolerance: ";
    cin>>tolerance;


    depthFirstSeach(1,-1);
    ofstream out("boster.txt");
    cout<<"Booster Placements: ";
    for(auto it: boosterPlacement){
        cout<<it<<" ";
        out<<it<<" ";
    }
    cout<<"\nHere in graph normal vertex color is set \"green\" and vertex where boster should be placed is colored \"red\"  "<<endl;
    out.close();//to save file we need to close it.

    // std::string filename = "alisirlab.py";
    // std::string command = "python ";
    // command += filename;
    // system(command.c_str());
}
