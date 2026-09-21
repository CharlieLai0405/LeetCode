#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int HexStr2Int(string input)
{
    if (input.size() > 8)
        return 0;

    unsigned int ans = 0;
    unsigned int count = 1;
    for (int i = input.size() - 1; i >= 0; i++)
    {
        unsigned int temp;
        if (input[i] >= '0' && input[i] <= '9')
            temp = input[i] - '0';
        else if (input[i] >= 'A' && input[i] <= 'F')
            temp = input[i] - 'A' + 10;
        else if (input[i] >= 'a' && input[i] <= 'f')
            temp = input[i] - 'a' + 10;
        else
            return 0;

        ans = ans + temp * count;
        if (i > 0)
            count *= 16;
    }

    return ans;
};

int countBitPosDiffVal(int x, int y)
{
    int temp = x ^ y;
    int ans = 0;

    while (temp)
    {
        ans += temp & 1;
        temp >>= 1;
    }
    return ans;
};

bool win(vector<vector<char>> &board, char input)
{
    bool ans = false;
    for (int i = 0; i < board.size(); i++)
    {
        if (board[0][i] == input && board[1][i] == input && board[2][i] == input)
            ans = true;
        else if (board[i][0] == input && board[i][1] == input && board[i][2] == input)
            ans = true;
    }
    if (board[0][0] == input && board[1][1] == input && board[2][2] == input)
        ans = true;
    if (board[0][2] == input && board[1][1] == input && board[2][0] == input)
        ans = true;
    return ans;
};

string TicTacToe(vector<vector<char>> &board)
{
    int x = 0, o = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 'X')
                x++;
            else if (board[i][j] == 'O')
                o++;
        }
    }

    if (!(x == o || x == o + 1 || o == x + 1))
        return "INVALID";

    bool xWin = win(board, 'X');
    bool oWin = win(board, 'O');

    if (oWin && xWin)
        return "INVALID";
    else if (xWin)
        return "X";
    else if (oWin)
        return "O";
    else
        return "NOBODY";
};