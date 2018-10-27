#include <iostream>
class binaryTree
{
private:
	struct node
	{
		int val;
		node *l;
		node *r;
		node():l(NULL),r(NULL){}
		node(int item,node* left=NULL,node* right=NULL):val(item),l(left),r(right){}
	};
	binaryTree():root(NULL){}
	void createTree(int N)
	{
		node **li=new node *[N];
		for (int i=1;i<=N;i++)
			li[i]=new node (i);
		for (int i=1;i<=N;i++)
		{
			if (l[i]!=0)
			{
				li[i]->l=li[l[i]];
			}
			if (r[i]!=0)
			{
				li[i]->r=li[r[i]];
			}
		}
	}
}
int N,l[10000],r[10000];
int main(int argc, char const *argv[])
{
	cin>>N;
	for (int i=0;i<N;i++)
		cin>>l[0]>>r[0];

	return 0;
}