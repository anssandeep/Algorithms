#include<iostream>
using namespace std;

void merge(int arr[],int temp[],int low1,int up1,int low2,int up2);
void copy(int arr[],int temp[],int low,int up);

void mergeSort(int arr[10],int low,int up){
	int mid;
	int temp[10];
	if(low<up){
		int mid=(low+up)/2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,up);
		merge(arr,temp,low,mid,mid+1,up);
		copy(arr,temp,low,up);
	}
}

void merge(int arr[],int temp[],int low1,int up1,int low2,int up2){
	int i = low1;
	int j = low2;
	int k = low1;
	while((i<=low1) && (j<=low2)){
		if(arr[i] <= arr[j])
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];
	}
	while(i<=up1)
		temp[k++]=arr[i++];
	while(j<=up2)
		temp[k++]=arr[j++];
}

void copy(int arr[],int temp[],int low,int up){
	int i;
	for(i=low;i<=up;i++){
		arr[i] = temp[i];
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}

int main(){
	int arr[10]={10,21,34,56,2,1,6,7,99,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	mergeSort(arr,0,n-1);
}
