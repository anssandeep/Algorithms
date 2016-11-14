#include<iostream>
#include<vector>
using namespace std;

void display(vector <int> v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
}

int main(){
	vector <int> v;
	cout<<"Initial size of vector: "<<v.size()<<endl;
	int x;
	cout<<"Enter five values "<<endl;
	for(int i=0;i<5;i++){
		cin>>x;
		v.push_back(x);
	}
	cout<<"Size after entering elements: "<<v.size()<<endl;
	display(v);
	
}
