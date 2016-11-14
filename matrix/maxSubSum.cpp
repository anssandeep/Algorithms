// An efficient C++ program to find maximum sum
// sub-square matrix
#include <bits/stdc++.h>
using namespace std;
 
// Size of given matrix
#define N 5

void printMaxSumSub(int mat[][N], int k){
	if (k > N) return;
	
	int stripSum[N][N];

	//preprocess column by column
	for(int j=0;j<N;j++){
		int sum = 0;
		for(i=0;i<N;i++){
			sum = sum + mat[j][i];	
		}
		mat[N-1][i]=sum;
	}
	
	//
}

// Driver program to test above function
int main()
{
	int mat[N][N] = {{1, 1, 1, 1, 1},
        		{2, 2, 2, 2, 2},
        		{3, 8, 6, 7, 3},
        		{4, 4, 4, 4, 4},
        		{5, 5, 5, 5, 5},
    			};
    	int k = 3;
  
    	cout << "Maximum sum 3 x 3 matrix is\n";
    	printMaxSumSub(mat, k);
 
    	return 0;
}
