#include <iostream>
#include <vector>
#include <queue>
using namespace std;
# define INF 987654321
# define SIZE 100001

struct Data {
	int vertex;
	int weight;
	Data() {};
	Data(int vertex, int weight) : vertex(vertex), weight(weight) {};
	bool operator<(const Data d) const {
		return weight > d.weight;
	}
};

vector <Data> Edge[SIZE];
priority_queue <Data> pq;
int dist[SIZE];
bool visit[SIZE];

int V, E;
int u, v, w;

void init() {
	for (int i = 0; i <= V; i++) {
		Edge[i].clear();
		dist[i] = INF;
		visit[i] = false;
	}
}


void Daijkstra(int start) {
	dist[start] = 0;
	pq.push(Data(start, 0));
	while (!pq.empty()) {
		Data u = pq.top();
		pq.pop();

		if (visit[u.vertex]) continue;
		visit[u.vertex] = true;
		for (int i = 0; i < Edge[u.vertex].size(); i++) {
			Data v = Edge[u.vertex].at(i);
			if (dist[v.vertex] > dist[u.vertex] + v.weight) {
				dist[v.vertex] = dist[u.vertex] + v.weight;
				pq.push(Data(v.vertex, dist[v.vertex]));
			}
		}
	}
}

int main(void) {
	int start;
	cin >> V >> E;
	cin >> start;
	init();
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		Edge[u].push_back(Data(v, w));
	}
	Daijkstra(start);
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF\n";
		}
		else cout << dist[i] << '\n';
	}
}