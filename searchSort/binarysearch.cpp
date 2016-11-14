#include<iostream>
using namespace std;

// A recursive binary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
int binarySearch(int arr[], int l, int r, int x){
	if(r>l){
	int mid = l+ (r-l)/2;
	if(arr[mid]==x)
		return mid;
	if(arr[mid]>x)
		return binarySearch(arr,l,mid-1,x);
	else if(arr[mid]<x)
		return binarySearch(arr,mid+1,r,x);
	}
	return -1;
}


int main(){
	int arr[] = {2, 3, 4, 10, 40};
	int n = sizeof(arr)/ sizeof(arr[0]);
	int x = 11;
	int result = binarySearch(arr, 0, n-1, x);
	if (result == -1)
		cout<<"Element is not present in array"<<endl;
	else cout<<"Element is present at index: "<<result<<endl;
	return 0;
}
