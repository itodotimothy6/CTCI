// Question 1.8
// Assume you have a method isSubstring which checks if one word is a substring of
// another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using
// only one call to isSubstring (i.e., “waterbottle” is a rotation of “erbottlewat”).

#include <iostream>

using namespace std;

bool isSubstring(string s1, string s2) {
    if(s1 == s2) return true;
    if(s2.length() > s1.length()) return false;

    for (int i = 0; i <= s1.length()-s2.length(); i++) {
        if(s2[0] == s1[i]) {
            if (s1.length() - i >= s2.length()) {
                int k = 0;
                int j;
                for (j = i; j < i + s2.length(); j++) {
                    if(s2[k++] != s1[j]) break;
                }
                if (j ==  i + s2.length()) return true;
            }
        }
    }

    return false;
}

bool isRotation(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    s1 += s1;

    if(isSubstring(s1, s2)) return true;
    return false;
}

int main() {
    string s1 = "Hello", s2 = "oHell";

    cout << isRotation(s1, s2) << endl;

    return 0;
}