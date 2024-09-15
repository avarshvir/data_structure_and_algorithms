#include <iostream>
#include <cstdio>  // Needed for printf

using namespace std;

void push();
void show();

int top = -1;
const int SIZE = 4;  // Define stack size
int stack[SIZE];

int main() {
    cout << "hello" << endl;
    push();
    show();  // Show the stack after pushing
    return 0;
}

void push() {
    int val;
    if (top == SIZE - 1) {  // Overflow check
        cout << "Stack overflow" << endl;
    } else {
        cout << "Enter value: ";
        cin >> val;
        top = top + 1;
        stack[top] = val;
    }
}

void show() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
