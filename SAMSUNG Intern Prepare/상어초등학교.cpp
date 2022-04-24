#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define Max 25

struct Student {
	int num;
	int close_friend[4];
};

struct Position {
	int x;
	int y;
	int Near_friend;
	int empty;
};

vector <Student> student;
Student arr[Max * Max];
int Map[Max][Max];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool Cmp(Position A, Position B)
{
	if (A.Near_friend >= B.Near_friend)
	{
		if (A.Near_friend == B.Near_friend)
		{
			if (A.empty >= B.empty)
			{
				if (A.empty == B.empty)
				{
					if (A.x <= B.x)
					{
						if (A.x == B.x)
						{
							if (A.y < B.y)
							{
								return true;
							}
							return false;
						}
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

int Calculate_satisfy(int num) {
	if (num == 0) return 0;
	if (num == 1) return 1;
	if (num == 2) return 10;
	if (num == 3) return 100;
	if (num == 4) return 1000;
}

int main(void) {
	int N, satisfy = 0;
	cin >> N;
	int a, b, c, d, e;
	for (int i = 0; i < N * N; i++) {
		cin >> a >> b >> c >> d >> e;
		student.push_back({ a, {b, c, d, e} });
		arr[a].num = a;
		arr[a].close_friend[0] = b;
		arr[a].close_friend[1] = c;
		arr[a].close_friend[2] = d;
		arr[a].close_friend[3] = e;
	}

	for (int i = 0; i < student.size(); i++) {
		int stu_num = student[i].num;
		vector <Position> Pos;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (Map[x][y] != 0) {
					continue;
				}
				int Near = 0, Empty = 0;
				for (int k = 0; k < 4; k++) {
					int ax = x + dx[k];
					int ay = y + dy[k];
					if (ax < 0 || ay < 0 || ax >= N || ay >= N) {
						continue;
					}
					if (Map[ax][ay] == 0) Empty++;
					else {
						for (int j = 0; j < 4; j++) {
							if (student[i].close_friend[j] == Map[ax][ay]) {
								Near++;
							}
						}
					}
				}
				Pos.push_back({ x, y, Near, Empty });
			}
		}
		sort(Pos.begin(), Pos.end(), Cmp);
		Map[Pos[0].x][Pos[0].y] = stu_num;
	}

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			int Friend = 0;
			for (int k = 0; k < 4; k++) {
				int ax = x + dx[k];
				int ay = y + dy[k];
				if (ax < 0 || ay < 0 || ax >= N || ay >= N) {
					continue;
				}
				for (int t = 0; t < 4; t++) {
					if (Map[ax][ay] == arr[Map[x][y]].close_friend[t]) {
						Friend++;
					}
				}
			}
			satisfy += Calculate_satisfy(Friend);
		}
	}
	cout << satisfy;
}
