#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
	int count=0;
	int r=0;
	int i,j,k,l;
	int n;
	vector<int> vec;
	for(n=1; n<=100; n++)
	{
		r=0;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=i; j++)
		{
			for(k=j; k<=(i+j); k++)
			{
				for(l=1; l<=(i+j-k); l++)
				{
					r+=1;
				}
			}
		}
	}
	vec.push_back(r);
	}
	for(i=0; i<vec.size(); i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;
	cout<<"R: "<<r<<endl;
	return 0;
}
