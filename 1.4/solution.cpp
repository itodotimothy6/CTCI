// Question 1.4
// Write a method to decide if two strings are anagrams or not.

#include <iostream>

bool areAnagrams(string word1, string word2)
{
    // Get the lengths of the two strings
    int len1 = word1.length();
    int len2 = word2.length();
    
    //This is checking if both strings are the same length and if not they cannot be anagrams
    if (len1 != len2){
        return false;
    }
    
    // using the sort method to sort both the strings after determining the length
    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());
    
    // This compares sorted strings to determine if they have the same letters
    for (int i = 0; i < len1; i++) {
        if (word1[i] != word2[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    string word1 = "time";
    string word2 = "mint";
    if (areAnagrams(word1, word2)){
        cout<<"Yes this strings are anagrams of each other \n";
    }
    else{
        cout<<"No they are not anagrams of each other \n";
    }
    
    return 0;
}
