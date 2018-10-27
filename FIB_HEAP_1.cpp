#include <iostream>
#include <cmath>
using namespace std;
class FIB_HEAP
{
	friend FIB_HEAP* FIB_HEAP_UNION(FIB_HEAP *H1,FIB_HEAP *H2);
	private:
		class node
	{
			public:
		int value;
		int degree;
		bool mark;
		node *parent;
		node *child;

		node *left;
		node *right;
		node(int v):value(v),degree(0),parent(NULL),mark(false),child(NULL){}
	};
	node *MIN;
	int n;

public:
	FIB_HEAP():n(0),MIN(NULL){};
	void FIB_HEAP_INSEART(int x)
	{
		node *a=new node (x);
		if (MIN==NULL)
		{
			MIN=a;
			a->left=a;
			a->right=a;
		}
		else 
		{
			a->right=MIN->right;
			MIN->right->left=a;
			a->left=MIN;
			MIN->right=a;
			if (MIN->value>a->value)
				MIN=a;
		}
		n+=1;
	}
	inline void removenode(node *p)
	{
		p->left->right=p->right;
		p->right->left=p->left;
	}
	inline void addnode(node *p)
	{
		p->left =MIN->left;
		MIN->left->right =p;
		p->right=MIN;
		MIN->left=p;

	}
	int FIB_HEAP_EXTRACT()
	{
		int v;
		node *z=MIN;
		if (z!=NULL)
		{
			
			node* p;
			while (z->child!=NULL)
			{
				
				p=z->child;
				removenode(p);
				if (p->right==p)
					z->child=NULL;
				else z->child=p->right;
				addnode(p);
				p->parent=NULL;
				

			}
			z->left->right=z->right;
			z->right->left=z->left;
			if (z==z->right)
				{MIN=NULL;}
			else 
			{
				MIN=z->right;
				CONSOLIDATE(n+z->degree-1);
			}
			n=n-1;
			v=z->value;
		}
		else v=-1;
		return v;
	}
	node * extractMIN()
	{
		node *p=MIN;
		if (p==p->right)
			MIN=NULL;
		else
		{
			p->left->right=p->right;
			p->right->left=p->left;
			MIN=p->right;
		}
		p->left=p->right=p;
		return p;
	}
	void CONSOLIDATE(int k)
	{
		int D=int(log(n*1.0)/log(2.0))+1;
		node **A=new node* [D];
		for (int i=0;i<D;i++)
			{A[i]=NULL;}
		while (MIN!=NULL)
		{
			node *x=extractMIN();
			int d=x->degree;
			while (A[d]!=NULL)
			{	
				node *y=A[d];
				if (x->value>y->value)
				{
					node *tmp=y;
					y=x;
					x=tmp;
				}

				FIB_HEAP_LINK(x,y);
				A[d]=NULL;
				d+=1;
			}
			A[d]=x;
		} 

		MIN=NULL;
		for (int i=0;i<D;i++)
		{
			if (A[i]!=NULL)
			{
				if (MIN==NULL)
				{
					MIN=A[i];
					MIN->left=MIN;
					MIN->right=MIN;
				}
				else 
				{
					A[i]->left=MIN;
					A[i]->right=MIN->right;

					MIN->right->left=A[i];
					MIN->right=A[i];
					if (A[i]->value<MIN->value)
					{
						MIN=A[i];
					}
				}
			}
		}
	}
	void FIB_HEAP_LINK(node* x,node* y)
	{
		node *son=x->child;
		y->left->right=y->right;
		y->right->left=y->left;
		if (son==NULL)
		{
			x->child=y;
		}
		y->left=x->child;
		y->right=x->child->right;
		x->child->right->left=y;
		x->child->right=y;

		x->degree+=1;
		y->mark=false;
	}
	~FIB_HEAP();
	
};
FIB_HEAP*  FIB_HEAP_UNION(FIB_HEAP *H1,FIB_HEAP *H2)
{
	FIB_HEAP *H=new FIB_HEAP ();
	H->MIN=H1->MIN;
	if (H->MIN==NULL)
	{
		H->MIN=H2->MIN;	
	}
	else if (H2->MIN==NULL)
	{
		H->MIN=H1->MIN;
	}
	else
	{

		H2->MIN->left->right=H->MIN->right;
		H->MIN->right->left=H2->MIN->left;

		H->MIN->right=H2->MIN;
		H2->MIN->left=H->MIN;
		if ((H1->MIN->value)<(H2->MIN->value))
			{H->MIN=H1->MIN;}
		else {H->MIN=H2->MIN;}
	}
	H->n=H1->n+H2->n;
	H2->MIN=NULL;H2->n=0;
	return H;
}



int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	int M,N;
	scanf("%d%d",&N,&M);
	FIB_HEAP **a=new FIB_HEAP* [N];
	int value;
	for (int i=0;i<N;i++)
	{
		scanf("%d",&value);
		a[i]=new FIB_HEAP ();
		a[i]->FIB_HEAP_INSEART(value);
	}
	int op,group1,group2;
	for (int i=0;i<M;i++)
	{
		scanf("%d",&op);
		if (op==0)
		{

			scanf("%d%d",&group1,&group2);
			a[group1]=FIB_HEAP_UNION(a[group1],a[group2]);
		}
		else if (op==1)
		{
			scanf("%d",&group1);
			printf("%d\n", a[group1]->FIB_HEAP_EXTRACT());
		}
		else
		{
			int tmp;
			scanf("%d%d",&group1,&tmp);
			a[group1]->FIB_HEAP_INSEART(tmp);
		}
	}	
	return 0;
}