#include <iostream>
using namespace std;
int n;
int f[1000005];
int l[1000005];
int r[1000005];
void bfs(int *l,int *r,int n)
{
	int head=0,tail=1;
	f[head]=0;
	int p;
	while (head<tail)
	{
		p=f[head];
		if (l[p]!=0)
		{
			f[tail]=l[p];
			tail+=1;
		}
		
		if (r[p]!=0)
		{
			f[tail]=r[p];
			tail+=1;
		}

		head+=1;
	}
	for (int i=0;i<n;i++)
	{
		cout<<f[i]<<' ';
	}
}
int main(int argc, char const *argv[])
{
	cin>>n;
	int m;
	for (int i=0;i<n-1;i++)
	{
		cin>>m;
		if (l[m]==0)
		{
			l[m]=i+1;
		}
		else r[m]=i+1;
	}
	bfs(l,r,n);
	return 0;
}