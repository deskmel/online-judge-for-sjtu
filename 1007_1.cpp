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
	char a[205];
	char b[205];
	cin.getline(a,205);
	cin.getline(b,205);
	char c[205];
	int pos_1,pos_2,len_1,len_2,len_3;
	len_3=0;
	for (int i=0;i<204;i++)
	{
		if (a[i]=='.')
			pos_1=i;
		if (a[i]=='\0')
			{
				len_1=i;
				break;
			}
	}
	
	for (int j=0;j<204;j++)
	{
		if (b[j]=='.')
			pos_2=j;
		if (b[j]=='\0')
			{
				len_2=j;
				break;
			}
	}
	pos_1=len_1-pos_1-1;
	pos_2=len_2-pos_2-1;
	reverse(b,len_2);
	reverse(a,len_1);
	for (int i=len_2;i<204;i++)
	{
		b[i]='0';
	}
	for (int i=len_1;i<204;i++)
		a[i]='0';
	int i=0;
	if (pos_1>pos_2)
	{
		int i=0;
		int j=0;
		int d;
		for (i=0;i<pos_1-pos_2;i++)
		{
			c[i]=a[i];
		}
		for (;i<pos_1;i++)
		{
			d=a[i]-'0'+b[i-pos_1+pos_2]-'0'+j;
			if (d>=10)
				j=1;
			else
				j=0;
			c[i]=(d)%10+'0';

		}
		c[i]='.';
		i+=1;
		for (;i<204;i++)
		{
			d=a[i]-'0'+b[i-pos_1+pos_2]-'0'+j;
			if (d>=10)
				j=1;
			else
				j=0;
			c[i]=(d)%10+'0';
		}
	}
	else
	{
		int i=0;
		int j=0;
		int d;
		for (i=0;i<pos_2-pos_1;i++)
		{
			c[i]=a[i];
		}
		for (;i<pos_1;i++)
		{
			d=a[i+pos_1-pos_2]-'0'+b[i]-'0'+j;
			if (d>=10)
				j=1;
			else
				j=0;
			c[i]=(d)%10+'0';

		}
		c[i]='.';
		i+=1;
		for (;i<204;i++)
		{
			d=a[i+pos_1-pos_2]-'0'+b[i]-'0'+j;
			if (d>=10)
				j=1;
			else
				j=0;
			c[i]=(d)%10+'0';
		}
	}
	for (int i=203;i>=0;i--)
	{
		if (c[i]!='0')
			{len_3=i+1;break;}

	}
	c[len_3]='\0';
	reverse(c,len_3);
	cout<<c;
	return 0;
}