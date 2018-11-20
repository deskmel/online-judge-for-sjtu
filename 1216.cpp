#include <iostream>
using namespace std;
int heap[20000];
void swap(int &x,int &y)
{
	int tmp;
	tmp=x;
	x=y;
	y=ymp;
}
void MIN_HEAPITY_DOWN(int *a,int i,int n)
{
	int l=i*2;
	int r=i*2+1;
	int m=i;
	if (l<=n && a[m]>a[l])
		m==l;
	if (r<=n && a[m]>a[r])
		m=r;
	if (m!=i)
	{
		swap(a[i],a[m])
		MIN_HEAPITY_DOWN(a,m,n);
	}
}
void MIN_HEAPITY(int *a,int i,int n)
{
	while (i/2>0)
	{
		if (a[i/2]>a[i])
		{
			swap(a[i],a[i/2]);
			i/=2;
		}
		else break;

	}
}
void insert(int x)
{
	heap[++n]=x;
	MIN_HEAPITY(heap,n+1,)
}
void BUILD_MIN_HEAP(int *a,int n)
{
	for (int i=n/2;i>=1;i--)
		MIN_HEAPITY_DOWN(a,i,n);
}
