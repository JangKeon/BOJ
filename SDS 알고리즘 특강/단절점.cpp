#include <iostream>
#include <vector>
using namespace std;

int V, E, a, b;
vector <int> graph[10001];

int visited[10001];	
vector <int> result;

int Order = 0;
int dfs(int cur, int parent) {
	visited[cur] = ++Order;

}

int main(void) {
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i <= V; i++) {
		if (visited[i] == 0) {
			dfs(i, 0);
		}
	}
}