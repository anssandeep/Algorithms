#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define bool int
#define R 6
#define C 5

int data[R][C]={{0,0,1,1,0},
		{1,1,0,1,0},
		{0,1,1,1,0},
		{1,1,1,1,0},
		{1,1,1,1,1},
		{0,0,0,0,0}
		};

int min(int a, int b){
	return (a<b)?a:b;
}
void printMaxSubSquare(int M[R][C]){
	int i,j;
	int s[R][C];
	int max_of_s=0, max_i, max_j; 
	/* copy the first row */
	for(j=0;j<C;j++)
		s[0][j]=M[0][j];
	/* copy the first col */
	for(i=0;i<R;i++)
		s[i][0]=M[i][0];
	/* Construct other entries of S[][]*/
	for(i=1;i<R;i++){
		for(j=1;j<C;j++){
			if(M[i][j]==1)
				s[i][j] = min(s[i][j-1], min(s[i-1][j], s[i-1][j-1])) + 1;
			else
				s[i][j] = 0;
		}
	}
	
	/* find the max number in the matrix */
	for (i=0;i<R;i++){
		for(j=0;j<C;j++){
			if(s[i][j]>max_of_s){
				max_of_s=s[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}

	cout<<max_of_s<<"\t"<<max_i<<"\t"<<max_j<<endl;	
	/* print the max array */
	for(i=max_i-max_of_s+1;i<=max_i;i++){
		for(j=max_j-max_of_s+1;j<=max_j;j++){
			cout<<M[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main(){
	int rows=sizeof(data)/sizeof(data[0]);
	int cols=sizeof(data[0])/sizeof(data[0][0]);
	cout<<rows<<" "<<cols<<endl;
	printMaxSubSquare(data);
}
