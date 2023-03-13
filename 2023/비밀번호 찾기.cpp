#include <iostream>
#include <map>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, M;
	map <string, string> m;
	cin >> N >> M;
	string str, str2;
	for (int i = 0; i < N; i++) {
		cin >> str >> str2;
		m.insert({ str, str2 });
	}
	for (int i = 0; i < M; i++) {
		cin >> str;
		cout << m[str] << '\n';
	}
}