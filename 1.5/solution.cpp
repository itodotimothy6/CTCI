// Question 1.5
// Write a method to replace all spaces in a string with ‘%20’.

#include <iostream>

using namespace std;

void replaceSpace(string &s) {
    int noOfSpaces = 0, length = s.length();
    for (int i = 0; i < length; i++) {
        if (s[i] == ' ') noOfSpaces++;
    }

    s.resize(length + noOfSpaces * 2);

    int i = length - 1;
    int j = s.length() - 1;

    while (i >= 0) {
        if (s[i] == ' ') {
            s[j] = '0';
            s[j-1] = '2';
            s[j-2] = '%';

            j = j-3; i--;
        }
        else {
            s[j--] = s[i--];
        }
    }
}

int main() {

    string s = "Hello world";

    cout << s << endl;
    replaceSpace(s);
    cout << s << endl;
    
    return 0;
}
