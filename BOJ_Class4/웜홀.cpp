#include <iostream>
#include <vector>
using namespace std;


vector <pair <pair <int, int>, int>> v;
int dist[501];

void bellmanford(int n) {
	for (int i = 0; i < n; i++) {
		for (int pos = 0; pos < v.size(); pos++) {
			int from = v[pos].first.first;
			int to = v[pos].first.second;
			int cost = v[pos].second;

			if (dist[from] + cost < dist[to]) {
				dist[to] = dist[from] + cost;
			}
		}
	}
	for (int pos = 0; pos < v.size(); pos++) {
		int from = v[pos].first.first;
		int to = v[pos].first.second;
		int cost = v[pos].second;

		if (dist[from] + cost < dist[to]) {
			cout << "YES" << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
}

int main(void) {
	int T;
	cin >> T;

	for (int a = 0; a < T; a++) {
		v.clear();
		int N, M, W;
		cin >> N >> M >> W;
		for (int i = 0; i < N; i++) {
			dist[i] = 987654321;
		}
		int S, E, T;
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			v.push_back({ {S, E}, T });
			v.push_back({ {E, S}, T });
		}

		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			v.push_back({ { S, E }, -T });
		}
		bellmanford(N);
	}
}