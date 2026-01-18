#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int> &arr, int lb, int ub) {
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while (start < end) {
        while (start <= ub && arr[start] <= pivot) {
            start++;
        }
        while (arr[end] > pivot) {
            end--;
        }
        if (start < end) {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[lb], arr[end]);
    return end;
}

void quickSort(vector<int> &arr, int lb, int ub) {
    if (lb < ub) {
        int pivIdx = partition(arr, lb, ub);
        quickSort(arr, lb, pivIdx - 1);
        quickSort(arr, pivIdx + 1, ub);
    }
}

int main() {
    vector<int> arr = {2, 1, 3, 5, 7};

    quickSort(arr, 0, arr.size() - 1);

    for (int val : arr) {
        cout << val << " ";
    }
    return 0;
}

