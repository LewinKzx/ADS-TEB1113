#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
    string arr[5];   // stack can store maximum 5 names
    int top;

    Stack() {
        top = -1;    // -1 means stack is empty
    }

    // Push: add new item to the top
    void push(string name) {
        if (top == 4) {
            cout << "Stack is full. Cannot push " << name << endl;
            return;
        }

        top++;
        arr[top] = name;
    }

    // Pop: remove top item
    void pop() {
        if (top == -1) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        cout << "Popped: " << arr[top] << endl;
        top--;
    }

    // Peek: show top item without removing
    void peek() {
        if (top == -1) {
            cout << "Stack is empty. Nothing to peek." << endl;
            return;
        }

        cout << "Top element: " << arr[top] << endl;
    }

    // Display stack from top to bottom
    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Stack stack;

    stack.push("Anjana");
    stack.push("Aimar");
    stack.push("Ahmed");

    cout << "Stack from top to bottom:" << endl;
    stack.display();

    cout << "\nPeek operation:" << endl;
    stack.peek();

    cout << "\nPop operation:" << endl;
    stack.pop();

    cout << "\nStack after pop:" << endl;
    stack.display();

    cout << "\nPush operation done" << endl;
    stack.push("Aina");

    cout << "\nStack after push:" << endl;
    stack.display();
    
    cout << "\nPeek after pop:" << endl;
    stack.peek();

    return 0;
}