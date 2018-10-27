#include <iostream>
using namespace std;
int n;
int num[100005];
int num1[100005];
int num2[100005];
int order1[100005];
int order2[100005];
long long sum=0;
int lowbit(int x)
{
	return x&-x;
}
int query(int n)
{
	int res=0;
	while (n)
	{
		res+=num[n];
		n=lowbit(n);
	}
	return res;
}
int insert(int n1)
{
	while (n1<=n)
	{
		num[n1]+=1;
		n1+=lowbit(n1);
	}
}
int divide(int l,int r,int *A,int *B)
{
	int m=A[r];
	int tmp;
	int k=l-1;
	int i=0;
	for (i=l;i<=r-1;i++)
	{
		if (A[i]<m)
		{
			k+=1;
			tmp=A[k];
			A[k]=A[i];
			A[i]=tmp;
			tmp=B[k];
			B[k]=B[i];
			B[i]=tmp;
		}
	}
	A[r]=A[k+1];
	A[k+1]=m;
	tmp=B[k+1];
	B[k+1]=B[r];
	B[r]=tmp;
	return k+1;
}
void quicksort(int l,int r,int *A,int *B)
{
	if (l<=r)
	{
		int m=divide(l,r,A,B);
		quicksort(l,m-1,A,B);
		quicksort(m+1,r,A,B);
	}

}
int main(int argc, char const *argv[])
{
	cin>>n;
	long long tmp;
	for (int i=1;i<=n;i++)
	{
		cin>>num1[i];
		order2[i]=i;
	}
	
	for (int i=1;i<=n;i++)
		cin>>num2[num1[i]];
	quicksort(1,n,num1,order2);
	for (int i=1;i<=n;i++)
		cout<<order2[i]<<' ';
	cout<<endl;
	quicksort(1,n,num2,order2);
	for (int i=1;i<=n;i++)
		cout<<order2[i]<<' ';
	cout<<endl;
	for (int i=n;i>=1;i--)
	{
		sum+=query(order2[i]-1);insert(order2[i]);
	}
	cout<<sum;
	return 0;
} 