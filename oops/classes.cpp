#include<iostream>
using namespace std;

class DateClass{
	int m_year;
        int m_month;
        int m_day;
public:
	DateClass(){
		m_year=2016;
		m_month=11;
		m_day=2;
	}
	void set(int a,int b,int c){
		m_year=a;
		m_month=b;
		m_day=c;
	}
	void print(){
		cout<<m_year<<"/"<<m_month<<"/"<<m_day<<endl;
	}
};

int main(){
	DateClass today;
	today.print();
	today.set(2020,12,14);
	today.print();
	return 0;
}
