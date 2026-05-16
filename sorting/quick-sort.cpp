#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {

    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {

    if (low < high) {

        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);

        quickSort(arr, pivotIndex + 1, high);
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

    quickSort(arr, 0, arr.size() - 1);

    print(arr);

    return 0;
}