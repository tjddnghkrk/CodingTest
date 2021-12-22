#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int arr[101][101] = {0, };
int check[101];
int number;

void DFS(int a)
{
    check[a] = 1;
    
    for (int i = 0; i < 101; i++)
    {
        if (arr[a][i] == 1) //가로로 확인
        {
            if (!check[i])
            {
                number++;
                DFS(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int MIN = 10001;
    
    for (auto & i : wires)
    {
        arr[i[0]][i[1]] = 1;
        arr[i[1]][i[0]] = 1;
    }
    
    for (auto & i : wires)
    {
        number = 1; //0으로 해서 헤맸다.
        for(int j = 0; j < 101; j++) //초기화
            check[j] = 0;
        
        //DFS START
        check[i[0]] = 1;
        DFS(i[1]);
        if (abs((n - number) - number) < MIN)
            MIN = abs((n - number) - number);
    }
    
    return (MIN);
}
