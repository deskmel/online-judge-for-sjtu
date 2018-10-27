#include <iostream>
#include <string.h>
using namespace std;
int heap[1024];
int index_1[1024];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int x,y,z;
	cin>>x>>y>>z;
	index_1[x]=1;
	index_1[y]=index_1[x]*2;
	index_1[z]=index_1[x]*2+1;
	heap[index_1[x]]=x;
	heap[index_1[y]]=y;
	heap[index_1[z]]=z;
	int i=3;
	while (i<n)
	{
		cin>>x>>y>>z;
		index_1[y]=index_1[x]*2;
		index_1[z]=index_1[x]*2+1;
		heap[index_1[y]]=y;
		heap[index_1[z]]=z;
		i+=2;
	}
	for (int i=1;i<=n;i++)
		cout<<heap[i]<<endl;
	return 0;
}
