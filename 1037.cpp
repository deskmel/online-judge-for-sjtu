#include <iostream>
using namespace std;
int M,N;
int V1[10000];
int V2[10000];
int divide(int *a,int l,int r)
{
	int m=a[r];
	int q=l-1;
	int tmp;
	for (int i=l;i<r;i++)
	{
		if (a[i]>m)
		{
			q+=1;
			tmp=a[i];
			a[i]=a[q];
			a[q]=tmp;
		}
	}
	q+=1;
	a[r]=a[q];
	a[q]=m;
	return q;

}
void quick_sort(int *a,int l,int r)
{
	int mid=divide(a,l,r);
	if (mid-l>1)
		quick_sort(a,l,mid-1);
	if (r-mid>1)
		quick_sort(a,mid+1,r);
}
int binarysearch(int *a,int key,int l,int r)
{
	int mid=(r+l)/2;
	if (a[mid]==key)
		return mid;
	else if (a[mid]>key)
		return binarysearch(a,key,l,mid-1);
	else return binarysearch(a,key,mid+1,r);
}
int main(int argc, char const *argv[])
{
	cin>>M>>N;
	for (int i=0;i<M;i++)
		cin>>V1[i];
	for (int i=0;i<N;i++)
		cin>>V2[i];
	quick_sort(V1,0,M-1);
	quick_sort(V2,0,N-1);
	int n,top=0;
	for (int i=0;i<M;i++)
	{
		while (V1[i]<=V2[top] && top!=N)
			{top+=1;}
		if (top==N)
			break;
		else 
			{n+=1;top+=1;}
	}

		n+=M;
	cout<<n<<endl;
	return 0;
}