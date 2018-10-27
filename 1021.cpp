#include <iostream>
#include <iomanip>
using namespace std;
int a[150][150];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int in=1;
	int left=0;
	int right=n-1;
	int up=0;
	int down=n-1;
	while (in<=n*n)
	{
		for (int j=left;j<=right;j++)
			{	
				a[up][j]=in;
				in+=1;
			}
		up+=1;
		for (int j=up;j<=down;j++)
		{
			a[j][right]=in;
			in+=1;
		}
		right-=1;
		for (int j=right;j>=left;j--)
		{
			a[down][j]=in;
			in+=1;
		}
		down-=1;
		for (int j=down;j>=up;j--)
		{
			a[j][left]=in;
			in+=1;
		}
		left+=1;
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			cout<<setw(6)<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}