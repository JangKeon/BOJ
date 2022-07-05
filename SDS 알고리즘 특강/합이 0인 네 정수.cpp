#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long AB[16000000];
long long CD[16000000]; 

int main(void) {
	long long A[4000];
	long long B[4000];
	long long C[4000];
	long long D[4000];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	int index = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			AB[index] = A[i] + B[j];
			index++;
		}
	}
	index = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			CD[index] = C[i] + D[j];
			index++;
		}
	}

	sort(CD, CD + N*N, greater<long long>()); 
	sort(AB, AB + N*N, less<long long>()); 

	long long start = 0, end = 0, result = 0;
	while (start < N*N && end < N*N) {
		if (AB[start] + CD[end] == 0) {
			result++;
		}
		if (AB[start] + CD[end] > 0) {
			end++;
		}
		else {
			start++;
		}
	}
	cout << result;
}