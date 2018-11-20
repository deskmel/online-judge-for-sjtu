#include <iostream>
using namespace std;
//binarysearch  Tree
class binarysearchTree
{
private:
	class node 
	{
	public:
		int val;
		node * left;
		node * right;
		node * p;
		node(int x):val(x),left(NULL),right(NULL),p(NULL){}
	};
	node * head;
public:
	binarysearchTree(int x){head=new node (x);}
	void Inorder(node *x)
	{
		if (x!=NULL)
		{
			Inorder(x->left);
			cout<<x->val<<' ';
			Inorder(x->right);
		}

	}
	void Inorder()
	{
		Inorder(head);
	}

	node* Tree_search(int k,node *x)
	{
		if (x==NULL || k==x->val)
			return x;
		if (k<x->val)
			return Tree_search(k,x->left);
		else return Tree_search(k,x->right);
	}
	node* Tree_search(int k)
	{
		Tree_search(k,head);
	}
	node * Tree_search_iteractive(node *x,int k)
	{
		while (x!=NULL && k!=x->val)
		{
			if (k<x->val)
				x=x->left;
			else
				x=x->right;
		}
		return x;
	}
	node* Tree_MINUMIN(node *x)
	{
		while (x->left!=NULL)
			x=x->left;
		return x;
	}
	node * Tree_MAXIMUM()
	{
		node *x=head;
		while (x->right!=NULL)
			x=x->right;
		return x;
	}
	node *Tree_succsor(node *x)
	{
		if (x->left!=NULL)
			return Tree_MINUMIN(x);
		node *y=x->p;
		while (y!=NULL && x==y->right)
		{
			x=y;
			y=y->p;
		}
		return y;
	}
	void tree_insert(int x)
	{
		node *t= new node (x);
		tree_insert(t);
	}
	void tree_insert(node *z)
	{
		node * y=NULL;
		node * x=head;
		while (x!=NULL)
		{
			y=x;
			if (z->val <x->val)
				x=x->left;
			else x=x->right;
		}
		z->p=y;
		if (y==NULL)
			head=z;
		else if (z->val<y->val)
			y->left=z;
		else y->right=z;
	}
	void tranparent(node *u,node* v)
	{
		if (u->p==NULL)
			head=v;
		else if (u->p->right==u)
			u->p->right=v;
		else u->p->left=v;
		if (v!=NULL)
			v->p=u->p;
	}
	void tree_delete(node *z)
	{
		if (z->left == NULL)
		{
			tranparent(z,z->right);
		}
		else if (z->left==NULL)
		{
			tranparent(z,z->left);
		}
		else 
		{
			node *y=Tree_MINUMIN(z->right);
			if (y->p!=z)
			{
				tranparent(y,y->right);
				y->right=z->right;
				y->right->p=y;
			}
			tranparent(z,y);
			y->left=z->left;
			y->left->p=y;
		}
	}
	void tree_delete(int x)
	{
		node *z=Tree_search(x);
		if (z==NULL)
			cout<<"can't find such node"<<'\n';
		else 
		{
			tree_delete(z);
		}
		return ;
	}
};



int main(int argc, char const *argv[])
{
	binarysearchTree *x=new binarysearchTree(1);
	for (int i=2;i<10;i++)
	{
		x->tree_insert(i);
	}
	x->Inorder();
	return 0;
}