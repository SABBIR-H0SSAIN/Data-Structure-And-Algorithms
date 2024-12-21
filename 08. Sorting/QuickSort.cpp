#include<iostream>
#include<vector>

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

    if (low >= high) return;
    int pivot = partition(arr, low, high);

    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
}

int main() {
    
    vector<int> arr = {8,7,0,3,1,2,5,4,9,6};
    quickSort(arr, 0, arr.size() - 1);
    for(int x : arr) cout<<x<<" ";
    cout<<endl;

    return 0;
}
