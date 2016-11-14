#include<iostream>
#include<cstring>
#include <cstdlib>
using namespace std;

int findSum(string str){
	int sum=0;
	string temp="";
	for(int i=0;i<str.length();i++){
		//cout<<str[i]<<"\t";
		temp = str[i];
		if(isdigit(str[i])!=0)
			sum=atoi(temp.c_str())+sum;
	}
	cout<<endl;
	cout<<sum<<endl;
}

int main(){
	string str = "12a222c20yz68";
	findSum(str);
	return 0;
}
