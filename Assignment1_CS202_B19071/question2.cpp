//My roll no is B19071
//So, last two digits are 71, and it is a prime number so its distinct prime factor is 71 only.
#include<iostream>
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
	cout<<"Enter two positive integers"<<endl;
	cin>>a;
	cin>>b;
	if(a<0 || b<0)
	{
		cout<<"Please, Enter positive integers only!!"<<endl;
	}
	else if(a==0 && b==0)
	{
		cout<<"The GCD of 0 and 0 is not defined."<<endl;
	}
	else
	{
		int gcd=GCD(a,b);
		cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd<<"\n";
	}
	
	return 0;
}
