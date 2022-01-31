#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(void) {
	cin.sync_with_stdio(0); cin.tie(0);
	unordered_map <int, string> pokemon;
	unordered_map <string, int> pokemon2;

	int N, M, index = 1;
	string name;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >>  name;
		pokemon.insert(make_pair(i + 1, name));
		pokemon2.insert(make_pair(name, i + 1));

	}
	string quiz;
	for (int i = 0; i < M; i++) {
		cin >> quiz;
		if (quiz[0] >= 'A' && quiz[0] <= 'Z') {
			cout << pokemon2.find(quiz)->second << '\n';
		}
		else {
			int q = stoi(quiz);
			cout << pokemon.find(q)->second << '\n';
		}
	}

}