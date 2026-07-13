#include <iostream>
#include <vector>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &image, vector<vector<int>> &ans, int iniColor, int newColor, int delRow[], int delCol[])
{
    int n = image.size();
    int m = image[0].size();

    // color the current pixel

    ans[row][col] = newColor;

    // traverse all 4 direction
    for (int i = 0; i < 4; i++)
    {
        int neigh_row = row + delRow[i];
        int neigh_col = col + delCol[i];

        if (neigh_row >= 0 && neigh_row < n && neigh_col >= 0 && neigh_col < m && image[neigh_row][neigh_col] == iniColor && ans[neigh_row][neigh_col] != newColor)
        {
            dfs(neigh_row, neigh_col, image, ans, iniColor, newColor, delRow, delCol);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> image(n, vector<int>(m));

    cout << "Enter the image: \n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> image[i][j];
        }
    }
    int sr, sc, newColor;

    cout << "Enter starting row and column: ";
    cin >> sr >> sc;

    cout << "Enter new color: ";
    cin >> newColor;

    int iniColor = image[sr][sc];

    vector<vector<int>> ans = image;
    //Uses extra O(N × M) space
    //we just copy of the vector or grid for comparision or visited array

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    dfs(sr, sc, image, ans,
        iniColor, newColor,
        delRow, delCol);

    cout << "\nFlood Filled Image:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}