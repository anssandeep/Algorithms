#include<iostream>
using namespace std;

#define n 5

void printSumTricky(int mat[][n], int k){
	if(k>n) return 0;

	int stripSum[n][n];
	
	for(int j=0;j<n;j++){
		int sum=0;
		for (int i=0; i<k; i++)
			sum += mat[i][j];
		stripSum[0][j] = sum;
		
	}
	
}

int main()
{
	int mat[n][n] = {{1, 1, 1, 1, 1},
			{2, 2, 2, 2, 2},
			{3, 3, 3, 3, 3},
			{4, 4, 4, 4, 4},
			{5, 5, 5, 5, 5},
			};
    	int k = 3;
    	printSumTricky(mat, k);
    	return 0;
}
