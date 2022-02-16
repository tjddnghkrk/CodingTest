#include <iostream>
#include <queue>

using namespace std;

char map[50][50];
int Fcheckmap[50][50]; // ���� �湮 üũ
int Mcheckmap[50][50]; // ����ġ�� �湮 üũ

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

int R, C;
int yy, xx; // D(������)�� y��ǥ, x��ǥ�� ���� ��
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

		Movesize = Move.size(); // �̸� queue�� ���̸� ���� ���� 1��ŭ�� Ȯ���ϵ���
		Floodsize = Flood.size(); //�̸� queue�� ���̸� ���� ���� 1��ŭ�� ���� ������

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
					continue; // ���� �Ѿ�ų�, ���� �����ų�, �̹� �湮�߰ų�, ��������� �������� �ʴ´�.
//				cout << tmpy << " " << tmpx << endl;
				map[tmpy][tmpx] = '*'; // ���� ������ �̸� ǥ�� (���⿡�� ���� �ʰ�)
				Flood.push(make_pair(tmpy, tmpx)); // queue�� �־��ش�.
				Fcheckmap[tmpy][tmpx] = 1; // �湮 ǥ���Ѵ�.
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
					continue; // ���� �Ѿ�ų�, ���� �����ų�, ���� �ְų�, �̹� �湮�ߴٸ� �������� �ʴ´�.

				//cout << tmpy << " " << tmpx << endl;

				if (map[tmpy][tmpx] == 'D')
					map[tmpy][tmpx] = 'W'; // �������� �����ߴٸ� 'W'�� �ٲ��־� Ż�� ������ ������ش�.
				Move.push(make_pair(tmpy, tmpx));
				Mcheckmap[tmpy][tmpx] = 1;
			}
		}
		Count++; // �� �� ���� �������� �����ߴ��� ����.
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
				Move.push(make_pair(i, j)); // ����ġ ��ǥ queue�� �ֱ�
				Mcheckmap[i][j] = 1;
			}
			if (tmp == '*') {
				Flood.push(make_pair(i, j)); // ���� ���� queue�� �ֱ�
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
