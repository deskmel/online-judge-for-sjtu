#include <iostream>
using namespace std;
int n;
int x[1000000];
int put(int *arr,int l,int r,int key)
{
	int mid;
	if (arr[r] <key)
		return r+1;
	while (l<r)
	{
		mid = l+(r-l)/2;
		if (arr[mid]<key)
		{
			l=mid+1;
		}
		else 
			r=mid;
	}
	return l;
}
int LIS(int *A,int n)
{
	int i=0;int len=1;
	int next;
	int *B=new int [(n+1)];
	B[1]=A[0];
	for (i=1;i<n;i++)
	{
		next=put(B,1,len,A[i]);
		cout<<next<<' ';
		B[next]=A[i];
		if (len<next) len=next;
	}
	return len;
}
int main(int argc, char const *argv[])
{
	scanf("%d\n",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&x[i]); 
	cout<<LIS(x,n);
	return 0;
} 