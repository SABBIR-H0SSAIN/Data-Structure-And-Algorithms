#include <iostream>
#include <vector>

using namespace std;

class maxHeap {
private:
    vector<int> arr;
    int size;
    int startIndex;

public:
    maxHeap() {
        arr.push_back(-1); 
        size = 0;
        startIndex = 1;
    }


    void push(int val) {
        size++;
        arr.push_back(val);
        int cur = size;
        int parent = cur / 2;
        while (parent >= startIndex && arr[cur] > arr[parent]) {
            swap(arr[cur], arr[parent]);
            cur = parent;
            parent = cur / 2;
        }
    }

    int pop(){
        int poppedValue=arr[startIndex];
        swap(arr[startIndex],arr[size]);
        arr.pop_back();
        size--;
        maxHeapify(startIndex);
        return poppedValue;
    }

    void maxHeapify(int i){

        int leftIndex= 2*i;
        int rightIndex=2*i+1;
        int largest=i;

        if(leftIndex <= size && arr[leftIndex] > arr[largest]){
            largest=leftIndex;
        }
        if(rightIndex <= size && arr[rightIndex] > arr[largest]){
            largest=rightIndex;
        }

        if(largest != i){
            swap(arr[i],arr[largest]);
            maxHeapify(largest);
        }
    }
    void print() {
        for (int i = startIndex; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    maxHeap h;
    h.push(1);
    h.push(7);
    h.push(3);
    h.push(8);
    h.push(2);
    h.push(4);
    h.push(6);

    h.print();
    cout << h.pop() << " has been pooped"<<endl;
    h.print();
    cout << h.pop() << " has been pooped"<<endl;
    h.print();
    cout << h.pop() << " has been pooped"<<endl;
    h.print();
    cout << h.pop() << " has been pooped"<<endl;
    h.print();
    return 0;
}
