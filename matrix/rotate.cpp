#include<iostream>
using namespace std;
#define R 4
#define C 4

int Mat[R][C]={{1,2,3,4},
		{1,2,3,4},
		{1,2,3,4},
		{1,2,3,4}
		};

void rotate(int Mat[R][C],int rows,int cols){
	int i,j;
	cout<<rows<<"\t"<<cols<<endl;
	int MatCopy[R][C];
	for(i=0;i<R;i++){
		for(j=0;j<C;j++){
			MatCopy[j][C-i-1]=Mat[i][j];
		}
	}
	for(i=0;i<R;i++){
		for(j=0;j<C;j++){
			cout<<MatCopy[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main(){
	int rows = sizeof(Mat)/sizeof(Mat[0]);
	int cols = sizeof(Mat[0])/sizeof(Mat[0][0]);
	rotate(Mat,rows,cols);
}
