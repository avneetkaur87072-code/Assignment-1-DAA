#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;

    vector<int> b(ub + 1);

    while (i <= mid && j <= ub) {
        if (arr[i] <= arr[j]) {
            b[k++] = arr[i++];
        } else {
            b[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        b[k++] = arr[i++];
    }

    while (j <= ub) {
        b[k++] = arr[j++];
    }

    for (int x = lb; x <= ub; x++) {
        arr[x] = b[x];
    }
}

void mergeSort(vector<int>& arr, int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

int main() {
    vector<int> arr = {2, 1, 3, 5, 7};

    mergeSort(arr, 0, arr.size() - 1);

    for (int val : arr) {
        cout << val << " ";
    }

    return 0;
}

