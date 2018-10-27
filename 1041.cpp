#include <iostream>
#include <string>
using namespace std;
int a[100010][2];
void MIN_HEAPITY_DOWN(int a[][2],int i,int n)
{
	int cmp;
	int l=i*2;
	int r=i*2+1;
	int m;
	if ( l<=n and (a[i][1]>a[l][1] or (a[i][1]==a[l][1] and a[i][0]>a[l][0])))
		m=l;
	else 
		m=i;
	if (r <=n and (a[m][1]>a[r][1] or (a[m][1]==a[r][1]and a[m][0]>a[r][0])))
		m=r;
	if (m!=i)
	{
		cmp=a[i][0];
		a[i][0]=a[m][0];
		a[m][0]=cmp;

		cmp=a[i][1];
		a[i][1]=a[m][1];
		a[m][1]=cmp;
		MIN_HEAPITY_DOWN(a,m,n);
	}

}
void MIN_HEAPITY(int a[][2],int i,int n)
{
	int cmp;
	while (i/2>0)
	{
		if (a[i/2][1]>a[i][1] or (a[i/2][1]==a[i][1] and a[i/2][0]>a[i][0]))
			{
				cmp=a[i][0];
				a[i][0]=a[i/2][0];
				a[i/2][0]=cmp;

				cmp=a[i][1];
				a[i][1]=a[i/2][1];
				a[i/2][1]=cmp;

				i/=2;
			}
		else break;
	}
}
void BUILD_MIN_HEAP(int a[][2],int n)
{
	for (int i=n/2;i>=1;i--)
	{
		MIN_HEAPITY_DOWN(a,i,n);
	}
}
int find_min(int a[][2],int n,int m)
{
	if (a[1][1]>m)
		return a[1][0];
	for (int i=2;i<=n;i++)
	{
		BUILD_MIN_HEAP(a+i-1,n-i+1);
		if (a[i][1]>m)
			{
				int w=a[i][0];
				BUILD_MIN_HEAP(a,n);
				return w;
			} 
	}
}
int main()
{
	int n;
	cin>>n;
	int m;
	for (int i=1;i<=n;i++)
	{
		cin>>m;
		a[i][0]=i;
		a[i][1]=m;
	}
	BUILD_MIN_HEAP(a,n);
	string s;
	int l;
	while (cin>>s)
	{
		if (s=="findmin")
		{
			cin>>m;
			cout<<(find_min(a,n,m))<<endl;
		}
		else if (s=="decrease")
		{
			cin>>m>>l;
			int i;
			for (i=0;i<=n;i++)
			{
				if (a[i][0]==m)
					break;
			}
			a[i][1]-=l;
			MIN_HEAPITY(a,i,n);
		}
		else if (s=="p")
		{
			for (int i=1;i<=n;i++)
				cout<<a[i][0]<<' '<<a[i][1]<<endl;
		}
	}

}