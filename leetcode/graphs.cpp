#include<bits/stdc++.h>

using namespace std;

/* for adjaceny matrix
int main(){
    int n,m;
    cin>>n>>m;
    //the graph is stored here
    int adj[n+1][m+1];
    //if weighted graph then take adj[u][v]=weight
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;//adj[u][v]=weight
        adj[v][u]=1;
    }
}
*/

/*For adjacency list
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    //if graph is directed then remove adj[v].push_back(u);
    //if graph is weighted then use pair<int,int> instead of int
    for(int i=0;i<m;i++){
        int u,v;
        //here use pair<int,int> p; cin>>p.first>>p.second>>weight;f
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
*/