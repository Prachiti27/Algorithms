#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {

    vector<int> temp;

    int i = l;
    int j = m + 1;

    while (i <= m && j <= r) {

        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        }
        else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= m) {
        temp.push_back(arr[i++]);
    }

    while (j <= r) {
        temp.push_back(arr[j++]);
    }

    for (int k = l; k <= r; k++) {
        arr[k] = temp[k - l];
    }
}

void mergeSort(vector<int>& arr, int l, int r) {

    if (l >= r) {
        return;
    }

    int m = (l + r) / 2;

    mergeSort(arr, l, m);

    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
}

void print(vector<int>& arr) {

    for (int x : arr) {
        cout << x << " ";
    }

    cout << "\n";
}

int main() {

    vector<int> arr = {5, 2, 8, 1, 9};

    mergeSort(arr, 0, arr.size() - 1);

    print(arr);

    return 0;
}