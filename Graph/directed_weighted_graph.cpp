#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    //storing a list
    vector<pair<int,int>>adj[n+1];
    cout << "Enter source destination weight:\n";

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;

           // Directed edge: u -> v 
           
        adj[u].push_back({v,w});
    }

    //print the list
      cout << "\nAdjacency List:\n";

    for(int i=1;i<=n;i++){
        cout<<i<<"-->";

        for(auto edge :adj[i]){
             cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout<<endl;
    }
    return 0;
}