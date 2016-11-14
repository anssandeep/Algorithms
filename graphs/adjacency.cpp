#include<iostream>
#define MAX 100
using namespace std;
int adj[MAX][MAX];
int n;

int main(){
	int max_edges,i,j,origin,destin;
	int graph_type;
	cout<<" Enter the graph type: ";
	cin>>graph_type;
	cout<<" Enter the number of vertices: ";
	cin>>n;
	if(graph_type == 1)
		max_edges = n*(n-1)/2;
	else
		max_edges = n*(n-1);
	for(i=1;i<max_edges;i++){
		cout<<" Enter edge: ";
		cin>>origin;
		cout<<" Enter destin: ";
		cin>>destin;
		if(origin==-1 && destin ==-1)
			break;
		if(origin>=n || destin>=n || origin<=0 || destin<=-1){
			cout<<"Invalid vertex"<<endl;
			i--;
		}
	else{
		adj[origin][destin]=1;
		if(graph_type==1)
			adj[destin][origin]=1;
	}
	}
	cout<<" Adjacent matrix"<<endl;
	for(int i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			cout<<adj[i][j]<<"\t";
		}
		cout<<endl;
	}
}
