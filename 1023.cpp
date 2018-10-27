#include <iostream>
using namespace std;
int matrix[700][700];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		int m;cin>>m;
		int t;cin>>t;
		for (int j=0;j<m;j++)
			for (int k=0;k<m;k++)
			{
				cin>>matrix[j][k];
			}
		if (t==0)
		{
			for (int l=0;l<m;l++)
			{
				for (int j=0;j<m;j++)
				{
					cout<<matrix[l][m-j-1]<<' ';
				}
				cout<<'\n';
			}
		}
		else if (t==1)
		{
			for (int l=0;l<m;l++)
			{
				for (int j=0;j<m;j++)
				{
					cout<<matrix[m-l-1][j]<<' ';
				}
				cout<<'\n';
			}
		}
		else
		{
			for (int l=0;l<m;l++)
			{
				for (int j=0;j<m;j++)
					{
					cout<<matrix[j][l]<<' ';
					}
				cout<<'\n';
			}

		}

	}
	return 0;
}