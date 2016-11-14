#include <bits/stdc++.h>
using namespace std;

bool isOneFlip(string str){
	int sum=0;
	int n = str.length();
	for(int i=0;i<n;i++)
		sum += str[i] - '0';
	 return (sum == n-1 || sum == 1);
}

int main(){
	isOneFlip("101101111")?cout<<"Yes\n":cout<<"No\n";
}
