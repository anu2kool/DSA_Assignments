#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Point
{
	int x;
	int y;
};
void Display(struct Point arr[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<arr[i].x<<" "<<arr[i].y<<endl;
	}
}
int main()
{
	cout<<"Hello";
	struct Point arr[10];
	for(int i=0; i<10; i++)
	{
		arr[i].x=i;
		arr[i].y=i*i;
	}
	Display(arr,10);
	return 0;
}
