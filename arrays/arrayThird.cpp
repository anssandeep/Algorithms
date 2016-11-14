#include<bits/stdc++.h>
using namespace std;

void thirdLargest(int arr[], int arr_size){
	int first=arr[0],second=INT_MIN,third=INT_MIN;
	for(int i=1;i<arr_size;i++){
		if(first<arr[i]){
			third=second;
			second = first;
			first=arr[i];
		}
		else if(second<arr[i]){
			third=second;
			second = arr[i];
		}
		else if(third<arr[i])
			third=arr[i];
			
	}
	cout<<first<<"\t"<<second<<"\t"<<third<<endl;
}


/* Driver program to test above function */
int main()
{
	int arr[] = {12, 13, 1, 10, 34, 16};
	int n = sizeof(arr)/sizeof(arr[0]);
	thirdLargest(arr, n);
	return 0;
}
