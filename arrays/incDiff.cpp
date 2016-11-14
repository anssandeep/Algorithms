#include<bits/stdc++.h>
using namespace std;

void printPair(int num[],int n,int k){
	if(n<k)
		return;
	int i=0,j=1;
	while(j<n){
		if(num[j]-num[i]<k)
			j++;
		if(num[j]-num[i]>k)
			i++;
		if(num[j]-num[i]==k){
			cout<<"Pair:"<<num[i]<<","<<num[j]<<endl;
			j++;
		}
		else{
			i++;
			j++;
		}
	}
	
}

int main(){
	int num[]={1,2,3,5,6,8,9,11,12,13};
	int n = sizeof(num)/sizeof(num[0]);
	cout<<n<<endl;
	int k=3;
	printPair(num,n,k);
}
