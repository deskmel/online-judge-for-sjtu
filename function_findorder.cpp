#include <iostream>
using namespace std;
int divide(int l,int r,int *a,int *order)
{
	int m=a[r];
	int q=l-1;
	int tmp=0;
	for (int i=l;i<=r-1;i++  )
	{
		if (a[i]<m)
		{
			q+=1;
			tmp=a[q];
			a[q]=a[i];
			a[i]=tmp;
			tmp=order[q];
			order[q]=order[i];
			order[i]=tmp;
		}
	}
	q+=1;
	a[r]=a[q];
	a[q]=m;
	tmp=order[r];
	order[r]=order[q];
	order[q]=tmp;
	return q;
}
void quicksort(int l,int r,int *a,int *order)
{
	if (l<r)
	{
		int k=divide(l,r,a,order);
		quicksort(l,k-1,a,order);
		quicksort(k+1,r,a,order);
	}
}
int main(int argc, char const *argv[])
{
	int n;
	int a[1000];
	int b[1000];
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
		b[i]=i;
	quicksort(1,n,a,b);
	for (int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
	for (int i=1;i<=n;i++)
		cout<<b[i]<<' ';
	cout<<endl;

	return 0;
}
