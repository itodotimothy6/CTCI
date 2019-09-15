// Implement a MyQueue class which implements a queue using two stacks.

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    void push(int n) {
        s1.push(n);
    }
    
    int pop() {
        if (s2.empty() && s1.empty()) return -99999;
        
        if (s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        int n = s2.top();
        s2.pop();
        return n;
    }
    
    bool isEmpty(){
        return s1.empty() && s2.empty();
    }
     
};

void print(MyQueue q) {
    while(!q.isEmpty()) {
        cout << q.pop() << " ";
    }
    cout << endl;
}



int main() {
    
    MyQueue q = MyQueue();
    
    q.push(5);
    print(q);
    
    q.push(3);
    print(q);
    
    q.push(-4);
    print(q);
    
    q.push(9);
    print(q);
    
    q.push(0);
    print(q);
    
    q.push(-2);
    print(q);
    
    cout << endl;
    
    q.pop();
    print(q);
    
    q.pop();
    print(q);
    
    q.pop();
    print(q);
    
    q.pop();
    print(q);
    
    q.pop();
    print(q);
    
    q.pop();
    print(q);
    
    return 0;
}