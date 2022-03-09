#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {};
    bool operator<(const Point p) const {
        if (y == p.y) {
            return x > p.x;
        }
        else {
            return y > p.y;
        }
    }
};

priority_queue <Point> pq;

int main(void) {
    int x, y , T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> x >> y;
        pq.push(Point(x, y));
    }

    for (int i = 0; i < T; i++) {
        cout << pq.top().x << ' ' << pq.top().y << '\n';
        pq.pop();
    }
}