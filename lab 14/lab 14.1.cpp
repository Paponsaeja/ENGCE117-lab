#include <stdio.h>
#include <vector>

int KnapsackBT( int *w, int *v, int n, int wx, int i, int *x ) ;

int maxValue = -1; // global variable to track maximum value found

void KnapsackBTHelper(int *w, int *v, int n, int wx, int i, std::vector<int>& currItems, std::vector<int>& maxItems) {
    // Base case: reached end of items or weight limit exceeded
    if (i == n || wx <= 0) {
        // Calculate total value of items chosen so far
        int currValue = 0;
        for (int j = 0; j < currItems.size(); j++) {
            currValue += v[currItems[j]];
        }
        // Update maximum value found and corresponding items
        if (currValue > maxValue) {
            maxValue = currValue;
            maxItems = currItems;
        }
        return;
    }

    // Case 1: don't include current item
    KnapsackBTHelper(w, v, n, wx, i+1, currItems, maxItems);

    // Case 2: include current item if it fits
    if (w[i] <= wx) {
        currItems.push_back(i);
        KnapsackBTHelper(w, v, n, wx - w[i], i+1, currItems, maxItems);
        currItems.pop_back();
    }
}

int KnapsackBT( int *w, int *v, int n, int wx, int i, int *x ) {
    std::vector<int> currItems, maxItems;
    KnapsackBTHelper(w, v, n, wx, 0, currItems, maxItems);

    // Fill in output array with items included in maximum value solution
    for (int j = 0; j < n; j++) {
        x[j] = 0;
    }
    for (int j = 0; j < maxItems.size(); j++) {
        x[maxItems[j]] = 1;
    }

    return maxValue;
}

int main() {
 int n = 5, wx = 11 ;
 int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
 int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
 int *x, vx ;
 x = new int[ n ] ;
 vx = KnapsackBT( w, v, n, wx, 0, x ) ;
 printf( "Value = %d \n", vx ) ;
 for( int i = 0 ; i < n ; i++ ) printf( "%d ", x[ i ] ) ;
 return 0 ;
}//end function

