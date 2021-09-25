#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct Pair
{
	char first;
	int second;
};
struct Node
{
	struct Pair p;
	struct Node* next;
};
struct Node* top=NULL;
class Stack
{
	public:
		void push(char ch, int x);
		void display();
		void pop();
		struct Pair Top();
		int empty();
		int size();
		int count;
		Stack()
		{
			count=-1;
		}
};

void Stack::push(char ch, int x)
{
	count++;
	if(top==NULL)
	{
		Node* temp;
		temp=new Node();
		struct Pair p1;
		p1.first=ch;
		p1.second=x;
		temp->p=p1;
		temp->next=NULL;
		top=temp;
	}
	else
	{
		Node* temp;
		temp=new Node();
		struct Pair p1;
		p1.first=ch;
		p1.second=x;
		temp->p=p1;
		temp->next=top;
		top=temp;
	}
}
void Stack::pop()
{
	Node* temp;
	temp=top;
	top=top->next;
	delete temp;
	count-=1;
}
struct Pair Stack::Top()
{
	return top->p;
}
int Stack::empty()
{
	if(top==NULL)
	{
		return 1;
	}
	return 0;
}
int Stack::size()
{
	return count+1;
}
int main()
{
	int row,col;
	cin>>row>>col;
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
			while(stack.Top().first!='n')
			{
				struct Pair p1;
				p1=stack.Top();
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
			int number=stack.Top().second;
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
		if(stack.Top().first=='N')
		{
			pN.second+=stack.Top().second;	
		}	
		if(stack.Top().first=='S')
		{
			pS.second+=stack.Top().second;	
		}
		if(stack.Top().first=='E')
		{
			pE.second+=stack.Top().second;	
		}
		if(stack.Top().first=='W')
		{
			pW.second+=stack.Top().second;	
		}
		stack.pop();
	}
	int y_dir=pS.second-pN.second;
	int x_dir=pE.second-pW.second;
	int y_cor=(row+y_dir%row)%row;
	int x_cor=(col+x_dir%col)%col;
	cout<<y_cor<<" "<<x_cor<<endl;
	return 0;
}
