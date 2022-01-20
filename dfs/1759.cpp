#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R;
int C;

int dy[] = {0, 1};
int dx[] = {1, 0};

char map[20][20];
int alpha[26];
int MAX = 0;

void DFS(int r, int c, int count)
{
    if (alpha[map[r][c] - 'A'] == 1)
    {
        if(count > MAX)
            MAX = count;
        alpha[map[r][c] - 'A'] = 0;
        return;
    }
    alpha[map[r][c] - 'A'] = 1;

    for(int i = 0; i < 2; i++)
    {
        DFS(r + dy[i], c + dx[i]);
    }
}

int main() {

    int r;
    int c;

    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
        }
    }

    DFS(0, 0, 0);
    cout << MAX;

}
