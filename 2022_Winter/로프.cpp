#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N, num;
	vector <int> vec;
	int answer;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	answer = vec[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		int sum = vec[i] * (N - i); 
		if (answer < sum) answer = sum;
	}
	cout << answer << '\n';
 // ���ĵǾ� �����ϱ� �� ��° ���� i ���� ������ ���� �ִ��� ���� �Ÿ� �����س��´�.
 // ���ĺ��ʹ� ����� �� ���̶��� ���ϸ� �Ǵϱ�? DP �������� Ǯ���.
}