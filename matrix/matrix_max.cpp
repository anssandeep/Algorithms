/** Complexity: Time O(n^2) and space O(n). **/


#include<bits/stdc++.h>
using namespace std;
#define n 5

//function to calculate maxValue.
int findMaxValue(int mat[][n]){
    //store the maximum value
    int maxValue = INT_MIN;
    //create a matrix of n+1 size and initialize with INT_MIN.
    int maxArr[n+1];
    //filling maxArr with INT_MIN.
    for(int i=0;i<n;i++){
        maxArr[i] = INT_MIN;
    }
    //maxArr will store the max values of the previously evaluated row.
    //initially maxArr[n] will store the last element of the given 2D matrix.
    maxArr[n]= mat[n-1][n-1];

    //calculating maxArr elements as well as maxValue.
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            //calculating maxArr elements.
            maxArr[j] = max(maxArr[j],max(maxArr[j+1],mat[i][j]));
            //handle the edge case and calculate maxValue.
            if(i-1>=0 && j-1>=0)
                maxValue = max(maxArr[j]-mat[i-1][j-1],maxValue);
        }
    }
    //return calculated maxValue.
    return maxValue;
}

//Driver program to test the above function.
int main(){
    int mat[n][n] = {
        {1,2,-1,-4,-20},
        {-8,-3,4,2,1},
        {3,8,6,1,3},
        {-4,-1,1,7,-6},
        {0,-4,10,-5,1}
        };
    cout<<"Maximum value is: "<<findMaxValue(mat);

return 0;
}


