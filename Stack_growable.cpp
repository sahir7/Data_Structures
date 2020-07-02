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
	
	
		int *make_new(int *a);
	      
		void push( int val);
	
		void pop();

		void top();
		
};

int* Stack::make_new(int *a){
		int * new_a=new int [2*l];
		for(int i=0;i<l;i++){
			new_a[i]=a[i];
		}
		l*=2;
		return new_a;
	}

void Stack::push( int val){
                if(in==l-2){
                        a=make_new(a);
                }
                a[++in]=val;
        }


void Stack:: pop(){
                
		try{
			if(in==-1)
				throw 1;
			else
				in--;
		}
		catch(int e){
			cout<<"exception caught "<<endl;
		}

                
        }


void Stack:: top(){
                try{
                        if(in==-1)
                                throw 1;
                        else
                               cout<<a[in]<<endl; 
                }
                catch(int e){
                        cout<<"exception caught "<<endl;
                }       
        }

int main(){
	Stack* s=new Stack();
//	for (int i = 0 ; i < 100;i++)
//	{	cout << "there " << endl;
//	s->push(i);
//	}	
//	s->top();
	s->pop();
	s->push(1);
	s->top();
	s->pop();
	s->pop();

         delete s;
	return 0;
}


