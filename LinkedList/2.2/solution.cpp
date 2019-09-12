// Implement an algorithm to find the nth to last element of a singly linked list.

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    void appendToTail(int data) {
        Node* current = this;
        while(current->next) {
            current = current->next;
        }
        Node* newNode = new Node(data);
        current->next = newNode;
    }
};

void printLinkedlist(Node* head) {
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int nthToTheLast(Node* head, int n) {
    if(!head) return -1;
    Node* temp = head;
    int i = 0;
    while (i < n) {
        temp = temp->next;
        i++;
    }

    while (temp) {
        head = head->next;
        temp = temp->next;
    }

    return head->data;
}

int main(){
    Node* head = new Node(1);
    
    for(int i = 2; i < 10; i++) {
        head->appendToTail(i);
    }

    printLinkedlist(head);

    cout << nthToTheLast(head, 4) << endl;
    cout << nthToTheLast(head, 2) << endl;
    cout << nthToTheLast(head, 5) << endl;
    cout << nthToTheLast(head, 1) << endl;

    // Node* head2 = new Node(1);
    // cout << nthToTheLast(head2, 1) << endl;

    return 0;
}

