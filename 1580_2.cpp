#include <iostream>
using namespace std;
int a[100005];
int b[100005];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	b[1]=a[0];
	int len=1;
	for (int i=1;i<n;i++)
	{
		if (a[i]>b[len])
			b[++len]=a[i];
		else 
		{
			int l=1,r=len;
			while (l<r)
			{
				int mid=l+(r-l)/2;
				if (b[mid]<a[i])
					l=mid+1;
				else
					r=mid;
			}
			b[l]=a[i];
		}
	}
	printf("%d\n",len );
	return 0;
}