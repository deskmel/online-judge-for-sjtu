#include <iostream>
using namespace std;
int l[1000000],r[1000000],heap_1[1000000];
int n;
bool heap(int i)
{	bool flag=true;
	if (l[heap_1[i]]!=-1)
	{
		
		if ((2*i+1)>n-1)
			return false;
		else
		{
			heap_1[2*i+1]=l[heap_1[i]];
			flag=heap(2*i+1);
		}
	}
	if (r[heap_1[i]]!=-1)
	{
		
		if ((2*i+2)>n-1)
			return false;
		else
		{
			heap_1[2*i+2]=r[heap_1[i]];
			flag=heap(2*i+2);
		}
	}
	return flag;
}
int main(int argc, char const *argv[])
{


	cin>>n;
	for (int i=0;i<n;i++)
	{
		l[i]=-1;
		r[i]=-1;
	}
	int node;
	for (int i=1;i<n;i++)
	{
		cin>>node;
		if (l[node]==-1)
		{
			l[node]=i;
		}
		else r[node]=i;
	}
	heap_1[0]=0;
	bool flag=heap(0);
	if (!flag)
	{
		cout<<"false"<<endl;
		return 0;
	}
	for(int i=1;i<=n-1;i++)
	{
		if (heap_1[i]==0)
			flag=false;
	}
	if (flag)
		cout<<"true"<<endl;
	else cout<<"false"<<endl;
	return 0;
}