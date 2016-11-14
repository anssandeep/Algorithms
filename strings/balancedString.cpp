#include<iostream>
#include<string>
#include<map>
using namespace std;

map <int,int> mymap;

void checkBalance(string str){
	mymap.insert(make_pair('(', 1));
	mymap.insert(make_pair(')', -1));
	mymap.insert(make_pair('[', 2));
	mymap.insert(make_pair(']', -2));
	mymap.insert(make_pair('{', 3));
	mymap.insert(make_pair('}', -3));
	map<int,int>::const_iterator it;
	it = mymap.begin();
	while (it != mymap.end()) // while it hasn't reach the end
    	{
        	cout << it->first << "=" << it->second << " "; // print the value of the element it points to
        	++it; // and iterate to the next element
    	}

    	cout << endl;
	int sum=0;
	for(int i=0;i<str.length();i++){
		sum = sum + mymap.find(int(str[i]))->second;
	}
	if(sum == 0)		
		cout<<" Balanced"<<endl;
	else
		cout<<" Not balanced"<<endl;
}

int main(){
	string arr="<({(})[]>";
	checkBalance(arr);
	return 0;
}
