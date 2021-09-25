#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
struct Pair
{
	char first;
	int second;
};
class Stack
{
	public:
		struct Pair s[MAX];
		struct Pair top();
		int size();
		void push(char ch, int x);
		void pop();
		void display();
		int Top;
		int empty();
		Stack()
		{
			Top=-1;
			for(int i=0; i<MAX; i++)
			{
				s[i].first='-';
				s[i].second=-1;
			}
		}
};
void Stack::push(char ch, int x)
{
	Top++;
	s[Top].first=ch;
	s[Top].second=x;
}
struct Pair Stack::top()
{
	return s[Top];
}
void Stack::display()
{
	int t=Top;
	while(t>-1)
	{
		cout<<s[t].first<<" "<<s[t].second<<endl;
		t--;
	}
}
void Stack::pop()
{
	s[Top].first='-';
	s[Top].second=-1;
	Top--;
}
int Stack::size()
{
	return Top+1;
}
int Stack::empty()
{
	if(Top==-1)
	{
		return 1;
	}
	return 0;
}
int main()
{
	string str;
	cin>>str;
	Stack stack;
	for(int i=0; i<str.size(); i++)
	{
		if(str[i]=='(')
		{
			struct Pair p;
			p.first='(';
			p.second=0;
			stack.push(p.first,p.second);
		}
		else if(str[i]==')')
		{
			int N,W,S,E;
			N=0;
			W=0;
			S=0;
			E=0;
			while(stack.top().first!='n')
			{
				struct Pair p1;
				p1=stack.top();
				stack.pop();
				if(p1.first=='N')
				{
					N+=p1.second;
				}
				else if(p1.first=='S')
				{
					S+=p1.second;
				}
				else if(p1.first=='E')
				{
					E+=p1.second;
				}
				else if(p1.first=='W')
				{
					W+=p1.second;
				}
			}
			int number=stack.top().second;
			stack.pop();
			N=N*number;
			S=S*number;
			E=E*number;
			W=W*number;
			if(N>0)
			{
				struct Pair n;
				n.first='N';
				n.second=N;
				stack.push(n.first,n.second);
			}
			if(S>0)
			{
				struct Pair s;
				s.first='S';
				s.second=S;
				stack.push(s.first,s.second);
			}
			if(E>0)
			{
				struct Pair e;
				e.first='E';
				e.second=E;
				stack.push(e.first,e.second);
			}
			if(W>0)
			{
				struct Pair w;
				w.first='W';
				w.second=W;
				stack.push(w.first,w.second);
			}
			
		}
		else if(int(str[i])-48>=0 && int(str[i])-48<=9)
		{
			int no=int(str[i])-48;
			struct Pair p;
			p.first='n';
			p.second=no;
			stack.push(p.first,p.second);
		}
		else 
		{
			if(str[i]=='N')
			{
				struct Pair p;
				p.first='N';
				p.second=1;
				stack.push(p.first,p.second);
			}
			if(str[i]=='S')
			{
				struct Pair p;
				p.first='S';
				p.second=1;
				stack.push(p.first,p.second);
			}
			if(str[i]=='E')
			{
				struct Pair p;
				p.first='E';
				p.second=1;
				stack.push(p.first,p.second);
			}
			if(str[i]=='W')
			{
				struct Pair p;
				p.first='W';
				p.second=1;
				stack.push(p.first,p.second);
			}
		}
	}
	struct Pair pN;
	struct Pair pS;
	struct Pair pE;
	struct Pair pW;
	pN.first='N';
	pN.second=0;
	pS.first='S';
	pS.second=0;
	pE.first='E';
	pE.second=0;
	pW.first='W';
	pW.second=0;
	while(!stack.empty())
	{
		if(stack.top().first=='N')
		{
			pN.second+=stack.top().second;	
		}	
		if(stack.top().first=='S')
		{
			pS.second+=stack.top().second;	
		}
		if(stack.top().first=='E')
		{
			pE.second+=stack.top().second;	
		}
		if(stack.top().first=='W')
		{
			pW.second+=stack.top().second;	
		}
		stack.pop();
	}
	cout<<pN.first<<" "<<pN.second<<"\n";
	cout<<pS.first<<" "<<pS.second<<"\n";
	cout<<pE.first<<" "<<pE.second<<"\n";
	cout<<pW.first<<" "<<pW.second<<"\n";
	return 0;
}
