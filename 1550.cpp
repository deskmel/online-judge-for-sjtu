#include <iostream>
using namespace std;
int n;
int height[10000];
int main(int argc, char const *argv[])
{
	cin>>n;
	char c;
	c=cin.get();
	c=cin.get();
	int MAX=0;int MAX_i=0;
	for (int i=0;i<n;i++)
	{
		scanf("%d%c",&height[i]);
		if (height[i]>MAX)
		{
			MAX=height[i];
			MAX_i=i;
		}
	}
	int high=0;
	int s=0;
	int total=0;
	for (int i=0;i<=MAX_i;i++)
	{
		if (height[i]>=high)
			{high=height[i];total+=s;s=0;}
		else {s+=high-height[i];}
	}
	high=0;
	s=0;
	for (int i=n-1;i>=MAX_i;i--)
	{
		if (height[i]>=high)
			{high=height[i];total+=s;s=0;}
		else {s+=high-height[i];}
	}	
	cout<<total<<endl;
	return 0;
}