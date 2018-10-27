#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int m,n;
	cin>>m>>n;
	int a[1001][1001];
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
		{
			if (i==0 and j==0)
			{
				cin>>a[i][j];
			}
			else if (i==0)
			{
				cin>>a[i][j];
				a[i][j]=a[i][j-1]+a[i][j];
			}
			else if (j==0)
			{
				cin>>a[i][j];
				a[i][j]=a[i][j]+a[i-1][j];
			}
			else
			{
				cin>>a[i][j];
				a[i][j]=a[i][j]+a[i][j-1]+a[i-1][j]-a[i-1][j-1];
			}
		}
	int l1,l2;
	cin>>l1>>l2;
	int sum=0;
	for (int i=0;i<m-l1+1;i++)
		for (int j=0;j<n-l2+1;j++)
		{
			if (i==0 and j==0)
			{
				sum=max(sum,a[l1-1][l2-1]);
			}
			else if (i==0)
			{
				sum=max(sum,a[l1-1][j+l2-1]-a[l1-1][j-1]);
			}
			else if (j==0)
			{
				sum=max(sum,a[l1+i-1][l2-1]-a[i-1][l2-1]);
			}
			else
			{
				sum=max(sum,a[l1+i-1][l2+j-1]-a[i-1][l2+j-1]-a[l1+i-1][j-1]+a[i-1][j-1]);
			}
		}
	cout<<sum;
	return 0;
}