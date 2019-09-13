// Question 2.3
// Implement an algorithm to delete a node in the middle of a single linked list, given
// only access to that node.
// EXAMPLE
// Input: the node ‘c’ from the linked list a->b->c->d->e
// Result: nothing is returned, but the new linked list looks like a->b->d->e

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
        Node* newNode = new Node(data);

        while (current->next) {
            current = current->next;
        }

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

void removeMiddle(Node* middle) {
    // Empty list => middle is NULL
    if (!middle) return;

    // If list has 1-2 elem => middle is the last elem
    // Dangling ptr tho
    if (!middle->next) {
        delete middle;
    }

    while (middle->next->next) {
        middle->data = middle->next->data;
        middle = middle->next;
    }

    Node* last = middle->next;
    middle->data = last->data;
    middle->next = NULL;
    delete last;
}

int main() {

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;


    removeMiddle(node3);
    printLinkedlist(node1);
    return 0;
}