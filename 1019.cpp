#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cin.sync();
	string para;
	for (int i=0;i<n;i++)
	{
		int top=0;
		cin>>para;
		for (int j=0;j<para.size();j++)
		{
			if (para[j]=='(')
				top++;
			else 
			if (top==0)
			{
				top-=1;
				break;
			}
			else
				top-=1;
		}
		if (top!=0)
			cout<<"NO"<<'\n';
		else cout<<"YES"<<'\n';

	}
	return 0;
}