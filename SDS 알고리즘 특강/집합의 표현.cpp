#include <iostream>
#include <vector>
using namespace std;

int arr[1000001];


int Find(int x) {
	if (arr[x] == x) {
		return x;
	}
	return arr[x] = Find(arr[x]);
}

void Union(int a, int b) {
	int aRoot = Find(a);
	int bRoot = Find(b);
	arr[bRoot] = aRoot;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, M;
	for (int i = 0; i < 1000001; i++) {
		arr[i] = i;
	}
	cin >> N >> M;
	int op, a, b;
	for (int i = 0; i < M; i++) {
		cin >> op >> a >> b;
		if (op == 0) {
			Union(a, b);
		}
		else if (op == 1) {
			if (Find(a) == Find(b)) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}
	}

}