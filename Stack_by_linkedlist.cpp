#include<iostream>


using namespace std;
int count=0;

class node{
	public:
	       int data;
	       node* next;
		node(int d){
			data=d;
			next=NULL;
		}

			
};

class Stack{
	node* peek;
	public:
		Stack(){
			peek=NULL;
		}

		void push(int val);
		void pop();
		bool Isempty();
		void top();



};

bool Stack::Isempty(){
	if(peek==NULL){
		return true;
	}
	else{
		return false;
	}
}

void Stack::push(int val){
	node *n=new node(val);
	if(peek==NULL){
		peek=n;
	}
	else{
		n->next=peek;
		peek=n;
	}
	cout<<val<<"is pushed at"<<count<<endl;
	count++;
}

void Stack::pop(){
	if(Isempty()){
		cout<<"stack is empty"<<endl;
	}
	else if(peek->next==NULL){
		peek=NULL;
	}
	else{
		node *temp=peek->next;
		 peek=NULL;
		peek=temp;
		 count--;
	}


}


void Stack::top(){
	if(Isempty()){
		cout<<"stack is empty"<<endl;
	}
	else{
		cout<<peek->data<<endl;
	}
}
int main(){
	Stack *s=new Stack();
	for(int i=0;i<10;i++){
		s->push(i);
	}
        s->top();

        s->pop();


        s->top();
        s->pop();
        s->pop();
        s->top();

        s->pop();
        s->top();
        s->pop();
        s->pop();
        s->top();
	s->pop();
	s->pop();
	s->pop();
	s->top();
	s->pop();
	s->top();
	s->pop();
	s->pop();




	return 0;
}
