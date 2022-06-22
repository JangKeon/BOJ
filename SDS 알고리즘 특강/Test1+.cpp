#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int map[301][301];
int cutted[301][301];
int oil[20001];
int N, M, D;

struct Grass {
	int data;
	int x;
	int y;
};

bool Compare(Grass a, Grass b) {
	return a.data > b.data;
};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for (int u = 0; u < T; u++) {
		memset(cutted, 0, sizeof(cutted));
		cin >> N >> M >> D;
		vector <Grass> vec;
		long long result = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
				vec.push_back({ map[i][j], i , j });
			}
		}

		sort(vec.begin(), vec.end(), Compare);

		for (int i = 0; i < D; i++) {
			cin >> oil[i];
		}

		int k = 0;
		int total_size = N * M;
		for (int a = 1; a <= D; a++) {
			int cut_num = oil[a - 1];
			int grass_cut = 0;
			for (int i = 0; i < cut_num; i++) {
				int num = k % total_size;
				grass_cut += map[vec[num].x][vec[num].y] + (a - cutted[vec[num].x][vec[num].y] - 1);
				map[vec[num].x][vec[num].y] = 1;
				cutted[vec[num].x][vec[num].y] = a;
				k++;
			}
			result += (long long)(a) * (long long)grass_cut;
		}
		cout << "#" << u+1 << ' ' << result << '\n';
	}
}