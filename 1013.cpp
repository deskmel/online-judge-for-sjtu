#include <iostream>
using namespace std;
int V,N;
int thing[1000][2];
int value[10002];
int main(int argc, char const *argv[])
{
	cin>>V>>N;
	for (int i=0;i<N;i++)
	{
		cin>>thing[i][0];
		cin>>thing[i][1];
	}
	int max_value=0;
	for (int i=1;i<=V;i++ )
	{
		max_value=value[i-1];
		for (int j=0;j<N;j++)
		{
			if (i-thing[j][0]>=0)
			{
				max_value=max(max_value,value[i-thing[j][0]]+thing[j][1]);
			}
		}
		value[i]=max_value;
	}

	cout<<value[V];
	return 0;
}