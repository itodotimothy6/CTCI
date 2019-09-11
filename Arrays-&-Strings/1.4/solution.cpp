// Question 1.4
// Write a method to decide if two strings are anagrams or not.

#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    unordered_map<char, int> charMap;
    for (int i = 0; i < s1.length(); i++) {
        charMap[s1[i]]++;
    }
    for (int i = 0; i < s2.length(); i++) {
        charMap[s2[i]]--;
        if (charMap[s2[i]] == 0) charMap.erase(s2[i]);
    }

    return charMap.empty();
}

int main() {
    string s1 = "maddam";
    string s2 = "mfdadm";
    cout << isAnagram(s1, s2) << endl;

    return 0;
}