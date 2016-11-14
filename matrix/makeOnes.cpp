#include<iostream>
#define r 3
#define c 4
using namespace std;

void makeOne(int arr[r][c],int R,int C){
	for(int i=1;i<r;i++){
		for(int j=1;j<c;j++){
			if(arr[i][j]==1)
				arr[0][j]=1;
		}
	}	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main(){
	int mat[r][c]={{1,0,0,1},
                    {0,0,1,0},
                    {0,0,0,0}
			};
	makeOne(mat,r,c);
	return 0;
}
