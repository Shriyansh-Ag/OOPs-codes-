Create a class called LIST with two pure virtual function store() and retrieve().
To store a value call store and to retrieve call retrieve function. 
Derive two classes stack and queue from it and override store and retrieve.


#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Abstract base class LIST with pure virtual functions
class LIST {
public:
    virtual void store(int value) = 0;    // Pure virtual function to store value
    virtual int retrieve() = 0;            // Pure virtual function to retrieve value
    virtual ~LIST() {}                      // Virtual destructor
};

// Derived class Stack
class Stack : public LIST {
private:
    stack<int> s;  // Internal stack to store integers

public:
    // Override store() to push a value onto the stack
    void store(int value) override {
        s.push(value);
        cout << "Stored in Stack: " << value << endl;
    }

    // Override retrieve() to pop and return the top value from the stack
    int retrieve() override {
        if (s.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;  // Return -1 if stack is empty
        } else {
            int value = s.top();
            s.pop();
            cout << "Retrieved from Stack: " << value << endl;
            return value;
        }
    }
};

// Derived class Queue
class Queue : public LIST {
private:
    queue<int> q;  // Internal queue to store integers

public:
    // Override store() to enqueue a value into the queue
    void store(int value) override {
        q.push(value);
        cout << "Stored in Queue: " << value << endl;
    }

    // Override retrieve() to dequeue and return the front value from the queue
    int retrieve() override {
        if (q.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;  // Return -1 if queue is empty
        } else {
            int value = q.front();
            q.pop();
            cout << "Retrieved from Queue: " << value << endl;
            return value;
        }
    }
};

int main() {
    // Create instances of Stack and Queue
    Stack stackObj;
    Queue queueObj;

    // Store values in the stack and queue
    stackObj.store(10);
    stackObj.store(20);
    stackObj.store(30);

    queueObj.store(100);
    queueObj.store(200);
    queueObj.store(300);

    // Retrieve values from the stack and queue
    stackObj.retrieve();  // Should retrieve 30 (LIFO)
    stackObj.retrieve();  // Should retrieve 20 (LIFO)
    stackObj.retrieve();  // Should retrieve 10 (LIFO)

    queueObj.retrieve();  // Should retrieve 100 (FIFO)
    queueObj.retrieve();  // Should retrieve 200 (FIFO)
    queueObj.retrieve();  // Should retrieve 300 (FIFO)

    return 0;
}

