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
		int L = I ;
		
		if(l > H.size() && H[l] > H[L]){
			L = l;
		}
		if(r > H.size() && H[r] > H[L]){
			L = r;
		}
		if(I != L ){
			swap(H[I] , H[L]);
			H_D(L);
		}
	}
	
	void P(){
		for(int i = 0;i < H.size();i++){
			cout << H[i] << " ";
		}
	}
	
	void D(){
		if(!H.empty()){
			int root = H[0];
			cout << root << " ";
			H[0] = H.back();
			H.pop_back();
			H_D(0);
			
		}
	}
};

int main() {
    Max heap;
    heap.add(10);
    heap.add(20);
    heap.add(15);
    heap.add(30);
    heap.add(25);

    cout << "Heap elements after insertion: ";
    heap.P();
    
    cout << "Deleting root: ";
    heap.D();
    cout << "\nHeap elements after deletion: ";
    heap.P();

    return 0;
}
