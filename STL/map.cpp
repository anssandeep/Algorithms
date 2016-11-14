#include <iostream>
#include <map>
#include <string>
int main()
{
    using namespace std;
 
    map<int, int> mymap;
    mymap.insert(make_pair(4, 10));
    mymap.insert(make_pair(2, 8));
    mymap.insert(make_pair(1, 2));
    mymap.insert(make_pair(3,6));
    mymap.insert(make_pair(6, 3));
    mymap.insert(make_pair(5, 7));
 
    map<int, int>::const_iterator it; // declare an iterator
    it = mymap.begin(); // assign it to the start of the vector
    while (it != mymap.end()) // while it hasn't reach the end
    {
        cout << it->first << "=" << it->second << " "; // print the value of the element it points to
        ++it; // and iterate to the next element
    }
 
    cout << endl;
}
