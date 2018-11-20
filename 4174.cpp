#include <iostream>
using namespace std;
int locate[100000];
int high[100000];
int time[100000][2];
int divide(int (*a)[2],int l,int r)
{
	int tmp;
	int q=l-1;
	int m=a[r][1];
	for (int i=l;i<r;i++)
	{
		if (a[i][1]<m)
		{
			q++;
			tmp=a[i][1];
			a[i][1]=a[q][1];
			a[q][1]=tmp;
			tmp=a[i][0];
			a[i][0]=a[q][0];
			a[q][0]=tmp;
		}
	}
	q++;
	tmp=a[r][0];
	a[r][0]=a[q][0];
	a[q][0]=tmp;
	tmp=a[r][1];
	a[r][1]=a[q][1];
	a[q][1]=tmp;
	return q;


}
void quicksort(int (*a)[2],int l,int r)
{
	if (r>l)
	{
		int mid=divide(a,l,r);
		quicksort(a,l,mid-1);
		quicksort(a,mid+1,r);
	}
}

int m;
int main(int argc, char const *argv[])
{
	cin>>m;
	for (int i=0;i<m;i++)
		cin>>locate[i];
	for (int i=0;i<m;i++)
		cin>>high[i];
	for (int i=0;i<m;i++)
	{
		time[i*2][0]=locate[i]-high[i];
		time[i*2][1]=locate[i];
		time[i*2+1][0]=locate[i];
		time[i*2+1][1]=locate[i]+high[i];
	}
	quicksort(time,0,m*2-1);
	for (int i=0;i<2*m;i++)
		cout<<time[i][1]<<' ';
	return 0;
}  