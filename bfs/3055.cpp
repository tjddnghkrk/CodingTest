#include <iostream>
#include <queue>

using namespace std;

char map[50][50];
int Fcheckmap[50][50]; // 물의 방문 체크
int Mcheckmap[50][50]; // 고슴도치의 방문 체크

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

int R, C;
int yy, xx; // D(목적지)의 y좌표, x좌표를 담을 곳
int Count = 0;


void Solve(queue <pair<int, int>> & Move , queue <pair<int, int>> & Flood){

	int Movesize;
	int Floodsize;
	int tmpy;
	int tmpx;
	pair<int, int> tmp;

	//cout << "flood" << endl;
	while (map[yy][xx] != 'W' && !Move.empty()) {

		//cout << "count is " << Count << endl;

		Movesize = Move.size(); // 미리 queue의 길이를 세어 길이 1만큼만 확장하도록
		Floodsize = Flood.size(); //미리 queue의 길이를 세어 길이 1만큼만 물에 젖도록

		while (!Flood.empty() && Floodsize)
		{
			Floodsize--;
			tmp = Flood.front();
			Flood.pop();
			for(int i = 0; i < 4; i++)
			{
				tmpy = tmp.first + dy[i];
				tmpx = tmp.second + dx[i];

				if (tmpy < 0 || tmpy >= R || tmpx < 0 || tmpx >= C || map[tmpy][tmpx] == 'X' || Fcheckmap[tmpy][tmpx] || map[tmpy][tmpx] == 'D')
					continue; // 맵을 넘어가거나, 돌을 만나거나, 이미 방문했거나, 목적지라면 진행하지 않는다.
//				cout << tmpy << " " << tmpx << endl;
				map[tmpy][tmpx] = '*'; // 물에 젖음을 미리 표시 (여기에는 가지 않게)
				Flood.push(make_pair(tmpy, tmpx)); // queue에 넣어준다.
				Fcheckmap[tmpy][tmpx] = 1; // 방문 표시한다.
			}
		}

		//cout << "move" << endl;
		while (!Move.empty() && Movesize)
		{
			Movesize--;
			tmp = Move.front();
			Move.pop();
			for(int i = 0; i < 4; i++)
			{
				tmpy = tmp.first + dy[i];
				tmpx = tmp.second + dx[i];

				if (tmpy < 0 || tmpy >= R || tmpx < 0 || tmpx >= C || map[tmpy][tmpx] == 'X' || map[tmpy][tmpx] == '*' || Mcheckmap[tmpy][tmpx])
					continue; // 맵을 넘어가거나, 돌을 만나거나, 물이 있거나, 이미 방문했다면 진행하지 않는다.

				//cout << tmpy << " " << tmpx << endl;

				if (map[tmpy][tmpx] == 'D')
					map[tmpy][tmpx] = 'W'; // 목적지에 도착했다면 'W'로 바꿔주어 탈출 조건을 만들어준다.
				Move.push(make_pair(tmpy, tmpx));
				Mcheckmap[tmpy][tmpx] = 1;
			}
		}
		Count++; // 몇 번 만에 목적지에 도착했는지 센다.
	}

	if (map[yy][xx] == 'W')
		cout << Count;
	else
		cout << "KAKTUS";

}
int main() {

	cin >> R >> C;

	queue <pair<int, int>> Move;
	queue <pair<int, int>> Flood;

	char tmp;


	for(int i = 0; i <R; i++)
	{
		for(int j = 0; j < C; j++)
		{

			cin >> tmp;
			if (tmp == 'S') {
				Move.push(make_pair(i, j)); // 고슴도치 좌표 queue에 넣기
				Mcheckmap[i][j] = 1;
			}
			if (tmp == '*') {
				Flood.push(make_pair(i, j)); // 젖은 지역 queue에 넣기
				Fcheckmap[i][j] = 1;
			}
			if (tmp == 'D')
			{
				yy = i;
				xx = j;
			}
			map[i][j] = tmp;
		}
	}

	Solve(Move, Flood);
}
