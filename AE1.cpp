#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> estimates, int k){

	int firstSum = 0;
	int start = 0;
	int end;
	int MAX;

	for(end = 0; end < k; end++)
		firstSum += estimates[end];

	MAX = firstSum;

	while (end < estimates.size())
	{
		firstSum = firstSum + estimates[end] - estimates[start];
		if (estimates[end] > estimates[start]) {
			if (firstSum > MAX)
				MAX = firstSum;
		}
		start++;
		end++;
	}
	return MAX;
}

int main() {

	vector<int> estimates = {1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1};
	int k = 4;

	printf("%d", solution(estimates, k));
}
