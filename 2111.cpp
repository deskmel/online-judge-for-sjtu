#include <iostream>
using namespace std;
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
	binarysearchTree(){head=NULL;}
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
		node *q=Tree_search(k,head);
		return q;
	}
	bool find(int x)
	{
		node* y=Tree_search(x);
		if (y==NULL)
			return false;
		else return true;
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
	node * Tree_MAXIMUM(node *x)
	{
		while (x->right!=NULL)
			x=x->right;
		return x;
	}
	node * Tree_MINUMIN()
	{
		if (head==NULL) return NULL;
		return Tree_MINUMIN(head);
	}
	node * Tree_MAXIMUM()
	{
		if (head==NULL) return NULL;
		return Tree_MAXIMUM(head);
	}
	node *Tree_succsor(node *x)
	{
		if (x->right!=NULL)
			return Tree_MINUMIN(x->right);
		node *y=x->p;
		while (y!=NULL && x==y->right)
		{
			x=y;
			y=y->p;
		}
		return y;
	}
	node *Tree_precusor(node *x)
	{
		if (x->left!=NULL)
			return Tree_MAXIMUM(x->left);
		node *y=x->p;
		while (y!=NULL && x==y->left)
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
		else if (z->right==NULL)
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
 		delete z; 
	}
	void tree_delete(int x)
	{
		node *z=Tree_search(x);
		if (z==NULL)
			return;
		else 
		{
			tree_delete(z);
		}
		return ;
	}
	int find_smallest(int x)
	{
		node *res=find_smallest(x,head);
		if (res->val<x)
		{
			node *q=Tree_succsor(res);
			if (q!=NULL)
				return min(x-res->val,q->val-x);
			else return x-res->val;
		}
		else 
		{
			node *q=Tree_precusor(res);
			if (q!=NULL)
				return min(res->val-x,x-q->val);
			else
				return res->val-x;
		}
	}
	node * find_smallest(int k,node *x)
	{
		if (k==x->val)
			return x;
		if (k<x->val)
		{
			if (x->left!=NULL)
				return find_smallest(k,x->left);
		}
		else 
		{
			if ((x->right)!=NULL)
				return find_smallest(k,x->right);
		}
		return x;
	}
};
int main(int argc, char const *argv[])
{
	int m,op,x;
	cin>>m;
	binarysearchTree *a=new binarysearchTree();
	for (int i=0;i<m;i++)
	{
		cin>>op>>x;
		switch(op)
		{
			case 0:cout<<a->find_smallest(x)<<endl;break;
			case 1:a->tree_insert(x);break;
			case 2:a->tree_delete(x);break;
		}
	}
	return 0;
}