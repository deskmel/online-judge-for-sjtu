#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int m;
	cin>>m;
	int a[105][105];
	for (int i=0;i<m;i++)
		for (int j=0;j<m;j++)
			{
			cin>>a[i][j];
			if (a[i][j]==2)
				a[i][j]=-1;
			}
	//无脑方法
	int times;
	bool full=true;
	for (int i=0;i<200;i++)
	{
		full=true;
		for (int i1=0;i1<m;i1++)
			for (int i2=0;i2<m;i2++)
			{
				if (a[i1][i2]==0)
				{
					full=false;
					if (i1==0 and i2==0)
					{
						if (a[i1+1][i2]==i+1 or a[i1][i2+1]==i+1)
							a[i1][i2]=i+2;
					}
					else if (i1==0 and i2==m-1)
					{
						if (a[i1+1][i2]==i+1 or a[i1][i2-1]==i+1)
							a[i1][i2]=i+2;
					}
					else if (i1==m-1 and i2 == 0)
					{
						if (a[i1-1][i2]==i+1 or a[i1][i2+1]==i+1)
							a[i1][i2]=i+2;
					}
					else if (i1==m-1 and i2==m-1)
					{
						if (a[i1-1][i2]==i+1 or a[i1][i2-1]==i+1)
							a[i1][i2]=i+2;
					}
					else if (i1==0)
					{
						if ( a[i1][i2-1]==i+1 or a[i1+1][i2]==i+1 or a[i1][i2+1]==i+1)
							a[i1][i2]=i+2;
					}
					else if (i1==m-1)
					{
						if (a[i1-1][i2]==i+1 or a[i1][i2-1]==i+1 or  a[i1][i2+1]==i+1)
							a[i1][i2]=i+2;
					}
					else if(i2==0)
					{
						if (a[i1-1][i2]==i+1 or a[i1+1][i2]==i+1 or a[i1][i2+1]==i+1)
							a[i1][i2]=i+2;
					}
					else if (i2==m-1)
					{
						if (a[i1-1][i2]==i+1 or a[i1][i2-1]==i+1 or a[i1+1][i2]==i+1)
							a[i1][i2]=i+2;
					}
					else
					{
						if (a[i1-1][i2]==i+1 or a[i1][i2-1]==i+1 or a[i1+1][i2]==i+1 or a[i1][i2+1]==i+1)
							a[i1][i2]=i+2;
					}		
				}

			}


		if (full==true)
		{
			times=i;
			break;
		}
	}
	cout<<times;
	return 0;
}