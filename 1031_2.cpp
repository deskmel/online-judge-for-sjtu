#include <iostream>
using namespace std;
int n;
int A[100][100],head,tail;
int queue[10000][3];
bool visit[100][100];
void enqueue(int x,int y)
{
	queue[tail][0]=x;
	queue[tail][1]=y;
	visit[x][y]=true;
	tail++;
}
void dequeue(int &x,int &y)
{
	x=queue[head][0];
	y=queue[head][1];
	head+=1;
}
int binarysearch(int low,int high)
{
	int l=low;
	int r=high;
	int mid;
	while (l<r)
	{
		mid=(l+r)/2;
		bool flag=false;
		for (int i=0;i<=min(A[0][0],A[n-1][n-1]);i++)
		{
			flag=false;
			head=tail=0;
			for (int j=0;j<n;j++)
				for (int k=0;k<n;k++)
					visit[j][k]=0;
			if (A[0][0]<=i+mid && A[0][0]>=i)
				enqueue(0,0);
			while (head!=tail)
			{
				int x,y;
				dequeue(x,y);
				if (x==n-1 && y==n-1)
				{
					flag=true;
					break;
				}
				if (x>0 && !visit[x-1][y] && A[x-1][y]<=i+mid && A[x-1][y]>=i)
					enqueue(x-1,y);
				if (y>0 && !visit[x][y-1] && A[x][y-1]<=i+mid && A[x][y-1]>=i)
					enqueue(x,y-1);
				if (x<n-1 && !visit[x+1][y] && A[x+1][y]<=i+mid && A[x+1][y]>=i )
					enqueue(x+1,y);
				if (y<n-1 && !visit[x][y+1] && A[x][y+1]<=i+mid && A[x][y+1]>=i)
					enqueue(x,y+1);
			}
			if (flag)
				break;
		}
		if (flag)
			{r=mid;}
		else {l=mid+1;}
	}
	mid = (l+r)/2;
	return mid;
}
int main(int argc, char const *argv[])
{
	cin>>n;
	int high=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		{
			cin>>A[i][j];
			if (A[i][j]>high)
				high=A[i][j];
		}
	cout<<binarysearch(0,high);
	return 0;
}