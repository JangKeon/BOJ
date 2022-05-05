#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map <string, string> map;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	string site, password;
	for (int i = 0; i < N; i++) {
		cin >> site >> password;
		map.insert(pair <string, string > (site, password));
	}

	for (int i = 0; i < M; i++) {
		cin >> site;
		cout << map.at(site) << '\n';
	}
}