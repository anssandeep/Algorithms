#include<iostream>
#include<stdlib.h>
#include<map>
using namespace std;

map <int,int> m;

struct node{
	int info;
	struct node *link;
};

struct node *createList(struct node *start);
void displayList(struct node *start);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addafter(struct node *start);
struct node *reverse(struct node *start);
struct node *delnode(struct node *start);
struct node *selectiveSort(struct node *start);
struct node *sortbylink(struct node *start);
struct node *divide(struct node *p);
struct node *merge(struct node *p,struct node *q);
struct node *merge_sort(struct node *p);
void printUnique(struct node *start);
void printAfterMergeSort(struct node *start);

int main(){
	struct node *start= NULL;
	int choice,data,item,pos;
	while(1){
		cout<<"1. Create a linkedlist"<<endl;
		cout<<"2. Display"<<endl;
		cout<<"3. Add after a value"<<endl;
		cout<<"4. Reverse "<<endl;
		cout<<"5. Delete an element"<<endl;
		cout<<"6. Sort the linked list using data exchange"<<endl;
		cout<<"7. Sorted by exchanging links"<<endl;
		cout<<"8. Print Unique elemenst"<<endl;
		cout<<"9. Merging Sort using LL"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Selected 1st option"<<endl;
				start = createList(start);
				break;
			case 2:
				displayList(start);
				break;
			case 3:
				start = addafter(start);
				break;
			case 4: 
				start = reverse(start);
				break;
			case 5:
				start = delnode(start);
				break;
			case 6:
				start = selectiveSort(start);
				break;
			case 7:
				start = sortbylink(start);
				break;
			case 8: 
				printUnique(start);
				break;
			case 9: 
				start = merge_sort(start);
				displayList(start);
				printAfterMergeSort(start);
				break;
			default:
				cout<<"Enter valid choice"<<endl;
		}
	}
}


struct node *merge_sort(struct node *start){
	struct node *start_first,*start_second,*start_merged;
	if(start!=NULL && start->link!=NULL){
		start_first = start;
		start_second = divide(start);
		start_first = merge_sort(start_first);
		start_second = merge_sort(start_second);
		start_merged = merge(start_first,start_second);
		return start_merged;
	}
	else
		return start;
}

struct node *divide(struct node *p){
	struct node *q,*start_second;
	q = p->link->link;
	while(q!=NULL){
		p = p->link;
		q = q->link;
		if(q!=NULL)
			q=q->link;
	}
	start_second = p->link;
	p->link = NULL;
	return start_second;
}

struct node *merge(struct node *p1, struct node *p2){
	struct node *start_merged,*q;
	if(p1->info <= p2->info){
		start_merged = p1;
		p1 = p1->link;
	}	
	else{
		start_merged = p2;
		p2 = p2->link;
	}
	q = start_merged;
	while(p1 != NULL && p2 != NULL){
		if(p1->info <= p2->info){
			q->link = p1;
			q = q->link;
			p1 = p1->link;
		}
		else{
			q->link = p2;
			q = q->link;
			p2 = p2->link;
		}
	}
	if(p1!=NULL)
		q->link = p1;
	else
		q->link = p2;
	return start_merged;
}


void printAfterMergeSort(struct node *start){
	if(start==NULL){
		cout<<"Empty List"<<endl;
		return;
	}
	struct node *tmp=start;
	/*
	int prev=tmp->info;
	cout<<tmp->info<<"\t";
	tmp=tmp->link;
	while(tmp->link!=NULL){
		if(tmp->info != prev || tmp->info != tmp->link->info)	
			cout<<tmp->info<<"\t";
		prev = tmp->info;
		tmp = tmp->link;
	}
	if(tmp->info != prev)
		cout<<tmp->info<<"\t";
	*/
 	struct node *prev;
	while(tmp->link!=NULL){
		if(tmp->info!=tmp->link->info)
			cout<<tmp->info<<"\t";
		prev = tmp;
		tmp = tmp->link;
	}
	if(prev->info!=tmp->info)
		cout<<tmp->info;
	cout<<endl;
}

void printUnique(struct node *start){
	struct node *ptr = start;
	if(start==NULL){
		cout<<"Empty List"<<endl;
		return;
	}
	pair<map<int,int>::iterator,bool> ret;
	while(ptr!=NULL){
		ret=m.insert(make_pair(ptr->info,0));
		if(ret.second==true)
			cout<<ptr->info<<"\t";
		ptr=ptr->link;
	}
	cout<<endl;
}

void displayList(struct node *start){
	struct node *p=start;
	if(start==NULL){
		cout<<"List is empty"<<endl;
		return;
	}
	while(p != NULL){
		cout<<p->info<<"\t";
		p = p->link;
	}
	cout<<endl;
}

struct node *addatbeg(struct node *start,int data){
	struct node *tmp;
	tmp = (struct node *) malloc(sizeof(struct node));
	tmp->info= data;
	tmp->link=start;
	start = tmp;
	return start;
}

struct node *addatend(struct node *start,int data){
	struct node *tmp,*p;
	p=start;
	while(p->link!=NULL)
		p=p->link;
	tmp = (struct node*) malloc(sizeof(struct node));
	p->link = tmp;
	tmp->info = data;
	tmp->link = NULL;
	return start; 
}

struct node *createList(struct node *start){
	int n,i=0,data;
	cout<<"Enter the number of nodes: ";
	cin>>n;
	start = NULL;
	if(n==0)
		return start;
	cout<<"Enter the data: ";
	cin>>data;
	start=addatbeg(start,data);
	for(i=1;i<n;i++){
		cout<<"Enter new element: ";
		cin>>data;
		start=addatend(start,data);
	}
	return start;
}

struct node *addafter(struct node *start){
	struct node *p,*tmp;
	int data,pos,i=1;
	p = start;
        if(p==NULL){
                cout<<"Empty list"<<endl;
                return start;
        }
	cout<<"Enter position: ";
	cin>>pos;
	tmp = (struct node *) malloc(sizeof(struct node));
	cout<<"Enter the info:";
	cin>>data;
	if(pos==1){
		tmp->link = start;
		start = tmp;
		return start;
	}
	while(i!=pos){
		p = p->link;
		i = i + 1;
	}
	tmp->info = data;
	tmp->link = p->link;
	p->link = tmp;
	return start;
}

struct node *delnode(struct node *start){
	struct node *ptr,*tmp,*p;
	int pos,num=1,data;
	ptr = start;
	if(ptr==NULL){
		cout<<"LinkedList is empty"<<endl;
		return start;
	}
	cout<<"Enter the position of node to delete: ";
	cin>>data;
	if(start->info == data){
		tmp = start;
		start = start->link;
		free(tmp);
		return start;
	}
	ptr = start;
	while(p->link != NULL){
	{
		if(ptr->info != data){
			if(ptr->link->info == data){
				tmp = ptr->link;
				ptr->link = tmp->link;
				free(tmp);
				return start;
			}
		} 
		ptr = ptr->link;
	}
	cout<<" Element not found"<<endl;
	return start;
}
}

struct node *reverse(struct node *start){
	struct node *prev,*next,*ptr;
	ptr = start;
	prev = NULL;
	while(ptr!=NULL){
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
	}
	start = prev;
	return start;
}

struct node *selectiveSort(struct node *start){
	struct node *p,*q;
	int tmp;
	for(p=start;p->link!=NULL;p=p->link){
		for(q=p->link;q!=NULL;q=q->link){
			if(p->info>q->info){
				tmp=p->info;
				p->info = q->info;
				q->info = tmp;
			}
		}
	}
	return start;
}

struct node *sortbylink(struct node *start){
	struct node *p,*q,*r,*s,*tmp;
	p = start;
	for(r=p=start;p->link!=NULL;r=p,p=p->link){
		for(s=q=p->link;q!=NULL;s=q,q=q->link){
			if(p->info>q->info){
				tmp=p->link;
				p->link = q->link;
				q->link = tmp;
				if(p!=start)
					r->link=q;
				s->link=p;
				if(p==start)
					start=q;
				tmp=p;
				p=q;
				q=tmp;	
				
			}
		}
	}
	return start;
}
