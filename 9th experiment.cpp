//Write a program to raise an exception if any attempt is made to refer to an element whose index is beyond the array size.



#include <iostream>
#include <stdexcept> // For std::out_of_range
using namespace std;

class Array {
private:
    int* arr;
    int size;

public:
    // Constructor to initialize array of given size
    Array(int s) : size(s) {
        arr = new int[size]; // Dynamically allocate memory for array
        for (int i = 0; i < size; ++i) {
            arr[i] = i + 1;  // Initialize array with values 1, 2, 3, ...
        }
    }

    // Destructor to free allocated memory
    ~Array() {
        delete[] arr;
    }

    // Function to access the element at a given index
    int getElement(int index) {
        // Check if index is out of bounds
        if (index < 0 || index >= size) {
            // If index is invalid, throw an out_of_range exception
            throw out_of_range("Index out of bounds!");
        }
        return arr[index]; // Return the element if index is valid
    }

    // Function to display the array
    void display() {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    try {
        // Create an array of size 5
        Array myArray(5);

        // Display the array
        cout << "Array elements: ";
        myArray.display();

        // Attempt to access an element within the bounds
        int validIndex = 2; // Valid index
        cout << "Element at index " << validIndex << ": " << myArray.getElement(validIndex) << endl;

        // Attempt to access an element beyond the bounds
        int invalidIndex = 10; // Invalid index
        cout << "Element at index " << invalidIndex << ": " << myArray.getElement(invalidIndex) << endl;

    } catch (const out_of_range& e) {
        // Catch the out_of_range exception and print the error message
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
