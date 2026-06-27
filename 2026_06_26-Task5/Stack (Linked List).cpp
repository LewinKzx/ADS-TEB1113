#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
    string name;
    Stack* next;

    // This pointer will always point to the top of the stack
    Stack* top = nullptr;

    // Push: insert new node at the top
    void push(string name) {
        Stack* newNode = new Stack();

        newNode->name = name;
        newNode->next = top;
        top = newNode;
    }

    // Pop: delete the top node
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        Stack* temp = top;
        cout << "Popped: " << top->name << endl;

        top = top->next;
        delete temp;
    }

    // Peek: show the top node
    void peek() {
        if (top == nullptr) {
            cout << "Stack is empty. Nothing to peek." << endl;
            return;
        }

        cout << "Top element: " << top->name << endl;
    }

    // Display: show stack from top to bottom
    void display_stack() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }

        Stack* display_node = top;

        while (display_node != nullptr) {
            cout << display_node->name << endl;
            display_node = display_node->next;
        }
    }
};

int main() {
    Stack* stack = new Stack();

    stack->push("A");
    stack->push("B");
    stack->push("C");
    stack->push("D");

    cout << "Stack after push:" << endl;
    stack->display_stack();

    cout << "\nPeek:" << endl;
    stack->peek();

    cout << "\nPop:" << endl;
    stack->pop();

    cout << "\nStack after pop:" << endl;
    stack->display_stack();

    return 0;
}