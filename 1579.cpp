#include <iostream>
using namespace std;
int m,n;
char a[1005];
char b[1005];
int ans[1005][1005];
int main(int argc, char const *argv[])
{
	cin>>m>>n;
	for (int i=0;i<m;i++)
		cin>>a[i];
	for (int j=0;j<n;j++)
		cin>>b[j];

	for (int i=0;i<m;i++)
		if (a[i]==b[0] || (i!=0 && ans[i-1][0]==1) )
			ans[i][0]=1;

	for (int j=0;j<n;j++)
		if (a[0]==b[j] || (j!=0 && ans[0][j-1]==1))
			ans[0][j]=1;

	for (int i=1;i<m;i++)
		for (int j=1;j<n;j++)
		{
			if (a[i]==b[j])
			{
				ans[i][j]=1+ans[i-1][j-1];
			}
			else ans[i][j]=max(ans[i-1][j],ans[i][j-1]); 
		}
	cout<<ans[m-1][n-1];
	return 0;
}