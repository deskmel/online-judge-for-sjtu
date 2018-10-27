#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, char const *argv[])
{
	char code[105];
	char sent[105];
	cin>>sent>>code;
	int n=strlen(code);
	bool flag=true;
	bool smallflag=true;
	for (int i=2;i<=n;i++)
	{
		if (n%i!=0)
			continue;
		else
		{
			smallflag=true;
			for (int j=0;j<n;j++)
			{
				if (sent[j]!=code[j/i+j%i*(n/i)])
				{
					smallflag=false;
					break;
				}
			}
			if (smallflag)
			{
				cout<<i;
				flag=false;
				break;
			}
		}

	}
	if (flag)
		cout<<"No Solution";
	return 0;
}