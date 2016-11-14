#include<iostream>
using namespace std;

#define MAX 10
int partition(int array[],int low,int pivot);

void quick(int array[],int low,int up){
	int pivloc;
	if(low>up)
		return;
	pivloc = partition(array,low,up);
	quick(array,low,pivloc-1);
	quick(array,pivloc+1,up);
}

int partition(int array[], int low, int up){
	int temp,i,j,pivot;
	i = low+1;
	j = up;
	pivot = array[low];
	while( i<= j){
		while(i<up && array[i]<pivot)
			i++;
		while(array[j]>pivot)
			j--;
		if(i<j){
			temp=array[i];
			array[i]=array[j];
			array[j]=temp;
			i++;
			j++;
		}
		else 
			i++;
	}
	array[low]=array[j];
	array[j]=pivot;
	return j;
}

int main(){
	int array[MAX] = {10,2,1,34,5,8,11,15,20,21};
	quick(array,0,MAX-1);
	for(int i=0;i<MAX-1;i++)
		cout<<array[i]<<"\t";
	cout<<"\n"<<endl;
}
