#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;
    int largest = i;

    if (leftIndex < n && arr[leftIndex] > arr[largest]) {
        largest = leftIndex;
    }
    if (rightIndex < n && arr[rightIndex] > arr[largest]) {
        largest = rightIndex;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for(int i=n/2-1;i>0;i--){
        heapify(arr,n,i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {9, 0, 2, 5, 1, 4, 3, 7, 6};

    cout << "Before Sort: ";
    printArray(arr);

    heapSort(arr);

    cout << "After Sort: ";
    printArray(arr);

    return 0;
}
