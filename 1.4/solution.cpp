// Question 1.4
// Write a method to decide if two strings are anagrams or not.


#include <iostream>
#include <string>
using namespace std;

bool areAnagrams(string one, string two){
	if(one.length() != two.length())
		return false;
	else{
		int characters[128];
		for(int i = 0; i < 128; i++)
			characters[i] = 0;
		bool valid = true;
		
		for(int i = 0; i < one.length(); i++)
			characters[one[i]]++;
		for(int i = 0; i < two.length(); i++)
			characters[two[i]]--;
		for(int i = 0; i < two.length(); i++)
		{
			if(characters[one[i]] > 0 )
				valid = false;
		}
		return valid;
	}
}

int main(){
	string one = "saecm", two = "semca";
	cout << "IsAnagrams: " << areAnagrams(one, two);
	
}


