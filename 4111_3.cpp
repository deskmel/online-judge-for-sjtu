#include <iostream>
using namespace std;
int m,n;
char a[1005][1005];
int ans[1000000][3];
int main(int argc, char const *argv[])
{
	int head=0,tail=0;
	int pos_1,pos_2;
	cin>>n>>m;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			cin>>a[i][j];
			if (a[i][j]=='@')
			{
				pos_1=i;
				pos_2=j;
			}
		}
	ans[0][0]=pos_1;
	ans[0][1]=pos_2;
	ans[0][2]=0;
	int d;
	a[pos_1][pos_2]='#';
	while (head<=tail)
	{
		d=tail;
		while (head<=d)
		{
			if (ans[head][0]>0 and a[ans[head][0]-1][ans[head][1]]!='#')
			{
				tail+=1;
				ans[tail][0]=ans[head][0]-1;
				ans[tail][1]=ans[head][1];
				ans[tail][2]=ans[head][2]+1;
				if (a[ans[tail][0]][ans[tail][1]]=='$')
					{cout<<ans[tail][2];return 0;}
				a[ans[tail][0]][ans[tail][1]]='#';
			}
			if (ans[head][0]<n-1 and a[ans[head][0]+1][ans[head][1]]!='#')
			{
				tail+=1;
				ans[tail][0]=ans[head][0]+1;
				ans[tail][1]=ans[head][1];
				ans[tail][2]=ans[head][2]+1;
				if (a[ans[tail][0]][ans[tail][1]]=='$')
					{cout<<ans[tail][2];return 0;}
				a[ans[tail][0]][ans[tail][1]]='#';
			}
			if (ans[head][1]>0 and a[ans[head][0]][ans[head][1]-1]!='#')
			{
				tail+=1;
				ans[tail][0]=ans[head][0];
				ans[tail][1]=ans[head][1]-1;
				ans[tail][2]=ans[head][2]+1;
				if (a[ans[tail][0]][ans[tail][1]]=='$')
					{cout<<ans[tail][2];return 0;}
				a[ans[tail][0]][ans[tail][1]]='#';
			}
			if (ans[head][1]<m-1 and a[ans[head][0]][ans[head][1]+1]!='#')
			{
				tail+=1;
				ans[tail][0]=ans[head][0];
				ans[tail][1]=ans[head][1]+1;
				ans[tail][2]=ans[head][2]+1;
				if (a[ans[tail][0]][ans[tail][1]]=='$')
					{cout<<ans[tail][2];return 0;}
				a[ans[tail][0]][ans[tail][1]]='#';
			}
			head+=1;
		}
	}
	cout<<-1;
	return 0;
}