#include<iostream>
using namespace std;

void reverse(int arr[], int n, int k){
	if(n==1 || n<k){
		cout<<" Cannot do reverse"<<endl;
		return;
	}
	int tmp;
	for (int i = 1; i+1 < n; i += k){
		tmp = arr[i+1];
		arr[i+1]=arr[i-1];
		arr[i-1]=tmp;
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout<<endl;
	return;
}

int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int k = 3;
	int n = sizeof(arr) / sizeof(arr[0]);
	reverse(arr,n,k);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout<<endl;
}
