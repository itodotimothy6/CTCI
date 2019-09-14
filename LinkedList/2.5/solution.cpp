// Question 2.5
// Given a circular linked list, implement an algorithm which returns node at the beginning
// of the loop.
// DEFINITION
// Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an
// earlier node, so as to make a loop in the linked list.
// EXAMPLE
// Input: A -> B -> C -> D -> E -> C [the same C as earlier]
// Output: C

#include <iostream>
#include <unordered_set>

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

Node* getCircularNode(Node* head) {
    unordered_set<Node*> nodeSet;
    Node* n = head;
    while (n) {
        if(nodeSet.find(n) != nodeSet.end()) return n;
        nodeSet.insert(n);
        n = n->next;
    }
    return NULL;
}

int main(){

    Node* head = new Node(3);
    head->appendToTail(4);
    head->appendToTail(7);

    Node* n = new Node(5);
    Node* p = head;
    while (p->next) {
        p=p->next;
    }
    p->next = n;
    head->appendToTail(0);
    head->appendToTail(1);
    while (p->next) {
        p=p->next;
    }
    p->next = n;

    // printLinkedlist(head);


    cout << "\n" << getCircularNode(head)->data << endl;

    return 0;
}