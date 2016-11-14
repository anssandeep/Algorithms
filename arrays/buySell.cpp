#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void stockBuySell(int price[],int n){
	int profit=0;
	int minP=INT_MAX;
	for(int i=0;i<n;i++){
		profit = max(profit,price[i]-minP);
		minP = min(price[i],minP);
	}
	cout<<profit<<endl;
}

// Driver program to test above functions
int main()
{
	// stock prices on consecutive days
    	int price[] = {100, 180, 260, 310, 40, 535, 695};
    	int n = sizeof(price)/sizeof(price[0]);
 
    	// fucntion call
    	stockBuySell(price, n);
 
    	return 0;
}
