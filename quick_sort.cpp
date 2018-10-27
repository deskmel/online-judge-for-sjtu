#include <iostream>
using namespace std;
int divide(long long *a,int l,int r)
{
	int d=a[r];
	int q=l-1;
	int cmp;
	for (int i=l;i<r;i++)
	{
		if (a[i]<=d)
		{
			q++;
			cmp=a[i];
			a[i]=a[q];
			a[q]=cmp;
		}
	}
	q++;
	a[r]=a[q];
	a[q]=d;
	return q;
}
void quick_sort(long long *a,int l,int r)
{
	int mid=divide(a,l,r);
	if (mid-l>1)
		quick_sort(a,l,mid-1);
	if (r-mid>1)
		quick_sort(a,mid+1,r);
}

int main(int argc, char const *argv[])
{
	long long a[10];
	for (int i=0;i<10;i++)
		cin>>a[i];
	quick_sort(a,0,9);
	for (int i=0;i<10;i++)
		cout<<a[i]<<' ';
	return 0;
}