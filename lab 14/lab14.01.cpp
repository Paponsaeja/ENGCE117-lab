#include <stdio.h>

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x) {
    if (i == n) {
        int tw = 0, tv = 0;
        for (int j = 0; j < n; j++) {
            if (x[j]) {
                tw += w[j];
                tv += v[j];
            }
        }
        if (tw <= wx) return tv;
        else return 0;
    }
    x[i] = 0;
    int v1 = KnapsackBT(w, v, n, wx, i + 1, x);
    x[i] = 1;
    int v2 = KnapsackBT(w, v, n, wx, i + 1, x);
    if (v1 > v2) {
        x[i] = 0;
        return v1;
    } else {
        x[i] = 1;
        return v2;
    }
}

int main() {
    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};
    int *x, vx;
    x = new int[n];
    vx = KnapsackBT(w, v, n, wx, 0, x);
    printf("Value = %d ", vx);
    printf("Selected items: ");
    for (int i = 0; i < n; i++) {
        printf("%d", x[i]);
    }
    return 0;
}

