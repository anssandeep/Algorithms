#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int n){
	int max_so_far = a[0];
	int curr_max = a[0];
	for(int i=0;i<n;i++){
		curr_max = max(a[i], curr_max + a[i]);
		max_so_far = max(max_so_far, curr_max);
	}
	return max_so_far;
}

int main(){
	int a[] =  {-2, 1, -3, 4, -1, 2, 1, -5,4};
	int n = sizeof(a)/sizeof(a[0]);
	int max_sum = maxSubArraySum(a, n);
	cout<<max_sum<<endl;
	return 0;
}
