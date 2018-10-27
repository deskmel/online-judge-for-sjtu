#include <iostream>
using namespace std;
long long n;
long long fib(long long a,long long b,int n)
{
	if (n==0)
		return a;
	else return fib(b,a+b,n-1);
}
int main(int argc, char const *argv[])
{
	cin>>n;
	if (n==1 or n==2)
		cout<<1;
	else cout<<(fib(1,1,n-1)%2010)<<endl;
	return 0;
}