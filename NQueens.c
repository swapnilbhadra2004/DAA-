#include <stdio.h>
#include <stdbool.h>

#define N 8

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;
    
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;
    
    return true;
}

bool solveNQueensUtil(int board[N][N], int col) {
    if (col >= N) {
        printSolution(board);
        return true;
    }
    
    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            res = solveNQueensUtil(board, col + 1) || res;
            board[i][col] = 0;
        }
    }
    return res;
}

void solveNQueens() {
    int board[N][N] = {0};
    if (!solveNQueensUtil(board, 0))
        printf("No solution exists\n");
}

int main() {
    solveNQueens();
    return 0;
}