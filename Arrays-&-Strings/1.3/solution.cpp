// Question 1.3
// Design an algorithm and write code to remove the duplicate characters in a string
// without using any additional buffer. NOTE: One or two additional variables are fine.
// An extra copy of the array is not.
// FOLLOW UP
// Write the test cases for this method.

#include <iostream>
#include <vector>
using namespace std;

// O(n^2)
// No Buffer
void removeDuplicate(char* str, int n) {
    if(!str) return;
    int tail = 0;

    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < tail; j++) {
            if (str[i] == str[j])
                break;
        }
        if (j == tail) {
            str[tail++] = str[i];
        }
    }
    cout << tail << endl;

    str[tail] = '\0';
}

// Using Buffer
// O(n)
void removeDuplicate_WithDS(string &str) {
    vector<bool> buffer(128);

    int tail = 0;
    for (int i = 0; i < str.length(); i++) {
        if (!buffer[str[i]]) {
            buffer[str[i]] = true;
            str[tail++] = str[i];
        }
    }

    str = str.substr(0, tail);
}

int main(){

    char s[] = "";
    int n = sizeof(s);
    removeDuplicate(NULL, n-1);
    cout << s << endl;

    string str = "";
    removeDuplicate_WithDS(str);
    cout << str << endl;

    return 0;
}
