//
// Created by 김성우 on 2022/03/24.
//

#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[51][51];

int MAX = 0;

int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

void findSafeDistance(int y, int x)
{
	//cout << "start !! " << y << " " << x << endl;
	queue<pair<int, int>> Q;
	Q.push({y, x});
	pair<int, int> tmp;
	bool findShark = false;
	int visit[51][51] = {0, };
	visit[y][x] = 1;
	int Distance[51][51] = {0, };

	while(!Q.empty())
	{

		int tmpy;
		int tmpx;

		tmp = Q.front();
		Q.pop();
		//cout <<"this QUEUE " << tmp.first << " " << tmp.second << endl;

		for(int i = 0; i < 8; i++) {

			tmpy = tmp.first + dy[i];
			tmpx = tmp.second + dx[i];

			if (tmpy < 0 || tmpy >= N || tmpx < 0 || tmpx >= M)
				continue;
			if (visit[tmpy][tmpx] == 1)
				continue;
			if (map[tmpy][tmpx] == 1)
			{
				findShark = 1;
				if (MAX < Distance[tmp.first][tmp.second] + 1)
					MAX = Distance[tmp.first][tmp.second] + 1;
				//cout << tmpy << " " << tmpx << " tmpMAX is " << Distance[tmp.first][tmp.second] + 1 << endl;
				break;
			}
			//cout << tmpy << " " << tmpx << " go now " << tmpMax << endl;
			visit[tmpy][tmpx] = 1;
			if(!Distance[tmpy][tmpx])
				Distance[tmpy][tmpx] = Distance[tmp.first][tmp.second] + 1;
			Q.push({tmpy, tmpx});
		}

		if(findShark)
			break;

	}

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			//cout << Distance[i][j] << " ";
		}
		//cout << endl;
	}
}


int main() {

	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(!map[i][j])
				findSafeDistance(i, j);
		}
	}
	cout << MAX;

	return 0;
}

