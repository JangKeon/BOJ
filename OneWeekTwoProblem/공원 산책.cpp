#include <string>
#include <vector>
#include <iostream>
using namespace std;

char map[51][51];
int x_size = 0;
int y_size = 0;

struct point {
	int x;
	int y;
};

point start = { 0, 0 };
point temp = { 0, 0 };

point check(char op, int n) {
	temp = start;
	for (int i = 0; i < n; i++) {
		if (op == 'N')	start.y -= 1;
		else if (op == 'S')	start.y += 1;
		else if (op == 'W')	start.x -= 1;
		else if (op == 'E') start.x += 1;

		if (start.x < 0 || start.x > x_size - 1 || start.y < 0 || start.y > y_size - 1 || map[start.x][start.y] == 'X') {
			return temp;
		}
		return start;
	}
}

vector<int> solution(vector<string> park, vector<string> routes) {
	vector<int> answer;
	x_size = park.size();
	y_size = park[0].size();
	for (int i = 0; i < park.size(); i++) {
		for (int j = 0; j < park[0].size(); j++) {
			if (park[i][j] == 'S') {
				start.x = i; start.y = j;
			}
			map[i][j] = park[i][j];
		}
	}
	for (int i = 0; i < routes.size(); i++) {
		cout << "X : " << start.x << " Y : " << start.y << '\n';
		check(routes[i][0], int(routes[i][2]));
	}
	answer.push_back(start.x);
	answer.push_back(start.y);
	return answer;
}
