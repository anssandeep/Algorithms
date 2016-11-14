#include<iostream>
struct Edge;
struct Vertex{
	int info;
	struct Vertex *nextVertex;
	struct Edge *firstEdge;
}*start=NULL;

struct Edge{
	struct Vertex *destVertex;
	struct Edge *nextEdge;
};


using namespace std;

int main(){
	int choice,u,origin,destin;
	while(1){
		cout<<"1. Insert a vertex"<<endl;
		cout<<"2. Insert an edge"<<endl;
		cout<<"3. Delete a vertex"<<endl;
		cout<<"4. Delete an edge"<<endl;
		cout<<"5. Display"<<endl;
		cout<<"6. Exit"<<endl;
		switch(choice){	
			case 1: 
				cout<<" Enter a vertex to be inserted: ";
				cin>>u;
				insertVertex(u);
				break;
			case 2:
				cout<<" Enter an edge to be inserted - origin: ";
				cin>>orig;
				cout<<" destination: ";
				cin>>destin;
				insertEdge(origin,destin);
				break;
			default:
				break;
		}
	}
}

void insertVertex(int u){
	struct Vertex *tmp,*ptr;
	tmp = malloc(sizeof(struct Vertex));
	tmp->info =u;
	tmp->nextVertex=NULL;
	tmp->firstEdge=NULL;
	if(start==NULL){
		start=tmp;
		return;
	}
	ptr=start;
	while(ptr->nextVertex!=NULL)
		ptr=ptr->nextVertex;
	ptr->nextVertex=tmp;
}

struct Vertex *findVertex(int u){
	struct Vertex *ptr,*loc;
	ptr = start;
	while(ptr!=NULL){
		if(ptr->info==u){
			loc=ptr;
			return loc;
		}
		else
			ptr=ptr->nextVertex;
	}
	loc=NULL;
	return loc;
}

void insertVertex(int u, int v){
	struct Vertex *locu,*locv;
	struct Edge *ptr,*tmp;
	locu=findVertx(u);
	locv=findVertex(v);
	if(locu==NULL || locv==NULL){
		cout<<" Enter a valid node"<<endl;
		return;
	}
	tmp=malloc(sizeof(struct Edge));
	tmp->destVertex = locv;
	tmp->nextVertex = NULL;
	if(locu->firstEdge==NULL){
		locu->firstEdge = tmp;
		return;
	}
	ptr = locu->firstEdge;
	while(ptr->nextEdge!=NULL)
		ptr = ptr->nextEdge;
	ptr->nextEdge = tmp;
}
