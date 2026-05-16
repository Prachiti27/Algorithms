#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {

    int n = arr.size();

    for (int i = 1; i < n; i++) {

        int key = arr[i];

        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void print(vector<int>& arr) {

    for (int x : arr) {
        cout << x << " ";
    }

    cout << "\n";
}

int main() {

    vector<int> arr = {5, 2, 8, 1, 9};

    insertionSort(arr);

    print(arr);

    return 0;
}