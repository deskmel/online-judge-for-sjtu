#include <iostream>
using namespace std;

int a,b,c,y1,y2;
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
bool islunerYEAR(int k)
{
	return (k%400==0)||(k%400!=0 && k%4==0 &&k%100!=0);
}
int main(int argc, char const *argv[])
{
	cin>>a>>b>>c>>y1>>y2;
	int day=0,xinqi;
	for (int i=1850;i<y1;i++)
	{
		day+=islunerYEAR(i)?366:365;
	}
	for (int y=y1;y<=y2;y++)
	{
		for (int i=0;i<a-1;i++)
		{
			if (i==1 && islunerYEAR(y))
				day+=29;
			else
				day+=month[i];
		}
		int delte;

		xinqi=(day%7+2)%7;
		if (xinqi==0)
			xinqi=7;
		if (c<xinqi)
			delte=7*(b)+c-xinqi;
		else delte=7*(b-1)+c-xinqi;
		if (delte+1>((islunerYEAR(y)&&a==2)?month[a-1]+1:month[a-1]))
			cout<<"none"<<endl;
		else
		{
		cout<<y<<'/';
		if (a<10)
			cout<<"0"<<a;
		else cout<<a;
		cout<<'/';
		if (delte+1<10)
			cout<<0<<delte+1;
		else cout<<delte+1;
		cout<<endl;
		}
		for (int i=a-1;i<12;i++)
		{
			if (i==1 && islunerYEAR(y))
				day+=29;
			else
				day+=month[i];
		}

	}


	return 0;
}