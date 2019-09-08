// Question 1.5
// Write a method to replace all spaces in a string with ‘%20’.

#include <iostream>

using namespace std;

const int MAX = 100;

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

void replaceSpace_cString(char* s) {
    char* i = s;
    int noOfSpaces = 0, length = 0;

    // Get the length of string & no of space occurences
    while (*i) { // This will only return false if i is pointing to null which is where a string terminates
        if(*i == ' ') noOfSpaces++;
        length++;
        i++;
    }

    // Calculate the new length of string when ' ' is replaced by '%20'
    int newLength = length + noOfSpaces * 2;

    // Case where new length is greater than max amount of character that was set
    if (newLength > MAX) {
        cout << "String exceeds the max limit of char" << endl;
        return;
    }

    s[newLength] = '\0'; // The new termination of string
    length--;
    newLength--;

    // Starting from the end
    while(length >= 0) {
        if (s[length] == ' ') { // If char is space, replace with '&20'
            s[newLength] = '0';
            s[newLength-1] = '2';
            s[newLength-2] = '%';

            newLength = newLength-3; length--;
        }
        else {
            s[newLength--] = s[length--];
        }
    }
}

int main() {

    // string s = "Hello world";

    // cout << s << endl;
    // replaceSpace(s);
    // cout << s << endl;


    char str[MAX] = " Hello        ";
    cout << str << endl;
    replaceSpace_cString(str);
    cout << str << endl;

    
    return 0;
}
