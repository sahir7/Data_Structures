#include<iostream>

using namespace std;


class Stack{
	public:
	int n=100;
        int a[100];	
        int in=-1;	
	bool empty(){
		if(in==-1){
			return true;
		}
		else{
			return false;
		}
	}
	void push(int val){
		if(in< n){
			in+=1;
			a[in]=val;
		}
		else{
		cout<<"stack is full"<<endl;
		}
	}
	void pop(){
		if(in==-1){
			cout<<"stack is empty"<<endl;
		}
		else{
			a[in]=-1;
			in-=1;
		}
	}
	void top(){
		if (in==-1){
			cout<<-1<<endl;
		}
		else{
			cout<<a[in]<<endl;
		}
	}

	void find(int val){
		int p=1;
		if(in==-1){
			cout<<"not found"<<endl;
		}
		else{
			int i=in;
			while(i >=0){
				if(a[i]==val){
					cout<<"found at"<<i<<endl;
					p=0;
				}
				i--;
			}
			if(p){
				cout<<"Not found"<<endl;
			}
		}
	}

		


};


int main(){
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
        while(!s.empty()){
		s.top();
         s.pop();
	}





	
	s.top();
	s.find(0);
	s.pop();
	s.find(1);
	s.top();
	s.pop();
	s.pop();
	if(s.empty()){
		cout<<"empty";
	}
	else{
		cout<<"not empty";
		s.top();
	}



	return 0;
}
