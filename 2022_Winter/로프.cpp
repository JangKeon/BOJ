#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N, num;
	vector <int> vec;
	int answer = 99999999;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
 // ���ĵǾ� �����ϱ� �� ��° ���� i ���� �������� ���� �ִ��� ���� �Ÿ� �����س��´�.
 // ���ĺ��ʹ� ����� �� ���̶��� ���ϸ� �Ǵϱ�? DP �������� Ǯ���.
}