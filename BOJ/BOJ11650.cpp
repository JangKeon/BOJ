#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

struct Point {
	int x;
	int y;
};

int compare(struct Point*  a, struct Point* b) {
    if (a->x == b->x)
        return (a->y > b->y ? 1 : (a->y == b->y ? 0 : -1));
    else
        return (a->x > b->x ? 1 : -1);
}

void quickSort(struct Point* array, int left, int right) {
    int i = left, j = right;
    struct Point tmp, pivot = array[(left + right) / 2];

    while (i <= j) {
        while (compare(&pivot, array + i) == 1) ++i;
        while (compare(array + j, &pivot) == 1) --j;
        if (i <= j) {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            ++i; --j;
        }
    }

    if (j > left) quickSort(array, left, j);
    if (right > i) quickSort(array, i, right);
}

int main() {
	int num;
	struct Point* point;
	std::cin >> num;
	point = (struct Point*)malloc(sizeof(struct Point) * num);
	for (int i = 0; i < num; i++) {
		std::cin >> point[i].x >> point[i].y;
	}
    quickSort(point, 0, num - 1);
	
	for (int i = 0; i < num; i++) {
		std::cout << point[i].x << " " << point[i].y << "\n";
	}
}