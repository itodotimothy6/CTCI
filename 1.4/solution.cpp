// Question 1.4
// Write a method to decide if two strings are anagrams or not.


#include <iostream>
#include <string>
using namespace std;

bool areAnagrams(string one, string two){
	if(one.length() != two.length())
		return false;
	else{
		int anagram[26];
		for(int i = 0; i < 26; i++)
			anagram[i] = 0;
		bool isAnagram = true;
		
		for(int i = 0; i < one.length(); i++)
			anagram[one[i] - 'a']++;
		for(int i = 0; i < two.length(); i++)
			anagram[two[i] - 'a']--;
		for(int i = 0; i < two.length(); i++)
		{
			if(anagram[one[i] - 'a'] > 0 )
				isAnagram = false;
		}
		return isAnagram;
	}
}

int main(){
	string one = "saecm", two = "semca";
	cout << "IsAnagrams: " << areAnagrams(one, two);
	
}


