#include <iostream>
#include <stdio.h>
using namespace std;
int val[1000005];
int seqTree[20000010];
int n,m;
void build(int root,int arr[],int istart,int iend)
{
	if (istart==iend)
		seqTree[root]=arr[istart];
	else
	{
		int mid= (istart +iend)/2;
		build(root*2+1,arr,istart,mid);
		build(root*2+2,arr,mid+1,iend);
		seqTree[root]=seqTree[root*2+1]+seqTree[root*2+2];
	}
}
int query(int root,int start,int end,int qstart,int qend)
{
	if (qstart>end || qend<start)
		return 0; 
	if (qstart==start && qend == end)
		return seqTree[root];
	int mid=(start+end)/2;
	if (qstart<=mid && qend>=mid)
		return query(root*2+1,start,mid,qstart,mid)+query(root*2+2,mid+1,end,mid+1,qend);
	else if (qend<mid)
		return query(root*2+1,start,mid,qstart,qend);
	else return query(root*2+2,mid+1,end,qstart,qend);
}
void update(int root,int start,int end,)
int main(int argc, char const *argv[])
{
	scanf("%d %d\n",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&val[i]);
		cout<<val[i]<<endl;
	}
	build(0,val,0,n-1);
	for (int i=0;i<m;i++)
	{
		int op,l,r,x;
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				scanf("%d %d",&l,&r);
				cout<<query(0,0,n-1,l-1,r-1);
				break;			
			case 2:

			case 3:break;
		}
	}
	return 0;
}