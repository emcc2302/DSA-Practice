#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;

    for (auto adjacentNode : adj[node])
    {
        if (!vis[adjacentNode])
        {
            if (dfs(adjacentNode, node, adj, vis))
                return true;
        }
        else if (adjacentNode != parent)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    cout << "Enter edges:\n";

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);

    bool cycle = false;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, adj, vis))
            {
                cycle = true;
                break;
            }
        }
    }

    if (cycle)
        cout << "Cycle Detected";
    else
        cout << "No Cycle";

    return 0;
}