#include <iostream>
using namespace std;
int m, n;
int edge[105][105];
int dp[105][105];
bool visited[105];
struct Node
{
	int l;
	int r;
	int val;
};
Node tree[105];



void createtree(int root)
{
	visited[root]=true;
	for (int i=1;i<=n;i++)
	{
		if (!visited[i] && edge[root][i])
		{
			if (!tree[root].l) tree[root].l = i;
			else tree[root].r = i;
			tree[i].val = edge[root][i];
			createtree(i);
		}
	}
}
int treedp(int root,int n)
{
	if (root==0 || n==0) 
		return 0;
	if (dp[root][n]!=0) return dp[root][n];
	int maxvalue=0,lvalue,rvalue;
	for (int i=0;i<n;i++)
	{
		lvalue = treedp(tree[root].l,i);
		rvalue = treedp(tree[root].r,n-i-1);
		maxvalue=max(lvalue+rvalue,maxvalue);
	}
	dp[root][n] = maxvalue+tree[root].val;
	return dp[root][n];
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	int n1,n2,value;
	for (int i=1;i<n;i++)
	{
		cin>>n1>>n2>>value;
		edge[n1][n2]=edge[n2][n1]=value;
	}
	createtree(1);
	cout<<treedp(1,m+1)<<endl;
	return 0;
}