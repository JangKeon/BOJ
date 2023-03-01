#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visit[101];
vector <int> graph[1000];
int result = 0;

void dfs(int x) {
	visit[x] = true;
	result++;
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visit[y]) {
			dfs(y);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector <int> vec;
	int N, M, a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	cout << result - 1;
}