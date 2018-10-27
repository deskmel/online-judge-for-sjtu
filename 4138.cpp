#include <iostream>
#include <iomanip>
using namespace std;
int n,m;
int M[100][3];
int countbits(int n)
{
	int count=0;
	while (n!=0)
	{
		n=n&(n-1);
		count++;
	}
	return count;
}
double Sol[66536];
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for (int i=0;i<m;i++)
	{
		cin>>M[i][0]>>M[i][1];
		int sum=0;
		for (int j=0;j<M[i][0];j++)
		{	
			int index;
			cin>>index;
			sum+=(1<<(index));
		}
		M[i][2]=sum;
	}
	double maxeff=0;
	for (int i=0;i<=(2<<n);i++)
	{
		for (int j=0;j<m;j++)
		{
			if ((i&M[j][2])==M[j][2])
			{
				Sol[i]+=M[j][1];
			}
		}
		maxeff=max(maxeff,double(Sol[i])/double(countbits(i)));
	}
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<maxeff;
	return 0;
}