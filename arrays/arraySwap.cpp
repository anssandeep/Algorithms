#include<bits/stdc++.h>
#define n 5
using namespace std;

void sort(char a[],int b[]){
	char tmp;
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	cout<<endl;
	int count=0,i=0;
	char t_c=a[b[i]];
	int t_i=b[b[i]];
	while(count<n){
		a[b[i]]=a[i];
		i=t_i;
		t_c=a[b[i]];
		t_i=b[b[i]];
		count++;
	}	
	for(i=0;i<n;i++)
                cout<<a[i]<<"\t";
	cout<<endl;

}

int main(){
	char a[5]={'C','D','E','F','G'};
	int b[5]={3,0,4,1,2};
	sort(a,b);
	return 0;
}
