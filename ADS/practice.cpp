#include <bits/stdc++.h>
using namespace std;

void Heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (i != largest) {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

void printArr(vector<int>& arr) {
    cout << "Increasing Order :" << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Decreasing Order :" << endl;
    for (int i = arr.size() - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Heapsort(vector<int>& arr, int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        Heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}

int main() {
    vector<int> v = {15, 3, 9, 8, 5, 2, 7, 1, 6};
    Heapsort(v, v.size());
    printArr(v);
    return 0;
}