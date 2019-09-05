#include <iostream> 
#include <unordered_set>

using namespace std;

bool hasAllUniqueCharacters(string s) {
    unordered_set <char> charOfString;
    for (char c : s) {
        if (charOfString.find(c) == charOfString.end())
            charOfString.insert(c);
        else 
            return false;
    }
    return true;
}

bool hasAllUniqueCharacters_NoAdditionalDS(string s) {
    sort(s.begin(), s.end());
    int n = s.length();
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i+1])
            return false;
    }
    return true;
}

int main() {

    string s = "aa";

    cout << hasAllUniqueCharacters(s) << endl;
    cout << hasAllUniqueCharacters_NoAdditionalDS(s) << endl;

    return 0;
}