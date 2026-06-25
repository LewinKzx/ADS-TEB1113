#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node* prev;

    Node(string n) {
        name = n;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertEnd(string name) {
        Node* newNode = new Node(name);

        // If list is empty
        if (head == nullptr) {
            head = newNode;

            // Circular connection to itself
            newNode->next = head;
            newNode->prev = head;
            return;
        }

        // tail is the node before head
        Node* tail = head->prev;

        // Insert newNode after tail
        tail->next = newNode;
        newNode->prev = tail;

        // Make it circular
        newNode->next = head;
        head->prev = newNode;
    }

    void insertAfter(string afterName, string newName) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;

        do {
            if (current->name == afterName) {
                Node* newNode = new Node(newName);

                newNode->next = current->next;
                newNode->prev = current;

                current->next->prev = newNode;
                current->next = newNode;

                return;
            }

            current = current->next;

        } while (current != head);

        cout << afterName << " not found." << endl;
    }

    void deleteByName(string name) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;

        do {
            if (current->name == name) {

                // If there is only one node
                if (current->next == head && current->prev == head) {
                    delete current;
                    head = nullptr;
                    return;
                }

                // Connect previous node to next node
                current->prev->next = current->next;
                current->next->prev = current->prev;

                // If deleting head, move head to next node
                if (current == head) {
                    head = current->next;
                }

                delete current;
                return;
            }

            current = current->next;

        } while (current != head);

        cout << name << " not found." << endl;
    }

    void displayCircular() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;

        do {
            cout << current->name << " <-> ";
            current = current->next;
        } while (current != head);

        cout << head->name << endl;
    }
};

int main() {
    LinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

    cout << "Initial circular list:" << endl;
    list.displayCircular();

    list.insertAfter("Anjana", "Ali");
    cout << "\nAfter inserting Ali after Anjana:" << endl;
    list.displayCircular();

    list.insertEnd("Jade");
    cout << "\nAfter inserting Jade at the end:" << endl;
    list.displayCircular();

    list.deleteByName("Jessy");
    cout << "\nAfter deleting Jessy:" << endl;
    list.displayCircular();

    return 0;
}