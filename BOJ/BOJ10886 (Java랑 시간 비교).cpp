#include <stdio.h>
#include <iostream>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    int cute = 0, ncute = 0, portion;
    for (int i = 0; i < N; i++) {
        cin >> portion;
        if (portion) {
            cute++;
        }
        else  ncute++;
    }
    if (cute > ncute) {
        cout << "Junhee is cute!";
    }
    else cout << "Junhee is not cute!";
}