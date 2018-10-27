#include <iostream>
using namespace std;
void dfs(int,int,int);
long long dp[40][40],a[40];
int main(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
		dp[i][i]=a[i];
	}
	for (int i=1;i<n;i++)
		for (int j=0;j<n-i;j++)
			for (int k=0;k<=i;k++)
			{
				if (k==0)
					dp[j][j+i]=max(dp[j][j+i],a[j]+dp[j+1][j+i]);
				else
				if (k==i)
					dp[j][j+i]=max(dp[j][j+i],a[j+i]+dp[j][j+i-1]);
				else
					dp[j][j+i]=max(dp[j][j+i],a[j+k]+dp[j][j+k-1]*dp[j+k+1][j+i]);
			}
	cout<<dp[0][n-1]<<endl;
	dfs(dp[0][n-1],0,n-1);
} 
void dfs(int value,int l,int r)
{
	if (l==r) cout<<l+1<<" ";
	else
	for (int i=l;i<=r;i++)
	{
		if (i==l)
		{
		if (a[l]+dp[l+1][r]==dp[l][r])
		{
			cout<<l+1<<" ";
			dfs(value-a[l],l+1,r);
			break;
		}
		}
		else if (i==r)
		{
		if (a[r]+dp[l][r-1]==dp[l][r])
		{
			cout<<r+1<<" ";
			dfs(value-a[r],l,r-1);
			break;
		}
		}
		else if (a[i]+dp[l][i-1]*dp[i+1][r]==dp[l][r])
		{
			cout<<i+1<<" ";
			dfs(dp[l][i-1],l,i-1);
			dfs(dp[i+1][r],i+1,r);
			break;
		}
	}
}
