#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
	string str = "Hello";
	stack <char> s;
	for(int i=0;i<str.length();i++)
		s.push(str[i]);
	while(s.size()!=0){
		cout<<s.top()<<endl;
		s.pop();
	}
}
