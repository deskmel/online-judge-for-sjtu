#include <iostream>
#include <stdio.h>
using namespace std;
int n,maxx,maxi;
char tmp;
int high[1005];
int sum;
int main(int argc, char const *argv[])
{
	scanf("%d\n",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%c%d",&tmp,&high[i]);
		if (high[i]>maxx)
			{maxx=high[i],maxi=i;}
	}
	int highest=0,s=0;
	for (int i=0;i<=maxi;i++)
	{
		if (high[i]>=highest)
			{highest=high[i];sum+=s;s=0;}
		else
			s+=highest-high[i];
	}
	highest=0;
	for (int i=n-1;i>=maxi;i--)
	{
		if (high[i]>=highest)
			{highest=high[i];sum+=s;s=0;}
		else
			s+=highest-high[i];
	}
	printf("%d\n",sum );
	return 0;
}