#include<iostream>
#include<map>
using namespace std;

int main(){

        map <char,int> m;
        int data,choice;

        cout<<"Inserting an element"<<endl;
        m['a']=1;
        m['b']=2;
        pair<map<char,int>::iterator,bool> ret;
        ret = m.insert(pair<char,int>('a',500));
        if(ret.second==false)
                cout<<" Element already exists"<<endl;
        if (ret.second==false) {
                  cout << "element 'a' already existed";
                  cout << " with a value of " << ret.first->second << '\n';
        }
        std::map<char,int>::iterator it;
        it=m.find('a');
        if(it!=m.end())
                cout<<"Not  an end element"<<endl;

}

