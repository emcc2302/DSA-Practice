#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool detectCycle(int src, vector<int> adj[], vector<int> &vis)
{
    vis[src] = 1;

    // {node, parent}
    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjacentNode : adj[node])
        {
            if (!vis[adjacentNode])
            {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            else if (adjacentNode != parent)
            {
                return true;
            }
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
            if (detectCycle(i, adj, vis))
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