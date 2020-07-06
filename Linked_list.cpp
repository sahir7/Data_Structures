#include<iostream>

using namespace std;


class node{
      public:
	      int data;
	      node* next;
	      
};

node::node(int d){
	data=d;
	next=NULL;
}

class Linked_list{
	node* head;
	node* tail;
	public:
		bool Isempty();
		void insertatback(int val);
		void insertatfront(int val);
		void insertatmid(int pos,int val);
		void removefromback();
		void removefrommid(int pos);
		void removefromfront();
		void print();
	
};

Linked_list::Linked_list(){
	head=NULL;
	tail=NULL;
}

bool Linked_list:: Isempty(){
	if(head==NULL){
		return true;
	}
	else{
		return false;
	}
}

void Linked_list::insertatback(int val){
	if(Isempty())
	{
		node* n=new node(val);
		head=n;
		tail=head;
		cout<<val<<" insert "<<endl;
	}
	else{
		node *n=new node(val);
		node* temp=tail;
		temp->next=n;
		tail=n;

		cout<<val<<" insert "<<endl;
		}
}

void Linked_list:: insertatfront(int val){
	if(Isempty()){
		node* n=new node(val);
		head=n;
		tail=n;
		cout<<val<<"insert"<<endl;
	}
	else{
	      node* n=new node(val);
	      n->next=head;
	      head=n;
	      cout<<val<<"insert"<<endl;
	}

}

void Linked_list::insertatmid(int pos,int val){
	node *temp=head;
	for (int i=0;i<pos-1;i++){
		temp=temp->next;
	}
	node *temp1=temp->next;
	
	node *n=new node(val);
	temp->next=n;
	n->next=temp1;
	cout<<val<<"insert"<<endl;
}






void Linked_list::removefromfront(){
	 if(head==tail && head!=NULL){
		 head=NULL;
		 tail=head;
	 }
	 else{
		 node *temp=head->next;
		 head=NULL;
		 head=temp;
	 }


}

void Linked_list::removefromback(){
	if (head==tail && head!=NULL){
		head=NULL;
		tail=head;

	}
	else{
		node* temp=head;
		while(temp!=tail){
			temp=temp->next;
		}
		tail=temp;
		tail->next=NULL;
	}


}

void Linked_list::removefrommid(int pos){
	node* temp=head;
	for(int i=0;i<pos-2;i++){
		temp=temp->next;
	}
	node* temp1=temp->next;
	node* temp2=temp1->next;
	temp->next=temp2;
}

	

void Linked_list::print(){
	          node *temp=head;
	
		while(temp!=NULL){
			cout<<temp->data<<"-->";
			temp=temp->next;
		}
		cout<<endl;
	
}


int main(){
	Linked_list *l=new Linked_list();

	for(int i=0;i<10;i++){
		l->insertatback(i);
	}
	l->print();
	l->removefromfront();
	l->removefromfront();
	l->insertatmid(2,11);
	l->print();
	l->insertatfront(3);
	l->print();
	l->removefromback();
	l->print();
	l->removefrommid(4);
	l->print();

	return 0;
}


