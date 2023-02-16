#include <stdio.h>

int BinSearch(int arr[], int n, int target);

int main() {
    int data[6] = {1, 2, 3, 4, 5, 7};
    int n = 6;
    int find = 5;
    int pos = BinSearch(data, n, find);
    if (pos == -1) {
        printf("%d not found in array.\n", find);
    } else {
        printf("%d found at position %d.\n", find, pos);
    }
    return 0;
}

int BinSearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

