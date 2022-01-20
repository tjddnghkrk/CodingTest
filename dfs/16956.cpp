#include <iostream>

using namespace std;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

char Map[500][500];
char checkMap[500][500];

int RR;
int CC;

void DFS(int y, int x)
{
    bool checkD = false;
    int newy;
    int newx;

    checkMap[y][x] = 1;

    for(int i = 0; i < 4; i++) {

        newy = y + dy[i];
        newx = x + dx[i];

        if (newy < 0 || newy >= RR || newx < 0 || newx >= CC || checkMap[newy][newx] == 1)
            continue;
        if (Map[newy][newx] == 'S')
        {
            if (Map[y][x] == '.') {
                Map[y][x] = 'D';
                checkD = true;
                break;
            }
            else
            {
                cout << 0;
                exit(0);
            }
        }
    }

    if (checkD)
        return;

    for(int i = 0; i < 4; i++) {

        newy = y + dy[i];
        newx = x + dx[i];

        if (newy < 0 || newy >= RR || newx < 0 || newx >= CC || checkMap[newy][newx] == 1 || Map[newy][newx] == 'D')
            continue;
        DFS (newy, newx);
    }


}


int main() {

    int R, C;

    cin >> R >> C;

    RR = R;
    CC = C;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> Map[i][j];
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (Map[i][j] == 'W')
                DFS(i, j);
        }
    }

    cout << 1 << endl;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << Map[i][j];
        }
        cout<< endl;
    }

    return 0;
}
