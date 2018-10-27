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
int main()
{
	char a[201];
	char b[201];
	cin.getline(a,201);
	cin.getline(b,201);
	char c[201];
	//高精度小数加法
	int pos_1,pos_2;
	int len_1,len_2;
	int len_3;
	for (int i=0;i<201;i++)
	{
		if (a[i]=='.')
			pos_1=i;
		if (a[i]=='\0')
			{
				len_1=i;
				break;
			}
	}
	reverse(a,len_1);
	for (int j=0;j<201;j++)
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
	if (pos_1>pos_2)
	{
		int j=0;
		char d;
		int i;
		for (i=0;i<pos_1-pos_2;i++)
		{
			c[i]=a[i];
		}
		for (i=pos_1-pos_2;i<pos_1;i++)
		{

			d=(a[i]-'0'+b[i-pos_1+pos_2]-'0'+j)%10; 
			j=(a[i]-'0'+b[i-pos_1+pos_2]-'0'+j);
			if (j>=10)
			{
				j=1;
			}
			else
			{
				j=0;
			}
			c[i]=d+'0';
		}
		c[i]='.';
		for (i=0;i<min(len_1-pos_1-1,len_2-pos_2-1);i++)
		{
			d=(a[pos_1+1+i]-'0'+b[pos_2+1+i]-'0'+j)%10;
			j=(a[pos_1+1+i]-'0'+b[pos_2+1+i]-'0'+j);
			if (j>=10)
			{
				j=1;
			}
			else
			{
				j=0;
			}
			c[pos_1+1+i]=d+'0';
		}
		for (;i<max(len_1-pos_1-1,len_2-pos_2-1);i++)
		{
			if (a[pos_1+1+i]=='\0')
			{
				c[pos_2+1+i]=(b[pos_2+1+i]+j)%10;
				j=b[pos_2+1+i]+j;
				if (j>=10)
				{
					j=1;
				}
				else
				{
					j=0;
				}
			}
			else
			{
				c[pos_2+1+i]=(a[pos_1+1+i]+j)%10;
				j=a[pos_1+1+i]+j;
				if (j>=10)
					j=1;
				else
					j=0;
			}
		}
		if (j!=0)
		{
			c[pos_1+1+i]=j+'0';
			c[pos_1+2+i]='\0';
			len_3=pos_1+2+i;
		}
		else 
		{
			c[pos_1+1+i]='\0';
			len_3=pos_1+1+i;	
		}


	} 
	else
	{
		int j=0;
		char d;
		int i;
		for (i=0;i<pos_2-pos_1;i++)
		{
			c[i]=b[i];
		}
		for (i=pos_2-pos_1;i<pos_2;i++)
		{ 

			d=(b[i]-'0'+a[i-pos_2+pos_1]-'0'+j)%10; 
			j=(b[i]-'0'+a[i-pos_2+pos_1]-'0'+j);
			if (j>=10)
			{
				j=1;
			}
			else
			{
				j=0;
			}
			c[i]=d+'0';
		}
		c[i]='.';
		for (i=0;i<min(len_1-pos_1-1,len_2-pos_2-1);i++)
		{
			d=(a[pos_1+1+i]-'0'+b[pos_2+1+i]-'0'+j)%10;
			j=(a[pos_1+1+i]-'0'+b[pos_2+1+i]-'0'+j);
			if (j>=10)
			{
				j=1;
			}
			else
			{
				j=0;
			}
			c[pos_2+1+i]=d+'0';
		}
		if (a[pos_1+1+i]=='\0')
		{
		

				c[pos_2+1+i]=(b[pos_2+1+i]+j)%10;
				j=b[pos_2+1+i]+j;
				if (j>=10)
				{
					j=1;
				}
				else
				{
					j=0;

				}
		}
		else
		{
			for (;i<max(len_1-pos_1-1,len_2-pos_2-1);i++)
			{
				c[pos_2+1+i]=(a[pos_1+1+i]+j)%10;
				j=a[pos_1+1+i]+j;
				if (j>=10)
					j=1;
				else
					j=0;
			}
		}
		if (j!=0)
		{
			c[pos_2+1+i]=j+'0';
			c[pos_2+2+i]='\0';
			len_3=pos_2+2+i;
		}
		else 
			{
				c[pos_2+1+i]='\0';
				len_3=pos_2+1+i;
			}
	}
	reverse(c,len_3);
	cout<<c<<endl;




}
