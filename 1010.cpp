#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int money=0,save_money=0;
	int a[12];
	for (int i=0;i<12;i++)
	{
		cin>>a[i];
	}
	for (int i=0;i<12;i++)
	{
		money+=(300-a[i]);
		if (money<0)
		{
			cout<<(i+1)*-1;
			return 0;
		}
		if (money>=100)
		{
			save_money+=(money/100)*100;
			money=money%100;
		}
	}
	cout<<money+save_money*1.2;
	return 0;
}