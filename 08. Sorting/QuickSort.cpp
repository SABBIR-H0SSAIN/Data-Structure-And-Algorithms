#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {

    int pivot = arr[low];
    int i = low, j = high;
    
    while (i < j) {
        while (i <= high && arr[i] <= pivot) i++;
        while (j > low && arr[j] > pivot) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    
    swap(arr[low], arr[j]);
    return j;
}

void quickSortR(vector<int>& arr, int low, int high) {
   
    if (low >= high) return;
    int pivotIndex = partition(arr, low, high);
    
    quickSortR(arr, low, pivotIndex - 1);
    quickSortR(arr, pivotIndex + 1, high);
}

void quickSort(vector<int>& arr) {
    quickSortR(arr, 0, arr.size() - 1);
}

int main() {

    vector<int> arr ={4, 1, 3, 2, 0};
    quickSort(arr);
    
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    return 0;
}
