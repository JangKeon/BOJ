#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector <int> Near[32001];
int InDegree[32001];
int res[32001], idx = 0;

int main(void) {
	int N, M, a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		Near[a].push_back(b);
		InDegree[b]++;
	}
	deque <int> q;	// In-Degree가 0이 되는 정점 저장

	for (int i = 1; i <= N; i++) {
		if (InDegree[i] == 0) {
			q.push_back(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop_front();	// q에 저장되어 있는 정점을 하나 끝내고 인접 정점 비교
		res[idx++] = cur;
		for (int next: Near[cur]) {
			if (!--InDegree[next]) {	// cur이 가리키는 방향의 정점을 탐색. for each 구문 사용
				q.push_back(next);
			}
		}
	}

	for (int i = 0; i < idx; i++) {
		cout << res[i] << ' ';
	}
}