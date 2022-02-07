#include <iostream>
#include <vector>

using namespace std;

int num[3] = {0, };

void Find(vector< vector<int> > v, int ystart, int yend, int xstart, int xend)
{
	int firstNum = v[ystart][xstart];
	bool failCheck = false;
	int i;
	int j;

	for(i = ystart; i < yend; i++)
	{
		for(j = xstart; j < xend; j++)
		{
			if (v[i][j] != firstNum)
			{
				failCheck = 1;
				break;
			}
		}
		if (failCheck)
			break;
	}

	if(!failCheck)
	{
		num[firstNum + 1]++;
		return;
	}

	int gap = (yend - ystart) / 3;

	for (i = ystart; i < yend; i += gap)
		for (j = xstart; j < xend; j += gap)
			Find(v, ystart, i, xstart, j);
}

int main()
{
	int N;

	cin >> N;
	vector< vector<int> > v(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
				cin >> v[i][j];
	Find(v, 0, N, 0, N);
	cout << num[0] << endl;
	cout << num[1] << endl;
	cout << num[2] << endl;

}
