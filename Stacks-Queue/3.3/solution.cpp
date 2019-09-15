// Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore,
// in real life, we would likely start a new stack when the previous stack exceeds
// some threshold. Implement a data structure SetOfStacks that mimics this. SetOf-
// Stacks should be composed of several stacks, and should create a new stack once
// the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should
// behave identically to a single stack (that is, pop() should return the same values as it
// would if there were just a single stack).
// FOLLOW UP
// Implement a function popAt(int index) which performs a pop operation on a specific
// sub-stack.

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 4;

struct Node {
    int data;
    Node* next;
    
    Node(int n) {
        this->data = n;
        this->next = NULL;
    }   
};

class Stack {
    Node* top = NULL;
    int size = 0;
public:
    void push(int n) {
        Node* newNode = new Node(n);
        if (top) {
            newNode->next = top;
        }
        
        top = newNode;
        size++;
    }
    
    int pop() {
        if (top) {
            Node* n = top;
            int data = n->data;
            
            top = top->next;
            delete n;
            size--;
            return data;
        }
        
        return -99999999;
    }
    
    int getSize() {
        return size;
    }
    
    void print() {
        Node* n = top;
        
        while(n) {
            cout << n->data << " ";
            n = n->next;
        }
        cout << endl;
    }

    Node* getTop() {
        return top;
    }
};


class SetOfStacks {
    int currentPile = -1;
    vector<Stack> stacks;
public:
    void push(int n) {
        
        if (currentPile == -1 || stacks[currentPile].getSize() == MAX) {
            Stack s = Stack();
            stacks.push_back(s);
            currentPile++;
        }
        
        stacks[currentPile].push(n);
    }
    
    int pop() {
        if (currentPile == -1){
            return -99999999;
        }
        
        // If pile is empty delect that stack & make
        // prev stack the current pile
        if (stacks[currentPile].getSize() == 0) {
            stacks.pop_back();
            currentPile--;
        }
        
        
        if (currentPile > -1) {
            return stacks[currentPile].pop();
        }
        
        return -99999999;
    }
    
    void print() {
        for(auto s : stacks) {
            s.print();
        }
    }
    
    int popAt(int pileIndex) {
        if(pileIndex < stacks.size()) {
            stacks[pileIndex].pop();


            while (pileIndex < stacks.size() - 1) {
                Stack s = stacks[pileIndex + 1];
                Node* n = s.getTop();
                
                if (n->next) {
                    while (n->next->next) {
                        n = n->next;
                    }
                    Node* bottom = n->next;
                    n->next = NULL;
                    stacks[pileIndex].push(bottom->data);
                    delete bottom;
                }
                else {
                    stacks[pileIndex].push(n->data);
                    stacks.pop_back();
                }
                pileIndex++;
            }

        }
        return -99999999;
    }
    
};

int main() {
    SetOfStacks stacks = SetOfStacks();
    stacks.print();
    
    for(int i=1; i<=25; i++) {
        stacks.push(i);
    }
    
    stacks.print();
    cout << endl;
    
    stacks.popAt(3);
    
    stacks.print();
    cout << endl;
    
    return 0;
}