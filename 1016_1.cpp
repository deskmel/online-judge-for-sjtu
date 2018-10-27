#include <iostream>
#include <string.h>
using namespace std;
char num_1_s[1000],num_2_s[1000];
int num_1[1000],num_2[1000];
char ans_t[1000];
int main(int argc, char const *argv[])
{
	cin>>num_1_s>>num_2_s;
	int s1=strlen(num_1_s),s2=strlen(num_2_s);
	for (int i=0;i<s1;i++){
		num_1[i]=num_1_s[s1-i-1]-'0';
	}
	for (int i=0;i<s2;i++)
	{
		num_2[i]=num_2_s[s2-i-1]-'0';
	}

	if (s1<s2)
		cout<<0;
	else if (s1==s2 && strcmp(num_1_s,num_2_s)<0)
		cout<<0;
	else
	{	
		int index=s1-s2,high=s1-s2;
		while (index>=0)
		{
			int ans=0;
			while (s1-index>s2 || ( num_1[s1-1]>num_2[s2-1] && s1-index==s2)  )
			{
				for (int i=0;i<s2;i++)
				{

					num_1[index+i]-=num_2[i];
					if (num_1[index+i]<0)
					{
						num_1[index+i]+=10;
						num_1[index+i+1]-=1;
					}
				}
				ans+=1;
				while (num_1[s1-1]==0&&s1>0 )
				{
					s1-=1;
				}

			}
			bool flag=true;
			if (num_1[s1-1]==num_2[s2-1] && s1-index==s2)
			{
				for (int i=0;i<s2;i++)
				{
					if (num_1[s1-i]<num_2[s2-i])
						{
							flag=false;
							break;
						}
					else if (num_1[s1-i]>num_2[s2-i])
					{
						break;
					}
				}
				if (flag)
				{
					for (int i=0;i<s2;i++)
					{
						num_1[index+i]-=num_2[i];
						if (num_1[index+i]<0)
						{
							num_1[index+i]+=10;
							num_1[index+i+1]-=1;
						}
					}
					ans+=1;
					while (num_1[s1-1]==0&&s1>0 )
					{
					s1-=1;
					}
				}
			}
			ans_t[index]=ans+'0';
			index-=1;
		}
		int i=high;
		for (;i>=0;i--)
			if (ans_t[i]!='0')
				break;
		high=i;
		char c;
		for (;i>=0;i--)
		{
			cout<<ans_t[i];
		}
		
	}
	
	return 0;
}