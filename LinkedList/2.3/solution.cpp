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

bool removeMiddle(Node* middle) {
    // When the node to be deleted is Null or is the last elem
    // Can not be deleted given only access to middle
    if (!middle || !middle->next) return false;

    Node* n = middle->next;
    middle->data = n->data;
    middle->next = n->next;
    delete n;
    return true;
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


    cout << removeMiddle(node3) << endl;
    printLinkedlist(node1);
    return 0;
}