#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    unordered_map<char, int> charSet;
    for (int i = 0; i < s1.length(); i++) {
        charSet[s1[i]]++;
    }
    for (int i = 0; i < s2.length(); i++) {
        charSet[s2[i]]--;
        if (charSet[s2[i]] == 0) charSet.erase(s2[i]);
    }

    return charSet.empty();
}

int main() {
    string s1 = "maddam";
    string s2 = "mfdadm";
    cout << isAnagram(s1, s2) << endl;

    return 0;
}