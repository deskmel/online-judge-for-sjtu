#include <iostream>
using namespace std;
int m,n;
int set1[30005];
int set2[30005];

const int MAXL = 60;
struct LinearBasis
{
	long long a[MAXL+1];

	LinearBasis()
	{
		fill(a,a+MAXL+1,0);
	}
	void insert(long long t)
	{
		for (int j = MAXL;j >= 0;j--)
		{
			if (! (t&(1ll<<j))) continue;
			if (a[j]) t^=a[j];
			else
			{
				for (int k=0;k<;k++) if (t&(1ll<<k)) t^=a[k];
				for (int k=j+1;k<=MAXL;k++) if (a[k]&(1ll<<j))a[k]^=t;
				a[j] = t;
				return;
			}
		}
	}
};
int main(int argc, char const *argv[])
{
	cin>>m>>n;
	for (int i=0;i<m;++)
		cin>>set1[i];
	for (int i=0;i<n;i++)
		cin>>set2[i];

	return 0;
}