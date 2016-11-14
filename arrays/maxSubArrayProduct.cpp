#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxSubArrayPdt(int a[], int n){
	int max_ending_here = 1;
	int min_ending_here = 1;
	int max_so_far = 1;
	for (int i = 0; i < n; i++){
		if(a[i]>0){
			max_ending_here = max_ending_here*arr[i];
			min_ending_here = min (min_ending_here * arr[i], 1);
		}
		else if(a[i]==0){
			max_ending_here = 1;
			min_ending_here = 1;
		}
		else{
			int temp = max_ending_here;
			
		}
	}
}

int main(){
	int a[] =  {-2, 1, -3, 4, -1, 2, 1, -5,4};
	int n = sizeof(a)/sizeof(a[0]);
	int max_sum = maxSubArrayPdt(a, n);
	cout<<max_sum<<endl;
	return 0;
}
