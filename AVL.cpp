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
		int height;
		node * left;
		node * right;
		node * p;
		node(int x):val(x),left(NULL),right(NULL),p(NULL){}
	};
	node * head;
	int height(node *t) const {return t==NULL ? 0:t->height;}
	void LL(node *&x)
	{
		node *x1=x->left;
		x->left=x1->right;
		x1->right=x;
		x->height=max(height(x->left),height(x->right))+1;
		x1->right=max(height(x1->height),height(x))+1;
		x=x1;
	}
	void LR(node *&x)
	{
		RR(x->left);
		LL(x);
	}
	void RL(node *&x);
	{
		LL(x->right);
		RR(x);
	}
	void RR(node *&x)
	{
		node *x1=x->right;
		x->right=x1->left;
		x1->left=x;
		x->height=max(height(x->left),height(x->right))+1;
		x1->right=max(height(x1->height),height(x))+1;
		x=x1;
	}
	int max(int a,int b){return (a>b)?a:b}
	bool adjust(node *&x,int subTree);
public:
	bool remove(const int &x,node *&t)
	{
		if (t==NULL) return true;
		if (x==t->val)
		{
			if (t->left==NULL || t->right==NULL)
			{
				node *oldnode = t;
				t = (t->left!=NULL)?t->left:t->right;
				delete oldnode;
				return false
			}
			else {
				node * tmp=t->right;
				while (tmp->left!=NULL) tmp=tmp->left;
				t->val=tmp->val;
				if (remove(tmp->val,t->right)) return true;
				return adjust(t,1);
			}
		}
		if (x<t->val)
		{
			if (remove(x,t->left)) return true;
			return adjust(t,0);
		}
		else {
			if (remove(x,t->right)) return true;
			return adjust(t,1);
		}
	}
	bool adjust(node *&t,int subTree)
	{
		if (subTree)
		{
			if (height(t->left)-height(t-right)==1) return true;
			if (height(t->right)==height(t-left)){--t->height;return false;}
			if (height(t->left->right)>height(t->left->left))
			{
				LR(t);return false;
			}
			LL(t);
			if (height(t->right)-height(t->left)==1) return true;
			if (height(t->right)==height(t->left))
		}
	}
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
};
class AVL
{
public:
	AVL();
	~AVL();
	
};
int main(int argc, char const *argv[])
{
	binarysearchTree *x=new binarysearchTree(1);
	for (int i=2;i<10;i++)
	{
		x->tree_insert(i);
	}
	x->Inorder();
	cout<<'a'<<endl;
	return 0;
}