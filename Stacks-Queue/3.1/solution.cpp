// 3.1 Describe how you could use a single array to implement three stacks.

#include <iostream>
using namespace std;

// Global var
const int N = 30; // N should be a multiple of 3
int* stack = new int[N];
int tops[3] = {-1, N/3 - 1, 2*N/3 - 1};

// Functions
void push(int stackNum, int n) {
    if (tops[stackNum - 1] < stackNum * N/3 - 1) {
        tops[stackNum - 1]++;
        stack[tops[stackNum - 1]] = n;
    }
}

int pop(int stackNum) {
    if(tops[stackNum - 1] > (stackNum-1) * N/3 - 1) {
        int n = stack[tops[stackNum - 1]];
        tops[stackNum - 1]--;
        return n;
    }
    
    tops[stackNum - 1]--;
    return -99999999;
}

bool isEmpty(int stackNum) {
    return tops[stackNum - 1] == (stackNum-1) * N/3 - 1;
}

void print(int stackNum) {
    cout << "Stack " << stackNum << ": ";
    
    int i = (stackNum-1) * N/3;
    
    while(i <= tops[stackNum - 1]) {
        cout << stack[i] << " ";
        i++;
    }
    
    cout << endl;
}

int main() {
    
    print(1);
    print(2);
    print(3);
    cout << endl;
    
    push(1, 4);
    push(2, 3);
    push(3, -1);
    
    print(1);
    print(2);
    print(3);
    cout << endl;
    
    push(1, 2);
    push(2, 0);
    push(3, 23);
    
    print(1);
    print(2);
    print(3);
    cout << endl;
    
    push(1, 0);
    push(2, -23);
    push(3, 3);
    
    print(1);
    print(2);
    print(3);
    cout << endl;
    
    pop(1);
    pop(2);
    pop(3);
    
    print(1);
    print(2);
    print(3);
    cout << endl;
    
    pop(1);
    pop(2);
    pop(3);
    
    print(1);
    print(2);
    print(3);
    cout << endl;
    
    pop(1);
    pop(2);
    pop(3);
    
    print(1);
    print(2);
    print(3);
    cout << endl;
    
    pop(1);
    pop(2);
    pop(3);
    
    print(1);
    print(2);
    print(3);
    cout << endl;
    
    return 0;
}
