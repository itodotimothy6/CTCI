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

// Using buffer or extra space
void removeDuplicates(Node* head) {
    if(!head) return;
    unordered_set<int> dataSet;
    dataSet.insert(head->data);
    Node *before = head;
    Node *current = head->next;
    while (current) {
        if (dataSet.find(current->data) != dataSet.end()) {
            Node* temp = current;
            before->next = current->next;
            current = current->next;
            delete temp;
        }
        else {
            dataSet.insert(current->data);
            before = current;
            current = current->next;
        }
    }
}

// Without extra space O(n^2)
void removeDuplicates2(Node* head) {
    if(!head) return;

    Node* current = head;

    while(current) {
        Node* prev = current;
        Node* runner = current->next;
        int num = current->data;

        while (runner){
            if (runner->data == num) {
                Node* temp = runner;
                prev->next = runner->next;
                runner = runner->next;
                delete temp;
            }
            else {
                prev = runner;
                runner = runner->next;
            }
        }
        current = current->next;
    }    
}


int main(){

    Node* head = new Node(1);
    
    for(int i = 2; i < 10; i++) {
        head->appendToTail(i);
    }

    for(int i = 2; i < 10; i++) {
        head->appendToTail(i);
    }

    printLinkedlist(head);
    removeDuplicates(head);
    printLinkedlist(head);

    Node* head2 = new Node(1);
    for(int i = 1; i < 10; i++) {
        head2->appendToTail(i);
        head2->appendToTail(i);
        head2->appendToTail(i);
    }

    printLinkedlist(head2);
    removeDuplicates2(head2);
    printLinkedlist(head2);



    return 0;
}