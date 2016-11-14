#include<iostream>
using namespace std;

string reverseWords(string str) {
        string tokens[] = str.split(" ");
        for (int first = 0, last = tokens.length - 1; first < last; first++, last--) {
            string swapStr = tokens[first];
            tokens[first] = tokens[last];
            tokens[last] = swapStr;
        }
        return string.join(" ", tokens);
}

int main(){
	string arr="Man bites dog";
	cout<<reverseWords(arr)<<endl;
	return 0;
}
