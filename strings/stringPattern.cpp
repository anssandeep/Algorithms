#include <bits/stdc++.h>
#include<string>
#include<map>
using namespace std;

bool checkPattern(string str, string pat){
	std::map<char,int> first;
	for(int i=0;i<pat.length();i++){
		first[pat[i]]=i+1;
	}
	cout<<pat.length()<<endl;
	int label_last=-1;
	for(int i=0;i<str.length();i++){
		if(first.find(str[i])->second){
			if(first.find(str[i])->second < label_last)
				return false;
			label_last = first.find(str[i])->second;
		}
	}
	return true;
}

int main(){
	string str="engineers rock";
	string pat="gsr";
	cout << checkPattern(str, pat)<<endl;
	return 0;
}
