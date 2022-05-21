// Given a N *N board with the Knight placed on the first block of an empty board.Moving according to the rules of chess knight must visit each square exactly once.Print the order of each cell in which they are visited.

#include <bits/stdc++.h>
using namespace std;

int ways = 0;

void display(vector<vector<int>> &grid, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool isitSafe(vector<vector<int>> &grid, int n, int i, int j, vector<vector<bool>> &visited)
{
    return (i >= 0 and i < n and j >= 0 and j < n and visited[i][j] == false);
}

void knightsTour(vector<vector<int>> &grid, int n, int i, int j, int counter, vector<vector<bool>> &visited)
{
    // base case:
    if (counter == n * n - 1)
    {
        grid[i][j] = counter;
        display(grid, n);
        ways++;
        cout << "\n\n";
        return;
    }

    if (counter >= n * n)
        return;

    int x_dir[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int y_dir[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    visited[i][j] = true;
    grid[i][j] = counter;

    for (int k = 0; k < 8; k++)
    {
        if(isitSafe(grid, n, i + x_dir[k], j + y_dir[k], visited))
        {
            knightsTour(grid, n, i + x_dir[k], j + y_dir[k], counter+1, visited);
        }
    }
    grid[i][j] = -1;
    visited[i][j] = false;
}

int main()
{
    int n;
    printf("Enter the Dimensions of board(N x N): ");
    cin >> n;
    cout << endl;

    vector<vector<int>> grid(n, vector<int>(n, -1));
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    knightsTour(grid, n, 0, 0, 0, visited);

    printf("\nTotal Possible ways for %d x %d Board = %d\n", n, n, ways);
}
