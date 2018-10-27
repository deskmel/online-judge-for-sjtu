#include <iostream>
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
	node *root_list;
	node *MIN;
	int n;

public:
	FIB_HEAP():n(0),root_list(NULL),MIN(NULL){};
	void FIB_HEAP_INSEART(int x)
	{
		node *a=new node (x);
		if (MIN==NULL)
		{
			root_list=a;
			a->left=a;
			a->right=a;
			MIN=a;
		}
		else 
		{
			a->right=root_list->right;
			a->right->left=a;
			a->left=root_list;
			root_list->right=a;
			if (MIN->value>a->value)
				MIN=a;
		}
		n+=1;
	}
	int FIB_HEAP_EXTRACT()
	{
		int v;
		node *z=MIN;
		if (z!=NULL)
		{
			node* p=z->child;
			node* q;
			for (int i=0;i<z->degree;i++)
			{
				q=p->right;

				p->left=z->left;
				z->left->right=p;
				p->right=z;
				z->left=p;
				p=q;
			}
			z->left->right=z->right;
			z->right->left=z->left;
			if (z==z->right)
				{MIN=NULL;root_list=NULL;}
			else 
			{
				MIN=z->right;
				CONSOLIDATE();
			}
			n=n-1;
			v=z->value;
		}
		else v=-1;
		return v;
	}
	void CONSOLIDATE()
	{
		node **A=new node* [n];
		for (int i=0;i<n;i++)
			{A[i]=NULL;}
		node *p=root_list;
		for (int i=0;i<n;i++)
		{
			node *x=p;
			int d=p->degree;
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
		for (int i=0;i<n;i++)
		{
			if (A[i]!=NULL)
			{
				if (MIN==NULL)
				{
					root_list=A[i];
					root_list->left=root_list;
					root_list->right=root_list;
					MIN=root_list;
				}
				else 
				{
					A[i]->left=root_list;
					A[i]->right=root_list->right;

					root_list->right->left=A[i];
					root_list->right=A[i];
				}
			}
		}
	}
	void FIB_HEAP_LINK(node* x,node* y)
	{
		node *son=x->child;
		y->left=y->right;
		y->right=y->left;

		y->left=x->child;
		y->right=x->child->right;
		x->child->right=y;
		x->child->right->left=y;

		y->mark=false;
	}
	~FIB_HEAP();
	
};
FIB_HEAP*  FIB_HEAP_UNION(FIB_HEAP *H1,FIB_HEAP *H2)
{
	cout<<H2->MIN;
	FIB_HEAP *H=new FIB_HEAP ();
	H->MIN=H1->MIN;
	H->root_list=H1->root_list;
	if (H->MIN==NULL)
	{
		H->root_list=H2->root_list;	
		H->MIN=H2->MIN;
	}
	else if (H2->MIN==NULL)
	{
		H->MIN=H1->MIN;
	}
	else
	{

		H2->root_list->left->right=H->root_list->right;
		H->root_list->right->left=H2->root_list->left;

		H->root_list->right=H2->root_list;

		H2->root_list->left=H->root_list;
		if ((H1->MIN->value)<(H2->MIN->value))
			{H->MIN=H1->MIN;}
		else {H->MIN=H2->MIN;}
	}
	H->n=H1->n+H2->n;
	
	return H;
}



int main(int argc, char const *argv[])
{
	int M,N;
	cin>>N>>M;
	FIB_HEAP **a=new FIB_HEAP* [N];
	int value;
	for (int i=0;i<N;i++)
	{
		cin>>value;
		a[i]=new FIB_HEAP ();
		a[i]->FIB_HEAP_INSEART(value);
	}
	int op,group1,group2;
	for (int i=0;i<M;i++)
	{
		cin>>op;
		if (op==0)
		{

			cin>>group1>>group2;
			a[group1]=FIB_HEAP_UNION(a[group1],a[group2]);
		}
		else if (op==1)
		{
			cin>>group1;
			cout<<a[group1]->FIB_HEAP_EXTRACT()<<endl;
		}
		else
		{
			int tmp;
			cin>>group1>>tmp;
			a[group1]->FIB_HEAP_INSEART(tmp);
		}
	}	
	return 0;
}