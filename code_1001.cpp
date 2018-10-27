#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int h,d,n;
	cin>>h>>d>>n;
	int total=0;
	int high=h+d;
	int high_apple;
	for (int i=0;i<n;i++)
	{
		cin>>high_apple;
		if (high_apple<=high)
			total+=1;

	}
	cout<<total;
	return 0;
}