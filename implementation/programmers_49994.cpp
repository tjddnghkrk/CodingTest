#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int nowy;
int nowx;
int answer;

unordered_map<string, int> MAP;

void Move(char dir)
{
    int tmpy;
    int tmpx;
    
    string Front = ""; 
    string Back = "";
    
    if (dir == 'U')
    {
        tmpy = nowy + dy[0];
        tmpx = nowx + dx[0];
    }
    else if (dir == 'D')
    {
        tmpy = nowy + dy[1];
        tmpx = nowx + dx[1];
    }
    else if (dir == 'R')
    {
        tmpy = nowy + dy[2];
        tmpx = nowx + dx[2];
    }
    else
    {
        tmpy = nowy + dy[3];
        tmpx = nowx + dx[3];     
    }
    
    if (tmpy < -5 || tmpy > 5 || tmpx < -5 || tmpx > 5)
            return;
    
    Front = to_string(tmpy) + to_string(tmpx);
    Back = to_string(nowy) + to_string(nowx);
    
    if(MAP[Front + Back] == 0)
    {
        MAP[Front + Back] = 1;
        MAP[Back + Front] = 1;
        answer++;
    }
    
    nowy = tmpy;
    nowx = tmpx;
}

int solution(string dirs) {
   
    nowx = 0;
    nowy = 0;
    for(int i = 0; i < dirs.length(); i++)
        Move(dirs[i]);
    
    return answer;
}
