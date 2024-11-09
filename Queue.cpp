#include <iostream>
using namespace std;

class Tata {
private:
    int arr[5];
    int tail = 0;
    int head = 0;
				//empty  full when tail - head = 5
public:
    void enqueue(int data) {
    	if(tail-head==5){
    		cout<<"stackfull"<<endl;
		}else if(tail==head&&head>0){
			tail=0;
			head=0;
		}else{
		    arr[tail%5] = data;
        	tail++;	
		}
    
    }

    void dequeue() {
        cout<< arr[head%5]<<endl;
        head++;
    }
    void show(){
    	for(int i=head;i<tail;i++){
    		cout<< arr[i]<<" ";
		}
		cout << endl;
	}
	int size(){
		return tail;
	}
	void showfl(){
		cout << arr[head] <<" "<< arr[tail-1] << endl;
	}
};

int main() {
char c;
int data;
Tata test;
do{
	cin >> c;
	switch(c){
		case 'e':{
			cin >> data;
			test.enqueue(data);
			break;
		}
		case 'd':{
			test.dequeue();
			break;
		}
		case 'p':{
			test.show();
			break;
	}
		case 'n':{
			cout << test.size() <<endl;
			break;
		}
		case 's':{
			test.showfl();
			break;
		}
}
}while(c!='x');
    
    return 0;
}

