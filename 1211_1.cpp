#include <iostream>
using namespace std;
int ls[100000];
int rs[100000];
bool fa[100000];
int m;
class binarytree
{
private:
	class node
	{
			public:
		int val;
		node* left;
		node* right;

		node(int x):val(x),left(NULL),right(NULL){}
		void setleft(node* l){left=l;}
		void setright(node * r){right=r;}
	};
	node* head;
public:
	binarytree(int x){createtree(x);}
	void createtree(int i)
	{
		head=new node (i);
		traverseset(head);
	}
	void traverseset(node *q)
	{
		int i=q->val;

		if (ls[i]!=0)
		{
			q->left=new node (ls[i]);
			traverseset(q->left);
		}
		if (rs[i]!=0)
		{
			q->right=new node (rs[i]);
			traverseset(q->right);
		}
	}
	bool judgecompletetree()
	{
		node *q=head;
		node* queue[100000];
		int head_=0,tail=0;
		queue[tail++]=head;
		bool flag=true,res=true;
		while (tail!=head_)
		{
			node* p=queue[head_++];

			if (p->left!=NULL)
			{
				queue[tail++]=p->left;
				if (!flag) res=false;
			}
			else flag=false;
			if (p->right!=NULL)
			{
				queue[tail++]=p->right;
				if (!flag) res=false;
			}
			else flag=false;
		}
		return res;

	}

};


int main(int argc, char const *argv[])
{
	cin>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>ls[i]>>rs[i];
		if (ls[i]!=0)
			fa[ls[i]]=true;
		if (rs[i]!=0)
			fa[rs[i]]=true;
	}
	for (int i=1;i<=m;i++)
	{
		if (!fa[i])
		{	
			binarytree *x=new binarytree(i);
			if (x->judgecompletetree())
				cout<<'Y';
			else cout<<'N';
		}
	}
	return 0;
}