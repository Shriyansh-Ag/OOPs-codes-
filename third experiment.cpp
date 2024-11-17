
Write a program to find the greatest of two given numbers in two different classes using friend function.



#include <iostream>
using namespace std;

// Forward declaration of ClassB
class ClassB;

// ClassA definition
class ClassA {
private:
    int numA;

public:
    // Constructor to initialize numA
    ClassA(int a) : numA(a) {}

    // Friend function declaration
    friend int findGreatest(ClassA, ClassB);
};

// ClassB definition
class ClassB {
private:
    int numB;

public:
    // Constructor to initialize numB
    ClassB(int b) : numB(b) {}

    // Friend function declaration
    friend int findGreatest(ClassA, ClassB);
};

// Friend function definition to find the greatest of two numbers
int findGreatest(ClassA objA, ClassB objB) {
    // Comparing the numbers from both classes
    if (objA.numA > objB.numB) {
        return objA.numA;  // Return numA if it's greater
    } else {
        return objB.numB;  // Return numB if it's greater or equal
    }
}

int main() {
    // Create objects of ClassA and ClassB
    ClassA objA(10);
    ClassB objB(20);

    // Call the friend function to find the greatest number
    int greatest = findGreatest(objA, objB);

    // Output the greatest number
    cout << "The greatest number is: " << greatest << endl;

    return 0;
}
