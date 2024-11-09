#include<iostream>
#include<vector>
using namespace std;

class Max{
	public :
		vector<int> H;
		
	void add(int D){
		H.push_back(D);
		H_UP(H.size()-1);
	}
	
	void H_UP(int I){
		int P = (I-1)/2;
		
		if(I > 0 && H[I] > H[P]){
			swap(H[I] , H[P]);
			H_UP(P);
		}
	}
	
	void H_D(int I){
		int l = 2*I+1;
		int r = 2*I+2;
		int L = l;
		
		if(l < H.size() && H[l] > H[L]){
			L = l ;
		}
		if(r < H.size() && H[r] > H[L]){
			L = r ;
		}
		if(I != L){
			swap(H[L],H[I]);
			H_D(L);
		}
	}
	
	void P(){
		for (int i = 0;i < H.size();i++){
			cout << H[i] << " ";
		}	
	}
	
	void D(){
		if(!H.empty()){
			int root = H[0];
			cout << root;
			H[0] = H.back();
			H.pop_back();
			H_D(0);
		}
	}
};

int main() {
    int data;
    char c;
    Max test;  // Create an instance of MaxHeap

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
                test.P();  // Call the print function
                break;
            }
            case 'd': {  // Case for deleting the root
                test.D();  // Call the delete function
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

