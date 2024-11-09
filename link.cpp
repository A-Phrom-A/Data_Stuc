#include <iostream>

using namespace std;

class Node {
public:
    int id;
    int data;
    Node* next;

    Node(int id, int data) : id(id), data(data), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

    // Utility function to print the linked list
    void printList() {
        Node* node = head;
        while (node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

public:
    LinkedList() : head(NULL) {}

    // Insert a new node before a node with the given ID
    void insertBefore(int id, int newData) {
        Node* newNode = new Node(-1, newData); // Temp ID, we set it later
        if (head == NULL) {
            // List is empty, add new node as the only node
            head = newNode;
        } else if (head->id == id) {
            // Insert before the head node
            newNode->next = head;
            head = newNode;
        } else {
            // Find the node to insert before
            Node* current = head;
            while (current->next != NULL && current->next->id != id) {
                current = current->next;
            }
            if (current->next != NULL) {
                newNode->next = current->next;
                current->next = newNode;
            } else {
                // If ID not found, add to the end
                current->next = newNode;
            }
        }
        // Assign the ID after insertion
        newNode->id = newData;
        printList();
    }

    // Insert a new node after a node with the given ID
    void insertAfter(int id, int newData) {
        Node* newNode = new Node(-1, newData); // Temp ID, we set it later
        Node* current = head;
        while (current != NULL && current->id != id) {
            current = current->next;
        }
        if (current != NULL) {
            newNode->next = current->next;
            current->next = newNode;
        } else {
            // If ID not found, add to the end
            if (head == NULL) {
                head = newNode;
            } else {
                Node* last = head;
                while (last->next != NULL) {
                    last = last->next;
                }
                last->next = newNode;
            }
        }
        // Assign the ID after insertion
        newNode->id = newData;
        printList();
    }

    // Delete a node with the given ID
    void deleteNode(int id) {
        if (head == NULL) {
            return;
        }

        if (head->id == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            printList();
            return;
        }

        Node* current = head;
        while (current->next != NULL && current->next->id != id) {
            current = current->next;
        }
        if (current->next != NULL) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            printList();
        }
    }
};

int main() {
    LinkedList list;
    char command;
    int id, data;

    while (true) {
        cin >> command;
        if (command == 'E') {
            break;
        }
        cin >> id >> data;

        switch (command) {
            case 'I':
                list.insertBefore(id, data);
                break;
            case 'A':
                list.insertAfter(id, data);
                break;
            case 'D':
                list.deleteNode(id);
                break;
            default:
                cout << "Invalid command" << endl;
                break;
        }
    }

    return 0;
}

