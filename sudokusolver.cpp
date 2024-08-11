#include<bits/stdc++.h>
using namespace std;

void printboard(int board[][9], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isvalid(int board[][9], int i, int j, int num, int n) {
    // Row check
    for (int x = 0; x < n; x++) {
        if (board[i][x] == num) return false;
    }

    // Column check
    for (int y = 0; y < n; y++) {
        if (board[y][j] == num) return false;
    }

    // Subgrid check
    int rn = sqrt(n);
    int si = i - i % rn;
    int sj = j - j % rn;
    for (int x = si; x < si + rn; x++) {
        for (int y = sj; y < sj + rn; y++) {
            if (board[x][y] == num) return false;
        }
    }

    return true;
}

bool solver(int board[][9], int i, int j, int n) {
    if (i == n) {
        printboard(board, n);
        return true;
    }

    if (j == n) {
        return solver(board, i + 1, 0, n);
    }

    if (board[i][j] != 0) {
        return solver(board, i, j + 1, n);
    }

    for (int num = 1; num <= 9; num++) {
        if (isvalid(board, i, j, num, n)) {
            board[i][j] = num;
            bool ans = solver(board, i, j + 1, n);
            if (ans) {
                return true;
            }
            board[i][j] = 0;
        }
    }

    return false;
}

int main() {
    int n = 9;
    int board[9][9] = {
        {0, 0, 7, 1, 0, 0, 0, 6, 0},
        {1, 0, 5, 2, 0, 8, 0, 0, 0},
        {6, 0, 0, 0, 0, 7, 1, 2, 0},
        {3, 1, 2, 4, 0, 5, 0, 0, 8},
        {0, 0, 6, 0, 9, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 1},
        {0, 0, 1, 0, 0, 4, 9, 8, 6},
        {8, 0, 3, 9, 0, 6, 0, 0, 0},
        {0, 6, 0, 0, 8, 2, 7, 0, 3},
    };

    solver(board, 0, 0, n);
    return 0;
}

