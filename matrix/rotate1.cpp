#include<iostream>
#define N 4
using namespace std;

void rotate(int mat[N][N],int n){

	for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                        cout<<mat[i][j]<<"\t";
                }
                cout<<endl;
        }
        cout<<endl;

	for (int x = 0; x <= N / 2; x++){
		for(int y=x;y<N-x-1;y++){
			int tmp=mat[x][y];
			mat[x][y]=mat[y][N-1-x];
			mat[y][N-1-x]=mat[N-x-1][N-y-1];
			mat[N-x-1][N-y-1]=mat[N-1-y][x];
			mat[N-y-1][x]=tmp;
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<mat[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main(){
	int mat[N][N]={
			{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12},
			{13,14,15,16}
		      };
	rotate(mat,N);
	return 0;
}
