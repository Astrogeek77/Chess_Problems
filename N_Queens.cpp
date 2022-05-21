// task is to place N (arbitrary number) queens on the chess board, such that no queen can attack other queens and print all the possible answers.

#include <bits/stdc++.h>
using namespace std;

int counter = 0; // total possible ways

bool isitSafe(vector<vector<int>> &grid, int row, int col, int n)
{
    // column
    for (int i = row - 1; i >= 0; i--)
    {
        if (grid[i][col])
            return false;
            
    }
    // left upper diagonal
    for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--)
    {
        if (grid[i][j])
            return false;
    }
    // right upper diagonal
    for (int i = row - 1, j = col + 1; i >= 0 and j < n; i--, j++)
    {
        if (grid[i][j])
            return false;
    }
    return true;
}

void display(vector<vector<int>> &grid, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

void countQueens(vector<vector<int>> &grid, int row, int n)
{
    // base case
    if (row == n)
    {
        counter++;
        display(grid, n);
        cout << "\n\n";
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isitSafe(grid, row, col, n))
        {
            grid[row][col] = 1;
            countQueens(grid, row + 1, n);
            grid[row][col] = 0; // backtrack
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
    countQueens(grid, 0, n);
    printf("\nTotal Possible ways for %d x %d Board = %d\n", n, n, counter);
}