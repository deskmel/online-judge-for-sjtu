#include <iostream>
using namespace std;
int a[20000][2];
int partition(int a[][2],int p,int r)
{
	int cmp;
	int x=a[r][0];
	int i=p-1;
	for (int j=p;j<=r-1;j++)
	{
		if (a[j][0]<=x)
		{
			i+=1;
			cmp=a[j][0];
			a[j][0]=a[i][0];
			a[i][0]=cmp;
			cmp=a[j][1];
			a[j][1]=a[i][1];
			a[i][1]=cmp;
		}
	}
	cmp=a[i+1][0];
	a[i+1][0]=a[r][0];
	a[r][0]=cmp;
	cmp=a[i+1][1];
	a[i+1][1]=a[r][1];
	a[r][1]=cmp;
	return i+1;
}
void quicksort(int a[][2],int p,int r)
{
	if (p<r)
	{
		int q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}

int main(int argc, char const *argv[])
{ 
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i][0];
		cin>>a[i][1];
	}
	quicksort(a,0,n-1);
	int m=a[0][0];
	int M=a[0][1];
	int total=M-m;
	for (int i=1;i<n;i++)
	{
		if (a[i][0]<M)
		{
			total+=max(a[i][1]-M,0);
			M=max(a[i][1],M);
		}
		else
		{
			m=a[i][0];
			M=a[i][1];
			total+=M-m;
		}
	}
	cout<<total;
	return 0;
}