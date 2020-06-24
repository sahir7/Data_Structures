#include<iostream>

using namespace std;
class Stack{
	public:
	int c=5;
	int l=0;
	int in=-1;
	int *a=make_new(a);
	
	int *make_new(int *a){
		int * new_a=new int [l+c];
		for(int i=0;i<l;i++){
			new_a[i]=a[i];
		}
		l+=c;
		return new_a;
	}
	void push(int val){
		if(in==l-1){
			a=make_new(a);
		}
		a[++in]=val;
	}

	void pop(){
		if(in==-1){
			cout<<"stack is empty";
		}

		in--;
	}
	void top(){
		if(in==-1){
			cout<<"stack is empty";
		}
		cout<<a[in]<<endl;
	}



		
};

int main(){
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(6);
	s.push(5);
	s.push(7);
	
	s.top();
	s.pop();
	s.top();


	return 0;
}


