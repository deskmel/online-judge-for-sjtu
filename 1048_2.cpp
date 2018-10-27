#include <iostream>
using namespace std;
class node
{
public:
	node* left=NULL;
	node* right=NULL; 
	int val;
	bool root=1;
	node (int v):val(v){}
};
node *a[1024];
node *li[1024];
void bfs(node *root)
{
	int head=1;int tail=1;
	li[head]=root;
	tail+=1;
	while (head!=tail)
	{
		node *q=li[head];
		if (q->left!=NULL)
		{
			li[tail]=q->left;
			tail+=1;
			li[tail]=q->right;
			tail+=1;
		}
		head+=1;
	}
	for (int i=1;i<tail;i++)
	{
		cout<<li[i]->val<<endl;
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		a[i]=new node(i);
	}
	int x,y,z;
	for (int i=0;i<n/2;i++)
	{
		cin>>x>>y>>z;
		a[x]->left=a[y];
		a[x]->right=a[z];
		a[y]->root=false;
		a[z]->root=false;
	}
	node *root;
	for (int i=1;i<=n;i++)
	{
		if (a[i]->root)
		{
			root=a[i];
			break;
		}
	}
	bfs(root);
	return 0;
}