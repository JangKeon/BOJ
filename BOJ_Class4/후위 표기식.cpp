#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	string formula, result;
	stack <char> s;
	cin >> formula;
	for (int i = 0; i < formula.size(); i++) {
		if (formula[i] - 'A' >= 0 && formula[i] - 'A' < 27) {
			result.push_back(formula[i]);
		}
		else if (formula[i] == '(') {
			s.push(formula[i]);
		}
		else if (formula[i] == '+' || formula[i] == '-') {
			while (!s.empty() && s.top() != '(') {
				result.push_back(s.top());
				s.pop();
			}
			s.push(formula[i]);
		}
		else if (formula[i] == '*' || formula[i] == '/') {
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				result.push_back(s.top());
				s.pop();
			}
			s.push(formula[i]);
		}
		else if (formula[i] == ')') {
			while (!s.empty() && s.top() != '(') {
				result.push_back(s.top());
				s.pop();
			}
			s.pop();
		}
	}

	while (!s.empty()) {
		result.push_back(s.top());
		s.pop();
	}
	cout << result;
}