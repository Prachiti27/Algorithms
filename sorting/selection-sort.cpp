#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {

    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {

        int minIndex = i;

        for (int j = i + 1; j < n; j++) {

            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
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

    selectionSort(arr);

    print(arr);

    return 0;
}