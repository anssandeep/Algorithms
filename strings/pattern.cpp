// C++ program to find if a string follows order
// defined by a given pattern.
#include <bits/stdc++.h>
using namespace std;
 
const int CHAR_SIZE = 256;

bool checkPatter(string str, string pat){
	vector<int> label(CHAR_SIZE, -1);
	int order =1;
	for(int i=0;i<pat.length();i++){
		label[pat[i]]=order;
		order++;
	}
	
	
}


int main()
{
    string str = "engineers rock";
    string pattern = "gsr";
    cout << boolalpha << checkPattern(str, pattern);
    cout<<endl;
    return 0;
}
