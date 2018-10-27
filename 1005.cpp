#include <iostream>
using namespace std;
bool judge(int a[9][9])
{
	if ((a[0][1]-a[0][0])==5 and (a[0][2]-a[0][1])==5)
		return false;
	for (int i=0;i<9;i++)
	{
		if (a[i][8]!=45*(i+1) or a[8][i]!=45*(i+1))
			return false;
	}
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
		{
			if (a[i*3+2][j*3+2]!=(45*(i+1)*(j+1)))
				return false;
		}
	return true;
}
int main()
{
	int n;
	cin>>n;
	bool b[20];
	int a[9][9];
	for (int times=0;times<n;times++)
	{

	for (int i=0;i<9;i++)
		for (int j=0;j<9;j++)
		{
			if (i==0 and j==0)
			{
				cin>>a[i][j];
			}
			else if (i==0)
			{
				cin>>a[i][j];
				a[i][j]=a[i][j]+a[i][j-1];
			}
			else if (j==0)
			{
				cin>>a[i][j];
				a[i][j]=a[i][j]+a[i-1][j];
			}
			else
			{
				cin>>a[i][j];
				a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
			}
		}
	b[times]=judge(a);
	}
	for (int i=0;i<n;i++)
	{
		if (b[i])
			cout<<"Right"<<'\n';
		else
			cout<<"Wrong"<<'\n';
	}
	return 0;
	
}