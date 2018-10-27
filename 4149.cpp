#include <iostream>
using namespace std;
class node
{
public:
	int val;
	node *next;
	node *pre;
	node(int x):val(x),next(NULL),pre(NULL){}
};
int n,m,k;

int main(int argc, char const *argv[])
{	
	cin>>n>>m>>k;
	node *head=new node(1);
	node *q=head;
	for (int i=2;i<=n;i++)
	{
		q->next=new node(i);
		q->next->pre=q;
		q=q->next;
	}
	q->next=head;
	head->pre=q;
	q=head;
	for (int i=0;i<k;i++)
	{
		for (int j=0;j<m-1;j++)
		{
			q=q->next;
		}
		q->pre->next=q->next;
		q->next->pre=q->pre;
		if (i==k-1)
			cout<<q->val;
		q=q->next;
	}
	return 0;
}