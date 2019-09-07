// Question 1.5
// Write a method to replace all spaces in a string with ‘%20’.

#include <iostream>

using namespace std;

void replaceSpace(char* str, int length) {
    int noOfSpaces = 0;

    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') noOfSpaces++;
    }

    int newLength = length + (noOfSpaces * 2);
    str[newLength] = '\0';

    for(int i = length - 1; i >= 0; i--) {
        if(str[i] == ' ') {
            
            str[newLength - 1] = '0';
            str[newLength - 2] = '2';
            str[newLength - 3] = '%';
            newLength = newLength - 3;
            
        }
        else {
            str[--newLength] = str[i];
        }
    }

}
int main() {
    char s[] = "my boy is good";

    replaceSpace(s, sizeof(s) - 1);
    cout << s << endl;

    return 0;
}
