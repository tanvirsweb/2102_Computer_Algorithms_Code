#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pr pair<ll,ll>
using namespace std;

map<ll, vector<pr>>graph;
map<ll,ll>parent;
ll max_node;
void backtrack(ll n){
    if(parent.find(n) == parent.end()) return;
    if(parent[n] == n) return;
    backtrack(parent[n]);
    cout<<n<<" ";
}

void print(vector<ll>&dist){
    for(int i = 1;i<max_node+1; i++){
        backtrack(i);
        cout<<"= "<<dist[i]<<endl;
    }
}
void bellman(ll root){
    vector<ll> dist(max_node+1,LONG_LONG_MAX);
    dist[0]=dist[root]=0;
    parent[0] = parent[root] = 0;
    for(int i=0;i<max_node-1;i++){
        for(auto u: graph){
            for(auto v: u.second){
                if(dist[u.first]+v.second < dist[v.first]){
                    dist[v.first] = dist[u.first] + v.second;
                    parent[v.first] = u.first;
                    
                }
            }
        }
    }
    print(dist);
}
int main()
{
    ifstream in("input.txt");
    ll u,v,w;
    while(in>>u>>v>>w){
        graph[u].pb({v,w});
        max_node = max(u,max(max_node,v));
    }
    bellman(1);
}