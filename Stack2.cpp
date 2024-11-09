#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> S) {
        stack<int> TS;
        while(!S.empty()){
        	TS.push(S.top());
        	S.pop();
			}
		while(!TS.empty()){
			cout << TS.top();
			TS.pop();
			if(!TS.empty()){
				cout << " ";
			}		}		
        cout << endl;
    }

int main (){
	stack<int> S;
	char N;
	bool T = true ;
	
	do{
		cin >> N;
		
		switch(N) {
			case 'U':
				int M;
					cin >> M;
					S.push(M);
				break;
			case 'O':
				if(!S.empty()){
				cout << S.top()<<endl;
				S.pop();
				}else{
					cout << "Stack is empty"<<endl;
				}
				break;
			case 'T':
				if(!S.empty()){
				cout << S.top()<<endl;
				}else{
					cout << "Stack is empty"<<endl;
				}
				break;
			case 'P':
				     print(S);
				break;
			case 'N':
					cout << S.size() <<endl;
				break;
			case 'X':
					T = false;
				break;	
		default:
			break;
		}
	}while(T);
	return 0;
}
