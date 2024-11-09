#include <iostream>
using namespace std;

class MaxHeap {
    public:
        int array[100];
        int size = 0;

        void add(int data) {
            if (size < 100) {
                array[size++] = data;
                heapify_up(size - 1); 
            } else {
                cout << "Heap is full" << endl;
            }
        }

        void heapify_up(int index) {
            int parent = (index - 1) / 2;
            if (index > 0 && array[index] > array[parent]) {
                swap(array[index], array[parent]);
                heapify_up(parent);
            }
        }

        void heapify_down(int index) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && array[left] > array[largest]) {
                largest = left;
            }
            if (right < size && array[right] > array[largest]) {
                largest = right;
            }
            if (largest != index) {
                swap(array[index], array[largest]);
                heapify_down(largest);
            }
        }

        void print() {
            for (int z = 0; z < size; z++) {
                cout << array[z] << " ";
            }
            cout << endl;
        }

        void delete_root() {
            if (size == 0) {
                cout << "Heap is empty" << endl;
                return;
            }

            int root_value = array[0];
            cout << root_value << endl;

            array[0] = array[size - 1];
            size--;

            heapify_down(0);
        }
};

int main() {
    int data;
    char c;
    MaxHeap test;
    do {
        cin >> c;
        switch (c) {
            case 'a': {
                cin >> data;
                test.add(data);
                break;
            }
            case 'p': {
                test.print();
                break;
            }
            case 'd': {
                test.delete_root();
                break;
            }
            case 'e': {
                break;
            }
        }
    } while (c != 'e');

    return 0;
}

