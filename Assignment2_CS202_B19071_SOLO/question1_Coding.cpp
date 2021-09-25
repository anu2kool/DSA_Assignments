//Name:Anukool Dwivedi
//Roll No:B19071
//Branch:CSE
//SOLO
//Group13
#include<iostream>
using namespace std;
//The structure Pair to store first and second members together that will be used to store the starting and ending timing 
//of the movies.
struct Pair
{
	int first;
	int second;
};

//Merge function to merge the arrays.
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
		else
		{
			tempC[k++]=tempA[i];
			i++;
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
//main function of merge sort 
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
//A utility function to call the mergesort function 
void Sort(struct Pair A[], int size)
{
	MergeSort(A,0,size-1);
}
int main()
{
	int n;
	cout<<"Enter the number of movies:"<<endl;
	cin>>n;
	//Declaring the array of type Pair of size n
	struct Pair intervals[n];
	int i,j;
	cout<<"Enter the movies:"<<endl;
	for(int i=0; i<n; i++)
	{
		int start, end;
		cin>>start;
		cin>>end;
		intervals[i].first=start;
		intervals[i].second=end;
	}
	//Sorting the intervals according to the ending times.
	Sort(intervals,n);
	int prev_ending=-1;
	int count=0;
	struct Pair movie_timings[n];
	for(i=0; i<n; i++)
	{
		if(prev_ending==-1)
		{
			count+=1;
			prev_ending=intervals[i].second;
			movie_timings[count-1]=intervals[i];
		}
		else
		{
			if(intervals[i].first>=prev_ending)
			{
				count+=1;
				prev_ending=intervals[i].second;
				movie_timings[count-1]=intervals[i];
			}
		}
	}
	cout<<"Maximum number of movies: "<<count<<"\n";
	cout<<"The movie timings are:"<<endl;
	for(i=0; i<count; i++)
	{
		cout<<movie_timings[i].first<<" "<<movie_timings[i].second<<"\n";
	}
	return 0;
}
