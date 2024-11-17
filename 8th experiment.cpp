Write a program to perform the deletion of white spaces such as horizontal tab, 
vertical tab, space ,line feed ,new line and carriage return from a text file 
and store the contents of the file without the white spaces on another file.


#include <iostream>
#include <fstream>
#include <cctype>  // For checking characters

using namespace std;

// Function to remove whitespace characters from a text file
void removeWhitespace(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);  // Open the input file for reading
    ofstream outFile(outputFile); // Open the output file for writing

    // Check if the input file was opened successfully
    if (!inFile) {
        cout << "Error opening input file!" << endl;
        return;
    }

    // Check if the output file was opened successfully
    if (!outFile) {
        cout << "Error opening output file!" << endl;
        return;
    }

    char ch;
    
    // Read each character from the input file
    while (inFile.get(ch)) {
        // Check if the character is a whitespace that should be removed
        if (!isspace(ch) && ch != '\r') {
            outFile.put(ch); // Write the non-whitespace character to the output file
        }
    }

    // Close both files
    inFile.close();
    outFile.close();

    cout << "Whitespace characters removed and saved to " << outputFile << endl;
}

int main() {
    string inputFile = "input.txt";   // Name of the input file
    string outputFile = "output.txt"; // Name of the output file

    // Call the function to remove whitespace and write to the output file
    removeWhitespace(inputFile, outputFile);

    return 0;
}
