#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = nullptr;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue: insert at the rear/end
    void enqueue(string name) {
        Node* newNode = new Node(name);

        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue: remove from the front
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node* temp = front; // * is pointer and temp is temporary
        cout << "Dequeued: " << temp->name << endl;

        front = front->next; // front goes to next name

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp; // delete initial front node to free memory
    }

    // Peek: show front element without removing
    void peek() {
        if (front == nullptr) {
            cout << "Queue is empty. Nothing to peek." << endl;
            return;
        }

        cout << "Front element: " << front->name << endl;
    }

    // Display queue from front to rear
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;

        while (current != nullptr) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

int main() {
    Queue queue;

    queue.enqueue("Anjana");
    queue.enqueue("Aimar");
    queue.enqueue("Ahmed");

    cout << "Queue from front to rear:" << endl;
    queue.display();

    cout << "\nPeek operation:" << endl;
    queue.peek();

    cout << "\nDequeue operation:" << endl;
    queue.dequeue();

    cout << "\nQueue after dequeue:" << endl;
    queue.display();

    cout << "\nPeek after dequeue:" << endl;
    queue.peek();

    return 0;
}