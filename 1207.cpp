#include <iostream>
#include <iomanip>
using namespace std;
int car[20000],head1,tail1;
int truck[20000],head2,tail2;
int n;
double wait1,wait2;
int main(int argc, char const *argv[])
{
	cin>>n;
	int type,time;

	for (int i=0;i<n;i++)
	{
		cin>>type;
		if (type)
			cin>>truck[tail2++];
		else cin>>car[tail1++];
	}
	int times=0;
	while (head1!=tail1 || head2!=tail2)
	{
		int k=10;
		int m=8,j=2;
		for (int i=0;i<8;i++)
		{
			if (head1!=tail1 && car[head1]<=10*times)
			{
				wait1+=times*10-car[head1++];
				m--;
			}
			else break;
		}
		for (int i=0;i<2;i++)
		{
			if (head2!=tail2 & truck[head2]<=10*times)
			{
				wait2+=times*10-truck[head2++];
				j--;
			}
			else break;
		}
		if (m==0 && j!=0)
		{
			for (int i=0;i<j;i++)
			{
				if (head1!=tail1 && car[head1]<=10*times)
				{
					wait1+=times*10-car[head1++];
				}
				else break;
			}
		}
		else if (m!=0 && j==0)
		{
			for (int i=0;i<m;i++)
			{
				if (head2!=tail2 & truck[head2]<=10*times)
				{
					wait2+=times*10-truck[head2++];
				}
				else break;				
			}
		}
		times+=1;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<wait1/tail1<<' '<<wait2/tail2<<endl;
	return 0;
}