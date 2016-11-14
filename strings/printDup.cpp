#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

void printDup(char *str){
	int count[256]={0};
	int i=0;
	for(int i=0;*(str+i)!=NULL;i++)
		cout<<i;
	cout<<endl;
	i=0;
	while(*str!=NULL){
		count[*(str+i)]++;
		i++;
	}
	
}

int main(){
	char str[] ="test string";
	printDup(str);
	return 0;
}
