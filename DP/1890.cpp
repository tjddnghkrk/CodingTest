#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

#define MAX 101

int N;
int cnt = 0;
int arr[MAX][MAX];
long long DP[MAX][MAX] = { 0, };

void func() {
	DP[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == N - 1 && j == N - 1) { cout << DP[N - 1][N - 1]; return; }
			if (DP[i][j] == 0) continue;
			if (i + arr[i][j] < N)
				DP[i + arr[i][j]][j] = DP[i][j] + DP[i + arr[i][j]][j];
			if (j + arr[i][j] < N)
				DP[i][j + arr[i][j]] = DP[i][j] + DP[i][j + arr[i][j]];
		}
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	
	func();
	return 0;
}
