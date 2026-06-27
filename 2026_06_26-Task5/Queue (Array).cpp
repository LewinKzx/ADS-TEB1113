#include <iostream>
#include <string>
using namespace std;

class Queue {
public:
    string arr[5];
    int front;
    int rear;
    int size;

    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    // Enqueue: insert at the rear
    void enqueue(string name) {
        if (size == 5) {
            cout << "Queue is full. Cannot enqueue " << name << endl;
            return;
        }

        rear++;
        arr[rear] = name;
        size++;
    }

    // Dequeue: remove from the front
    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;

        front++;
        size--;
    }

    // Peek: show front element
    void peek() {
        if (size == 0) {
            cout << "Queue is empty. Nothing to peek." << endl;
            return;
        }

        cout << "Front element: " << arr[front] << endl;
    }

    // Display queue from front to rear
    void display() {
        if (size == 0) {
            cout << "Queue is empty." << endl;
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << endl;
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