#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int direction, N, K, L, result = 0;

int dx[4] = { 1, 0, 0 , -1};
int dy[4] = { 0, -1, 1, 0 };

int map[101][101];
queue <pair<int, int>> snake;
vector <pair<int, char>> rotation;

void setdirection_left(int dir) {
	switch(dir) {
	case 0: direction = 1;
	case 1: direction = 3;
	case 2: direction = 0;
	case 3: direction = 2;
	}
}

void setdirection_right(int dir) {
	switch (dir) {
	case 0: direction = 2;
	case 1: direction = 0;
	case 2: direction = 3;
	case 3: direction = 1;
	}
}

int main(void) {
	snake.push(make_pair(1, 1)); 
	cin >> N >> K;
	int apple_x, apple_y;
	for (int i = 0; i < K; i++) {
		cin >> apple_x >> apple_y;
		map[apple_x][apple_y] = 1;
	}
	cin >> L;
	int X; char C;
	for (int i = 0; i < L; i++) {
		cin >> X >> C;
		rotation.push_back(make_pair(X, C));
	}
	direction = 0;
	while (1) {
		for (int i = 0; i < L; i++) {
			int ax, ay, time_num = result;
			for (int j = time_num + 1; j <= rotation[i].first; j++) {
				result++;
				if (i == 0) {
					ax = snake.front().first + dx[direction];
					ay = snake.front().second + dy[direction];
				}
				else {
					if (rotation[i].second == 'L') {
						setdirection_left(direction);
						ax = snake.front().first + dx[direction];
						ay = snake.front().second + dy[direction];
					}
					if (rotation[i].second == 'D') {
						setdirection_right(direction);
						cout << "D : " << direction << '\n';
						ax = snake.front().first + dx[direction];
						ay = snake.front().second + dy[direction];
					}
				}

				cout << "X : " << ax << " Y : " << ay << '\n';
				if (ax < 1 || ax > N || ay < 1 || ay > N ) {
					cout << result << '\n';
					cout << "Out of range \n";
					exit(0);
				}

				queue <pair<int, int>> tmp;
				while (!tmp.empty()) {
					int a = tmp.front().first;
					int b = tmp.front().second;
					if (ax == a && ay == b) {
						cout << result << '\n';
						cout << "Snake crash \n";
						exit(0);
					}
					tmp.pop();
				}

				snake.push(make_pair(ax, ay));
				if (!map[ax][ay]) {
					snake.pop();
				}

			}
		}
		
	}
}