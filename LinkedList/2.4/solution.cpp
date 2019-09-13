// Question 2.4
// You have two numbers represented by a linked list, where each node contains a single
// digit. The digits are stored in reverse order, such that the 1’s digit is at the head of
// the list. Write a function that adds the two numbers and returns the sum as a linked
// list.
// EXAMPLE
// Input: (3 -> 1 -> 5), (5 -> 9 -> 2)
// Output: 8 -> 0 -> 8

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

Node* add(Node* head1, Node* head2) {
    Node* head = new Node(0);
    int carryover = 0;
    int sum;

    Node* p1 = head1;
    Node* p2 = head2;
    Node* p3 = head;

    while (p1 || p2) {
        sum = carryover;
        if (p1) sum += p1->data;
        if (p2) sum += p2->data;
        if (sum >= 10) {
            p3->data = sum % 10;
            carryover = 1;
        }
        else {
            p3->data = sum;
            carryover = 0;
        }

        if (p1 && p2 && (p1->next || p2->next) || (p1 && p1->next) || (p2 && p2->next)){
            Node* newNode = new Node(0);
            p3->next = newNode;
            p3 = newNode;
        }

        if (p1) p1 = p1->next;
        if (p2) p2 = p2->next;
    }

    if (carryover == 1) {
        Node* newNode = new Node(0);
        p3->next = newNode;
        p3 = newNode;
    }

    return head;
}

int main() {

    Node* head1 = new Node(1);
    Node* head2 = new Node(1);
    
    for(int i = 2; i < 10; i++) {
        head1->appendToTail(i);
    }

    for(int i = 2; i < 8; i++) {
        head2->appendToTail(i);
    }

    printLinkedlist(head1);
    printLinkedlist(head2);
    printLinkedlist(add(head1,head2));

    return 0;
}