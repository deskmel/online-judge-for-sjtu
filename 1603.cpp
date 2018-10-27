#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n;

	vector<int> nums,t,res(n);
	for (int i=0;i<n;i++)
	{
		cin>>m;
		nums.push_back(m);
	}

	for (int i=n-1;i>=0;i--)
	{
		int left=0,right=t.size();
		while (left<right)
		{
			int mid=left+(right-left)/2;
			if (t[mid]>=nums[i]) right =mid;
			else left=mid+1;
		}
		res[i]=right;
		t.insert(t.begin()+right,nums[i]);
	}
	for (int i=0;i<n;i++)
		cout<<t[i]<<' ';

	for (int i=0;i<n;i++)
		cout<<res[i]<<' ';

	return 0;
}