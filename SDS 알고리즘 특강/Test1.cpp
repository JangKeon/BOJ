#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[301][301];
int oil[20001];
int N, M, D;
int cut_day[20001];

void grass_grow(int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			map[i][j]++;
		}
	}
}

struct Grass {
	int data;
	int x;
	int y;
	Grass() {};
	Grass(int data, int x, int mQuantity) : data(data), x(x), y(y) {};
	bool operator<(const Grass g) const {
		return data < g.data;
	}
};

int main(void) {
	int T;
	cin >> T;
	for (int u = 0; u < T; u++) {
		cin >> N >> M >> D;
		priority_queue <Grass> que;
		long long result = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
				que.push({ map[i][j], i , j });
			}
		}
		
		for (int i = 0; i < D; i++) {
			cin >> oil[i];
		}

		for (int a = 0; a < D; a++) {
			int cut_num = oil[a];
			int grass_cut = 0;
			for (int i = 0; i < cut_num; i++) {
				grass_cut += (que.top().data - 1 + a);
				que.push({ 1, que.top().x, que.top().y });
				que.pop();
			}
			result += (a + 1) * grass_cut;
		}
		cout << "Result : " << result << '\n';
	}
}