#include <iostream>
using namespace std;
int index[30005];
int heap[100005];
void print(int *heap,int head)
{
	if (heap[head*2]==0 and heap[head*2+1]==0)
		cout<<heap[head]<<' ';
	else if (heap[head*2]==0)
		{
			print(heap,head*2+1);
			cout<<heap[head]<<' ';
		}
	else if (heap[head*2+1]==0)
	{
		print(heap,head*2);
		cout<<heap[head]<<' ';
	}
	else
	{
		print(heap,head*2);
		print(heap,head*2+1);
		cout<<heap[head]<<' ';
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int f,l,r;
	index[1]=1;
	heap[1]=1;
	for (int i=1;i<=n;i++)
	{
		cin>>f>>l>>r;
		if (l!=-1)
		{
			index[l]=index[f]*2;
			heap[index[l]]=l;
		}
		if (r!=-1)
		{
			index[r]=index[f]*2+1;
			heap[index[r]]=r;
		}
	}
	for (int i=1;i<=n;i++)
		cout<<index[i]<<' ';
	int head=1;
	cout<<endl;
	print(heap,head);
	return 0;
}