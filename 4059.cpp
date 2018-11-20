#include <iostream>
using namespace std;
int n;
int val[105][2];
int divide(int a[][2],int l,int r);
void quicksort(int a[][2],int l,int r)
{
	if (l<r)
	{
		int mid=divide(a,l,r);
		quicksort(a,l,mid-1);
		quicksort(a,mid+1,r);
	}
}
int divide(int a[][2],int l,int r)
{
	int q=l-1;
	int m=a[r][0];
	int tmp1,tmp2;
	for (int i=l;i<r;i++)
	{
		if (a[i][0]>m)
		{
			q++;
			tmp1=a[q][0];
			tmp2=a[q][1];
			a[q][0]=a[i][0];
			a[q][1]=a[i][1];
			a[i][0]=tmp1;
			a[i][1]=tmp2;
		}
	}
	q++;
	tmp1=a[r][0];
	tmp2=a[r][1];
	a[r][0]=a[q][0];
	a[r][1]=a[q][1];
	a[q][0]=tmp1;
	a[q][1]=tmp2;
	return q;
}
int main(int argc, char const *argv[])
{
	cin>>n;
	for (int i=0;i<n;i++)
		{
			cin>>val[i][0];
			val[i][1]=(i+1);
		}
	quicksort(val,0,n-1);
	cout<<val[0][0]<<' '<<val[0][1];

	
	return 0;
}