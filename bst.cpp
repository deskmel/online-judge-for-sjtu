#include <iostream>
#include <string.h>
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
	node *tree_findith(int x)
	{
		int k=x-1;
		if (head==NULL)
			return head;
		node *q=Tree_MINUMIN(head);
		for (int i=0;i<k;i++)
		{
			if (q==NULL)
				break;
			q=Tree_succsor(q);
		}
		return q;
	}
	void tree_findith_(int x)
	{
		node *q=tree_findith(x);
		if (q==NULL)
			cout<<'N'<<endl;
		else cout<<q->val<<endl;
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
	void tree_delete_greater(int x)
	{
		node *q=Tree_MAXIMUM();
		if (q==NULL)
			return;
		while ((q->val)>x)
		{	
			tree_delete(q);
			q=Tree_MAXIMUM();
			if (q==NULL)
				return;
		}
		return;
	}
	void tree_delete_less(int x)
	{
		node *q=Tree_MINUMIN();
		if (q==NULL)
			return;
		while (q->val<x)
		{
			tree_delete(q);
			q=Tree_MINUMIN();
			if (q==NULL)
				return;
		}
		return;
	}
	void tree_delete_between(int x,int y)
	{
		node *q=Tree_search(x);
		node *p;
		if (q==NULL)
		{
			node *q=new node (x);
			tree_insert(q);
			do
			{		
				p=Tree_succsor(q);
				tree_delete(q);
				q=p;
			}
			while (q!=NULL  && q->val<y);
		}
		else
		{
			p=Tree_succsor(q);
			while (p!=NULL && p->val<y)
			{
				tree_delete(p);
				p=Tree_succsor(q);
			}
		}
		return ;
	}
};
int N;
char op[25];
int tmp;
int main(int argc, char const *argv[])
{
	cin>>N;
	binarysearchTree *x= new binarysearchTree();
	for (int j=0;j<N;j++)
	{
		cin>>op;
		if (strcmp(op,"insert")==0)
		{
			cin>>tmp;
			x->tree_insert(tmp);
		}
		else if (strcmp(op,"find")==0)
		{
			cin>>tmp;
			if (x->find(tmp))
				cout<<'Y'<<endl;
			else cout<<'N'<<endl;
		}
		else if (strcmp(op,"find_ith")==0)
		{
			cin>>tmp;
			x->tree_findith_(tmp);
		}
		else if (strcmp(op,"delete")==0)
		{
			cin>>tmp;
			x->tree_delete(tmp);
		}
		else if (strcmp(op,"delete_less_than")==0)
		{
			cin>>tmp;
			x->tree_delete_less(tmp);
		}
		else if (strcmp(op,"delete_greater_than")==0)
		{
			cin>>tmp;
			x->tree_delete_greater(tmp);
		}
		else if (strcmp(op,"delete_interval")==0)
		{
			int tmp1,tmp2;
			cin>>tmp1>>tmp2;
			x->tree_delete_between(tmp1,tmp2);
		}
	}
	return 0;
}