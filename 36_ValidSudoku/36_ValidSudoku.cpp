#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> check;
        for (int i = 0; i <= 9; i++)
            check.push_back(false);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    int temp = board[i][j] - '0';
                    if (check[temp])
                        return false;
                    check[temp] = true;
                }
            }
            for (int i = 1; i <= 9; i++)
                check[i] = false;
        }

        for (int i = 1; i <= 9; i++)
            check[i] = false;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[j][i] != '.') {
                    int temp = board[j][i] - '0';
                    if (check[temp])
                        return false;
                    check[temp] = true;
                }
            }
            for (int i = 1; i <= 9; i++)
                check[i] = false;
        }

        int col = 0;
        while (col < 9) {
            int col_temp = col;
            int row = 0;
            while (row < 9) {
                col = col_temp;
                while (col < col_temp + 3) {
                    for (int i = row; i < row + 3; i++) {
                        if (board[col][i] != '.') {
                            int temp = board[col][i] - '0';
                            if (check[temp]) 
                                return false;
                            check[temp] = true;
                        }
                    }
                    col++;
                }
                for (int i = 1; i <= 9; i++)
                    check[i] = false;
                row += 3;
            }
            for (int i = 1; i <= 9; i++)
                check[i] = false;
        }

        return true;

    }
};