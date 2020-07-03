#include<iostream>

using namespace std;

class Queue{
	int max_size;
	int f;
	int r;
	int *a;
	public:
		Queue(){
			r=-1;
			f=-1;
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
	    else if(Isempty()){
		    f=r=0;
		    a[r]=val;
	    }
	    else {
	    a[++r]=val;
	    }

}

void Queue::pop(){
	if(Isempty()){
		cout<<"queue is empty"<<endl;
	
	}
	else if(f==r){
		f=-1;
		r=-1;
	}
	else{
		f++;
	}

	
}

void Queue::front(){
	if(Isempty()){
		cout<<"queue is empty"<<endl;
	}
	else{
	cout<<a[f]<<endl;
	}
}

bool Queue::Isempty(){
	if(r==-1 && f==-1)
		return true;
	else
		return false;
}

bool Queue::IsFull(){
	if(r==max_size-1)
		return true;
	else
		return  false;
}






int main(){
	Queue *q=new Queue();
	
	for(int i=0;i<102;i++){
		q->push(i);
	}
	for(int i=0;i<50;i++){
		q->pop();
	}
	q->push(1);
	q->front();
        q->pop();
	q->pop();
	q->front();
         return 0;
}
