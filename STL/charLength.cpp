#include<iostream>
#include<map>
#include<cstring>
using namespace std;

int main(){
        char arr[]="aaabcAbd";
	map<char,int> M;
	for(int i=0;i<strlen(arr);i++)
		M[arr[i]]++;
	cout<<"Size of MAP: "<<M.size()<<endl;
	for(map<char,int>::iterator it=M.begin();it!=M.end();*it++)
		cout << it->first << " => " << it->second << '\n';
}
