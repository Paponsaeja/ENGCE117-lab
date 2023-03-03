#include <stdio.h>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

bool compare(Item i1, Item i2) {
    return ((double) i1.value / i1.weight) > ((double) i2.value / i2.weight);
} 

int *KnapsackGreedy(int *w, int *v, int n, int wx) {
    Item items[n];
    int *x = new int[n];
    int total_weight = 0;

    for (int i = 0; i < n; i++) {
        items[i].weight = w[i];
        items[i].value = v[i];
    }

    sort(items, items + n, compare);

    for (int i = 0; i < n; i++) {
        if (total_weight + items[i].weight <= wx) {
            x[i] = 1;
            total_weight += items[i].weight;
        } else {
            x[i] = 0;
        }
    }

    return x;
}

int main() {
 int n = 5, wx = 11 ;
 int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
 int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
 int *x = KnapsackGreedy( w, v, n, wx ) ;
 for( int i = 0 ; i < n ; i++ ) printf( "%d ", x[ i ] ) ;
 return 0 ;
}//end function

