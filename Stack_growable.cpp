#include<iostream>

using namespace std;
class Stack{
	int l;
	int in;
	int *a;
	public:
	Stack(){
		l=1;
		in=-1;
		a =new int [l];
	}
	
	
	int *make_new(int *a){
		int * new_a=new int [2*l];
		for(int i=0;i<l;i++){
			new_a[i]=a[i];
		}
		l*=2;
		return new_a;
	}
	void push( int val){
		cout << "here" << endl;
		if(in==l-2){
			cout<<"ksmks";
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
	for (int i = 0 ; i < 100;i++)
	{	cout << "there " << endl;
	s.push(i);
	}	
	s.top();
	s.pop();
	s.pop();
	s.top();


	return 0;
}


