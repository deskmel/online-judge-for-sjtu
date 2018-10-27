#include <iostream>
using namespace std;
int a[150000];
int m,n;
class node
{
	int i;
	node *next;
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	node *a[150002];
	for (int i=0;i<n;i++)
	{
		a[i]=new node (0);
	}
	int c,d;
 	for (int i=0;i<m;i++)
 	{
 		cin>>c>>d;
 		a[c]->next=new node (d);
 		a[d]->next=new node (c);
 	}
 	int seq[150000];
 	 
	return 0;
}