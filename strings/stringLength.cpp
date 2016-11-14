#include<iostream>
using namespace std;

int main(){
	char *p="abcde hello",*c;
	int i=0;
	while(p[i]!='\0'){
		i++;
	}
	cout<<p<<"\t"<<i<<endl;
}
