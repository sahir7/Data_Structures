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

Node*  insertIterative(Node* root,int d){
	Node* n=new Node(d);
	Node* curr=root;
	if(root==NULL){
		root=n;
		return root;
	}
        	Node *par=NULL;
	
		while(curr!=NULL){
			par=curr;
			if(d > curr->data ){
				curr=curr->right;
			}
			else{
				curr=curr->left;
			}
		}

		if(par->data < d){
	         	par->right=n;
		}
		else{
			par->left=n;
		}
		return par;

}

Node * insertRecursive(Node *root,int d){
	Node* n=new Node(d);
	if(root==NULL){
		root=n;
	        return root;
	}
	else if(d > root->data){
		root->right=insertRecursive(root->right,d);
	}
	else{
		root->left=insertRecursive(root->left,d);
	}
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

void inorder(Node *root){
	if(root==NULL){
		return ;
	}
	inorder(root->left);
	cout<<root->data<<"-->";
	inorder(root->right);
}
void postorder(Node *root){
	if(root==NULL){

	   return ;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<"-->";
}

void Levelorder(Node* root){
	if(root==NULL){
		return ;
	}
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* curr=q.front();
		cout<<curr->data<<"-->";
		if(curr->left!=NULL){
			q.push(curr->left);
		}
		if(curr->right!=NULL){
			q.push(curr->right);
		}
		q.pop();
	}
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






Node* Delete(Node* root,int k){
	if(root==NULL){
		return root;
	}

	if(k > root->data){
		root->right=Delete(root ->right,k);
		return root;
	}
	else if(k < root->data){
		root->left=Delete(root->left,k);
		return root;
	}
	else {

        if(root->left==NULL){
		Node* temp=root->right;
		delete root;
		return temp;
	}
	else if(root->right==NULL){
		Node* temp=root->left;
		delete root;
		return temp;
	}
	else{
		Node *succParent=root;
		Node* succ=root->right;
		while(succ->left!=NULL){
			succParent=succ;
			succ=succ->left;
		}

		if(succParent!=root){
			succParent->left=succ->right;
		}
		else{
			succParent->right=succ->right;
		}

		root->data=succ->data;
		delete succ;
		return root;
	}
	}
}

int height(Node* root){
	if(root==NULL){
		return 0;
	}
	int left=height(root->left);
	int right=height(root->right);

	
	
	if(left > right){
	      left=1+left;
	}
	else{
		 right=1+right;
	}

	return max(left,right);

}

bool  Search(Node* root,int k){
	if(root==NULL){
		return false;
	}
	
	if(k==root->data){
	       return true;
	}
	else if(k > root->data){
	 return	Search(root->right,k);
	}
	else {
	 return	Search(root->left,k);
	}
	



}

		
	    




int main(){
	Node* root=NULL;
//        root=insertIterative(root, 50);
//        insertIterative(root, 30);
//        insertIterative(root, 20);
//        insertIterative(root, 40);
//        insertIterative(root, 70);
//        insertIterative(root, 60);
//        insertIterative(root, 80);

	root=insertRecursive(root,50);
        insertRecursive(root,30);
        insertRecursive(root,20);
        insertRecursive(root,40);
        insertRecursive(root,70);
        insertRecursive(root,60);
        insertRecursive(root,80);
                
//	int pre[]={10,5,1,7,40,50};
//	int n=sizeof(pre)/sizeof(int);
//        Node* root=preorderInput(pre,0,n);




       
      
       inorder(root);      
       int h=height(root);
       
       cout<<endl;
       cout<<h<<endl;
//      Delete(root,20);
       if(Search(root,30)){
	       cout<<"found"<<endl;
       }
       else{
	       cout<<"Not Found"<<endl;
       }

       inorder(root);
       cout<<endl;
       Levelorder(root);
       cout<<endl;
       PrintLevelwise(root);




        

	return 0;
}
