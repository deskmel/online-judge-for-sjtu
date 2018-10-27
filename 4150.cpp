#include <iostream>
using namespace std;
int n,m;
int M[1005];
int K[1005];
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for (int i=0;i<m;i++)
	{
		cin>>M[i];
		if (i!=0)
			M[i]=M[i]+M[i-1];
	}
	for (int i=0;i<m;i++)
	{
		if (i<n)
			cout<<((M[i])/(i+1))<<endl;
		else cout<<(M[i]-M[i-n])/n<<endl;
	}
	/* code */
	return 0;
}