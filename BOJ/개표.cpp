#include <iostream>
using namespace std;

int main(void) {
	int N;
	string vote;
	cin >> N >> vote;
	int A = 0, B = 0;
	for (int i = 0; i < vote.size(); i++) {
		if (vote[i] == 'A')	A++;
		else B++;
	}
	if (A > B) {
		cout << "A";
	}
	else if (A == B) {
		cout << "Tie";
	}
	else
	{
		cout << "B";
	}
}