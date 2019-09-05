#include <iostream>
using namespace std;

// // Code in main without using functions
// int main() {
//     char str[255];

//     while (true) {
//         cout << "Enter a string: ";
//         cin.getline(str, 255);

//         int i = 0;
//         int j = strlen(str) - 1;

//         while (i < j) {
//             char temp = str[i];
//             str[i++] = str[j];
//             str[j--] = temp;
//         }

//         cout << "Ans: " << str << endl;
//     }
//     return 0;
// }

// Using Function
void reverseString(char* str) {
    // Find end of char array
    char* end = str;
    while(*end) {
        end++;
    }
    end--; // Ignore the null char
    
    while(str < end) {
        char temp = *str;
        *(str++) = *end;
        *(end--) = temp;
    }
}

// For testing
int main() {
    char str[255];

    while(true) {
        cout << "Enter a string: ";
        cin.getline(str, 255);

        reverseString(str);
        cout << "Ans: " << str << endl;
    }
    return 0;
}
