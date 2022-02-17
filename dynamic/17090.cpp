#include <iostream>
#include <vector>
#include <map>

using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

char Map[500][500];
int CheckMap[500][500]; // 메모이제이션에 사용될 맵

int N, M;
int result = 0;

void Go(int y, int x)
{

	int tmpy;
	int tmpx;
	map<pair<int,int>, int> tmpMap; //중복 확인을 위해 map 컨테이너를 사용했다.
	// 앞에는 (y좌표, x좌표를 담고,
	// 뒤에는 1을 담아서, 순회하다가 또 다시 같은 곳으로 오는지를 체크했다.
	// 출발점에서 시작하여 또 다시 같은 곳으로 온다면 무한 루프에 해당하기 떄문이다.

	tmpMap[make_pair(y, x)] = 1; //시작 좌표를 해시맵에 넣는다.

	while (1)
	{

		if(Map[y][x] == 'U') // 쓰여진 글자에 따라서 1 이동한 새로운 좌표를 생성한다.
		{
			tmpy = y + dy[0];
			tmpx = x + dx[0];
		}
		else if(Map[y][x] == 'R')
		{
			tmpy = y + dy[1];
			tmpx = x + dx[1];
		}
		else if(Map[y][x] == 'D')
		{
			tmpy = y + dy[2];
			tmpx = x + dx[2];
		}
		else
		{
			tmpy = y + dy[3];
			tmpx = x + dx[3];
		}

		if (tmpy < 0 || tmpy >= N || tmpx < 0 || tmpx >= M) //맵의 범위를 벗어나면
		{
			for(auto i : tmpMap)
				CheckMap[i.first.first][i.first.second] = 1; //여태 지나온 길들 모두 메모이제이션 (1로)
			break;
		}
		if (CheckMap[tmpy][tmpx] == 1) // 예전에 Go로 갔던 곳에 도달했는데 (메모이제이션 해놓은) 성공이었다면
		{
			for(auto i : tmpMap)
				CheckMap[i.first.first][i.first.second] = 1;
			break;
		}
		if (CheckMap[tmpy][tmpx] == -1) // 예전에 Go로 갔던 곳에 도달했는데 (메모이제이션 해놓은) 실패였다면
		{
			for(auto i : tmpMap)
				CheckMap[i.first.first][i.first.second] = -1; //여태 지나온 길들 모두 메모이제이션 (-1로)
			break;
		}
		if (tmpMap.count(make_pair(tmpy, tmpx))) // 이번 Go에서 시작점에서 출발했으나 지나온 길을 또 방문한 중복이라면
		{
			for(auto i : tmpMap)
				CheckMap[i.first.first][i.first.second] = -1;
			break;
		}

		tmpMap[make_pair(tmpy, tmpx)] = 1; //해시맵에 새로운 y, x 추가
		y = tmpy;
		x = tmpx;
	}
}

int main()
{
	cin >> N >> M;

	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin >> Map[i][j];

	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
		{
			if (!CheckMap[i][j]) {
				Go(i, j);
			}
		}

	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
		{
			if (CheckMap[i][j] == 1) // 1이면 길따라 가면 탈출 되는 좌표, -1이면 길 따라 가도 탈출 안되는 좌표
				result += 1;
		}

	cout << result;
}