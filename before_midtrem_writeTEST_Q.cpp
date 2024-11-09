#include<iostream>
#include<Queue>
using namespace std;

class P{
	public:
		int pid;
		int at;
		int st;
};
// lifo -> stack
// fifo -> Queue
int main (){
	P pc[100];
	int n;
	cin >> n;
	for(int i =0;i < n ;i++){
		cin >> pc[i].pid;
		cin >> pc[i].at;
		cin >> pc[i].st;
		}
	int Cp = 0;
	int T = 0;
	bool R = false;
	
	queue<P> QP;
	P C;	
	
	while(Cp < n){
		for(int i =0; i < n;i++){
			if(pc[i].at == T){
				QP.push(pc[i]);
			}
		}
		if(!R){
			if(!QP.empty()){
				C = QP.front();
				QP.pop();
				R = true;
			}
		}
		if(R){
			cout << C.pid << " : " << C.st<< endl;
			C.st--;
			if(C.st == 0){
				R = false;
				Cp++;
			}
		}
		T++;
		
	}
}
