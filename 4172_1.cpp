#include <iostream>
#include <stdlib.h>
using namespace std;
int val[1000005];
struct node
{
	int val;
	int lmax,rmax;
	int maxlen;
	bool full;
	bool lazy;
	node(int x):full(x),val(x),lmax(x),rmax(x),maxlen(x),lazy(false){}
};
node* seqTree[4000010];
void change(int root,int value,int len)
{
	node * target=seqTree[root];
	target->val=value*len;
	target->maxlen=target->lmax=target->rmax=value*len;
	target->full=value;
}
void pushdown(int root,int ln,int rn)
{
	if (ln!=0 && rn!=0 && seqTree[root]->lazy)
	{
		seqTree[root*2+1]->lazy=true;
		seqTree[root*2+2]->lazy=true;
		int value=int(seqTree[root]->full);
		change(root*2+1,value,ln);
		change(root*2+2,value,rn);
		seqTree[root]->lazy=false;
	}
}
void pushup(int root)
{
	seqTree[root]->val=seqTree[root*2+1]->val+seqTree[root*2+2]->val;
	seqTree[root]->lmax=(seqTree[root*2+1]->full)?seqTree[root*2+1]->lmax+seqTree[root*2+2]->lmax:seqTree[root*2+1]->lmax;
	seqTree[root]->rmax=(seqTree[root*2+2]->full)?seqTree[root*2+2]->rmax+seqTree[root*2+1]->rmax:seqTree[root*2+2]->rmax;
	seqTree[root]->full=(seqTree[root*2+1]->full&&seqTree[root*2+2]->full)?1:0;
	seqTree[root]->maxlen=max(seqTree[root*2+1]->maxlen,max(seqTree[root*2+2]->maxlen,seqTree[root*2+1]->rmax+seqTree[root*2+2]->lmax));
}
void build(int root,int arr[],int istart,int iend)
{
	if (istart==iend)
		seqTree[root]=new node (arr[istart]);
	else
	{
		seqTree[root]=new node (0);
		int mid= (istart +iend)/2;
		build(root*2+1,arr,istart,mid);
		build(root*2+2,arr,mid+1,iend);
		pushup(root);
	}
}
int query_1s(int root,int start,int end,int qstart,int qend)
{
	if (qstart>end || qend<start)
		return 0; 
	if (qstart==start && qend == end)
		return seqTree[root]->val;
	int mid=(start+end)/2;
	pushdown(root,mid-start+1,end-mid);
	if (qstart<=mid && qend>=mid)
		return query_1s(root*2+1,start,mid,qstart,mid)+query_1s(root*2+2,mid+1,end,mid+1,qend);
	else if (qend<mid)
		return query_1s(root*2+1,start,mid,qstart,qend);
	else return query_1s(root*2+2,mid+1,end,qstart,qend);
}
node query_1cs(int root,int start,int end,int qstart,int qend)
{
	if (qstart<=start && qend>=end)
		return *seqTree[root];
	int mid=(start+end)/2;
	pushdown(root,mid-start+1,end-mid);
	bool flag1=false;bool flag2=false;
	node lnode=node(0);node rnode=node(0);node res=node(0);
	if (qstart<=mid)
	{
		lnode=query_1cs(root*2+1,start,mid,qstart,qend);
		flag1=true;
	}
	if (qend>mid)
	{
		rnode=query_1cs(root*2+2,mid+1,end,qstart,qend);
		flag2=true;
	}

	if (flag1 && flag2)
	{

		res.maxlen=max(lnode.maxlen,max(rnode.maxlen,lnode.rmax+rnode.lmax));
		res.lmax=(lnode.full)?lnode.lmax+rnode.lmax:lnode.lmax;
		res.rmax=(rnode.full)?rnode.rmax+lnode.rmax:rnode.rmax;
		res.full=(lnode.full&&rnode.full);
	}
	else if (flag1)
	{
		res=lnode;
	}
	else
	{
		res=rnode;
	}
	return res;
}

void updateone(int root,int l,int r,int L,int C)
{
	if (l==r)
	{
		node *nod=seqTree[root];
		nod->val=nod->maxlen=nod->lmax=nod->rmax=nod->full=C;
		return;
	}
	int mid=(l+r)/2;
	if (L<=mid) updateone(root*2+1,l,mid,L,C);
	else updateone(root*2+2,mid+1,r,L,C);
	pushup(root);
}



void update(int root,int l,int r,int L,int R,int value)
{
	if (L<=l && R>=r)
	{
		change(root,value,r-l+1);
		seqTree[root]->lazy=true;
		return;
	}
	int m=(l+r)/2;
	pushdown(root,m-l+1,r-m);
	if (L<=m) update(root*2+1,l,m,L,R,value);
	if (R>m)  update(root*2+2,m+1,r,L,R,value);
	pushup(root);
}
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&val[i]);
	}
	build(0,val,0,n-1);
	for (int i=0;i<m;i++)
	{
		int op,l,r,x;
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				scanf("%d %d %d",&l,&r,&x);
				update(0,0,n-1,l-1,r-1,x);
				break;
			case 2:
				scanf("%d %d",&l,&r);
				printf("%d\n",query_1s(0,0,n-1,l-1,r-1));
				break;
			case 3:
				scanf("%d %d",&l,&r);
				printf("%d\n",query_1cs(0,0,n-1,l-1,r-1).maxlen);
				break;
		}
	}
}