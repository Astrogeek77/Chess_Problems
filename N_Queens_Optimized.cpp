#include <iostream>
#include <bitset>
using namespace std;

bitset<100> col, rd, ld;

int counter = 0;

void nqueens(int row, int n)
{
    if (row == n)
    {
        counter++;
        return;
    }

    for (int c = 0; c < n; c++)
    {
        if (!col[c] and !ld[row - c + n - 1] and !rd[row + c])
        {
            col[c] = ld[row - c + n - 1] = rd[row + c] = 1;
            nqueens(row+1, n);
            col[c] = ld[row - c + n - 1] = rd[row + c] = 0;
        }
    }
}

int main(){
    int n;
    printf("Enter the Dimensions of board(N x N): ");
    cin >> n;
    cout << endl;

    nqueens(0, n);
    printf("\nTotal Possible ways for %d x %d Board = %d\n", n, n, counter);
}