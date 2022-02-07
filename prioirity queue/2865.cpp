#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int M;
int K;
float people[101] = {0, };

bool cmp(float a, float b)
{
	return a > b;
}

int main()
{
	int man;
	float value;
	float result = 0;
	vector<float> tmp;

	cin >> N >> M >> K;
	for (int i = 0; i < M * N; i++)
	{
		cin >> man;
		cin >> value;
		if (people[man])
		{
			if (value > people[man])
				people[man] = value;
		}
		else
			people[man] += value;
	}
	for (int j = 1; j <= N; j++)
		tmp.push_back(people[j]);
	sort(tmp.begin(), tmp.end(), cmp);
	for (int i = 0; i < K; i++)
		result += tmp[i];
	result *= 10;
	round(result);
	result /= 10;

	cout << fixed;
   	cout.precision(1);
	cout << result;

}
