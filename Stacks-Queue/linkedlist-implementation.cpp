#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
    Node* top = NULL;
  
public:
    void push(int n) {
        Node* newNode = new Node(n);

        if(!top) 
            top = newNode;
        else {
            newNode->next = top;
            top = newNode;
        }
    }
    
    int pop() {
        if (top){
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        return -9999999;
    } 
    
    void print() {
        Node* n = top;
        while (n) {
            cout << n->data << " ";
            n = n->next;
        }
        cout << endl;
    }
    
};

class Queue {
    Node* front = NULL;
    Node* back = NULL;
    
public:
    void push_back(int n) {
        Node* newNode = new Node(n);
        
        if (!front && !back) {
            front = newNode;
            back = newNode;
        }
        else {
            back->next = newNode;
            back = newNode; 
        }
    }
    
    int pop_front() {
        if (front) {
            Node* temp = front;
            int n = temp->data;
            
            if (front == back) {
                front = NULL;
                back = NULL;
                
            }
            else {
                front = front->next;
            }
            
            delete temp;
            return n;
        }
        return -99999;
    }
    
    void print(){
        Node* n = front;
        while(n) {
            cout << n->data << " ";
            n = n->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s = Stack();
    s.print();
    
    s.push(5);
    s.print();
    s.push(3);
    s.print();
    s.push(-9);
    s.print();
    s.push(0);
    s.print();
    s.push(1);
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    
    cout << endl;
    
    Queue q = Queue();
  
    q.push_back(3);
    q.print();
    q.push_back(2);
    q.print();
    q.push_back(0);
    q.print();
    q.push_back(9);
    q.print();
    q.push_back(-1);
    q.print();
    q.push_back(7);
    q.print();

    q.pop_front();
    q.print();
    q.pop_front();
    q.print();
    q.pop_front();
    q.print();
    q.pop_front();
    q.print();
    q.pop_front();
    q.print();
    q.pop_front();
    q.print();
    q.pop_front();
    q.print();
    
    return 0;
}