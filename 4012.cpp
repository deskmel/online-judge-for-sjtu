#include <iostream>
using namespace std;
int heap[10000],length;
void insert(int x)
{
	heap[++length]=x;
	int tmp,k=length;
	while (k/2>0)
	{
		if (heap[k]<heap[k/2])
		{
			tmp=heap[k];heap[k]=heap[k/2];heap[k/2]=tmp;
		}
		else break;
		k/=2;
	}
}
void MAKE_HEAPITY(int);
int pop()
{
	int min=heap[1];
	heap[1]=heap[length--];
	MAKE_HEAPITY(1);
	return min;
}
void MAKE_HEAPITY(int index)
{
	int val=heap[index];
	int next_index=index;
	int tmp;
	if (index*2<=length&&val>heap[index*2])
		{val=heap[index*2];next_index=index*2;}
	if (index*2+1<=length&&val>heap[index*2+1])
		{val=heap[index*2+1];next_index=index*2+1;}
	if (next_index!=index)
	{
		heap[next_index]=heap[index];
		heap[index]=val;
		MAKE_HEAPITY(next_index);
	}
}
void show()
{
	for (int i=1;i<=length;i++)
		cout<<heap[i]<<' ';
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	int m;
	cin>>m;
	int tmp;
	for (int i=1;i<=m;i++)
	{
		cin>>tmp;
		insert(tmp);
	}
	int ans=0;
	for (int i=0;i<m-1;i++)
	{
		int tmp=pop()+pop();
		insert(tmp);
		ans+=tmp;
	}
	cout<<ans;
	return 0;
}