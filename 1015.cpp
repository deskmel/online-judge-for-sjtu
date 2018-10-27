#include <iostream>
#include <cstring>
#include <string>
using namespace std;
char a1[1000];
char b1[1000];
int main(int argc, char const *argv[])
{
	int a[1000],b[1000],c[1000],lena,lenb,lenc,i,j,x;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	cin>>a1;cin>>b1;
	lena=strlen(a1);lenb=strlen(b1);
	for (int i=0;i<lena;i++)
		a[lena-i]=a1[i]-48;
	for (int i=0;i<lenb;i++)
		b[lenb-i]=b1[i]-48;
	for (i=1;i<=lena;i++)
	{
		x=0;
		for (j=1;j<=lenb;j++)
		{
			c[i+j-1]=a[i]*b[j]+x+c[i+j-1];
			x=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
		c[i+j-1]=x;

	}
	lenc=lena+lenb;
	while (c[lenc]==0 and lenc>1)
		lenc--;
	for (i=lenc;i>=1;i--)
		cout<<c[i];
	cout<<endl;
	return 0;
}