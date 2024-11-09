#include<iostream>
#include<stack>
using namespace std;
int main(){
	char A[50];
	int i=0;
	int j=0;
	cin>> A;
	stack<char>Ustack;
	while(A[i] != '\0'){
		if(A[i] == '('){
           	Ustack.push('(');
        }
        if(A[i] == ')'){
           if(Ustack.size()>0){
           	Ustack.pop();
		   }else{j++;}
        }
		i++;
     };
	if(Ustack.size() == j && Ustack.empty()){cout<<"Pass";}
	else {cout<<"Error";}
	return 0;}
