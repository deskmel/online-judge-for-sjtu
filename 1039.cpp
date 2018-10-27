#include <iostream>
using namespace std;
class node
{
public:
	int val;
	node *left;
	node *right;
	node(int x,node* l=NULL,node *r=NULL):val(x),left(l),right(r){}

};
void postorder(node *root)
{
	if (root->left==NULL and root->right==NULL)
		{
			cout<<root->val<<' ';
			return ;
		}
	else if (root->left==NULL)
	{
		postorder(root->right);
		cout<<root->val<<' ';
		return;
	}
	else if (root->right==NULL)
	{
		postorder(root->left);
		cout<<root->val<<' ';
		return;
	}
	else
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->val<<' ';
		return;
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	node *a[30000];
	for (int i=1;i<=n;i++)
		a[i]=new node(i);
	node *head=a[1];
	int f,l,r;
	for (int i=0;i<n;i++)
	{
		cin>>f>>l>>r;
		if (l!=-1)
		a[f]->left=a[l];
		if (r!=-1)
		a[f]->right=a[r];
	}
	postorder(a[1]);
	return 0;
}