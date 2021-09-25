#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string str;
	cin>>str;
	stack< pair<char, int> > stack;
	for(int i=0; i<str.size(); i++)
	{
		if(str[i]=='(')
		{
			pair<char, int> p;
			p.first='(';
			p.second=0;
			stack.push(p);
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
				pair<char, int>p1;
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
				pair<char, int> n;
				n.first='N';
				n.second=N;
				stack.push(n);
			}
			if(S>0)
			{
				pair<char, int> s;
				s.first='S';
				s.second=S;
				stack.push(s);
			}
			if(E>0)
			{
				pair<char, int> e;
				e.first='E';
				e.second=E;
				stack.push(e);
			}
			if(W>0)
			{
				pair<char, int> w;
				w.first='W';
				w.second=W;
				stack.push(w);
			}
			
		}
		else if(int(str[i])-48>=0 && int(str[i])-48<=9)
		{
			int no=int(str[i])-48;
			pair<char, int> p;
			p.first='n';
			p.second=no;
			stack.push(p);
		}
		else 
		{
			if(str[i]=='N')
			{
				pair<char, int>p;
				p.first='N';
				p.second=1;
				stack.push(p);
			}
			if(str[i]=='S')
			{
				pair<char, int>p;
				p.first='S';
				p.second=1;
				stack.push(p);
			}
			if(str[i]=='E')
			{
				pair<char, int>p;
				p.first='E';
				p.second=1;
				stack.push(p);
			}
			if(str[i]=='W')
			{
				pair<char, int>p;
				p.first='W';
				p.second=1;
				stack.push(p);
			}
		}
	}
	pair<char, int> pN;
	pair<char, int> pS;
	pair<char, int> pE;
	pair<char, int> pW;
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
