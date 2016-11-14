#include<iostream>
#include<map>
using namespace std;

int main(){
        std::map<char,int> mymap;
        std::map<char,int>::iterator it;
        pair<map<char,int>::iterator,bool> ret;
        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;
        mymap['d']=40;
        mymap['e']=50;
        it=mymap.find('b');
        //cout<<it<<endl;
        mymap.erase(it);
        ret = mymap.insert(pair<char,int>('a',500));
        if(ret.second==true)
                cout<<" inserted successfully"<<endl;
        else
                cout<<"already exists"<<endl;
        //mymap.erase(it,mymap.end());
        //show content
        for(it=mymap.begin();it!=mymap.end();++it)
                cout<<it->first<<"=>"<<it->second<<endl;
}
