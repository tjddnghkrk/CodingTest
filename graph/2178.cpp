#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
 
int a[101][101];
bool check[101][101];
 
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
 
int n, m; // n:����, m:����
int ans = 10001; // ����
 
void dfs(int x, int y, int cnt) { // x�� ����, y�� ����
	if (x < 0 || y < 0 || x >= n || y >= m)
	{
		return;
	}
 
	if (x == n-1 && y == m-1)
	{
		ans = min(ans, cnt);
		return;
	}
	
 
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
 
		if (0 <= nx && nx < n && 0 <= ny && ny < m)
		{
			if (a[nx][ny] == 1 && check[nx][ny] == false)
			{
				check[nx][ny] = true;
				dfs(nx, ny, cnt+1);
				check[nx][ny] = false;
			}
		}
 
	}
 
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			scanf("%1d", &a[i][k]);
		}
	}
 
	// �̷�ã��� (0,0)���� �ѹ��� �����ϸ� ��.
	dfs(0, 0, 1); 
	printf("%d\n", ans);
 
	return 0;
 
}
