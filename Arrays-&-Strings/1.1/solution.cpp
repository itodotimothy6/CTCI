// Question 1.1
// Implement an algorithm to determine if a string has all unique characters. What if you
// can not use additional data structures?

#include <iostream> 
#include <unordered_set>
#include <vector>

using namespace std;

// No DS
// O(nlogn)
bool hasAllUniqueCharacters_NoDS(string s) {
    sort(s.begin(), s.end());
    int n = s.length();
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i+1])
            return false;
    }
    return true;
}

// Using Set DS
// O(n)
bool hasAllUniqueCharacters_Set(string s) {
    unordered_set <char> charSet;

    for (char c : s) {
        if (charSet.find(c) != charSet.end()) 
            return false;
        charSet.insert(c);
    }

    return true;
}

// Using array of bool as set
// O(n)
bool hasAllUniqueCharacters(string s) {
    if (s.length() > 128) return false;

    vector <bool> charSet(128);
    for (int i = 0; i < s.length(); i++) {
        int asciiNum = s[i];
        if(charSet[asciiNum]) 
            return false;
        charSet[asciiNum] = true;
    }

    return true;
}

int main() {

    // vector<string> test_strings = {"aple", "apple", "a", "", "\taewer\t"}; c++ 11 supported
    vector<string> test_strings;
    test_strings.push_back("aple");
    test_strings.push_back("apple");
    test_strings.push_back("a");
    test_strings.push_back("");
    test_strings.push_back("\taewer\t");

    for (string s : test_strings) {
        cout << "\n" + s << endl;
        cout << hasAllUniqueCharacters_NoDS(s) << endl;
        cout << hasAllUniqueCharacters_Set(s) << endl;
        cout << hasAllUniqueCharacters(s) << endl;
    }

    return 0;
}
