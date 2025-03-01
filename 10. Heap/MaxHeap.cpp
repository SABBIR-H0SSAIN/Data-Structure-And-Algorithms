#include <iostream>
#include <vector>

using namespace std;

class maxHeap {

private:
    vector<int> arr;
    int len;
    int startIndex;

public:

    maxHeap() {
        arr.push_back(-1); 
        len = 0;
        startIndex = 1;
    }

    void push(int val) {
        
        len++;
        arr.push_back(val);

        int cur = len;
        int parent = cur / 2;

        while (parent >= startIndex && arr[cur] > arr[parent]) {

            swap(arr[cur], arr[parent]);
            cur = parent;
            parent = cur / 2;
        }
    }

    int pop(){

        if(empty()){
            cout<<"The heap is empty"<<endl;
            return 0;
        }

        int poppedValue=arr[startIndex];
        swap(arr[startIndex],arr[len]);
        
        arr.pop_back();
        len--;
        
        maxHeapify(startIndex);
        return poppedValue;
    }

    bool empty(){ return len==0; }
    int size(){ return len; }
    int top(){ return arr[startIndex]; }

    void maxHeapify(int i){

        int leftIndex= 2*i;
        int rightIndex=2*i+1;
        int largest=i;

        if(leftIndex <= len && arr[leftIndex] > arr[largest]){
            largest=leftIndex;
        }
        if(rightIndex <= len && arr[rightIndex] > arr[largest]){
            largest=rightIndex;
        }

        if(largest != i){
            swap(arr[i],arr[largest]);
            maxHeapify(largest);
        }
    }
    void print() {
        if(empty()){
            cout<<"The heap is empty"<<endl;
            return;
        }

        for (int i = startIndex; i <= len; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    maxHeap h;
    h.push(6);
    h.push(1);
    h.push(2);
    h.push(8);
    h.push(3);
    h.push(7);
    h.push(4);
    h.push(5);
    
    while(!h.empty()){
        h.print();
        int top = h.top();
        h.pop();
        cout << top << " has been pooped"<<endl<<endl;
    }

    return 0;
}
