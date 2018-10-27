#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int M[5];
	for (int i=0;i<5;i++)
	{
		cin>>M[i];
	}
	int t=0;
	int num=0;
	char s;
	int k;
	for (int i=0;i<M[1];i++)
	{
		cin>>s;
		if (s=='u')
		{
			k=(M[2]+M[4]);
		}
		else if (s=='f')
		{
			k=(M[3]*2);
		}
		else
		{
			k=(M[4]+M[2]);
		}
		if (k<=M[0]-t)
		{
			t+=k;
			num+=1;

		}
		else break;

	}
	cout<<num;
	return 0;
}
