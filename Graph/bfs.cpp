#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n,m;

    cin>>n>>m;
    vector<int>adj[n+1];
    cout << "Enter edges:\n";

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //1 based indexing
    int vis[n+1]={0};
    vis[1]=1;
    queue<int>q;
    q.push(1);

    vector<int>bfs;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);


        for(auto it :adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    cout << "BFS Traversal: ";

    for (auto node : bfs)
        cout << node << " ";

    return 0;
   
}