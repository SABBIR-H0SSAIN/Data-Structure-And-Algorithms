#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head = nullptr;
    int length = 0;

public:
    LinkedList() {}
    ~LinkedList();

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

LinkedList::~LinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}

void LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    length++;
}

void LinkedList::prepend(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    length++;
}

void LinkedList::insertAtIndex(int index, int value) {
    if (index < 0 || index > length) {
        cout << "Index out of bounds" << endl;
        return;
    }
    if (index == 0) {
        prepend(value);
        return;
    }
    Node* newNode = new Node(value);
    Node* temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    length++;
}

void LinkedList::insertBeforeData(int ref_data, int value) {
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
        temp->next = newNode;
        length++;
    }
}

void LinkedList::insertAfterData(int ref_data, int value) {
    Node* newNode = new Node(value);
    Node* temp = head;
    while (temp && temp->data != ref_data) {
        temp = temp->next;
    }
    if (temp) {
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
    }
}

void LinkedList::deleteFirst() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
    length--;
}

void LinkedList::deleteLast() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    length--;
}

void LinkedList::deleteAtIndex(int index) {
    if (index < 0 || index >= length) {
        cout << "Index out of bounds" << endl;
        return;
    }
    if (index == 0) {
        deleteFirst();
        return;
    }
    Node* temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
    length--;
}

void LinkedList::deleteBeforeData(int ref_data) {
    if (!head || !head->next || head->data == ref_data) return;
    if (head->next->data == ref_data) {
        deleteFirst();
        return;
    }
    Node* temp = head;
    while (temp->next->next && temp->next->next->data != ref_data) {
        temp = temp->next;
    }
    if (temp->next->next) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        length--;
    }
}

void LinkedList::deleteAfterData(int ref_data) {
    Node* temp = head;
    while (temp && temp->data != ref_data) {
        temp = temp->next;
    }
    if (temp && temp->next) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        length--;
    }
}

void LinkedList::printList() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool LinkedList::isEmpty() {
    return !head;
}

int LinkedList::size() {
    return length;
}

int main() {
    LinkedList list;

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
