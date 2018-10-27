#include <iostream>
using namespace std;
void reverse(char *a,int len_1)
{
	char cmp;
	for (int i=0;i<len_1/2;i++)
	{
		cmp=a[i];
		a[i]=a[len_1-i-1];
		a[len_1-i-1]=cmp;
	}
}
int main(int argc, char const *argv[])
{
	char a[100001];
	char b[100001];
	char c[100001];
	int len_a,len_b,len_c;
	cin.getline(a,100001);
	cin.getline(b,100001);
	for (int i=0;i<100001;i++)
	{
		if (a[i]=='\0')
			{
				len_a=i;
				break;
			}
	}
	for (int j=0;j<100001;j++)
	{
		if (b[j]=='\0')
		{
			len_b=j;
			break;
		}
	}
	reverse(a,len_a);
	reverse(b,len_b);
	len_c=max(len_a,len_b)+5;
	for (int i=len_a;i<len_c;i++)
	{
		a[i]='0';
	}
	for (int j=len_b;j<len_c;j++)
	{
		b[j]='0';
	}
	int j=0;
	int d;
	for (int i=0;i<len_c;i++)
	{
		d=(a[i]-'0'+b[i]-'0'+j)%10;
		j=a[i]-'0'+b[i]-'0'+j;
		c[i]=d+'0';
		if (j>=10)
			j=1;
		else j=0;
	}
	int len_d;
	for (int i=len_c-1;i>=0;i--)
		{if (c[i]!='0')
					{
						len_d=i;
						break;
					}}
	c[len_d+1]='\0';
	reverse(c,len_d+1);
	cout<<c<<endl;
	return 0;
}