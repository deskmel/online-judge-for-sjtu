#include <iostream>
#include <string.h>
using namespace std;
int heap[20000];
int n,M;
int swap2(int &x,int &y)
{
	int tmp;
	tmp=x;
	x=y;
	y=tmp;
}
void MIN_HEAPITY_DOWN(int *a,int i,int n)
{
	int l=i*2;
	int r=i*2+1;
	int m=i;
	if (l<=n && a[m]>a[l])
		m=l;
	if (r<=n && a[m]>a[r])
		m=r;
	if (m!=i)
	{
		swap2(a[i],a[m]);
		MIN_HEAPITY_DOWN(a,m,n);
	}
}
void MIN_HEAPITY(int *a,int i)
{
	while (i/2>0)
	{
		if (a[i/2]>a[i])
		{
			swap2(a[i],a[i/2]);
			i/=2;
		}
		else break;
	}
}
void decrease(int i,int v)
{
	heap[i]-=v;
	MIN_HEAPITY(heap,i);
}
int find(int x)
{
	bool flag=true;
	int re,min1;
	for (int i=1;i<=n;i++)
	{
		if (heap[i]>x && flag)
		{
			re=i;
			min1=heap[i];
			flag=false;
		}
		else if (heap[i]>x && heap[i]<min1)
		{
			min1=heap[i];
			re=i;
		}
	}
	return re;
}
void insert(int x)
{
	heap[++n]=x;
	MIN_HEAPITY(heap,n);
} 
void BUILD_MIN_HEAP(int *a,int n)
{
	for (int i=n/2;i>=1;i--)
		MIN_HEAPITY_DOWN(a,i,n);
}
void HEAP_DELETE()
{
	heap[1]=heap[n--];
	MIN_HEAPITY_DOWN(heap,1,n);
}
void p()
{
	for (int i=1;i<=n;i++)
		cout<<heap[i]<<'\t';
	cout<<'\n';
}
int main(int argc, char const *argv[])
{
	cin>>M;
	for (int i=0;i<M;i++)
	{
		int tmp1;
		int tmp2;
		char tmp[10];
		cin>>tmp;
		if (strcmp(tmp,"insert")==0)
		{
			cin>>tmp1;
			insert(tmp1);
		}
		else if (strcmp(tmp,"find")==0)
		{
			cin>>tmp1;
			cout<<find(tmp1)<<'\n';
		}
		else if (strcmp(tmp,"decrease")==0)
		{	
			cin>>tmp1>>tmp2;
			decrease(tmp1,tmp2);
		}
		else if (strcmp(tmp,"min")==0)
			cout<<heap[1]<<'\n';
		else if (strcmp(tmp,"p")==0)
			p();

	}

	return 0;
}