#include<iostream>
#include<map>
using namespace std;

int main(){
	map<int> M;
	M.push_back(0);
	M.push_back(22);
	M.push_back(2);
	M.push_back(15);
	map<int>::iterator it;
	for(it=M.begin();it!=M.end;*it++)
		cout<<*it<<endl;
}
