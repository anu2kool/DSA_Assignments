#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//This is a function to find the maximum of two positive integers by comparing the two. 
int Max(int a, int b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}
//This is a function to find the minimum of two positive integers by comparing the two.
int Min(int a, int b)
{
	if(a>b)
	{
		return b;
	}
	return a;
}
//The function to check if the integer is even or odd.
bool isEven(int n) 
{  
    return ((n / 2) * 2 == n); 
} 
//The main function to find the greatest common divisor using only addtion, subtraction and mutliplication, division by 2.
//This function uses the fact that if two numbers are even, then they will have definitely has one 2 as common factor,
//then gcd(a,b)=2*gcd(a/2,b/2), if one is even and the other is odd, then they do not has 2 as common factor, 
//gcd(a,b)=gcd(a/2,b) if a is even only and gcd(a,b)=gcd(a,b/2) and if both are odd then
// gcd(a,b)=gcd(a-b,b) if a>b and gcd(a,b)=gcd(a,b-a) if b>a.
//This is because if x is a common factor of a and b then it also divides a-b,
//let a=tx, b=yx then a-b=x(t-y) so we say that x divides (a-b) also.
//And, also gcd(a,0)=a, so it will converge to te state where one number will become 0 and the other one is the gcd.
int GCD(int a, int b)
{
	if(a==0 && b==0)
	{
		return -1;
	}
	if(a==0)
	{
		return b;
	}
	if(b==0)
	{
		return a;
	}
	int prod_of_2s=1, ans_gcd=1;
	while(a>0 && b>0)
	{
		if(isEven(a) && isEven(b))
		{
			prod_of_2s=prod_of_2s*2;
			a=a/2;
			b=b/2;
		}
		else if(isEven(a) && !isEven(b))
		{
			a=a/2;
		}
		else if(isEven(b) && !isEven(a))
		{
			b=b/2;
		}
		else
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
	}
	ans_gcd=Max(ans_gcd,Max(a,b));
	while(prod_of_2s>1)
	{
		ans_gcd=ans_gcd*2;
		prod_of_2s=prod_of_2s/2;
	}
	return ans_gcd;
}
int main()
{
	int a,b;
	int count=0;
	for(int i=1; i<=1000; i++)
	{
		for(int j=1; j<=10000; j++)
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
