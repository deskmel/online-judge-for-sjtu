#include <iostream>
using namespace std;
int ls[100000];
int rb[100000];
bool fa[100000];
int n;
void preorder(int i)
{
	cout<<i<<' ';
	if (ls[i]!=0)
		preorder(ls[i]);
	if (rb[i]!=0)
		preorder(rb[i]);
	
}
void postorder(int i)
{
	
	if (ls[i]!=0)
		postorder(ls[i]);
	cout<<i<<' ';
	if (rb[i]!=0)
		postorder(rb[i]);
	
}
void levelorder(int i)
{
	int queue[100000],head=0,tail=0;
	queue[tail++]=i;
	while (head!=tail)
	{
		int t=queue[head++];
		cout<<t<<' ';
		if (ls[t]!=0)
		{
			queue[tail++]=ls[t];
			int j=ls[t];
			while (rb[j]!=0)
			{
				queue[tail++]=rb[j];
				j=rb[j];
			}
		}
	}

}
int main(int argc, char const *argv[])
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp;
		cin>>ls[tmp]>>rb[tmp];
		if (ls[tmp]!=0)
			fa[ls[tmp]]=true;
		if (rb[tmp]!=0)
			fa[rb[tmp]]=fa[tmp]=true;
	}
	for (int i=1;i<=n;i++)
		if (!fa[i])
		{
			preorder(i);cout<<endl;
			postorder(i);cout<<endl;
			levelorder(i);
		}

	return 0;
}