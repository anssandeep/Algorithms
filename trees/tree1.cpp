#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int info;
	struct Node* left;
	struct Node* right;
};

void print_nodes(Node* pnode);

Node *newNode(int key){
	Node *temp = new Node;
	temp->info = key;
	temp->left = NULL;
	temp->right = NULL;
	return (temp);
}

// calculating height of the tree
int height(Node *start){
	if(start == NULL)
		return 0;
	int lh = height(start->left);
	int rh = height(start->right);
	return(1+max(lh,rh));
}

//printing the nodes of 
void print_nodes(Node* pnode)
{
	Node* pcurnode = pnode;
	
	while(pcurnode)
	{
		cout<<pcurnode->info<<"\t";	
		int lh = height(pcurnode->left);
		int rh = height(pcurnode->right);
		pcurnode = lh > rh ? pcurnode->left : pcurnode->right;
	}
}

void PrintParent(Node *start,int x){
	if(start == NULL)
		return;
	Node *tmp = start,*par=start;
	while(tmp!=NULL){
		if(x > tmp->info){
			par = tmp;
			tmp = tmp->right;
		}
		else if (x < tmp->info){
			par = tmp;
			tmp = tmp->left;
		}
		else{
			cout<<"Found element: "<<x<<endl;
			cout<<"Parent: "<<par->info<<endl;
			return;
		}
	} 
	cout<<" Element is not availble "<<endl;
}

int main(){
	Node *root  = newNode(10);
	root->left = newNode(3);
	root->right = newNode(4);
    	root->right->left   = newNode(9);
    	root->right->right  = newNode(8);
	root->left->left = newNode(5);
	root->left->right = newNode(7);
 
	//cout<<"Height: "<<height(root)<<endl;
	//print_nodes(root);
	PrintParent(root,3);
	cout<<endl;
}
