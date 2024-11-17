Write a program to read the class object of student info such as name , age ,sex ,height 
and weight from the keyboard and to store them on a specified file using read() and write() 
functions. Again the same file is opened for reading and displaying the contents of the file on the screen.

#include <iostream>
#include <fstream>
#include <cstring> // For string manipulation
using namespace std;

class Student {
private:
    char name[50];
    int age;
    char sex;
    float height;
    float weight;

public:
    // Default constructor
    Student() : age(0), sex('M'), height(0.0f), weight(0.0f) {
        strcpy(name, "");  // Initialize name as an empty string
    }

    // Function to take input from user
    void input() {
        cout << "Enter name: ";
        cin.getline(name, 50);  // Read name as string
        
        cout << "Enter age: ";
        cin >> age;

        cout << "Enter sex (M/F): ";
        cin >> sex;

        cout << "Enter height (in meters): ";
        cin >> height;

        cout << "Enter weight (in kilograms): ";
        cin >> weight;

        // Clear the input buffer before using getline again
        cin.ignore();  // Ignore the newline character left in the input buffer
    }

    // Function to display the student's data
    void display() const {
        cout << "Student Info: \n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sex: " << sex << endl;
        cout << "Height: " << height << " meters" << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }

    // Function to write student data to a file
    void writeToFile(ofstream &outFile) {
        outFile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }

    // Function to read student data from a file
    void readFromFile(ifstream &inFile) {
        inFile.read(reinterpret_cast<char*>(this), sizeof(*this));
    }
};

int main() {
    Student student;
    
    // Get student info from user
    student.input();

    // Open file to write student info
    ofstream outFile("student_data.dat", ios::binary); // Open file in binary mode
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }
    
    // Write student data to the file
    student.writeToFile(outFile);
    outFile.close();  // Close the output file after writing

    // Open the file to read the data back
    ifstream inFile("student_data.dat", ios::binary); // Open file in binary mode
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }
    
    // Read student data from the file
    Student studentFromFile;
    studentFromFile.readFromFile(inFile);
    inFile.close();  // Close the input file after reading

    // Display the data read from the file
    cout << "\nData read from file:\n";
    studentFromFile.display();

    return 0;
}
