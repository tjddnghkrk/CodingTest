#include <iostream>
#include <vector>

/*
 *
 * 8
 * 7 1
 * 6 2 // 맨 뒤가 1이 아니라면.. 맨 뒤만 바꿔주기  (n-1) 과 1 두 개를 추가.
 *
 * 6 1 1 // 맨 뒤가 1이라면.. 1 이 아닌 6까지 찾아가서, (6 - 1)로 바꾼 후 , (6 - 1)보다 작은 값들로 뒤를 채우기
 *
 * 5 3
 * 5 2 1
 * 5 1 1 1
 *
 *
 *
 *
 * */

using namespace std;

int solution(int K)
{
	vector <int> Stack;
	Stack.push_back(K);

	int tmp; // pop 한 값 받기
	int countOne;
	int MAX = 0;
	int point; // 1 이 아닌 숫자 찾기
	int Value;

	while (1)
	{

		Value = 1;
		for(auto & i : Stack) // 한 줄의 곱들이 MAX를 갱신할 수 있는지 확인
			Value *= i;
		if (Value > MAX)
			MAX = Value;

		tmp = Stack.back();
		Stack.pop_back();

		if (tmp != 1) // 맨 뒤가 1이라면
		{
			Stack.push_back(tmp - 1);
			Stack.push_back(1);
		}

		else // 맨 뒤가 1이 아니라면
		{
			countOne = 1;
			while (!Stack.empty() && Stack.back() == 1) // 1인 수들을 세어줌
			{
				countOne ++;
				Stack.pop_back();
			}

			if (Stack.empty())
				break;

			point = Stack.back(); // 1 이 아닌 수를 찾음
			Stack.pop_back();

			countOne += point;

			Stack.push_back(point - 1); // 1 이 아닌 수에 -1 하고 넣어줌
			countOne -= (point - 1);

			while (countOne > point - 1)  // (n - 1) 이하인 숫자로 뒤를 넣어주기
			{
				Stack.push_back(point - 1);
				countOne -= (point - 1);
			}
			Stack.push_back(countOne);
		}
	}
	return MAX;
}

int main() {

	int K = 8;
	printf("%d", solution(K));

}
