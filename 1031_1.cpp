#include <iostream>
using namespace std;
int n;
int A[100][100];  
int queue[10000][4],head,tail;
bool visit[100][100];

void enqueue(int x,int y,int mid,int low,int h)
{
	if (x>0 && !visit[x-1][y] && A[x-1][y]-low<=mid && A[x-1][y]>=low)
	{
		queue[tail][0]=x-1;
		queue[tail][1]=y;
		queue[tail][2]=max(h,A[x-1][y]);
		visit[x-1][y]=true;
		tail+=1;
	}
	if ( y<n-1 && !visit[x][y+1] && A[x][y+1]-low<=mid && A[x][y+1]>=low)
	{
		queue[tail][0]=x;
		queue[tail][1]=y+1;
		queue[tail][2]=max(h,A[x][y+1]);
		visit[x][y+1]=true; 
		tail+=1;
	}
	if (x<n-1  && !visit[x+1][y] && A[x+1][y]-low<=mid && A[x+1][y]>=low)
	{
		queue[tail][0]=x+1;
		queue[tail][1]=y;
		queue[tail][2]=max(h,A[x+1][y]);
		visit[x+1][y]=true;
		tail+=1;
	}
	if (y>0 && !visit[x][y-1] &&A[x][y-1]-low<=mid & A[x][y-1]>=low)
	{
		queue[tail][0]=x;
		queue[tail][1]=y-1;
		queue[tail][2]=max(h,A[x][y-1]);
		visit[x][y-1]=true;
		tail+=1;
	}
}
int binarysearch(int low,int high)
{

	int ans=0;
	int l=low;
	int r=high;
	int mid;

	while (l<r)
	{
		bool flag=false;
		for (int j=0;j<=min(A[0][0],A[n-1][n-1]);j++)
		{
			flag=false;
			head=0;tail=0;
			mid=(l+r)/2;
			for (int i=0;i<n;i++)
				for (int k=0;k<n;k++)
					visit[i][k]=0;
			queue[tail][0]=0;
			queue[tail][1]=0;
			queue[tail][2]=A[0][0];
			visit[0][0]=true;
			tail+=1;	

			while (head!=tail)
			{
				int x=queue[head][0];
				int y=queue[head][1];
				int h=queue[head][2];
				head+=1;
				if (x==n-1 && y==n-1)
				{
					ans=h-j;
					flag=true;
					break;
				}
				enqueue(x,y,mid,j,h);
			}
			if (flag)
				break;
			}
		if (flag)
			r=mid-1;
		else l=mid+1;	
	}
	return ans;
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
	cout<<binarysearch(1,high);
	return 0;
}