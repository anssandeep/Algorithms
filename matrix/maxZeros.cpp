#include<iostream>
#define R 5
#define C 5
using namespace std;

void countZeros(int mat[R][C], int rows, int cols){
	int r,count=0,i;
	i=0;
	for(int j=C;j>0 && i< R;){
		if(mat[i][j-1]==1)
			j--;
		else{
			count = count + j;	
			i = i +1;
		}
	}
	cout<<count<<endl;
}

// Driver Program to test above functions
int main()
{
	int N=5;
	int mat[R][C] =
    	{{ 0, 0, 0, 0, 1 },
        { 0, 0, 0, 1, 1 },
        { 0, 0, 1, 1, 1 },
        { 0, 0, 1, 1, 1 },
        { 0, 1, 1, 1, 1 }
    	};
	
	int cols = sizeof(mat)/sizeof(mat[0]);
	int rows = sizeof(mat[0])/sizeof(mat[0][0]);
	countZeros(mat,rows,cols);
	return 0;
}
