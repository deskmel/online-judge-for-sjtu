#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int li1[1000010];
int li2[1000010];
int height[1000010];
int dead_weight;
int dead_height[1000010];
struct node
{
	int x;
	int y;
	int value;
	node(int a,int b,int c):x(a),y(b),value(c){}
};
node* heap[1000010];
int length;
void insert(int x,int y,int value)
{
	heap[++length]=new node(x,y,value);
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
void show()
{
	for (int i=1;i<=length;i++)
		cout<<heap[i]->value<<' ';
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	cin>>n;
	for (int i=0;i<n;i++)
		scanf("%d",&li1[i]);
	for (int i=0;i<n;i++)
		scanf("%d",&li2[i]);
	quicksort(li1,0,n-1);
	quicksort(li2,0,n-1);
	int index=0;
	insert(0,0,li1[0]+li2[0]);
	while (index<n)
	{
		node *k=pop();
		index++;
		dead_weight=max(k->x,dead_weight);
		dead_height[k->x]=k->y;
		printf("%d ",k->value);
		if ((dead_height[k->x+1]==(k->y-1)  && height[k->x+1]<k->y)||(k->y==0 && dead_weight==k->x))
		{
			height[k->x+1]=k->y;
			insert(k->x+1,k->y,li1[k->x+1]+li2[k->y]);
		}
		if (k->x==0  && height[k->x]<k->y+1 || dead_height[k->x-1]>=k->y+1 && height[k->x]<k->y+1)
		{	
			height[k->x]=k->y+1;
			insert(k->x,k->y+1,li1[k->x]+li2[k->y+1]);
		}
	}
	return 0;
}