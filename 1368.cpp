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
int n,m,sum,total;
node* del(int k,node *start)
{
	node *tmp=start;
	if (k==0)
	{
		tmp=tmp->pre;
	}
	else	
	for (int i=0;i<k-1;i++)
	{
	 	tmp=tmp->next;
	}
	tmp->pre->next=tmp->next;
	tmp->next->pre=tmp->pre;
	sum-=tmp->val;
	total-=1;
	return tmp->next;
}
node * insert(int k,node *start,int w)
{
	node *tmp=start;
	if (k==0)
	{
		tmp=tmp->pre;
	}
	else	
	for (int i=0;i<k-1;i++)
	{
		tmp=tmp->next;
	}
	node * q=new node (w);
	q->next=tmp->next;
	tmp->next->pre=q;
	tmp->next=q;
	q->pre=tmp;
	sum+=w;
	total+=1;
	return q;
}
int main(int argc, char const *argv[])
{	
	node *head=new node (1);
	node *q=head;
	cin>>n>>m;
	sum=(n+1)*n/2;
	total=n;
	for (int i=2;i<=n;i++)
	{
		node *tmp=new node(i) ;
		q->next=tmp;
		tmp->pre=q;
		q=q->next;
	}
	q->next=head;
	head->pre=q;
	for (int i=0;i<m;i++)
	{
		int op,k,w;
		cin>>op;
		if (op==0)
		{
			cin>>k;
			head=del(k%total,head);
		}
		else 
		{
			cin>>k>>w;
			head=insert(k%total,head,w);
		}
	}
	cout<<sum;
	
	return 0;
}