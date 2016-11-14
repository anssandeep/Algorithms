#include<iostream>
using namespace std;

void insertionSort(int arr[10],int n){
	int min=arr[0];
	cout<<"Array before sorting"<<endl;
	for(int i =0;i<n;i++)
		cout<<arr[i]<<"\t";
	cout<<endl;
	int j;
	for(int i=1;i<n;i++){
		int k=arr[i];
		for(j=i-1;j>=0 && k<arr[j] ;j--){
			arr[j+1]=arr[j];
		}
		arr[j+1]=k;
	}
	cout<<"Sorted array"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<"\t";
	cout<<endl;
}

int main(){
	int arr[10]={10,9,8,2,3,4,7,6,21,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	insertionSort(arr,n);
}
