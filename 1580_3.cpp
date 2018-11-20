#include <iostream>
using namespace std;
int n;
int a[1000005];
int b[1000005];
int LIS()
{
	b[1]=a[0];
	int len=1;
	for (int i=1;i<n;i++)
	{
		if (a[i]>b[len])
			b[++len]=a[i];
		else
		{
			int l=1,r=len;
			while (r>l)
			{
				int mid=(r+l)/2;
				if (a[i]<=b[mid])
					r=mid;
				else
					l=mid+1;
			}
			b[l]=a[i];
		}
	}
	return len;
}

int main(int argc, char const *argv[])
{
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	cout<<LIS();
	return 0;
}