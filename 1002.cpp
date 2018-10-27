#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int m,n;
	cin>>m>>n;
	int a[1000][1000];
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	int l1,l2;
	int sum=0;
	int sum_1;
	cin>>l1>>l2;
	for (int i=0;i<m-l1+1;i++)
		for (int j=0;j<n-l2+1;j++)
		{
			sum_1=0;

			for (int k1=0;k1<l1;k1++)
				for (int k2=0;k2<l2;k2++)
				{
					sum_1+=a[i+k1][j+k2];
				}
			if (sum_1>sum)
				sum=sum_1;
		}
	cout<<sum;
	return 0;
}