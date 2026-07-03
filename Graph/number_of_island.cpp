#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    q.push({row, col});
    vis[row][col] = 1;

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
   

    // Traverse all 8 neighbours
    for (int delRow = -1; delRow <= 1; delRow++)
    {
        for (int delCol = -1; delCol <= 1; delCol++)
        {
            int neig_row = row + delRow;
            int neig_col = col + delCol;

            if (neig_row >= 0 && neig_row < n && neig_col >= 0 && neig_col < m && grid[neig_row][neig_col] == '1' && !vis[neig_row][neig_col])
            {
                vis[neig_row][neig_col] = 1;
                q.push({neig_row, neig_col});
            }
        }
    }
}
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    cout << "Enter the grid (0 or 1):\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int cnt = 0;

    for (int row = 0; row < n; row++)
    {

        for (int col = 0; col < m; col++)
        {

            if (!vis[row][col] && grid[row][col] == '1')
            {

                cnt++;
                bfs(row, col, grid, vis);
            }
        }
    }

    cout << "Number of Islands = " << cnt << endl;

    return 0;
}