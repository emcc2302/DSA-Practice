#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans) {

    vis[node] = 1;
    ans.push_back(node);

    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis, ans);
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    cout << "Enter edges:\n";

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);
    vector<int> ans;

    dfs(1, adj, vis, ans);   // Start DFS from node 1

    cout << "DFS Traversal: ";

    for (auto node : ans)
        cout << node << " ";

    return 0;
}