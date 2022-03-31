#include <iostream>
#include <vector>
using namespace std;

int parent[100001];
vector <int> tree[100001];

void dfs(int x) {
	for (int i = 0; i < tree[x].size(); i++) {
		if (!parent[tree[x][i]]) {
			parent[tree[x][i]] = x;
			dfs(tree[x][i]);
		}
	}
}

int main(void) {
	int N, x, y;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	dfs(1);
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}
}