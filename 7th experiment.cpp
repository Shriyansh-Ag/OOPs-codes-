//Write a program to demonstrate the use of special functions, 
constructor and destructor in the class template. T
he program is used to find the bigger of two entered numbers.







#include <iostream>
using namespace std;

// Class template definition
template <typename T>
class Compare {
private:
    T num1, num2;

public:
    // Constructor to initialize the values
    Compare(T a, T b) {
        num1 = a;
        num2 = b;
        cout << "Constructor called! Numbers initialized." << endl;
    }

    // Destructor to handle cleanup
    ~Compare() {
        cout << "Destructor called! Cleaning up." << endl;
    }

    // Function to find the bigger number
    T findBigger() {
        return (num1 > num2) ? num1 : num2;
    }

    // Function to display the numbers
    void display() {
        cout << "Number 1: " << num1 << endl;
        cout << "Number 2: " << num2 << endl;
    }
};

int main() {
    // Creating an object of class Compare to find the larger of two integers
    Compare<int> intCompare(10, 20);
    intCompare.display();
    cout << "Bigger of the two integers: " << intCompare.findBigger() << endl;

    // Creating an object of class Compare to find the larger of two floats
    Compare<float> floatCompare(10.5f, 20.3f);
    floatCompare.display();
    cout << "Bigger of the two floats: " << floatCompare.findBigger() << endl;

    return 0;
}
