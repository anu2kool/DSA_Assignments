//My roll no is B19071
//So, last two digits are 71, and it is a prime number so its distinct prime factor is 71 only.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//The function to find maximum of two positive integers
int Max(int a, int b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}
//The main function to find the GCD of two positive integers.
//The fact used here is that gcd(a,b)=gcd(a,b-a), if a is smaller and vice versa.
//This is because if x is a common factor of a and b then it also divides a-b,
//let a=tx, b=yx then a-b=x(t-y) so we say that x divides (a-b) also.
//And, also gcd(a,0)=a, so it will converge to te state where one number will become 0 and the other one is the gcd.
int GCD(int a, int b)
{
	if(a==0)     //If a is 0, then gcd(0,b)=b
	{
		return b;
	}
	if(b==0)     //If b is,  then gcd(a,0)=a
	{
		return a;
	}
	int gcd=1;
	while(a>0 && b>0)    //This while runs until one of the numbers become 0
	{
		if(a>b)
		{
			a=a-b;
		}
		else
		{
			b=b-a;
		}
	}
	gcd=Max(a,b);    
	return gcd;
}
int main()
{
	int a,b;
	for(int i=1; i<=10; i++)
	{
		for(int j=1; j<=10; j++)
		{
			int gcd1=__gcd(i,j);
			int gcd2=GCD(i,j);
			cout<<gcd1<<" "<<gcd2<<endl;
			if(gcd1!=gcd2)
			{
				cout<<"Wrong"<<endl;
			}
		}
	}
	cout<<"Right"<<endl;
	return 0;
}
