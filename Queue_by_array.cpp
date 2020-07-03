#include<iostream>

using namespace std;

class Queue{
	int index;
	int max_size;
	int *a;
	public:
		Queue(){
			index=-1;
			max_size=100;
			a=new int [max_size];
		}

		void push(int val);

		void pop();

		void front();

		bool Isempty();

		bool IsFull();
};

void Queue::push(int val){
            if(IsFull()){
		    cout<<"queue is full"<<endl;
	    }
	    a[++index]=val;
}

void Queue::pop(){
	if(Isempty()){
		cout<<"queue is empty"<<endl;
	}
	else{
		for(int i=0;i<index;i++){
			a[i]=a[i+1];
		}
		index--;
	}
}

void Queue::front(){
	if(Isempty()){
		cout<<"queue is empty"<<endl;
	}
	else{
	cout<<a[0]<<endl;
	}
}

bool Queue::Isempty(){
	if(index==-1)
		return true;
	else
		return false;
}

bool Queue::IsFull(){
	if(index==max_size)
		return true;
	else
		return  false;
}






int main(){
	Queue *q=new Queue();
	
//	for(int i=0;i<50;i++){
//		q->push(i);
//	}
//	q->front();
//	q->pop();
	q->pop();
	q->front();
	if(q->Isempty()){
		cout<<"empty";
	}
	return 0;

}
