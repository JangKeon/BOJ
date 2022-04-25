#include <iostream>
#include <vector>
using namespace std;

int score[21][21];
bool Team[20];

int main(void) {
	int N, total = 0; 
	vector <int> star;
	vector <int> link;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> score[i][j];
			total += score[i][j];
		}
	}


}