#include <iostream>
using namespace std;

struct Node{
	int data;
    Node *next;
    Node(int value):data(value),next(nullptr){}
};

Node *findMid(Node * head) {
    Node *once=head;
    Node *twice=head->next;
    while(twice && twice->next) {
        once = once->next;
        twice = twice->next->next;
    }
    return once;
}

Node *merge(Node *left,Node *right) {
    if(!left) return right;
    if(!right) return left;

    Node *dummy = new Node(-1);
    Node *temp = dummy;

    while(left && right) {

        if(left->data <= right->data) {
            temp->next = left;
            left=left->next;
        } else {
            temp->next = right;
            right=right->next;
        }

        temp=temp->next;
    }

    temp->next=left ? left : right;
    return dummy->next;
}

Node* mergeSort(Node* head) {
    if(!head) return nullptr;
    if(!head->next) return head;

    Node *left = head;
    Node *mid = findMid(head);
    Node *right = mid->next;

    mid->next = nullptr;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left,right);

}

void printList(Node *head){

	Node *temp = head;

	while(temp){
    	cout<<temp->data<<" ";
    	temp=temp->next;
    }
    cout<<endl;
}

int main(){

	Node *n1 = new Node(4);
    Node *n2 = new Node(3);
    Node *n3 = new Node(1);
    Node *n4 = new Node(5);
    Node *n5 = new Node(2);
    
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    
    Node *head = mergeSort(n1);
    printList(head); 
}