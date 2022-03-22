#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
/*
 *
 * [1, 1], [2, 10], [4, 3], [5, 7] 처럼 겹쳐졌을 때 최대가 되는 수를 구해야 한다. 정렬되지 않음.
 *
 */

int solution(vector<vector<int>> V)
{
	int answer = 1;
	sort(V.begin(), V.end());

	for(int i = 0; i < V.size() - 1; i++)
		if (V[i][0] < V[i + 1][0] && V[i][1] < V[i + 1][1]) // [a, b] 일 때, a, b가 각각 중복이 안되는 조건이었는지 헷갈림
			answer++;
	return answer;
}

int main() {

	vector<vector<int>> V = {{1, 1}, {10, 2}, {4, 3}, {5, 7}};
	printf("%d", solution(V));
	return 0;
}
