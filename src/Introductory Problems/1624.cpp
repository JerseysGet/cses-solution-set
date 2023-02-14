#include <bits/stdc++.h>
using namespace std;
#define int long long

bool canPlace(string (&grid)[8], int row, int col, bool (&rowCheck)[8], bool (&colCheck)[8], bool (&mainDiagonalCheck)[15], bool (&alternateDiagonalCheck)[15]) {
    return (!rowCheck[row] && !colCheck[col] && !mainDiagonalCheck[row-col+7] && !alternateDiagonalCheck[row+col] && grid[row][col] == '.');
}


void place(string (&grid)[8], int row, int col, bool (&rowCheck)[8], bool (&colCheck)[8], bool (&mainDiagonalCheck)[15], bool (&alternateDiagonalCheck)[15]) {
    grid[row][col] = '1';
    rowCheck[row] = true;
    colCheck[col] = true;
    mainDiagonalCheck[row - col + 7] = true;
    alternateDiagonalCheck[row + col] = true;
}


int answer = 0;
void queens(string (&grid)[8], int row, bool (&rowCheck)[8], bool (&colCheck)[8], bool (&mainDiagonalCheck)[15], bool (&alternateDiagonalCheck)[15]) {
    if (row == 8) {
        answer++;
        return;
    }

    for (int c = 0; c < 8; c++) {
        if (canPlace(grid, row, c, rowCheck, colCheck, mainDiagonalCheck, alternateDiagonalCheck)) {
            place(grid, row, c, rowCheck, colCheck, mainDiagonalCheck, alternateDiagonalCheck);
            queens(grid, row+1, rowCheck, colCheck, mainDiagonalCheck, alternateDiagonalCheck);
            grid[row][c] = '.';
            rowCheck[row] = false;
            colCheck[c] = false;
            mainDiagonalCheck[row - c + 7] = false;
            alternateDiagonalCheck[row + c] = false;
        }
    }
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string grid[8];
    for (int i = 0; i < 8; i++) {
        getline(cin, grid[i]);
    }

    bool rowCheck[8] = {0};
    bool colCheck[8] = {0};
    bool mainDiagonalCheck[15] = {0};
    bool alternateDiagonalCheck[15] = {0};
    queens(grid, 0, rowCheck, colCheck, mainDiagonalCheck, alternateDiagonalCheck);
    cout << answer;
    return 0;
}