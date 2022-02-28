#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> estimates, int k){

	int firstSum = 0;
	int start = 0;
	int end;

	for(int end = 0; end < k; end++)
		firstSum += estimates[end];

	while (end)
}

int main() {

	vector<int> estimates = {1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1};
	int k;

	printf("%d", solution(estimates, k));

}
