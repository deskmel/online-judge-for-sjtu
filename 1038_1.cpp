#include <iostream>
using namespace std;
class node
{

public:
	int x;
	node *next;
	node(int x_1):x(x_1){}
	~node();
	
};
int main(int argc, char const *argv[])
{
	int m;
	cin>>m;
	node *head=new node(1);
	node *q=head;
	for (int i=2;i<=m;i++)
	{
		q->next=new node(i);
		q=q->next;
	}
	node *tail=q;
	q->next=head;
	int k;
	int s=m;
	for (int i=0;i<m-1;i++)
	{
		cin>>k;
		if (k>s)
			k=k%s;
		if (k==0)
			k=s;
		while (k>1)
		{
			q=q->next;
			k-=1;
		}
		q->next=q->next->next;
		s-=1;
	}
	cout<<q->x<<endl;
	return 0;
}