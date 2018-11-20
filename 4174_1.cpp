#include <iostream>
using namespace std;
long long locate[100005];
long long h[100005];
int m,ans=0;
int divide(long long*,int,int);
void quicksort(long long *a,int l,int r)
{
	if (l<r)
	{
		int mid=divide(a,l,r);
		quicksort(a,l,mid-1);
		quicksort(a,mid+1,r);
	}
}
int divide(long long *a,int l,int r)
{
	int q=l-1;
	long long k=a[r];
	long long tmp;
	for (int i=l;i<r;i++)
	{
		if (a[i]<k)
		{
			q++;
			tmp=a[i];a[i]=a[q];a[q]=tmp;
			tmp=h[i];h[i]=h[q];h[q]=tmp;
		}
	}
	q++;
	tmp=a[r];a[r]=a[q];a[q]=tmp;
	tmp=h[r];h[r]=h[q];h[q]=tmp;
	return q;
}
int main(int argc, char const *argv[])
{
	cin>>m;
	for (int i=0;i<m;i++)
		cin>>locate[i];
	for (int i=0;i<m;i++)
		cin>>h[i];
	quicksort(locate,0,m-1);
	long long end=locate[0]-h[0];
	for (int i=0;i<m;i++)
	{
		if (locate[i]-h[i]>=end)
		{
			ans+=1;end=locate[i]+1;
		}
		else if ((i==m-1) || (locate[i]+h[i])<locate[i+1])
		{
			ans+=1;end=locate[i]+h[i]+1;
		}
		else
			end=locate[i+1];
	}
	cout<<ans;
	return 0;
}