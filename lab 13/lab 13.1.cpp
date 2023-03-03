#include <stdio.h>
#include <stdlib.h>

int *KnapsackDP(int *w, int *v, int n, int wx) {
    int **u = (int **)malloc((n+1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        u[i] = (int *)malloc((wx+1) * sizeof(int));
    }
    int **y = (int **)malloc((n+1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        y[i] = (int *)malloc((wx+1) * sizeof(int));
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= wx; j++) {
            if (i == 0 || j == 0) {
                u[i][j] = 0;
                y[i][j] = 0;
            } else if (w[i-1] <= j) {
                int a = u[i-1][j];
                int b = u[i-1][j-w[i-1]] + v[i-1];
                if (b > a) {
                    u[i][j] = b;
                    y[i][j] = 1;
                } else {
                    u[i][j] = a;
                    y[i][j] = 0;
                }
            } else {
                u[i][j] = u[i-1][j];
                y[i][j] = 0;
            }
        }
    }

    int *x = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }
    int j = wx;
    for (int i = n; i > 0 && j > 0; i--) {
        if (y[i][j] == 1) {
            x[i-1] = 1;
            j -= w[i-1];
        }
    }

    for (int i = 0; i <= n; i++) {
        free(u[i]);
        free(y[i]);
    }
    free(u);
    free(y);

    return x;
}

int main() {
    int n = 5 , wx = 11 ;
    int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
    int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
    int *x ;
    x = KnapsackDP( w, v, n, wx ) ;
    for( int i = 0 ; i < n ; i++ ) printf( "%d ", x[ i ] ) ;
    free(x);
    return 0 ;
}

