#include<iostream>
using namespace std;

class Queue{
	int f=-1;
	int r=-1;
	int *a;
	int n;
	public:
		Queue(){
			f=-1;
			r=-1;
			n=1;
			a= new int[n];
		}
		int * make_new(int *a,int val);
		bool Isfull();
		bool Isempty();
		void enqueue (int val);
		void dequeue();
		void front();
};
bool Queue::Isfull(){

	if(f<=  r && r!=-1 && f!=-1){

		if(r-f==n-1   )
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	else{
		if((n-f)+r==n-1){

			return true;
		}
		else{

			return false;
		}
	}
}


int *Queue::make_new(int *a,int val){
	int *new_a=new int [n*2];

	
	if(f<= r){
		for (int i=f;i<r+1;i++){
			new_a[i]=a[i];
		}		
	}

	else{
		for(int i=f;i<(n-f)+r;i++){
			new_a[i%n]=a[i%n];
		}	
	}
       	new_a[n]=val;
	r=n;
        cout<<val<<"ispushed here"<<r<<endl;
         n*=2;	
	
	return new_a;
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
		a=make_new(a,val);

	}
	else if(r==-1 && f==-1){

		r=f=0;

		a[r]=val;

		cout<<val<<"ispushed here"<<r<<endl;
	}
	else{
	        int temp1=r;

	        temp1+=1;

	        r=temp1%n;

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

		f=temp % n;


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
	Queue *q=new Queue();

	for(int i=0;i<8;i++){
		q->enqueue(i);
	}
	q->front();
	q->dequeue();

	q->dequeue();
	q->enqueue(9);
	q->enqueue(8);
//	q->front();
//	q->dequeue();
//	q->front();
	q->dequeue();
	q->dequeue();
	q->dequeue();
	q->dequeue();
	q->dequeue();
	q->dequeue();
	q->dequeue();
	q->dequeue();
	


	return 0;
}

