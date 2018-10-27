#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;
long long t,t1;
int n,m,v,v1;
long long operate[10007][3];
int main(int argc, char const *argv[])
{
	double money=0;
	cin>>m;
	for (int i=0;i<m;i++)
	{
			cin>>operate[i][0]>>operate[i][1]>>operate[i][2];
	}
	int head=0;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>t>>v;
		while (operate[head][0]<t and head<m)
		{
			if (operate[head][2]==1)
			{
				money-=(operate[head][1]*v1*0.2>=5)?(100.2*operate[head][1]*v1):(operate[head][1]*100*v1+5);
				money-=(operate[head][1]*0.1);
				money-=1;
			}
			else 
			{
				money+=(operate[head][1]*v1*0.2>=5)?(99.8*operate[head][1]*v1):(operate[head][1]*100*v1-5);
				money-=(operate[head][1]*0.1);
				money-=1;
				money-=(operate[head][1]*v1*0.1);
			}
			head+=1;
		}
		t1=t;v1=v;
	}
	for (;head<m;head++)
	{
		if (operate[head][2]==1)
			{
				money-=(operate[head][1]*v1*0.2>=5)?(100.2*operate[head][1]*v1):(operate[head][1]*100*v1+5);
				money-=(operate[head][1]*0.1);
				money-=1;
			}
			else 
			{
				money+=(operate[head][1]*v1*0.2>=5)?(99.8*operate[head][1]*v1):(operate[head][1]*100*v1-5);
				money-=(operate[head][1]*0.1);
				money-=1;
				money-=(operate[head][1]*v1*0.1);
			}
	}
	printf("%.2f\n",money );
	return 0;
}