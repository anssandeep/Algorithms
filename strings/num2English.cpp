#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution
{
	private:
		static const string _n2sL10[] ;
		static const string _n2sTens[] ;
		static const string _n2sTeens[] ;
		static void num2StringL10(int num)
		{
			cout <<_n2sL10[num];
		}
		static void num2StringTeens(stack<int>& myStack)
		{
			int n1 = myStack.top(); myStack.pop();
			int n2 = myStack.top(); myStack.pop();
			n1 = n1*10 + n2;
			cout <<_n2sTeens[n1 - 10];
		}
		static void num2StringTens(int num)
		{
			cout <<_n2sTens[num]; 
		}

		static void num2String(stack<int>& myStack, int size)
		{
			stack<int> newStack;
			switch(size)
			{
				
				case 1:
					num2StringL10(myStack.top());
					myStack.pop();
					return;
					break;
				case 2: 
					{
					int num = myStack.top();
					if(num == 0)
					{
						myStack.pop();
						num2StringL10(myStack.top());
						cout<<" ";	
						myStack.pop();
						return;
					}
					if(num == 1)
					{
						num2StringTeens(myStack);
						cout<< " ";
						return;
					}
					else
					{
						num2StringTens(myStack.top());
						myStack.pop();
						if(myStack.top() == 0)
						{
							myStack.pop();
							return;
						}
						cout<<" ";
						num2StringL10(myStack.top());
						cout<<" ";
						myStack.pop();
						return;
					}
					}
					break;
				case 3:
					{
					int n  = myStack.top();
					num2StringL10(myStack.top());
					myStack.pop();
					if(n != 0)
					{ cout<<" Hundred";
				  	  cout<<" And ";
					}
					num2String(myStack, 2);
					cout<< " ";
					}
					break;
				case 4:
					num2String(myStack, 1);
					cout << " Thousand ";
					num2String(myStack, myStack.size());
					break;
				case 5:
					num2String(myStack, 2);
					cout<<" Thousand ";
					num2String(myStack, myStack.size());
					break;
				case 6: 
					num2String(myStack, 3);
					cout<<" Thousand ";
					num2String(myStack, myStack.size());
					break;	
					 
				default:
					break;
			}
		}	

	public:
		static void numToString(int N)
		{
			//Special
			switch(N)
			{
				case 0:
					cout<<"Zero"; return;
				case 100:
					cout<<"One Hundred"; return;
				case 1000:
					cout<<"One Thousand"; return;
				case 1000000:
					cout<<"One Million"; return;
				case 1000000000:
					cout<<"One Billion"; return;
				default:
					break;
			}
			stack<int> myStack;
			int num = N;
			while(num)
			{
				myStack.push(num%10);
				num/=10;
			}
			num2String(myStack, myStack.size());
		}
};

const string Solution::_n2sL10[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
const string Solution::_n2sTens[] = {"", "",  "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const string Solution::_n2sTeens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};


int main()
{
	int num, n;
	cin >> num;
	cin >>n;
	for(int i = num; i<=n; ++i)
	{ Solution::numToString(i); cout<<endl;} 
	cout<< endl;
}
