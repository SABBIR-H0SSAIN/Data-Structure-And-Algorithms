#include <iostream>
#include <vector>

using namespace std;

void maxHeapify(vector<int>& arr, int i, int len) {
    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;
    int largest = i;

    if (leftIndex < len && arr[leftIndex] > arr[largest]) {
        largest = leftIndex;
    }
    if (rightIndex < len && arr[rightIndex] > arr[largest]) {
        largest = rightIndex;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest, len);
    }
}

void buildMaxHeap(vector<int>& arr) {
    int len = arr.size();
    for (int i = len / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, i, len);
    }
}

void heapSort(vector<int>& arr) {
    buildMaxHeap(arr);
    int len = arr.size();
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, 0, i);
    }
}

void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {9, 8, 2, 5, 1, 4, 3, 7, 6};

    cout << "Before Sort: ";
    printArray(arr);

    heapSort(arr);

    cout << "After Sort: ";
    printArray(arr);

    return 0;
}
