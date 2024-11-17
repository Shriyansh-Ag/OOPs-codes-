//Write a program to perform addition of two complex numbers using constructor overloading. 
The first constructor which takes no argument is used to create objects which are not initialized, 
second which takes one argument is used to initialize real and imag parts to equal values and third
 which takes two argument is used to initialized real and imag to two different values

 #include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    // Default constructor (no arguments)
    Complex() {
        real = 0;
        imag = 0;
    }

    // Constructor with one argument (initializes real and imag to the same value)
    Complex(float value) {
        real = value;
        imag = value;
    }

    // Constructor with two arguments (initializes real and imag to different values)
    Complex(float r, float i) {
        real = r;
        imag = i;
    }

    // Function to add two complex numbers
    Complex add(const Complex &other) {
        float sumReal = real + other.real;
        float sumImag = imag + other.imag;
        return Complex(sumReal, sumImag); // Return the result as a new Complex object
    }

    // Function to display the complex number
    void display() {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main() {
    // Creating objects using different constructors
    Complex c1;                 // Default constructor (0 + 0i)
    Complex c2(5);              // Constructor with one argument (5 + 5i)
    Complex c3(3, 4);           // Constructor with two arguments (3 + 4i)

    // Display the complex numbers
    cout << "Complex number c1: ";
    c1.display();
    
    cout << "Complex number c2: ";
    c2.display();
    
    cout << "Complex number c3: ";
    c3.display();

    // Adding two complex numbers
    Complex sum = c2.add(c3);
    cout << "Sum of c2 and c3: ";
    sum.display();

    return 0;
}
