// Sudoku Solver using Backtracking
#include <iostream>
using namespace std;

// For empty cells
#define UNASSIGNED 0

#define N 9

// Checks for a valid cell and position
bool findPos(int grid[N][N], int& row, int& col);
bool isValid(int grid[N][N], int row, int col, int num);

bool solve(int grid[N][N]) {
    int row, col;

    if (!findPos(grid, row, col))
        return true;

    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {

            grid[row][col] = num;
            
            if (solve(grid))
                return true;

            grid[row][col] = UNASSIGNED;
        }
    }

    return false;
}

bool findPos(int grid[N][N], int& row, int& col) {
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

bool usedInRow(int grid[N][N], int row, int num) {
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool usedInColumn(int grid[N][N], int col, int num) {
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool usedInSubSquare(int grid[N][N], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
    return false;
}

bool isValid(int grid[N][N], int row, int col, int num) {
    return !usedInRow(grid, row, num)
           && !usedInColumn(grid, col, num)
           && !usedInSubSquare(grid, row - row % 3,
                               col - col % 3, num)
           && grid[row][col] == UNASSIGNED;
}

void print(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}

int main() {
    int grid[N][N] = { { 0, 0, 4, 2, 5, 0, 0, 6, 0 },
                       { 0, 0, 0, 0, 3, 0, 0, 0, 4 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 3, 0, 0, 0, 0, 0 },
                       { 3, 8, 6, 7, 0, 0, 4, 0, 0 },
                       { 0, 0, 9, 0, 0, 6, 0, 0, 1 },
                       { 0, 5, 2, 8, 7, 0, 6, 4, 3 },
                       { 6, 3, 0, 1, 0, 5, 2, 0, 0 },
                       { 0, 0, 0, 0, 2, 3, 5, 0, 7 } };

    if (solve(grid))
        print(grid);
    else
        cout << "There's no solution :(";

    return 0;
}
