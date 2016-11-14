#include<bits/stdc++.h>
#include<list>
using namespace std;

void alternateSort(list<int> inp){
	cout<<inp.size()<<endl;
	list <int>::iterator it;
	for(it=inp.begin();it!=inp.end();it++){
		cout<<*it<<endl;
	}
	inp.sort();
	cout<<"Sorted"<<endl;
	cout<<endl;
        for(it=inp.begin();it!=inp.end();it++){
                cout<<*it<<endl;
        }	
	cout<<"Rearranging"<<endl;
	cout<<endl;
	for(it=inp.end();it!=inp.begin();it--){
		cout<<*it<<endl;
	}
	for(int i=0;i<(inp.size()+1)/2;i++){
		int val = inp.back();
		//inp.pop_back();
		//inp.insert(it, val);
		
	}
}
int main(){
	std::list<int> integer_list;
	integer_list.push_front(1);
	integer_list.push_front(7);
	integer_list.push_front(3);
	integer_list.push_front(10);
	integer_list.push_front(2);
	alternateSort(integer_list);
	return 0;
}
