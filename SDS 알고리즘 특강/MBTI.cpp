#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 16

int T, num, N;
int costs[MAX];
int r, sum = 0, result = 9999999;
int MBTI[8] = {0, };
bool check = true, visited[16];

void Calculation() {
	check = true;
	for (int i = 0; i < 8; i++) {
		if (MBTI[i] < N) {
			check = false;
			break;
		}
	}
	if (check) {
		if (result > sum) {
			cout << "Result : " << result << '\n';
			result = sum;
		}
	}
}

void DFS(int Idx, int Cnt)
{
	switch (Idx) {
	case 0: MBTI[0] ++; MBTI[3]++; MBTI[5]++; MBTI[6]++;
	case 1: MBTI[0] ++; MBTI[5]++; MBTI[6]++; MBTI[7]++;
	case 2: MBTI[0] ++; MBTI[2]++; MBTI[3]++; MBTI[5]++;
	case 3: MBTI[0] ++; MBTI[2]++; MBTI[5]++; MBTI[7]++;
	case 4: MBTI[0] ++; MBTI[1]++; MBTI[3]++; MBTI[6]++;
	case 5: MBTI[0] ++; MBTI[1]++; MBTI[6]++; MBTI[7]++;
	case 6: MBTI[0] ++; MBTI[1]++; MBTI[2]++; MBTI[3]++;
	case 7: MBTI[0] ++; MBTI[1]++; MBTI[2]++; MBTI[7]++;
	case 8: MBTI[3] ++; MBTI[4]++; MBTI[5]++; MBTI[6]++;
	case 9: MBTI[4] ++; MBTI[5]++; MBTI[6]++; MBTI[7]++;
	case 10: MBTI[2] ++; MBTI[3]++; MBTI[4]++; MBTI[5]++;
	case 11: MBTI[2] ++; MBTI[4]++; MBTI[5]++; MBTI[7]++;
	case 12: MBTI[1] ++; MBTI[3]++; MBTI[4]++; MBTI[6]++;
	case 13: MBTI[2] ++; MBTI[4]++; MBTI[6]++; MBTI[7]++;
	case 14: MBTI[1] ++; MBTI[2]++; MBTI[3]++; MBTI[4]++;
	case 15: MBTI[1] ++; MBTI[2]++; MBTI[4]++; MBTI[7]++;
	}
	sum += costs[Idx];

	if (Cnt == r){
		Calculation();
		return;
	}

	for (int i = Idx; i < MAX; i++){
		if (visited[i] == true) continue;
		visited[i] = true;
		DFS(i, Cnt + 1);
		sum -= costs[Idx];
		switch (Idx) {
		case 0: MBTI[0]--; MBTI[3]--; MBTI[5]--; MBTI[6]--;
		case 1: MBTI[0] --; MBTI[5]--; MBTI[6]--; MBTI[7]--;
		case 2: MBTI[0] --; MBTI[2]--; MBTI[3]--; MBTI[5]--;
		case 3: MBTI[0] --; MBTI[2]--; MBTI[5]--; MBTI[7]--;
		case 4: MBTI[0] --; MBTI[1]--; MBTI[3]--; MBTI[6]--;
		case 5: MBTI[0] --; MBTI[1]--; MBTI[6]--; MBTI[7]--;
		case 6: MBTI[0] --; MBTI[1]--; MBTI[2]--; MBTI[3]--;
		case 7: MBTI[0] --; MBTI[1]--; MBTI[2]--; MBTI[7]--;
		case 8: MBTI[3] --; MBTI[4]--; MBTI[5]--; MBTI[6]--;
		case 9: MBTI[4] --; MBTI[5]--; MBTI[6]--; MBTI[7]--;
		case 10: MBTI[2] --; MBTI[3]--; MBTI[4]--; MBTI[5]--;
		case 11: MBTI[2] --; MBTI[4]--; MBTI[5]--; MBTI[7]--;
		case 12: MBTI[1] --; MBTI[3]--; MBTI[4]--; MBTI[6]--;
		case 13: MBTI[2] --; MBTI[4]--; MBTI[6]--; MBTI[7]--;
		case 14: MBTI[1] --; MBTI[2]--; MBTI[3]--; MBTI[4]--;
		case 15: MBTI[1] --; MBTI[2]--; MBTI[4]--; MBTI[7]--;
		}
		visited[i] = false;
	}
}

int main(void) {
	cin >> T;
	for (int u = 0; u < T; u++) {
		cin >> N;
		memset(visited, 0, sizeof(visited));
		memset(MBTI, 0, sizeof(MBTI));
		result = 99999999;
		for (int i = 0; i < 16; i++) {
			cin >> num;
			costs[i] = num;
		}

		for (int i = 2; i < 9; i++) {
			r = i;
			memset(visited, 0, sizeof(visited));
			DFS(0, 0);
		}

		cout << "#" << u + 1 << ' ' << result << '\n';
	}
}