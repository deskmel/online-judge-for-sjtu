#include <iostream>
using namespace std;
int l[30000],r[30000];
int N;
int index[30000];
void heap(int i)
{
	if (l[i]!=-1)
	{
		index[l[i]]=index[i]*2;
		heap(l[i]);
	}
	if (r[i]!=-1)
	{
		index[r[i]]=index[i]*2+1;
		heap(r[i]);
	}
}
void post_order(int i)
{
	if (l[i]!=-1)
		post_order(l[i]);

	if (r[i]!=-1)
		post_order(r[i]);
	cout<<i<<' ';
}
int main(int argc, char const *argv[])
{
	cin>>N;
	
	for (int i=0;i<N;i++)
	{	
		int m;
		cin>>m;
		cin>>l[m]>>r[m];
	}
	index[1]=1;
	heap(1);
	for (int i=1;i<=N;i++)
		cout<<index[i]<<' ';
	cout<<endl;
	post_order(1);
	return 0;
}