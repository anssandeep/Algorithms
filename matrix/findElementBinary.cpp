#include<iostream>
#define R 5
#define C 5
using namespace std;

int M[R][C]={{1,4,7,14,15},
             {2,5,8,12,19},
             {3,6,9,16,22},
             {10,13,14,17,24},
             {18,21,23,26,30}
             };

bool findNum(int arr[R][C],int xmin, int xmax, int ymin,int ymax,int key)
{
    if (xmin > xmax || ymin > ymax || xmax < xmin || ymax < ymin) return false;
    if ((xmin == xmax) && (ymin == ymax) && (arr[xmin][ymin] != key)) return false;
    if (arr[xmin][ymin] > key || arr[xmax][ymax] < key) return false;
    if (arr[xmin][ymin] == key || arr[xmax][ymax] == key) return true;

    int xnew = (xmin + xmax)/2;
    int ynew = (ymin + ymax)/2;

    if (arr[xnew][ynew] == key) return true;
    if (arr[xnew][ynew] < key)
    {
        if (findNum(arr,xnew+1,xmax,ymin,ymax,key))
            return true;
        return (findNum(arr,xmin,xmax,ynew+1,ymax,key));
    } else {
        if (findNum(arr,xmin,xnew-1,ymin,ymax,key))
            return true;
        return (findNum(arr,xmin,xmax,ymin,ynew-1,key));
    }
}

bool stepWise(int M[R][C],int min_row,int min_col,int max_row,int max_col,int target){
	if(target<M[min_row][min_col])
		return false;
        if(target>M[max_row][max_col])
                return false;
        int i=max_row+min_row/2;
        int j=max_col+min_col/2;
	if(M[i][j]==target){
		cout<<"Element Found"<<endl;
		cout<<"Row: "<<i<<"\t"<<"Col: "<<j<<endl;
		return true;
	}
	else if(M[i][j]>target){
		cout<<"Number greater than target"<<endl;
		cout<<i<<"\t"<<j<<"\t"<<M[i][j]<<endl;
		stepWise(M,i,j,max_col,max_col,target);
	}
	else if(M[i][j]<target){
		cout<<"Mid element lesser than target"<<endl;
		cout<<i<<"\t"<<j<<"\t"<<M[i][j]<<endl;
		stepWise(M,min_row,min_col,i,j,target);
	}
	else{
		cout<<"Element not Found"<<endl;
		return false;
	}
}

int main(){
	int target;
	int rows=sizeof(M)/sizeof(M[0]);
	int cols=sizeof(M[0])/sizeof(M[0][0]);
	cout<<rows<<"\t"<<cols<<endl;
	cout<<"Enter the element :";
	cin>>target;
	//stepWise(M,0,0,rows,cols,target);
	if(findNum(M,0,cols-1,0,rows-1,target))
		cout<<"Element Found"<<endl;
	else
		cout<<"Element not found"<<endl;
}
