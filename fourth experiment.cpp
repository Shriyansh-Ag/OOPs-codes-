//Implement a class string containing the following functions:

a. Overload + operator to carry out the concatenation of strings.
b. Overload = operator to carry out string copy.
c. Overload <= operator to carry out the comparison of strings.
d. Function to display the length of a string.
e. Function tolower( ) to convert upper case letters to lower case.
f. Function toupper( ) to convert lower case letters to upper case.


#include <iostream>
#include <cstring>  // For strlen and strcpy
#include <cctype>   // For tolower and toupper

using namespace std;

class String {
private:
    char* str;  // Pointer to dynamically allocated memory for the string

public:
    // Constructor
    String(const char* s = "") {
        str = new char[strlen(s) + 1]; // Allocate memory
        strcpy(str, s); // Copy the input string
    }

    // Destructor to free memory
    ~String() {
        delete[] str; // Free the allocated memory
    }

    // Overload + operator to concatenate two strings
    String operator+(const String& other) {
        char* result = new char[strlen(str) + strlen(other.str) + 1]; // Allocate memory for concatenated string
        strcpy(result, str); // Copy the first string
        strcat(result, other.str); // Concatenate the second string

        String temp(result); // Create a new String object with the result
        delete[] result; // Free the temporary result array
        return temp;
    }

    // Overload = operator for string copy
    String& operator=(const String& other) {
        if (this != &other) { // Check for self-assignment
            delete[] str; // Free the old memory
            str = new char[strlen(other.str) + 1]; // Allocate new memory
            strcpy(str, other.str); // Copy the string
        }
        return *this; // Return the current object to allow chain assignment
    }

    // Overload <= operator to compare two strings
    bool operator<=(const String& other) const {
        return strcmp(str, other.str) <= 0; // Lexicographical comparison
    }

    // Function to display the length of the string
    int length() const {
        return strlen(str); // Return the length of the string
    }

    // Function to convert the string to lowercase
    void tolowercase() {
        for (int i = 0; str[i] != '\0'; i++) {
            str[i] = tolower(str[i]); // Convert each character to lowercase
        }
    }

    // Function to convert the string to uppercase
    void touppercase() {
        for (int i = 0; str[i] != '\0'; i++) {
            str[i] = toupper(str[i]); // Convert each character to uppercase
        }
    }

    // Function to display the string
    void display() const {
        cout << str << endl;
    }
};

int main() {
    // Create and display some string objects
    String str1("Hello");
    String str2("World");

    // Display initial strings
    cout << "String 1: ";
    str1.display();
    cout << "String 2: ";
    str2.display();

    // Concatenate strings using overloaded + operator
    String str3 = str1 + str2;
    cout << "Concatenated String: ";
    str3.display();

    // Copy string using overloaded = operator
    String str4;
    str4 = str3;
    cout << "Copied String: ";
    str4.display();

    // Compare strings using overloaded <= operator
    if (str1 <= str2) {
        cout << "String 1 is lexicographically less than or equal to String 2." << endl;
    } else {
        cout << "String 1 is lexicographically greater than String 2." << endl;
    }

    // Display length of the string
    cout << "Length of String 3: " << str3.length() << endl;

    // Convert to lowercase and display
    str3.tolowercase();
    cout << "String 3 in lowercase: ";
    str3.display();

    // Convert to uppercase and display
    str3.touppercase();
    cout << "String 3 in uppercase: ";
    str3.display();

    return 0;
}



