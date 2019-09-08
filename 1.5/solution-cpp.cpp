//solution to ctci exercise 1.5
//replace all the spaces in a string with "%20"
#include <iostream>
#include <string>
using namespace std;

void replace(string& word){
	for(int i = 0; i < word.length(); i++){
		char x = word[i];
		if(x == ' '){
			word.replace(i, 1, "%20");
		}
	}
}

int main() {
  string word = "my name is faruq";
  replace(word);
  cout << word;
}
