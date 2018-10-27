#include <iostream>
#include <string.h>
using namespace std;
char num_1_str[1000],num_2_str[1000];
int num_1[1000],num_2[1000];
int ans;
int main(int argc, char const *argv[])
{
	cin>>num_1_str;
	cin>>num_2_str;
	int s1=strlen(num_1_str),s2=strlen(num_2_str);
	for (int i=s1-1;i>=0;i--)
		num_1[s1-i-1]=num_1_str[i]-'0';
	for (int i=s2-1;i>=0;i--)
		num_2[s2-i-1]=num_2_str[i]-'0';

	if (s1<s2)
		cout<<0;
	else if (s1==s2 && strcmp(num_1_str,num_2_str)<0)
		cout<<0;
	else
	{
		while (s1>s2 || ( num_1[s1-1]>=num_2[s1-1] && num_1[s1-1]!=0))
		{
			ans++;
			for (int i=0;i<=s1-1;i++)
			{
				num_1[i]-=num_2[i];
				if (num_1[i]<0)
				{
					num_1[i]+=10;
					num_1[i+1]-=1;
				}
			}
			while (num_1[s1-1]==0&&s1>1)
			{
				s1--;
			}
		}
		cout<<ans;
	}

	return 0;
}