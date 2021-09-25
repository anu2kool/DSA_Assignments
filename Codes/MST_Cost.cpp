#include<bits/stdc++.h>
#include<vector>
#include<stack>
#include<queue>
#define MAX 1000000007
using namespace std;
vector< pair<int, int> > adj[5001];
int max_weight;
int final_max_weight;
stack<int>final_path;
stack<int>path;
void add_Edge(int u, int v, int weight)
{
	adj[u].push_back(make_pair(v,weight));
	adj[v].push_back(make_pair(u,weight));
}
int find_Min(int mst_set[],bool visited[], int V, int E)
{
	int min=MAX;
	int min_index=-1;
	for(int i=0; i<V; i++)
	{
		if(!visited[i])
		{
			if(mst_set[i]<min)
			{
				min=mst_set[i];
				min_index=i;
			}
		}
	}
	return min_index;
}
int find_weight(int u, int v, int V)
{
	for(int j=0; j<V; j++)
	{
		if(adj[u][j].first==v)
		{
			return adj[u][j].second;
		}
	}
}
void DFS(int vertex, int B, bool visited[], int V, vector< pair<int, int> > mst[])
{
	path.push(vertex);
	visited[vertex]=true;
	for(int i=0; i<mst[vertex].size(); i++)
	{
		if(mst[vertex][i].first==B && !visited[mst[vertex][i].first])
		{
			path.push(B);
			final_path=path;
			break;
		}
		else
		{
			if(!visited[mst[vertex][i].first])
			{
				DFS(mst[vertex][i].first,B,visited,V,mst);
			}
		}
	}
	path.pop();
}
void Find_MST(int V, int E, int A, int B, int C)
{
	int mst_set[V];
	int parent[V];
	bool visited[V];
	for(int i=0; i<V; i++)
	{
		mst_set[i]=MAX;	
		parent[i]=-1;
		visited[i]=	false;
	}
	mst_set[0]=0;
	for(int i=0; i<V-1; i++)
	{
		int min_vertex=find_Min(mst_set,visited,V,E);
		visited[min_vertex]=true;
		for(int j=0; j<adj[min_vertex].size(); j++)
		{
			if(!visited[adj[min_vertex][j].first] && mst_set[adj[min_vertex][j].first]>adj[min_vertex][j].second)
			{
				mst_set[adj[min_vertex][j].first]=adj[min_vertex][j].second;
				parent[adj[min_vertex][j].first]=min_vertex;
			}
		}
	}
	vector< pair<int, int> > mst[V];
	for(int i=1; i<V; i++)
	{
		//cout<<parent[i]<<"-"<<i<<"-weight-"<<find_weight(parent[i],i,V)<<endl;
		mst[i].push_back(make_pair(parent[i],find_weight(parent[i],i,V)));
		mst[parent[i]].push_back(make_pair(i,find_weight(parent[i],i,V)));
	}
	max_weight=0;
	final_max_weight=MAX;
	bool vis[V];
	for(int i=0; i<V; i++)
	{
		vis[i]=false;
	}
	DFS(A,B,vis,V,mst);
	//cout<<"Path"<<endl;
	vector<int>paths;
	while(!final_path.empty())
	{
		//cout<<final_path.top()<<endl;
		paths.push_back(final_path.top());
		final_path.pop();
	}
	int maxcost=0;
	for(int i=1; i<paths.size(); i++)
	{
		int weight=find_weight(paths[i-1],paths[i],V);
		maxcost=max(weight,maxcost);
	}
	if(maxcost>C)
	{
		cout<<"Not Possible"<<endl;
	}
	else
	{
		cout<<"Possible"<<endl;
		reverse(paths.begin(),paths.end());
		for(int i=0; i<paths.size(); i++)
		{
			cout<<paths[i]+1<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		int u,v,cost;
		cin>>u>>v>>cost;
		u--;
		v--;
		add_Edge(u,v,cost);
	}
	int A,B,C;
	cin>>A>>B>>C;
	A--;
	B--;
	Find_MST(n,m,A,B,C);
	
}
