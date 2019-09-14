#include <iostream>
using namespace std;
const int MAX = 100;

class Stack {
  int top = -1;
  int* stack = new int[MAX];

public:
  int pop() {
    if (top > -1) {
      int n = stack[top];
      top--;
      return n;
    }
    top--;
    return -99999;
  }

  void push(int n) {
    top++;
    stack[top] = n;
  }

  void print() {
    int i = 0;
    while(i <= top) {
      cout << stack[i] << " ";
      i++;
    }
    cout << endl;
  }
};

class Queue {
  int front = -1;
  int back = -1;
  
  int* queue = new int[MAX];
  
public:
  void push_back(int n) {
    if(front == -1) {
      front++; back++;
      queue[front] = n;
    }
    else {
      back++;
      queue[back] = n;
    }
  }
  
  int pop_front() {
    if (back == front) {
      int n = queue[front];
      front = -1;
      back = -1;
      return n;
    }
    
    if (front == -1 && back == -1) {
      return -99999;
    }
    
    int n = queue[front];
    front++;
    return n;
  }
  
  void print() {
    if (front != -1 && back != -1) {
      for(int i = front; i <= back; i++) {
        cout << queue[i] << " ";
      }
    }
    cout << endl;
  }
  
  int getFront() {
    return front;
  }
  
  int getBack() {
    return back;
  }
  
};


int main() {
  
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
  
  return 0;
}
