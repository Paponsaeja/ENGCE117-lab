#include <stdio.h>

void TowerHanoi(int m, int i, int j, int k);

int main() {
    TowerHanoi(3, 1, 3, 2);
    return 0;
}

void TowerHanoi(int m, int i, int j, int k) {
    if (m == 1) {
        printf("Move disk %d from tower %d to tower %d\n", m, i, j);
    } else {
        TowerHanoi(m - 1, i, k, j);
        printf("Move disk %d from tower %d to tower %d\n", m, i, j);
        TowerHanoi(m - 1, k, j, i);
    }
}

