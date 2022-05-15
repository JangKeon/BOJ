# Bellman Ford

밸만포드 알고리즘을 사용하여 푸는 문제이다. 정리 예정.

다만 이 문제에서는 주의해야 할 점이 두 가지 있었다.

웜홀이 아닌 길에 대해서는 갈 수 있는 경로가 양방향이라는 점과 음수 사이클이 존재하는지 안 하는지에 대한 판단만 하면 된다는 부분이었다.


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