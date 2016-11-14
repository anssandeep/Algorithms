#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;


void computeLPSArray(char *pat, int M, int *lps);

void KMPSearch(char *pat, char *txt){
	int M = strlen(pat);
	int N = strlen(txt);
	int *lps = (int *)malloc(sizeof(int)*M);
	computeLPSArray(pat,M,lps);
	int i=0;
	int j=0;
	while(i<N){
		if(pat[j]==txt[i]){
			i++;
			j++;
		}
		if(j==M){
			cout<<" Found String at :"<<i-j<<endl;
			j = lps[j-1];
		}
		else if(i<N && pat[j]!=txt[i]){
			if(j!=0)
				j = lps[j-1];
			else
				i = i + 1;
		}
	}
}

void computeLPSArray(char *pat, int M, int *lps){
	int len = 0;
	int i=1,j=0;
	lps[0] = 0; // lps[0] is always 0
	while (i < M){
		if(pat[i]==pat[j]){
			lps[i]=j+1;
			i++;
			j++;
		}
		else{
			if(j!=0){
				j = lps[j-1];
			}
			else {
				lps[i]=0;
				i++;
			}
		}
		
	}
}

// Driver program to test above function
int main()
{
	char *txt = "ABABDABACDABABCABAB";
	char *pat = "ABABCABAB";
	KMPSearch(pat, txt);
   	return 0;
}
