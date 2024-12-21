#include <iostream>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int length = 0;

public:
    DoublyLinkedList() {}
   ~DoublyLinkedList();

    void append(int value);
    void prepend(int value);
    void insertAtIndex(int index, int value);
    void insertBeforeData(int ref_data, int value);
    void insertAfterData(int ref_data, int value);
    void deleteFirst();
    void deleteLast();
    void deleteAtIndex(int index);
    void deleteBeforeData(int ref_data);
    void deleteAfterData(int ref_data);
    void printList();
    bool isEmpty();
    int size();
};

DoublyLinkedList::~DoublyLinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}

void DoublyLinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    length++;
}

void DoublyLinkedList::prepend(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    length++;
}

void DoublyLinkedList::insertAtIndex(int index, int value) {
    if (index < 0 || index > length) {
        cout << "Index out of bounds" << endl;
        return;
    }
    if (index == 0) {
        prepend(value);
        return;
    }
    if (index == length) {
        append(value);
        return;
    }
    Node* newNode = new Node(value);
    Node* temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    length++;
}

void DoublyLinkedList::insertBeforeData(int ref_data, int value) {
    if (!head) return;
    if (head->data == ref_data) {
        prepend(value);
        return;
    }
    Node* newNode = new Node(value);
    Node* temp = head;
    while (temp->next && temp->next->data != ref_data) {
        temp = temp->next;
    }
    if (temp->next) {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        length++;
    }
}

void DoublyLinkedList::insertAfterData(int ref_data, int value) {
    Node* newNode = new Node(value);
    Node* temp = head;
    while (temp && temp->data != ref_data) {
        temp = temp->next;
    }
    if (temp) {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;
        }
        temp->next = newNode;
        length++;
    }
}

void DoublyLinkedList::deleteFirst() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
    length--;
}

void DoublyLinkedList::deleteLast() {
    if (!tail) return;
    Node* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
    length--;
}

void DoublyLinkedList::deleteAtIndex(int index) {
    if (index < 0 || index >= length) {
        cout << "Index out of bounds" << endl;
        return;
    }
    if (index == 0) {
        deleteFirst();
        return;
    }
    if (index == length - 1) {
        deleteLast();
        return;
    }
    Node* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    length--;
}

void DoublyLinkedList::deleteBeforeData(int ref_data) {
    if (!head || !head->next || head->data == ref_data) return;
    Node* temp = head;
    while (temp->next && temp->next->data != ref_data) {
        temp = temp->next;
    }
    if (temp->next && temp->prev) {
        Node* nodeToDelete = temp;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete nodeToDelete;
        length--;
    }
}

void DoublyLinkedList::deleteAfterData(int ref_data) {
    Node* temp = head;
    while (temp && temp->data != ref_data) {
        temp = temp->next;
    }
    if (temp && temp->next) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        if (temp->next) {
            temp->next->prev = temp;
        } else {
            tail = temp;
        }
        delete nodeToDelete;
        length--;
    }
}

void DoublyLinkedList::printList() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool DoublyLinkedList::isEmpty() {
    return !head;
}

int DoublyLinkedList::size() {
    return length;
}

int main() {
    DoublyLinkedList list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.printList();

    list.prepend(0);
    list.printList();

    list.insertAtIndex(2, 5);
    list.printList();

    list.insertBeforeData(2, 4);
    list.printList();

    list.insertAfterData(2, 6);
    list.printList();

    list.deleteFirst();
    list.printList();

    list.deleteLast();
    list.printList();  

    list.deleteAtIndex(2);
    list.printList(); 

    list.deleteBeforeData(2);
    list.printList();  

    list.deleteAfterData(2);
    list.printList();

    cout << "Is Empty : " << (list.isEmpty() ? "YES" : "NO") << endl;  
    cout << "Length   : " << list.size() << endl; 

    return 0;
}
