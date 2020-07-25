#include<iostream>
#include<queue>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int d){
			data=d;
			left=right=NULL;
		}
};
int height(Node *n){
	if(n==NULL){
		return 0;
	}
	int left=height(n->left);
	int right=height(n->right);
	
	if(left > right){
	      left=1+left;
	}
	else{
		 right=1+right;
	}
	
	return max(left,right);
}

int Balancefactor(Node *n){
	if(n==NULL){
		return 0;
	}
	int l=height(n->left);
	int r=height(n->right);
        int bf=l-r;
        return bf;
}

Node* RightRotate(Node *n){
       Node* x=n->left;
       Node* T=x->right;

       n->left=T;
       x->right=n;
       
       cout<<"rightrotate"<<endl;

      return x;
}

Node * LeftRotate(Node* n){
	Node* x=n->right;
	Node* T=x->left;

        x->left=n;
	n->right=T;
	
	cout<<"leftrotate"<<endl;
      
      return x;
}

Node* Balancing(Node *root){
	  int balance=Balancefactor(root);


          if(balance > 1){
		  int bf=Balancefactor(root->left);
		  if(bf>=0){
                           cout<<"here1"<<endl;
                           return RightRotate(root);
		  }
		  else{
                       cout<<"here2"<<endl;
                       root->left=LeftRotate(root->left);
                       return RightRotate(root);
		  }
          
	  }

          if(balance < -1 ){
		  int bf=Balancefactor(root->right);
		  if(bf >=0){
                            cout<<"here3"<<endl;
                            return LeftRotate(root);
		  }
		  else{
                       cout<<"here4"<<endl;
                       root->right=RightRotate(root->right);
                       return LeftRotate(root);
		  }
	  }
          

          return root;
}



Node*  insert(Node* root,int key){
          Node* n=new Node(key);
	  if(root==NULL){
		  root=n;
		  return root;
	  }

	  else if(key < root->data){
		  root->left=insert(root->left,key);
	  }
	  else if(key > root->data){
		  root->right=insert(root->right,key);
	  }
	          root=Balancing(root);
		  return root;
	 
}

Node* Delete(Node* root,int key){
	if(root==NULL){
		return root;
	}
	if( key > root->data){
		root->right=Delete(root->right,key);
	}
	else if(key < root->data){
		root->left=Delete(root->left,key);
	}
	else{
	        if(root->left==NULL){

		        Node* temp=root->right;
			root=temp;
		        delete temp;
               	}
         	else if(root->right==NULL){

	                Node* temp=root->left;
		        root=temp;
	                delete temp;
		
         	}
		else{
			Node* succparent=root;
			Node* succ=root->right;
			while(succ->left!=NULL){
				succparent=succ;
				succ=succ->left;
			}
			if(succparent!=root){
				succparent->left=succ->right;
			}
			else{
				succparent->right=succ->right;
			}
			root->data=succ->data;
			delete succ;
		}
	}

	root=Balancing(root);
	return root;
}




void preorder(Node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<"-->";
	preorder(root->left);
	preorder(root->right);
}

void PrintLevelwise(Node* root){
	if(root==NULL){
		return;
	}
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		Node* curr=q.front();
		q.pop();
		if(curr==NULL){
			cout<<endl;
			if(!q.empty()){
			q.push(NULL);
			}
		}
		else{
			cout<<curr->data<<" ";
			if(curr->left!=NULL){
				q.push(curr->left);
			}
			if(curr->right!=NULL){
				q.push(curr->right);
			}
		}
	}
}

int main(){
	Node *root = NULL;

	//root=insert(root, 10);
	//root=insert(root, 20);
	//root=insert(root, 30);
	//root=insert(root, 40);
	//root=insert(root, 50);
	//root=insert(root, 25);
        root = insert(root, 9);
        root = insert(root, 5);
        root = insert(root, 10);
        root = insert(root, 0);
        root = insert(root, 6);
        root = insert(root, 11);
        root = insert(root, -1);
        root = insert(root, 1);
        root = insert(root, 2);

	preorder(root);
	cout<<endl;

//	root=Delete(root,1);
//	preorder(root);
	PrintLevelwise(root);
//	root=Delete(root,2);
//	preorder(root);
//	cout<<endl;
//	PrintLevelwise(root);
//	root=Delete(root,5);
        root=Delete(root,10);
//	preorder(root);

	PrintLevelwise(root);




	return 0;
}
