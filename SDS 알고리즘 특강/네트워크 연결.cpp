#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int arr[1000001];

struct Edge {
	int start;
	int end;
	int cost;
	bool operator <(const Edge E) const {
		return cost < E.cost;
	}
};

int Find(int x) {
	if (arr[x] == x) {
		return x;
	}
	return Find(arr[x]);
}

void Union(int a, int b) {
	int aRoot = Find(a);
	int bRoot = Find(b);
	arr[bRoot] = aRoot;
}

int main(void) {
	int N, M, a, b, c;
	cin >> N >> M;
	vector <Edge> E;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		E.push_back({ a, b, c });
	}
	sort(E.begin(), E.end());
	for (int i = 1; i <= N; i++) {
		arr[i] = i;
	}
	int result = 0;
	for (int i = 0; i < M; i++) {
		if (Find(E[i].start) != Find(E[i].end)) {
			Union(E[i].start, E[i].end);
			result += E[i].cost;
		}
	}

	cout << result;
}