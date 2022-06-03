#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct nation {
	int num;
	int g;
	int s;
	int b;
};

bool Cmp(nation A, nation B) {
	if (A.g >= B.g) 
	{
		if (A.g == B.g) 
		{
			if (A.s >= B.s)		
			{
				if (A.s == B.s) 
				{
					if (A.b > B.b) 
					{
						return true;
					}
					return true;
				}
				return true;
			}
			return true;
		}
		return true;
	}
}

priority_queue <nation> que;
vector <nation> vec;

int main(void) {
	int N, K;
	int n, G, S, B;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> n >> G >> S >> B;
		vec.push_back({ n, G, S, B }); 
	}
	sort(vec.begin(), vec.end(), Cmp);

	for (int i = 0; i < N; i++) {
		cout << vec[i].num << ' ';
	}
}