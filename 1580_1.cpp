#include <iostream>
using namespace std;
int a[1000000];
int n;
int LIS(int x)
{
	int num[1000000];
	for (int i=0;i<x;i++)
	{
		num[i]=1;
		for (int j=0;j<i;j++)
		{
			if (a[j]<a[i]&&num[j]+1>num[i])
				num[i]=num[j]+1;
		}
	}
	int max_len=0;
	for (int i=0;i<x;i++)
		max_len=max(max_len,num[i]);
	return max_len;
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("%d\n",LIS(n) );
	return 0;
}