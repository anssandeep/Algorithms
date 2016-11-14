#include<iostream>
using namespace std;

void subArraySum(int arr[],int n,int sum){
	int curr_sum = arr[0], start = 0, i;
	for(int i=1;i<=n;i++){
		while(curr_sum > sum && start < i-1){
			curr_sum = curr_sum - arr[start];
			start++;
		}
		if(curr_sum == sum){
			cout<<"Sum Found: "<<start<<"\t"<<i-1<<endl;
			return;
		}
		if(i<n)
			curr_sum = curr_sum + arr[i];
	}
	cout<<"Sum not found"<<endl;
	return;
}

// Driver program to test above function
int main()
{
	int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
	int n = sizeof(arr)/sizeof(arr[0]);
	int sum = 23;
    	subArraySum(arr, n, sum);
    	return 0;
}
