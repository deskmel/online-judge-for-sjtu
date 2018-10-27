#include <iostream>
using namespace std;
int N[100000];
int a,b;
int index;
int L[200000];
int R[200000];
int main(int argc, char const *argv[])
{
	int total=0;
	cin>>a>>b;
	for (int i=0;i<a;i++)
	{
		cin>>N[i];
		if (N[i]==b)
		{
			index=i;
			N[i]=0;
		}
		else if (N[i]>b)
		{
			N[i]=1;
		}
		else
		{
			N[i]=-1;
		}

	}

	int l=a,r=a;
	for (int i=index;i>=0;i--)
	{
		l+=N[i];
		L[l]++;
	}
	for (int i=index;i<a;i++)
	{
		r+=N[i];
		R[r]++;
	}
	total+=L[a]*R[a];
	for (int i=1;i<=a;i++)
	{
		total+=L[a-i]*R[a+i];
		total+=L[a+i]*R[a-i];
	}
	cout<<total;
	return 0;
}