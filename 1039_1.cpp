#include <iostream>
using namespace std;
int a[30000];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int f,l,r;
	a[1]=1;
	head=1;
	for (int i=1;i<=n;i++)
	{
		cin>>f>>l>>r;
		if (l!=-1)
		a[l]=a[f]*2;
		if (r!=-1)
		a[r]=a[f]*2+1;
	}
	for (int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	int list[30000];
	head=1
	while (a[head]!=0)
	{
		
	}
	
	return 0;
}