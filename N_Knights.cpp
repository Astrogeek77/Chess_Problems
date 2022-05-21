// task is to place N (arbitrary number) queens on the chess board, such that no queen can attack other queens and print all the possible answers.

#include <bits/stdc++.h>
using namespace std;

int counter = 0; // total possible ways

bool isitSafe(vector<vector<int>> &grid, int r, int c, int n)
{
    if (r - 2 >= 0 and c - 1 >= 0 and grid[r - 2][c - 1])
        return false;
    if (r - 1 >= 0 and c - 2 >= 0 and grid[r - 1][c - 2])
        return false;
    if (r - 2 >= 0 and c + 1 < n and grid[r - 2][c + 1])
        return false;
    if (r - 1 >= 0 and c + 2 < n and grid[r - 1][c + 2])
        return false;
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

void countKnights(vector<vector<int>> &grid, int row, int col, int n, int count)
{
    // base case
    if (count == nT)
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
                countKnights(grid, i, j + 1, n, count + 1);
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
    countKnights(grid, 0, 0, n, 0);
    printf("\nTotal Possible ways for %d x %d Board = %d\n", n, n, counter);
}