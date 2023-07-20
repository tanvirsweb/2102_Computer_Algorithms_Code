#include<bits/stdc++.h>
using namespace std;
#define V 9
int G[V][V];
int parent[V]={-1};
/*

lab final: 11th lab.

instead  of infinite use any suitable sign
dijkstra.txt
0 for - ->same node
-1 for infinite -->no G directly connected to the node

sample output:
shortest path for each each node from root.
0-1-2-8-14
0-1,4
0-8

*/
void printPath(int parent[], int j)
{
    // Base Case : If j is source
    if (parent[j]==-1)
        return;

    printPath(parent, parent[j]);

    printf(" > %d ", j);
}

int minDfromSrc(int d[],bool visited[]){
    int min=INT_MAX,min_index;
    for(int i=0;i<V;i++){
        if(visited[i]==false && d[i]<=min){
            min=d[i];
            min_index=i;
        }
    }
    return min_index;
}

void dijkstraFunc(int G[V][V],int src){
    int d[V];
    bool visited[V];
    for(int i=0;i<V;i++){
        // initialize visited and d from src
        d[i]=INT_MAX;
        // d from all vertex to source INFINITE
        visited[i]=false;
        // all are unvisited
    }
    //d from source to itself is 0
    d[src]=0;
    for(int i=0;i<V-1;i++){
        //from unvisited nodex u th index has minimun d from Source
        int u=minDfromSrc(d,visited);
        visited[u]=true;
        // we are taking u vertex.
        
        int par=-1;
        for(int j=0;j<V;j++){

            // edge j -> unvisited & edge u-j exists & d from root to is not infinite
            if(visited[j]==false && G[u][j] && d[u]!=INT_MAX && d[u]+G[u][j] < d[j] ){
                d[j]=d[u]+G[u][j];
                parent[j]=u;// parent of jth is u;
            }
        }
    }

    cout<<"\nVertex d from Source:"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<"\t\t"<<d[i]<<endl;
    }
    
    cout<<"Shortest paths from source vertex:"<<src<<" to each vertex:"<<endl;
    for(int i=0;i<V;i++){
        cout<<src;
        printPath(parent,i);
        cout<<endl;
        
    }

    
}

int main(){
    ifstream in("dijkstra.txt");

    cout<<"  \t";
    for(int i=0;i<V;i++) 
        cout<<i<<": \t";
    cout<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<": \t";
        for(int j=0;j<V;j++){
            in>>G[i][j];
            if(G[i][j]==-1){
                cout<<"inf  \t";
                G[i][j]=0;
            }
            
            else if(G[i][j]==0)
                cout<<"-  \t";
            else cout<<G[i][j]<<"  \t";

            
        }
        cout<<endl;
    }

    dijkstraFunc(G,0);
    return 0;
}