#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> MAP;

void DFS(int y, int x, int size, vector<int> &answer)
{
    //cout << y << " " << x << " " << size << endl;
    int first;
    bool check = true;
    
    first = MAP[y][x];
    for(int i = y; i < y + size; i++)
    {
        for(int j = x; j < x + size; j++)
        {
            if (MAP[i][j] != first)
            {
                check = false;
                break;
            }
        }
        if (!check)
            break;
    }
    
    if (check){
        answer[first]++;
        return;
    }
    
    DFS(y, x, (size/2), answer);
    DFS(y, x + (size/2), (size/2), answer);
    DFS(y + (size/2), x, (size/2), answer);
    DFS(y + (size/2), x + (size/2), (size/2), answer);
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    MAP = arr;
    DFS(0, 0, arr.size(), answer);
    return answer;
}
