//Name: Anukool Dwivedi
//Roll No: B19071
//SOLO
//Group-13

#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
int maze[11][11];
//Counting the number of zombies in the maze
int Count_Zombies(int m, int n)
{
	int count=0;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(maze[i][j]==2)
			{
				count++;
			}
		}
	}
	return count;
}
//Counting the number of people in the maze
int Count_People(int m, int n)
{
	int count=0;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(maze[i][j]==1)
			{
				count++;
			}
		}
	}
	return count;
}
int main()
{
	int m,n;
	cin>>m>>n;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>maze[i][j];
		}
	}
	
	int no_of_zombies=Count_Zombies(m,n);
	int no_of_people=Count_People(m,n);
	
	if(no_of_people=0)
	{
		cout<<0<<endl;
	}
	else if(no_of_zombies==0)
	{
		cout<<-1<<endl;
	}
	else
	{
		queue< pair<int, int> > queue1;
		queue< pair<int, int> > queue2;
		int count=0;
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(maze[i][j]==2)
				{
					queue1.push(make_pair(i,j));
				}
			}
		}
		//Doing BFS using queues 
		while(!queue1.empty())
		{
			pair<int, int> p;
			p=queue1.front();
			queue1.pop();
			int i=p.first;
			int j=p.second;
			if(i-1>=0 && maze[i-1][j]==1)
			{
				queue2.push(make_pair(i-1,j));
				maze[i-1][j]=2;
			}
			if(i+1<m && maze[i+1][j]==1)
			{
				queue2.push(make_pair(i+1,j));
				maze[i+1][j]=2;
			}
			if(j-1>=0 && maze[i][j-1]==1)
			{
				queue2.push(make_pair(i,j-1));
				maze[i][j-1]=2;
			}
			if(j+1<n && maze[i][j+1]==1)
			{
				queue2.push(make_pair(i,j+1));
				maze[i][j+1]=2;
			}
			if(queue1.empty())
			{
				queue< pair<int, int> > temp;
				temp=queue1;
				queue1=queue2;
				queue2=temp;
				count++;
			}
			if(queue1.empty() && queue2.empty())
			{
				break;
			}
		}
		count--;
		if(count==0)
		{
			cout<<-1<<endl;
		}
		else
		{
			int no_of_people=Count_People(m,n);
			if(no_of_people==0)
			{
				cout<<count<<endl;
			}
			else
			{
				cout<<-1<<endl;
			}
		}
	
	}
	
	return 0;
}
