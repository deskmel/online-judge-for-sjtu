#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int li1[1000010];
int divide(int *a,int l,int r)
{
	int q=l-1;
	int m=a[r];
	int tmp;
	for (int i=l;i<r;i++)
	{
		if (a[i]<m)
		{
			q++;
			tmp=a[i];a[i]=a[q];a[q]=tmp;
		}
	}
	q++;
	a[r]=a[q];
	a[q]=m;
	return q;
}
void quicksort(int *a,int l,int r)
{
	if (l<r)
	{
		int m=divide(a,l,r);
		quicksort(a,l,m-1);
		quicksort(a,m+1,r);
	}
}
struct node
{
	int index;
	int value;
	node(int i,int v):index(i),value(v){}
};
node* heap[1000010];
int length;
void insert(int value)
{
	heap[++length]=new node(0,value);
	int k=length;
	node *tmp;
	while (k/2>0)
	{
		if (heap[k/2]->value>heap[k]->value)
		{
			tmp=heap[k];heap[k]=heap[k/2];heap[k/2]=tmp;
		}
		else break;
		k/=2;
	}
}
void UP_HEAPITY(int);
node* pop()
{	

	node *k=heap[1];
	heap[1]=heap[length--];
	UP_HEAPITY(1);
	return k;
}
int pop_()
{
	int tmp=heap[1]->value;
	heap[1]->index+=1;
	heap[1]->value+=(li1[heap[1]->index]-li1[heap[1]->index-1]);
	UP_HEAPITY(1);
	return tmp;

}
void UP_HEAPITY(int i)
{
	if (length==0)
		return;
	int val=heap[i]->value;
	int m=i;
	if (i*2<=length && heap[i*2]->value<val)
	{
		val=heap[i*2]->value;m=i*2;
	}
	if (i*2+1<=length && heap[i*2+1]->value<val)
	{
		val=heap[i*2+1]->value;m=i*2+1;
	}
	if (m!=i)
	{
		node *tmp=heap[i];heap[i]=heap[m];heap[m]=tmp;
		UP_HEAPITY(m);
	}
}
int main(int argc, char const *argv[])
{
	cin>>n;
	for (int i=0;i<n;i++)
		scanf("%d",&li1[i]);
	quicksort(li1,0,n-1);
	int tmp;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		insert(tmp);
	}
	for (int i=0;i<n;i++)
	{
		printf("%d ", pop_()+li1[0]);
	}
	return 0;
}