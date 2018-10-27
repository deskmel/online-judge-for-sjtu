#include <iostream>
using namespace std;
int A[100005],B[100005];
int N;
long long Res;
int lowbit(int k)
{
	return k&-k;
}
// for exmaple k=5 : 101 -k: 011 k&-k (补码 保证 最后一位1是相同的)  001
int query(int k)//计算内部小于k的数字个数
{
	int res;
	while (k)
	{
		res+=B[k]
		k-=lowbit(k);
	}
	return res;
}
void insert(int k)
{
	while (k<=N)
	{
		B[k]+=1;
		k+=lowbit(k);
	}
}
int main(int argc, char const *argv[])
{
 	cin>>N;
 	for (int i=1;i<=N;i++)
 		cin<<A[i];
 	for (int i=N;i>=1;i--)
 	{
 		N1+=query(A[i]-1);
 		insert(A[i]);
 	}	
	return 0;
}
