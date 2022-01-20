#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dy[] = {0, 1, -1, 0};
int dx[] = {1, 0, 0, -1};

char map[20][20];
int alpha[26];
int MAX = 0;

int R;
int C;

void DFS(int r, int c, int count)
{
    /*cout << " r " << r << " c " << c << endl;
    cout << map[r][c] << endl;
    for( auto i : alpha)
        cout << i << " ";
    cout << endl;*/
    int tmpr;
    int tmpc;

    alpha[map[r][c] - 'A'] = 1;

    for(int i = 0; i < 4; i++) {
        tmpr = r + dy[i];
        tmpc = c + dx[i];
        if (tmpr < 0 || tmpr >= R || tmpc < 0 || tmpc >= C)
            continue;
        if (alpha[map[tmpr][tmpc] - 'A'] == 1)
        {
            if (count > MAX)
                MAX = count;
            continue;
        }
        DFS(tmpr, tmpc, count + 1);
        alpha[map[tmpr][tmpc] - 'A'] = 0;
    }
}
int main()
{

    int r;
    int c;
    cin >> r >> c;
    R = r;
    C = c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
        }
    }
    DFS(0, 0, 1);
    cout << MAX;
}

