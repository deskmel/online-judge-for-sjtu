#include <iostream>
using namespace std;
long long dps[2005][2005],dpt[2005][2005],mins,mint;
int road[2005];
int sortroad[2005];
int n;
void quicksort(int *s,int *t)
{
	if (s+1>=t) return;
	int i=0,j=int (t-s)-1,x=s[0];
	while (i<j)
	{
		while (i<j&&s[j]>=x) j--;
		if (i<j) s[i++]=s[j];
		while (i<j&&s[i]<=x) i++;
		if (i<j) s[j--]=s[i];
	}
	s[i]=x;
	quicksort(s,s+i);
	quicksort(s+i+1,t);
}

int main(int argc, char const *argv[])
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>road[i];
		sortroad[i]=road[i];
	}
	quicksort(sortroad+1,sortroad+n+1);
	for (int i=1;i<=n;i++)
	{
		mins=1e12;
		for (int j=1;j<=n;j++)
		{
			if (dps[i-1][j]<mins) mins=dps[i-1][j];
			dps[i][j]=mins+abs(road[i]-sortroad[j]);
		}
		mint=1e12;
		for (int j=n;j>=1;j--)
		{
			if (dps[i-1][j]<mint) mint=dpt[i-1][j];
			dpt[i][j]=mint+abs(road[i]-sortroad[j]);
		}
	}
	mins=1e12;
	mint=1e12;
	for (int i=1;i<=n;i++)
	{
		mins=min(dps[n][i],mins);
		mint=min(dpt[n][i],mint);
	}
	cout<<min(mins,mint);

	return 0;
}