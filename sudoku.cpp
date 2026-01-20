#include <bits/stdc++.h>
using namespace std;

static const int N = 9;

bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num) return false;
        if (grid[i][col] == num) return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[startRow + i][startCol + j] == num)
                return false;

    return true;
}

bool solveSudoku(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku(grid))
                            return true;
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    //valid sudoku
    int grid[N][N] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    //invalid sukodu
    // int grid[9][9] = {
    //     {5, 1, 6, 8, 4, 9, 7, 3, 2},
    //     {3, 0, 7, 6, 0, 5, 0, 0, 0},
    //     {8, 0, 9, 7, 0, 0, 0, 6, 5},
    //     {1, 3, 5, 0, 6, 0, 9, 0, 7},
    //     {4, 7, 2, 5, 9, 1, 0, 0, 6},
    //     {9, 6, 8, 3, 7, 0, 5, 0, 0},
    //     {2, 5, 3, 1, 8, 6, 0, 7, 4},
    //     {6, 8, 4, 2, 0, 7, 0, 5, 0},
    //     {7, 9, 1, 0, 5, 0, 6, 0, 8}
    // };


    if (solveSudoku(grid)) {
        printGrid(grid);
    } else {
        cout << "No solution exists\n";
    }

    return 0;
}
