#include <iostream>
using namespace std;
int T,N,M;
int num[1001];
bool whether(int n,int m)
{
	int stack[1001];
	int top=-1;
	int index_0=0;
	int index_1=0;
	while (index_0!=n)
	{
		if (index_1==num[index_0])
		{
			index_1++;
			index_0++;
		}
		else if (top!=-1 && stack[top]==num[index_0])
		{
			index_0++;
			top-=1;
		}
		else if (index_1!=n && top!=m-1)
		{
			stack[++top]=index_1++;

		}
		else 
			return false;
	}
	return true;


}
int main(int argc, char const *argv[])
{
	cin>>T;
	for (int i=0;i<T;i++)
	{
		cin>>N>>M;
		for (int j=0;j<N;j++)
		{
			cin>>num[j];
		}
		if (whether(N,M))
		{
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;

	}
	return 0;
}