#include <iostream>
using namespace std;
int N;
int NUM[100005];
int T[100005];
long long N1;
int lowbit(int x)
{
	return x&(-x);
}
int query(int k)
{
	int res=0;
	while (k)
	{
		res+=T[k],k-=lowbit(k);
	}
	return res;
}
void insert(int k)
{
	while (k<=N)
		T[k]++,k+=lowbit(k);
}
int main(int argc, char const *argv[])
{
	cin>>N;
	for (int i=1;i<=N;i++)
	{
		cin>>NUM[i];
	}
	for (int i=N;i>=1;i--)
	{
		N1+=query(NUM[i]-1),insert(NUM[i]);
	}
	cout<<N1;
	return 0;
}