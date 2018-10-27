#include <iostream>
using namespace std;
long long a[100005];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	int total=1;
	for (int i=0;i<n-1;i++)
	{
		if (a[i]>=a[i+1])
			total+=1;
	}
	if (n==0)
		total=0;
	cout<<total;
	
	return 0;
}