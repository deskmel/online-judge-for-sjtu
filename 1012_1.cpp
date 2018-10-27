#include <iostream>
using namespace std;
//dp问题

int s,t;
int ans[2000007];
long long times[2000007];
int main(int argc, char const *argv[])
{
	cin>>s>>t;
	int tmp;
	for (int i=s;i<=t;i++)
		times[i]=ans[i]=1;
	int max_0=1;
	int ans_0=t;
	for (int i=t;i>=s;i--) 
	{
		for (int j=1;j<=100;j++) if ((i*j)%100==0)
		{
			tmp=i+i*j/100;
			if (tmp<=t)
			{
				if (ans[tmp]+1>ans[i])
				{
					ans[i]=ans[tmp]+1;
					times[i]=times[tmp];

				}
				else if (ans[tmp]+1==ans[i])
				{
					times[i]+=times[tmp];
				}
				if (ans[i]>max_0)
				{
					max_0=ans[i];
				}

			}
		}
	}
	long long t1=0;
	for (int i=s;i<=t;i++)
	{
		if (ans[i]==max_0)
			t1+=times[i];
	}
	cout<<max_0<<'\n'<<t1;
	return 0;
}