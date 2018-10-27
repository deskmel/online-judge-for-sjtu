#include <iostream>
#include <vector>
using namespace std;
int n,m;
class node
{
public:
	int num;
	node(int x,int y=0):num(x),numnode(y){}
	vector<node*> nextnode;
	int numnode;
	void add(node *x)
	{
		nextnode.push_back(x);
		numnode+=1;
	}
}*a[150009];
int branch_num=0;
bool DFS_VISIT(node *,int ,int &);
bool DFS()
{
int node_num;
	for (int i=1;i<=n;i++)
	{
		if (a[i]->num==0)
		{	node_num=0;
			if (not DFS_VISIT(a[i],a[i]->numnode,node_num))
			{
				return false;
			}
			else if (node_num!=a[i]->numnode)
				return false;
		}
	}
	return true;
}
bool DFS_VISIT(node *x,int z,int &y)
{
	x->num=1;
	if (x->numnode!=z)
		return false;
	for (int i=0;i<(x->numnode);i++)
		if (x->nextnode[i]->num==0)
			{
			y+=1;
			if (not DFS_VISIT(x->nextnode[i],z,y))
					return false;
			}
	return true;
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		a[i]=new node(0);
	}
	int x,y;
	for (int i=0;i<m;i++)
	{
		cin>>x>>y;
		a[x]->add(a[y]);
		a[y]->add(a[x]);
	}
	if (DFS())
		cout<<"YES";
	else
		cout<<"NO";
	cout<<endl;
	return 0;
}