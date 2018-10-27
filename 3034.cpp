#include <iostream>
using namespace std;
bool prime[2000000];
void makePrime(int n)
{
	int i,j;
	n=min(2000000,2*n);
	for (i=2;i<=n;++i)
		prime[i]=true;
	for (i=2;i<n;i++)
		if (prime[i])
		{
			j=i*2;
			while (j<=n)
			{
				prime[j]=false;j=j+i;
			}
		}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	makePrime(n);
	if (prime[n])
		cout<<0<<endl;
	else
	{
		int total=0;
		for (int i=n-1;i>=2;i--)
		{
			if (prime[i])
			{
				total+=1;
				break;
			}
			else total+=1;
		}
		for (int i=n+1;i<=2*n;i++)
		{
			if (prime[i])
			{
				total+=1;
				break;
			}
			else total+=1;
		}
		cout<<total<<endl;

	}
	return 0;
}