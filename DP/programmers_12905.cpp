#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int MAX = 0;
    int ySide = board.size();
    int xSide = board[0].size();
    
    for(int i = 0; i < ySide; i++)
        if (board[i][0] == 1)
        {
            MAX = 1;
            break;
        }
    if(!MAX)
    {
        for(int i = 0; i < xSide; i++)
            if (board[0][i] == 1)
            {
                MAX = 1;
                break;
            }
    }
    
    for(int i = 1; i < ySide; i++)
        for(int j = 1; j < xSide; j++)
            if (board[i][j] == 1)
            {
                board[i][j] = min({board[i-1][j], board[i][j-1], board[i-1][j-1]}) + 1;
                if (MAX < board[i][j])
                    MAX = board[i][j];
            }

    return ((MAX) * (MAX));
}
