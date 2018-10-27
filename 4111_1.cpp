#include <iostream>
using namespace std;
int m,n1;
int a[1003][1003];
int solu=-1;
void next(int x,int y,int n)
{
	if (a[x][y]==-2 )
		{
			if (solu==-1)
				solu=n;
			else
				solu=min(solu,n);
		}
	a[x][y]=n;
	int num=-1;
	int q;
	if (x>0 and a[x-1][y]!=-1 and ( a[x-1][y]==0 or a[x-1][y]>n+1 or a[x-1][y]==-2) and (solu==-1 or n+1<solu))
	{
		next(x-1,y,n+1);
	}
	if (x<n1-1 and a[x+1][y]!=-1 and ( a[x+1][y]==0 or a[x+1][y]>n+1 or a[x+1][y]==-2) and (solu==-1 or n+1<solu))
	{
		next(x+1,y,n+1);
	}
	if (y>0 and a[x][y-1]!=-1 and(a[x][y-1]==0 or a[x][y-1]>n+1 or a[x][y-1]==-2) and (solu==-1 or n+1<solu))
	{
		next(x,y-1,n+1);
	}
	if (y<m-1 and  a[x][y+1]!=-1 and (a[x][y+1]==0 or a[x][y+1]>n+1 or a[x][y+1]==-2) and (solu==-1 or n+1<solu) )
	{
		next(x,y+1,n+1);
	}
}
int main(int argc, char const *argv[])
{
	int pos_1,pos_2;
	cin>>n1>>m;
	char c;
	for (int i=0;i<n1;i++)
		for (int j=0;j<m;j++)
		{
			cin>>c;
			if (c=='@')
			{
				pos_1=i;
				pos_2=j;
			}
			else if (c=='#')
			{
				a[i][j]=-1;
			}
			else if (c=='$')
			{
				a[i][j]=-2;
			}
		}
		next(pos_1,pos_2,0);
	cout<<solu;
	return 0;
}