#include <iostream>
using namespace std;
int N,nums[1000000],res[1000000],t[1000000];

int main(int argc, char const *argv[])
{
	cin>>N;
	for (int i=0;i<N;i++)
		cin>>nums[i];
	for (int i=N-1;i>=0;i++)
	{
		int left=0,right=N-i-1;
		while (left<right)
		{
			int mid=left+(right-left)/2;
			if (t[mid]>=nums[i]) right=mid;
			else left=mid+1;
		}
		res[i]=right;
		for (int i=;)
	}
	return 0;
}