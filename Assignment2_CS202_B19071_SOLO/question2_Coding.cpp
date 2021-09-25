//Name:Anukool Dwivedi
//Roll No:B19071
//Branch:CSE
//SOLO
//Group13
#include<iostream>
using namespace std;
//Structure Pair to store the first and second members together, here we store number at first and its frequency at second.
struct Pair
{
	int first;
	int second;
};

//The function to find the maximum of the array
int Max(int balls[], int n)
{
	int max1=balls[0];
	for(int i=1; i<n; i++)
	{
		if(balls[i]>max1)
		{
			max1=balls[i];
		}
	}
	return max1;
}
//The function to merge the arrays
void Merge(struct Pair A[], int l, int mid, int h)
{
	int i,j,k,n1,n2,n3;
	n1=mid-l+1;
	n2=h-mid;
	n3=h-l+1;
	struct Pair tempA[n1];
	struct Pair tempB[n2];
	struct Pair tempC[n3];
	for(i=0; i<n1; i++)
	{
		tempA[i]=A[i+l];
	}
	for(j=0; j<n2; j++)
	{
		tempB[j]=A[mid+1+j];
	}
	i=0;
	j=0;
	k=0;
	while(i<n1 && j<n2)
	{
		if(tempA[i].second>tempB[j].second)
		{
			tempC[k++]=tempB[j];
			j++;
		}
		else if(tempA[i].second<tempB[j].second)
		{
			tempC[k++]=tempA[i];
			i++;
		}
		else
		{
			if(tempA[i].first<tempB[j].first)
			{
				tempC[k++]=tempA[i];
				i++;
			}
			else
			{
				tempC[k++]=tempB[j];
				j++;
			}
		}
	}
	while(i<n1)
	{
		tempC[k++]=tempA[i++];
	}
	while(j<n2)
	{
		tempC[k++]=tempB[j++];
	}
	for(i=0; i<n3; i++)
	{
		A[i+l]=tempC[i];
	}
}
//Merge sort main function
void MergeSort(struct Pair A[], int l, int h)
{
	if(l<h)
	{
		int mid=(h+l)/2;
		MergeSort(A,l,mid);
		MergeSort(A,mid+1,h);
		Merge(A,l,mid,h);
	}
}
//Helper function to call the merge sort function.
void Sort(struct Pair A[], int size)
{
	MergeSort(A,0,size-1);
}
int main()
{
	int n;
	cout<<"Enter the number of balls:"<<endl;
	cin>>n;
	int i;
	int balls[n];
	cout<<"Enter the balls:"<<endl;
	for(i=0; i<n; i++)
	{
		cin>>balls[i];
	}
	int max_ball_no=Max(balls,n);
	int count[max_ball_no+1];
	for(i=0; i<=max_ball_no; i++)
	{
		count[i]=0;  
	}
	for(i=0; i<n; i++)
	{
		count[balls[i]]++;
	}
	struct Pair freq[max_ball_no+1];
	int size=0;
	for(i=0; i<=max_ball_no; i++)
	{
		if(count[i]>0)
		{
			freq[size].first=i;
			freq[size].second=count[i];
			size++;
		}
	}
	//Sorting the freq array on the basis of frequency stored at second place .
	Sort(freq,size);
	cout<<"The sorted balls according to the frequency:"<<endl;
	for(i=0; i<size; i++)
	{
		for(int j=0; j<freq[i].second; j++)
		{
			cout<<freq[i].first<<" ";
		}
	}
	cout<<endl;
	return 0;
}
