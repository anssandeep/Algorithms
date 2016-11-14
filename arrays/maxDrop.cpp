#include<bits/stdc++.h>
using namespace std;

void find_max_drop(int input[],int n){
	int maxD=INT_MIN,minD=INT_MAX,min_i=1,max_i=0;
	for(int i=0;i<n;i++){
		if(i<min_i){
			maxD=max(maxD,input[i]);
			min_i=i;
		}
		if(i>max_i){
			minD=min(minD,input[i]);
			max_i=i;
		}
	}
	cout<<maxD-minD<<endl;
}

int main(){
	//int input[6] = {5,3,4,1,6,7};
	int input[7]={10, 9, 6, 11, 3, 4, 5};
	find_max_drop(input, 6);
}
