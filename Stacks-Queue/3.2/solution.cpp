// How would you design a stack which, in addition to push and pop, also has a function
// min which returns the minimum element? Push, pop and min should all operate in
// O(1) time.

// How would you design a stack which, in addition to push and pop, also has a function
// min which returns the minimum element? Push, pop and min should all operate in
// O(1) time.


#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
    Node* top = NULL;
    unordered_map<Node*, int> minMap;
    int min = INT_MAX;
    
public:
    void push(int n) {
        Node* newNode = new Node(n);
        
        if (top) {
            newNode->next = top;
            top = newNode;
        }
        else {
            top = newNode;
        }
        
        if (min > top->data) {
            min = top->data;
        }
        minMap[top] = min;
    }
    
    int pop() {
        if (top->next) {
            int data = top->data;
            Node* n = top;
            top = top->next;
            
            delete n;
            min = minMap[top];
            return data;
        }
        
        if(top) {
            int data = top->data;
            Node* n = top;
            top = top->next;
            
            delete n;
            min = INT_MAX;
            return data;
        }
        
        return -99999999;
    }
    
    int getMin() {
        return min;
    }
    
    void print() {
        Node* n = top;
        while (n) {
            cout << n->data << " ";
            n = n->next;
        }
        cout << endl;
        cout << getMin() << endl;
        cout << endl;
    }
};


int main() {
    
    Stack s = Stack();
    s.print();
    
    s.push(5);
    s.print();
    
    s.push(4);
    s.print();
    
    s.push(9);
    s.print();
    
    s.push(-4);
    s.print();
    
    s.pop();
    s.print();
    
    s.pop();
    s.print();
    
    s.pop();
    s.print();
    
    s.pop();
    s.print();
    
    
    return 0;
}