// Sudoku: Backtracking
#include <iostream>
using namespace std;

// Para las celdas vacías
#define UNASSIGNED 0

#define N 9

// Revisa si la posición es válida
bool encontrarPosicion(int grid[N][N], int& row, int& col);

// Revisa si la celda es válida
bool esValida(int grid[N][N], int row, int col, int num);

bool resolverSudoku(int grid[N][N]) {
    int row, col;

    if (!encontrarPosicion(grid, row, col))
        return true;

    for (int num = 1; num <= 9; num++)
    {

        if (esValida(grid, row, col, num))
        {

            grid[row][col] = num;

            if (resolverSudoku(grid))
                return true;

            grid[row][col] = UNASSIGNED;
        }
    }

    return false;
}

bool encontrarPosicion(int grid[N][N], int& row, int& col) {
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

bool usadoEnFila(int grid[N][N], int row, int num) { 
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool usadoEnColumna(int grid[N][N], int col, int num) { 
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool usadoEnSubcuadro(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow]
                [col + boxStartCol] ==
                num)
                return true;
    return false;
}

bool esValida(int grid[N][N], int row, int col, int num) {

    return !usadoEnFila(grid, row, num)
           && !usadoEnColumna(grid, col, num)
           && !usadoEnSubcuadro(grid, row - row % 3,
                                col - col % 3, num)
           && grid[row][col] == UNASSIGNED;
}

void imprimirMatriz(int grid[N][N]) {
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}

int main() {
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    if (resolverSudoku(grid) == true)
        imprimirMatriz(grid);
    else
        cout << "No existe solución :(";

    return 0;
}
