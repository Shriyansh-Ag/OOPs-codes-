Write a program to define the function template for calculating the square of given numbers with different data types.




#include <iostream>
using namespace std;

// Function template to calculate the square of a number
template <typename T>
T square(T num) {
    return num * num;  // Return the square of the number
}

int main() {
    // Call the square function with different data types
    
    int intNum = 5;
    float floatNum = 5.5;
    double doubleNum = 9.8;

    cout << "Square of " << intNum << " (int): " << square(intNum) << endl;
    cout << "Square of " << floatNum << " (float): " << square(floatNum) << endl;
    cout << "Square of " << doubleNum << " (double): " << square(doubleNum) << endl;

    return 0;
}
