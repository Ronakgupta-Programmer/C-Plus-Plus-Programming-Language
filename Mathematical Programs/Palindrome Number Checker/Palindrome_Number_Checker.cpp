#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Function to check if a string is a palindrome
bool isPalindrome(string str) {
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        // Ignore non-alphanumeric characters and check equality
        while (start < end && !isalnum(str[start])) start++;
        while (start < end && !isalnum(str[end])) end--;

        if (tolower(str[start]) != tolower(str[end]))
            return false;

        start++;
        end--;
    }
    return true;
}

int main() {
    string str;

    cout << "--- Palindrome Checker ---" << endl;
    cout << "Enter a string: ";
    getline(cin, str);

    if (isPalindrome(str)) {
        cout << "\"" << str << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << str << "\" is not a palindrome." << endl;
    }

    return 0;
}
