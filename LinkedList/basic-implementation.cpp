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




Node* deleteNode(Node* head, int data) {
    if (!head) return head;
    Node* current = head;

    if (head->data == data) {
        head = head->next;
        delete current;
        return head;
    }

    while (current->next) {
        if (current->next->data == data) {
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
            return head;
        }
        else {
            current = current->next;
        }
    }

    return head;
}

void printLinkedlist(Node* head) {
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    
    for(int i = 2; i < 10; i++) {
        head->appendToTail(i);
    }

    printLinkedlist(head);
    
    head = deleteNode(head, 7);
    head = deleteNode(head, 9);
    head = deleteNode(head, 1);
    printLinkedlist(head);

    Node* head2 = NULL;
    head2 = deleteNode(head2, 3);
    printLinkedlist(head2);

    return 0;
}