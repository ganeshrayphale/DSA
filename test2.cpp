#include <iostream>
using namespace std;

struct MinMax {
    int min;
    int max;
};

MinMax findMinMax(int arr[], int low, int high) {
    MinMax result, left, right;

    
    if (low == high) {
        result.min = result.max = arr[low];
        return result;
    }

    

    
    int mid = (low + high) / 2;

    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    
    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int arr[] = {5, 3, 8, 1, 9, 2, 7,18};
    int n = sizeof(arr) / sizeof(arr[0]);

    MinMax result = findMinMax(arr, 0, n - 1);

    cout << "Minimum element: " << result.min << endl;
    cout << "Maximum element: " << result.max << endl;

    return 0;
}
