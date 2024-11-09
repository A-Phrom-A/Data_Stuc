#include <iostream>
#include <vector>  // Include the vector header for dynamic array
#include <algorithm>  // Include algorithm for std::swap
using namespace std;

class MaxHeap {
public:
    vector<int> heap;  // Use vector to store the heap elements

    // Function to add an element to the heap
    void add(int data) {
        heap.push_back(data);  // Add the new element to the end of the vector
        heapify_up(heap.size() - 1);  // Maintain the heap property
    }

    // Function to maintain the heap property after adding an element
    void heapify_up(int index) {
        int parent = (index - 1) / 2;  // Calculate the index of the parent
        // If the current node is greater than its parent, swap them
        if (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);  // Swap with parent
            heapify_up(parent);  // Recursively heapify up the tree
        }
    }

    // Function to maintain the heap property after deleting the root
    void heapify_down(int index) {
        int left = 2 * index + 1;  // Calculate the index of the left child
        int right = 2 * index + 2;  // Calculate the index of the right child
        int largest = index;  // Assume the largest is the current index

        // Update largest if the left child is greater
        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;  // Update largest
        }
        // Update largest if the right child is greater
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;  // Update largest
        }
        // If the largest is not the current index, swap and heapify down
        if (largest != index) {
            swap(heap[index], heap[largest]);  // Swap with largest
            heapify_down(largest);  // Recursively heapify down the tree
        }
    }

    // Function to print the contents of the heap
    void print() {
        cout << "Heap contents: ";
        for (int value : heap) {
            cout << value << " ";  // Print each element in the heap
        }
        cout << endl;
    }

    // Function to delete the root of the heap
    void delete_root() {
        if (heap.empty()) {  // Check if the heap is empty
            cout << "Heap is empty" << endl;
            return;
        }

        int root_value = heap[0];  // Get the root value to print
        cout << "Deleted root value: " << root_value << endl;

        heap[0] = heap.back();  // Move the last element to the root
        heap.pop_back();  // Remove the last element
        heapify_down(0);  // Maintain the heap property
    }
};

int main() {
    int data;
    char c;
    MaxHeap test;  // Create an instance of MaxHeap

    // Command loop for user interaction
    do {
        cout << "Enter command (a: add, p: print, d: delete root, e: exit): ";
        cin >> c;
        switch (c) {
            case 'a': {  // Case for adding a new value
                cout << "Enter value to add: ";
                cin >> data;
                test.add(data);  // Call the add function
                break;
            }
            case 'p': {  // Case for printing the heap
                test.print();  // Call the print function
                break;
            }
            case 'd': {  // Case for deleting the root
                test.delete_root();  // Call the delete function
                break;
            }
            case 'e': {  // Case for exiting the program
                cout << "Exiting..." << endl;
                break;
            }
            default:  // Invalid command
                cout << "Invalid command!" << endl;
                break;
        }
    } while (c != 'e');  // Continue until the user chooses to exit

    return 0;
}

