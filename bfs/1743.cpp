#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
int checkmap[101][101];

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int N, M, K;
int MAX = 0;

void BFS(int y, int x)
{
	pair<int, int> tmp;
	queue<pair<int,int>> Q;
	Q.push({y,x});
	int tmpMax = 1;

	while(!Q.empty())
	{
		tmp = Q.front();
		Q.pop();

		int tmpy, tmpx;

		for(int i = 0; i < 4; i++)
		{
			tmpy = tmp.first + dy[i];
			tmpx = tmp.second + dx[i];

			if (tmpy < 0 || tmpy >= N || tmpx < 0 || tmpx >= M)
				continue;
			if (!map[tmpy][tmpx] || checkmap[tmpy][tmpx])
				continue;
			checkmap[tmpy][tmpx] = 1;
			tmpMax++;
			Q.push({tmpy, tmpx});
		}
		if (tmpMax > MAX)
			MAX = tmpMax;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	int y, x;

	for(int i = 0; i < K; i++)
	{
		cin >> y >> x;
		map[y - 1][x - 1] = 1;
	}
/*
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cout << map[i][j]<< " ";
		}
		cout << endl;
	}
*/
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if (map[i][j] == 1 && checkmap[i][j] == 0) {
				checkmap[i][j] = 1;
				BFS(i, j);
			}
		}
	}
	cout << MAX;
}
