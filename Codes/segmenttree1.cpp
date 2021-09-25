#include<iostream>
#include <bits/stdc++.h> 
using namespace std; 
int N;
int tree[500001];
int arr[500001];
int lazy[500001];
void Update_Range(int si, int ss, int se, int us, int ue, int d) 
{ 
    if (lazy[si] != 0) 
    { 
        tree[si]-=lazy[si]; 
        if (ss!=se) 
        { 
            lazy[si*2 + 1]+= lazy[si]; 
            lazy[si*2 + 2]+= lazy[si]; 
        } 
        lazy[si] = 0; 
    } 
    if (ss>se || ss>ue || se<us) 
        {
        	return ; 
		}
    if (ss>=us && se<=ue) 
    { 
        tree[si] -= d; 
        if (ss != se) 
        { 
            lazy[si*2+1]+=d; 
            lazy[si*2]+=d; 
        } 
        return; 
    } 
    int mid = (ss+se)/2; 
    Update_Range(si*2, ss, mid, us, ue, d); 
    Update_Range(si*2+1, mid+1, se, us, ue, d); 
    tree[si] = min(tree[si*2+1] ,tree[si*2]); 
} 
void Segment_Tree(int A[], int ss, int se, int si) 
{ 
    if (ss>se) 
    {
    	return; 
	}
    if (ss == se) 
    { 
        tree[si] = A[ss]; 
        return; 
    } 
    int mid = (ss + se)/2; 
    Segment_Tree(A, ss, mid, si*2); 
    Segment_Tree(A, mid+1, se, si*2+1); 
    tree[si] = min(tree[si*2 + 1] , tree[si*2]);
} 

int Less(int ss, int se, int value, int si) 
{ 
    if (lazy[si] != 0) 
    { 
        tree[si] -= lazy[si]; 
        if (ss != se) 
        {
            lazy[si*2+1] += lazy[si]; 
            lazy[si*2+2] += lazy[si]; 
        } 
        lazy[si] = 0; 
    } 
    if(ss == se)
    {
         if(tree[si] < value)
         {
              return ss;
         }
         else
         {
              return INT_MAX;
         }
    }
    int mid = ss + (se-ss)/2;
    int index1 = INT_MAX;
    int index2 = INT_MAX;
    if(tree[2*si]-lazy[2*si] < value)
    {  
        index1=Less(ss,mid,value,2*si);
    }
    else if(tree[2*si+1]-lazy[2*si+1] < value)
    {
        index1=Less(mid+1,se,value,2*si+1);
    }
    return min(index1,index2);
} 
int main() 
{ 

	int N;
	int Q;
	cin>>N>>Q;
	for(int i=1; i<=N; i++)
	{
		cin>>arr[i];
	}
     Segment_Tree(arr, 1, N, 1);
     for(int i=0; i<Q; i++)
     {
      int t;
      cin>>t;
      if(t==1)
      {
          int l,r,v;
          cin>>l>>r>>v;
          l++;
          r++;
          Update_Range(1, 1, N, l, r, v); 
      }
      else
      {
          int v;
         cin>>v;
         int result =Less(1,N,v,1);
         if(result==INT_MAX)
         {
              cout<<-1<<endl;
              continue;
         }
         result--;
         cout<<result<<endl;
      }
     }
	return 0; 
}
