#include<iostream>
#include<stdlib.h>
#include <stack>
#include<queue>
#include<limits.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
};

stack <struct node*> s;
queue <struct node*> q;

void preorder(struct node *root){
	struct node *ptr=root;
	if(ptr==NULL){
		cout<<" Tree is NULL";
		return;
	}
	s.push(ptr);
	while(!s.empty()){
		ptr=s.top();
		s.pop();
		cout<<ptr->data<<endl;
		if(ptr->rchild!=NULL)
			s.push(ptr->rchild);
		if(ptr->lchild!=NULL)
			s.push(ptr->lchild);
	}
	cout<<endl;	
}


bool isBST(struct node *temp, int min, int max){
	if(temp == NULL)
		return true;
	if(temp->data > min && temp->data<max){
		if(isBST(temp->lchild, min, temp->data) && 
			isBST(temp->rchild, temp->data, max))
			return true;
	}
	return false;
}

void inorder(struct node *root){
	struct node *ptr=root;
	if(ptr==NULL){
		cout<<"Tree is empty"<<endl;
		return;
	}
	while(1){
		while(ptr->lchild!=NULL){
			s.push(ptr);
			ptr=ptr->lchild;
		}
		while(ptr->rchild==NULL){
			cout<<ptr->data<<endl;
			if(s.empty())
				return;
			ptr=s.top();
			s.pop();
		}
		cout<<ptr->data<<endl;
		ptr=ptr->rchild;
	}
	
}


void levelorder(struct node *root){
	struct node *ptr=root;
	if(ptr==NULL){
		cout<<" Empty Tree"<<endl;
		return;
	}
	q.push(ptr);
	while(!q.empty()){
		ptr=q.front();
		q.pop();
		cout<<ptr->data<<"\t";
		if(ptr->lchild!=NULL)
			q.push(ptr->lchild);
		if(ptr->rchild!=NULL)
			q.push(ptr->rchild);
	}
	cout<<"\n";
	return;
}

int height(struct node *ptr){
	int h_left,h_right;
	if(ptr==NULL)
		return 0;
	h_left=height(ptr->lchild);
	h_right=height(ptr->rchild);
	if(h_left> h_right)
		return h_left+1;
	else
		return h_right+1;
}

bool isBST(struct node *root){
	struct node *ptr;
	return true;
}

struct node *newnode(int item){
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data=item;
	node->lchild=NULL;
	node->rchild=NULL;
};

int main(){
	struct node *root=newnode(4);
	root->lchild       = newnode(1111);
	root->rchild      = newnode(12);
	root->lchild->lchild  = newnode(1);
	root->lchild->rchild = newnode(7); 
	if (isBST(root))
		cout<<" Tree is a binary tree"<<endl;
	else
		cout<<" Tree is not a binary tree"<<endl;
	cout<<" Preorder "<<endl;
	preorder(root);
	cout<<" inorder "<<endl;
	inorder(root);
	cout<<" Level order"<<endl;
	levelorder(root);
	cout<<" Height of the tree"<<endl;
	cout<< height(root)<<endl;
	if(isBST(root,INT_MIN,INT_MAX))
		cout<<" Tree is a BST"<<endl;
	else
		cout<<" Tree is not a BST"<<endl;
}
