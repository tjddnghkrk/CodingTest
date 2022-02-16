#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


struct Student
{
	int id;
	int value;
	int count;
	int time;
};

struct cmp{
	
	bool operator()(const Student &A, const Student &B)
	{
		if (A.value == B.value)
		{
			if (A.count == B.count)
			{
				return A.time > B.time;
			}
			return A.count > B.count;
		}
		return A.value < B.value;
	}

};

int main()
{
	int N;
	int value;
	int count;
	int time;
	int id = 1;
	Student student;

	priority_queue<Student, vector<Student>, cmp> pq;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		student.id = id;
		cin >> student.value;
		cin >> student.count;
		cin >> student.time;

		pq.push(student);
		id ++;
	}

	student = pq.top();
	cout << student.id;

}
