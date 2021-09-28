#include <iostream>

using namespace std;

int TR[501][501];
int Value;
int N;
int dy[] = {1, 1};
int dx[] = {0, 1};

void DFS(int y, int x, int value)
{
	int tmpy;
	int tmpx;

	value += TR[y][x];

	if (value > Value)
		Value = value;
	if (y == N - 1)
		return;
	for (int i = 0; i < 2; i++)
	{
		tmpy = y + dy[i];
		tmpx = x + dx[i];
		if (tmpy >= N)
			continue;
		DFS(tmpy, tmpx, value);
	}
}

int main()
{
	int n;
	int layer;

	cin >> n;
	N = n;
	layer = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < layer; j++)
		{
			cin >> TR[i][j];
		}
		layer++;
	}

	DFS(0, 0, 0);
	cout << Value;	
}
