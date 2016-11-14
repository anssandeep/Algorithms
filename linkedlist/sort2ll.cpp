#include<iostream>
#include<list>
using namepsace std;

void sort(list <int> ll1,list <int> ll2);

list <int> ll1;
list <int> ll2;

void sort(list <int> ll1,list <int> ll2){
	list<int>::iterator i,j;
	for(int i = ll1.begin();i!=ll1.end();++1)
		cout<<*i<<"\t";
	cout<<endl;
}

int main(){
	ll1.push_back(0);
	ll1.push_back(1);
	ll1.push_back(10);
	ll2.push_back(3);
	ll2.push_back(4);
	sort(ll1,ll2);	
	//sub(ll1,ll2);
}
