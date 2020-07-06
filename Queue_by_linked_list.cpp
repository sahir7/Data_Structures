#include<iostream>

using namespace std;

int count=0;

class node{
	public:
		int data;
		node * next;
		node(int d){
			data=d;
			next=NULL;
		}
};


class Queue{
	node * front;
	node *back;
	public:
		Queue(){
			front=NULL;
			back=NULL;
		}
		bool Isempty();

		void push (int val);
		void  pop();
		void  top();
};

int main(){
	Queue *q=new Queue();

	for(int i=11;i<20;i++){
		q->push(i);
	}
	q->top();
	q->pop();
	q->top();
	q->pop();
	q->top();
	q->pop();
	q->pop();
	q->pop();
	q->pop();
	q->pop();
	q->pop();
	q->pop();
	q->pop();
	q->pop();
	q->pop();


	return 0;
}

bool Queue::Isempty(){
	if(front==NULL){
		return true;
	}
	else{
		return false;
	}
}

void Queue::push(int val){
	node* n=new node(val);
	if(Isempty()){
		front=n;
		back=front;
	}

	else{
		back->next=n;
		back=n;

	}
	cout<<n->data<<"is pushed at"<<count<<endl;
	count++;
}
 
void Queue::pop(){
	if(Isempty()){
		cout<<"queue is empty"<<endl;
	}
	else{
		node *temp=front->next;
		cout<<front->data<<"is poped"<<endl;
		front=NULL;
		front=temp;
		delete temp;
		count--;

	}
}

void Queue::top(){
	if(Isempty()){
		cout<<"queue is empty";
	}
	else{
		cout<<front->data<<"is at front"<<endl;
	}
}


