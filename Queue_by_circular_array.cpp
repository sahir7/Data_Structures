#include<iostream>

using namespace std;

class Queue{
	int f=-1;
	int r=-1;
	int *a;
	int max_size;
	public:
		Queue(int n){
			f=-1;
			r=-1;
			max_size=n;
			a= new int[n];
		}

		bool Isfull();

		bool Isempty();

		void enqueue (int val);
		
		void dequeue();

		void front();



};


bool Queue::Isfull(){

	if(f< r){

		if(r-f==max_size-1)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	else{
		if((max_size-f)+r==max_size-1){

			return true;
		}
		else{

			return false;
		}
	}
}


bool Queue::Isempty(){

	if(f==-1 && r==-1   ){

		return true;
	}

	else{

		return false;
	}
}


void Queue :: enqueue(int val){

	if(Isfull()){
		
		cout<<"queue is full"<<endl;
	}

	else if(r==-1 && f==-1){
		
		r=f=0;
		
		a[r]=val;

		cout<<val<<"ispushed here"<<r<<endl;
	}
	else{
	        int temp1=r;

	        temp1+=1;

	        r=temp1%max_size;	 

		a[r]=val;

		cout<<val<<"ispushed here"<<r<<endl;
	}
}


void Queue::dequeue(){
	
	if(Isempty()){

		cout<<"queue is empty"<<endl;
	}

	else if(f==r){

		cout<<"poped "<<a[f]<<"from"<<f<<endl;
		
		f=-1;

		r=-1;
	}
	else{
		cout<<"poped "<<a[f]<<"from"<<f<<endl;

		int temp=f;

		temp+=1;

		f=temp % max_size;


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




int main(){
	Queue *q=new Queue(10);

	for(int i=0;i<10;i++){
		q->enqueue(i);
	}
	for(int i=0;i<5;i++){
		q->dequeue();
	}
	q->front();
	for(int i=0;i<6;i++){
                q->enqueue(i);
        }


	return 0;
}

