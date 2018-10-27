#include <iostream>
using namespace std;
int ls[100005];
int rb[100005];
int val[100005];
int son[100005];
int N;
void pre(int i)
{
	cout<<val[i]<<' ';
	int l=ls[i];
	while (l!=0)
	{
		pre(l);
		l=rb[l];
	}
}
void post(int i)
{
	int l=ls[i];
	while (l!=0)
	{
		post(l);
		l=rb[l];
	}
	cout<<val[i]<<' ';
}
void levelorder(int i)
{
	int que[100000];
	int head=0,tail=0;
	que[tail++]=i;
	while (head!=tail)
	{
		int tmp=que[head++];
		int k=ls[tmp];
		cout<<val[tmp]<<' ';
		while (k!=0)
		{
			que[tail++]=k;
			k=rb[k];
		}
	}
}
int main(int argc, char const *argv[])
{
	cin>>N;
	for (int i=0;i<N;i++)
	{
		cin>>ls[i+1]>>rb[i+1]>>val[i+1];
		son[ls[i+1]]=1;
		son[rb[i+1]]=1;
	}
	for (int i=1;i<=N;i++)
	{
		if (son[i]==0)
		{
			pre(i);
			cout<<endl;
			post(i);
			cout<<endl;
			levelorder(i);
			break;
		}
	}

	return 0;
}