// task is to place N (arbitrary number) kings on the chess board, such that no king can attack other kings and print all the possible answers.

#include <bits/stdc++.h>
using namespace std;

int counter = 0; // total possible ways

bool isitSafe(vector<vector<int>> &grid, int r, int c, int n)
{
    if (r - 1 >= 0 and c - 1 >= 0 and grid[r - 1][c - 1]) // left upper diagonal
        return false;
    if (r - 1 >= 0 and c >= 0 and c < n and grid[r - 1][c]) // top
        return false;
    if (r - 1 >= 0 and c + 1 < n and grid[r - 1][c + 1]) // right upper diagonal
        return false;
    if (r >= 0 and r < n and c - 1 >= 0 and grid[r][c - 1]) // left
        return false;
    if (r >= 0 and r < n and c + 1 < n and grid[r][c + 1]) // right
        return false;
    // if (r + 1 < n and c - 1 >= 0 and grid[r + 1][c - 1]) // bottom left diagonal
    //     return false;
    // if (r + 1 < n and c < n and c > 0 and grid[r + 1][c]) // bottom
    //     return false;
    // if (r + 1 < n and c + 1 < n and grid[r + 1][c + 1]) // bottom right diagonal
        // return false;
    return true;
}

void display(vector<vector<int>> &grid, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
                cout << "K ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

void countKings(vector<vector<int>> &grid, int row, int col, int n, int count)
{
    // base case
    if (count == n)
    {
        counter++;
        display(grid, n);
        return;
    }

    for (int i = row; i < n; i++)
    {
        for (int j = (i == row) ? col : 0; j < n; j++)
        {
            if (isitSafe(grid, i, j, n))
            {
                grid[i][j] = 1;
                countKings(grid, i, j + 2, n, count + 1);
                grid[i][j] = 0;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the Dimensions of board(N x N): ");
    cin >> n;
    cout << endl;

    vector<vector<int>> grid(n, vector<int>(n, 0));
    countKings(grid, 0, 0, n, 0);
    printf("\nTotal Possible ways for %d x %d Board = %d\n", n, n, counter);
}