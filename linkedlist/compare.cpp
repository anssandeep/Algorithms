#include<iostream>
using namespace std;

struct Node{
	char data;
	struct Node *link;
};

Node* newNode(char c){
	Node *tmp=new Node;
	tmp->data=c;
	tmp->link=NULL;
	return tmp;
}

int compare(Node *list1, Node *list2){
	while(list1 && list2 && list1->data == list2->data){
		list1 = list1->link;
		list2 = list2->link;
	}
	if(list1 && list2)
		return (list1->data!=list2->data)?-1:1;
	if(list1 && !list2) return -2;
	if(!list1 && list2) return 2;
	return 0;
}

int main(){
	Node *list1 = newNode('g');
	list1->link = newNode('e');
	list1->link->link = newNode('e');
	list1->link->link->link = newNode('k');
	list1->link->link->link->link = newNode('s');
	//list1->link->link->link->link->link = newNode('b');

	Node *list2 = newNode('g');
	list2->link = newNode('e');
	list2->link->link = newNode('e');
	list2->link->link->link = newNode('k');
	list2->link->link->link->link = newNode('s');
	list2->link->link->link->link->link = newNode('a');

	cout << compare(list1, list2)<<endl;
	return 0;
}
