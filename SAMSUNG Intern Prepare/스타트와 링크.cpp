#include <iostream>
#include <vector>
using namespace std;

int score[21][21];
bool Team[20];
int N, min_num = -999999;

void teamset(int idx, int cnt)
{
    vector<int> start; 
    vector<int> link; 
    int start_score = 0;
    int link_score = 0;
    if (cnt == (N / 2))
    {
        for (int i = 0; i < N; i++)
        {
            if (start[i] == true) 
                start.push_back(i);
            else 
                link.push_back(i);
        }
        for (int i = 0; i < (N / 2); i++)
            for (int j = 0; j < (N / 2); j++)
            {
                start_score += score[start[i]][start[j]];
                link_score += score[link[i]][link[j]];
            } 
        if (abs(start_score - link_score) < min_num)
            min_num = abs(start_score - link_score);
        return;
    }
}

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