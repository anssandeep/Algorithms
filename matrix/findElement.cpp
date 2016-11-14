#include<iostream>
#define R 5
#define C 5
using namespace std;

bool stepWise(int M[R][C],int rows,int cols){
	int target;
	cout<<"Enter the element to find: ";
	cin>>target;
	if(target < M[0][0] || target > M[R-1][C-1]) return false;
	int row = 0;
	int col = C-1;
	while(row<R-1 && col >=0){
		if(target>M[row][col])
			row++;
		else if(M[row][col]>target)
			col--;
		else{
			cout<<row<<"\t"<<col<<endl;
			return true;
		}
	}
	return false;
}

int main(){
	int M[R][C]={{1,4,7,14,15},
		     {2,5,8,12,19},
		     {3,6,9,16,22},
		     {10,13,14,17,24},
		     {18,21,23,26,30}
		     };
	int rows=sizeof(M)/sizeof(M[0]);
	int cols=sizeof(M[0])/sizeof(M[0][0]);
	cout<<rows<<"\t"<<cols<<endl;
	stepWise(M,rows,cols);
}
