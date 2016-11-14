// Standard Template Library example

#include <iostream>
#include <list>
using namespace std;

// Simple example uses type int

list<int> listSub(list<int> L,list<int> M){
	if(L.size() != M.size()){
		if(L.size()<M.size()){
			int diff = M.size() - L.size();
			for(int i=0;i<diff;i++){
				L.push_front(0);
			}
		}
		else{
                	int diff = L.size() - M.size();
                	for(int i=0;i<diff;i++){
                        	M.push_front(0);
                	}
        	}
	}
	list<int>::iterator it,it1;
	for(it=L.begin(), it1=M.begin();it!=L.end() && it1!=M.end();it++,it1++){
		if(*it == *it1)
			*it=0;
		else if(*it > *it1)
			*it = *it - *it1;
		else
			*it = *it1 - *it;
	}
	return L;
}

main()
{
	list<int> L;
   	L.push_back(0);              // Insert a new element at the end
   	L.push_back(5);
   	L.push_back(6);

  	list<int> M;
	M.push_back(9);
	list<int> K =listSub(L,M);
	list<int>::iterator it;
	for (it=K.begin(); it!=K.end();it++)
		cout<<*it<<endl;
   	return 0;
}
