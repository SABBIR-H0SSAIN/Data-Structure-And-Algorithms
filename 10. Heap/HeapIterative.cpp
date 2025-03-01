#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
    vector<int> arr;
    int size;
    int startIndex;

public:
    Heap() {
        arr.push_back(-1); 
        size = 0;
        startIndex = 1;
    }

    void insert(int val) {
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

    void remove() {
        if (size == 0) return;

        int deletedValue = arr[startIndex];
        int i = startIndex;
        swap(arr[i], arr[size]);
        arr.pop_back();
        size--;
        int largest = i;

        while (true) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex <= size && arr[leftIndex] > arr[largest]) {
                largest = leftIndex;
            }
            if (rightIndex <= size && arr[rightIndex] > arr[largest]) {
                largest = rightIndex;
            }

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else break;
        }
        cout << deletedValue << " is deleted from the heap" << endl;
    }

    void print() {
        for (int i = startIndex; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h;
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(6);
    h.insert(9);

    h.print();
    h.remove();
    h.print();
    h.remove();
    h.print();
    h.remove();
    h.print();
    h.remove();
    h.print();
    return 0;
}
