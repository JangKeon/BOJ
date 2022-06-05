#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main(void) {
	string str, key;
	queue <char> que;
	cin >> str >> key;
	for (int i = 0; i < str.size(); i++) {
		que.push(str[i]);
	}

	for (int i = 0; i < str.size(); i++) {
		if (que.front() >= 48 && que.front() <= 57) {
			que.pop();
		}
		else {
			que.push(que.front());
			que.pop();
		}
	}
	str = "";
	while (!que.empty()) {
		str.push_back(que.front());
		que.pop();
	}
	
	size_t nPos = str.find(key);
	if (nPos != string::npos) cout << "1";
	else cout << "0";
}