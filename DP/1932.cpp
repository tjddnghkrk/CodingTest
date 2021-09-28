#include <iostream>
#include <algorithm>

using namespace std;

int TR[501][501];

void DP(int n)
{
	int layer = n - 2;
	for (int i = layer; i >= 0; i--)
	{
		for(int j = 0; j <= i; j++)
		{
			TR[i][j] = max(TR[i][j] + TR[i + 1][j], TR[i][j] + TR[i + 1][j + 1]);

		}
	}
}

int main()
{
	int n;
	int layer;

	cin >> n;
	layer = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < layer; j++)
		{
			cin >> TR[i][j];
		}
		layer++;
	}
	DP(n);
	cout << TR[0][0];
}
