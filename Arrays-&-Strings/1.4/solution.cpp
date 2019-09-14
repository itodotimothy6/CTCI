// Question 1.4
// Write a method to decide if two strings are anagrams or not.

#include <iostream>
#include <string>
using namespace std;

bool areAnagrams(string one, string two)
{
    //return false if the lengths are different
	if(one.length() != two.length())
		return false;
	else{
		//create an array of 128 ints  -- number of ascii characters
		int characters[128];
		for(int i = 0; i < 128; i++)
			characters[i] = 0; //initialise all elements to 0
		bool valid = true;
		
		//for every element in the first string, increase the
		// corresponding int by 1
		for(int i = 0; i < one.length(); i++)
			characters[one[i]]++;
		//reduce by one for every element in the second string
		for(int i = 0; i < two.length(); i++)
			characters[two[i]]--;
		//set valid to false if there is a int that's not equal 0
		//among the ints that were used.
		for(int i = 0; i < two.length(); i++)
		{
			if(characters[one[i]] > 0 )
				valid = false;
		}
		return valid;
	}
}

int main()
{
    string one = "saecm", two = "semca";
    cout << "IsAnagrams: " << areAnagrams(one, two);
}
