#include <iostream>
using namespace std;
int n,x[100000];
int divie_sort(int *a,int l,int r)
{
	int m=a[r];
	int n=l-1;
	int cmp;

	for (int i=l;i<=r-1;i++)
	{
		if (a[i]<=m)
		{
			n+=1;
			cmp=a[i];
			a[i]=a[n];
			a[n]=cmp;
		}
	}
	cmp=a[n+1];
	a[n+1]=a[r];
	a[r]=cmp;
	return n+1;
}
void quick_sort(int *a,int l,int r)
{
	if (l<r)
	{
	int q=divie_sort(a,l,r);
	quick_sort(a,l,q-1);
	quick_sort(a,q+1,r);
	}
}

int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>x[i];
	quick_sort(x,0,n-1);
	long long sum=0;
	for (int i=0;i<n/2;i++)
		sum+=x[n-i-1]-x[i];
	cout<<sum<<endl;
	
	return 0;
}