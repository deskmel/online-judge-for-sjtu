#include <iostream>
using namespace std;
int  A[1000005];
int stack[1000005];
int top=-1;
int T;
bool judge(int *stack,int k)
{
	int top=-1;int m=1;int i=1;
	while (i<k)
	{
		while (top==-1 || stack[i-1]>A[top] )
		{
			A[++top]=m++;
		}
		while (top!=-1 && stack[i-1]==A[top])
		{
			i++;
			top--;
		}
		if (top!=-1 && stack[i-1]<A[top])
			return false;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	int tmp;
	cin>>T;
	for (int i=0;i<T;i++)
	{
		cin>>tmp;
		for (int i=0;i<tmp;i++)
			cin>>stack[i];
		if (judge(stack,tmp)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	return 0;
}