#include <iostream>
using namespace std;
int total=0;
int index;
int N[100000];
int main(int argc, char const *argv[])
{

	int a,b;
	cin>>a>>b;
	for (int i=0;i<a;i++)
		{
			cin>>N[i];
			if (i==0)
			{
				if (N[i]>b)
					N[i]=1;
				else if (N[i]==b)
					{
						N[i]=0;
						index=i;
					}
				else 
					N[i]=-1;
			}
			else
			{
				if (N[i]>b)
					N[i]=N[i-1]+1;
				else if (N[i]==b)
				{
					N[i]=N[i-1];
					index=i;
				}
				else
				{
					N[i]=N[i-1]-1;
				}
			}
		}
	for (int i=0;i<=index;i++)
		for (int j=index;j<a;j++)
		{
			if ((j-i+1)%2==1)
			{
				if(i==0)
				{
					if (N[j]==0)
						total+=1;
				}
				else
				{
					if (N[j]==N[i-1])
					total+=1;
				}
			}
		}
	cout<<total;
	return 0;
}