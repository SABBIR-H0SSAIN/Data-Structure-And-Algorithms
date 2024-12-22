#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>&arr,int mid, int low, int high){

    vector<int> temp;
    int left=low, right=mid+1;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left++]);
        }else{
            temp.push_back(arr[right++]);
        }
    }

    while(left <= mid) temp.push_back(arr[left++]);
    while(right <= high) temp.push_back(arr[right++]);

    for(int i=low; i<=high; i++){
        arr[i]=temp[i-low];
    }
}
void mergeSortR(vector<int>& arr, int low, int high) {

    if (low >= high) return;
    int mid = low + (high - low) / 2;

    mergeSortR(arr, low, mid);
    mergeSortR(arr, mid + 1, high);
    merge(arr, mid, low, high);

}

void mergeSort(vector<int>& arr){    
    mergeSortR(arr, 0, arr.size() - 1);
}

int main() {
    
    vector<int> arr = {8,7,0,3,1,2,5,4,9,6};
    mergeSort(arr);
    for(int x : arr) cout<<x<<" ";
    cout<<endl;

    return 0;
}
