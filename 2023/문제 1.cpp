#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct point {
	int x;
	int y;
};

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) {
			return a > b;
		}
		else return a > b;
	}
};

char map[1001][1001];
int main(void) {
	int N, K;
	vector <point> vec;
	vector <pair<int, int>> distance;
	point base;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B') {
				base.x = i;
				base.y = j;
			}
			if (map[i][j] == 'O') {
				vec.push_back({ i, j });
			}
		}
	}
	if (vec.size() < K) {
		cout << -1;
	}
	else {
		for (int i = 0; i < vec.size(); i++) {
			distance.push_back({ abs(base.x - vec[i].x) + abs(base.y - vec[i].y), i });
		}
		sort(distance.begin(), distance.end());
		for (int i = 0; i < K; i++) {
			map[vec[distance[i].second].x][vec[distance[i].second].y] = 'X';
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << map[i][j];
			}
			cout << '\n';
		}
	}
}