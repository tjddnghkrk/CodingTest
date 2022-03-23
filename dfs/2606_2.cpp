//
// Created by 김성우 on 2022/03/24.
//

#include <iostream>
#include <vector>

using namespace std;

int Vertex, Edge;
int check[101];

void DFS(vector<int> Graph[] , int Vertex)
{
	check[Vertex] = 1;

	for(int i = 0; i < Graph[Vertex].size(); i++)
	{
		if(check[Graph[Vertex][i]])
			continue;
		DFS(Graph, Graph[Vertex][i]);
	}
}

int main()
{
	int count = 0;
	int First, Second;

	cin >> Vertex;
	vector<int> Graph[Vertex + 1];

	cin >> Edge;
	for(int i = 0; i < Edge; i++)
	{
		cin >> First >> Second;
		Graph[First].push_back(Second);
		Graph[Second].push_back(First); //양방향이니 둘 다 추가해주기
	}

	DFS(Graph, 1);

	for(int i = 2; i < 101; i++)
	{
		if(check[i]) {
			count++;
		}
	}

	cout << count;
}