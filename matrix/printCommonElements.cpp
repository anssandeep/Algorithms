#include<iostream>
#include<unordered_map>
// Specify number of rows and columns
#define M 4
#define N 5
using namespace std;

void printCommonElements(int mat[M][N]){
	unordered_map <int,int> mp;
	int i=0,j=0;
	for(i=0;i<N;i++)
		mp[mat[0][i]]=1;

	for(int i=1;i<M;i++){
		for(int j=0;j<N;j++){
			if(mp[mat[i][j]] == i){
				mp[mat[i][j]]=i+1;
			}
			if(i == M-1)
				cout<<mat[i][j]<<" ";
		}
	}
	cout<<endl;
}

int main(
	int mat[M][N] ={
        		{1, 2, 1, 4, 8},
        		{3, 7, 8, 5, 1},
        		{8, 7, 7, 3, 1},
        		{8, 1, 2, 7, 9},
    			};
 
    	printCommonElements(mat);
    	return 0;
}
