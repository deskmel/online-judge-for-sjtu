#include <iostream>
using namespace std;
//并查集
int p[100000];
int rank[100000];
int ca[100000];
bool get[100000];
int a,b;
int n;
int l[1000000];
int r[1000000];
void link(int x,int y)
{
	if (r[x]>r[y])
		p[y]=x;
	else
	{	
	 	p[x]=y;
	 	if (r[x]==r[y])
	 		r[y]+=1;
	}
}
void UNION(int x,int y)
{
	link(x,y);
}

int find_set(int x)
{
	if (p[x]!=0)
	{
		p[x]=find_set(p[x]);
		return p[x];
	}
	else return x;
	
}
//tarjin算法
int ans;
int tarjan(int x)
{
	ca[find_set(x)]=x;
	if (l[x]!=0)
	{
		tarjan(l[x]);
		UNION(x,l[x]);
		ca[find_set(l[x])]=x;
	}
	if (r[x]!=0)
	{
		tarjan(r[x]);
		UNION(x,r[x]);
		ca[find_set(r[x])]=x;
	}
	get[x]=true;
	if (x==a)
	{
		if (get[b])
			ans=ca[find_set(b)];
	}
	else if(x==b)
	{
		if (get[a])
			ans=ca[find_set(a)];
	}


}
bool root[1000000];
int main(int argc, char const *argv[])
{
	cin>>n;
	cin>>a>>b;
	for (int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		root[l[i]]=true;
		root[r[i]]=true;
	}
	for (int i=1;i<=n;i++)
		if (!root[i])
		{
			tarjan(i);
			break;
		}
	cout<<ans;
	return 0;
}