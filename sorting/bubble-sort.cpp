#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr) {

    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
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

    bubbleSort(arr);

    print(arr);

    return 0;
}