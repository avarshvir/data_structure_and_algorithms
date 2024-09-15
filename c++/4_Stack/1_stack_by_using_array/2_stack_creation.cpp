#include <iostream>
using namespace std;

#define MAX 100  // Define the maximum size of the stack

// Global variables
int stack[MAX];
int top = -1;
int n;  // Size of the stack

// Function prototypes
void push();
void pop();
bool isEmpty();
bool isFull();
void peek();
void show();
int size();  // New function to get the number of elements
void clear(); // New function to clear the stack

int main() {
    cout << "Enter the number of elements you want in the stack (max " << MAX << "): ";
    cin >> n;

    // Ensure the stack size does not exceed the maximum allowed
    if (n > MAX) {
        cout << "Stack size cannot exceed " << MAX << ". Setting stack size to " << MAX << "." << endl;
        n = MAX;
    }

    int choice = 0;

    while (choice != 8) {  // Updated exit option
        cout << "\nChoose one from the below options..." << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Show" << endl;
        cout << "4. Peek" << endl;
        cout << "5. Size" << endl; // New option for size
        cout << "6. Is Empty" << endl; // New option for isEmpty
        cout << "7. Is Full" << endl; // New option for isFull
        cout << "8. Exit" << endl; // Updated exit option
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                show();
                break;
            case 4:
                peek();
                break;
            case 5:
                cout << "Current size of the stack: " << size() << endl;
                break;
            case 6:
                cout << (isEmpty() ? "Stack is empty!" : "Stack is not empty!") << endl;
                break;
            case 7:
                cout << (isFull() ? "Stack is full!" : "Stack is not full!") << endl;
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}

void push() {
    int value;
    if (isFull()) {
        cout << "Stack overflow! Cannot push more elements." << endl;
    } else {
        cout << "Enter the value to push: ";
        cin >> value;
        stack[top+1] = value;
        cout << value << " pushed to stack" << endl;
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Stack underflow! Cannot pop." << endl;
    } else {
        cout << stack[top--] << " popped from stack" << endl;
    }
}

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == n - 1;  // Stack is full when top == n - 1
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Top element is: " << stack[top] << endl;
    }
}

void show() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack elements are:" << endl;
        for (int i = top; i >= 0; --i) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int size() {
    return top + 1;  // Top is zero-based, so the size is top + 1
}

void clear() {
    top = -1;  // Reset top to -1 to clear the stack
    cout << "Stack cleared!" << endl;
}
