#include<iostream>
#include<string>
using namespace std;

void checkDup(string str){
	int len = str.length();
	int i=0;
	int count[256]={0};
	for(int i=0;i<len;i++){
		cout<<str[i]<<endl;
		count[str[i]]++;
	}
	char asciiChar;
	for(int i=0;i<256;i++){
		if(count[i]>1){
			asciiChar = i;
			cout<<char(i)<<"\t"<<count[i]<<endl;
		}
	}
}

int main(){
	string str = "test string";
	checkDup(str);
}
