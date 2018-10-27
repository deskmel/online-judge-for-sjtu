#include <iostream>
using namespace std;
int m;
int a[1000000];
int find_max_cross_array(int l,int r,int mid)
{
	int sum=0;
	int left_sum=a[mid];
	for (int i=mid;i>=l;i--)
	{
		sum=sum+a[i];
		if (sum>left_sum)
		{
			left_sum=sum;
		}
	}
	sum=0;
	int right_sum=a[mid+1];
	for (int i=mid+1;i<=r;i++)
	{
		sum=sum+a[i];
		if (sum>right_sum)
			right_sum=sum;
	}
	return right_sum+left_sum;
}
int find_max_sub_array_(int low,int high)
{
	int left_sum;
	int right_sum;
	int cross_sum;
	int mid;
	if (high == low +1)
		return a[high]+a[high-1];
	else 
	{
		mid = (low + high)/2;
		if (mid>low)
		{
			left_sum=find_max_sub_array_(low,mid);
		}
		else
		{
			left_sum=-1;
		}
		if (high>mid+1)
		{
			right_sum=find_max_sub_array_(mid+1,high);
		}
		else
		{
			right_sum=-1;
		}
		cross_sum=find_max_cross_array(low,high,mid);
		if (left_sum>=right_sum and left_sum>=cross_sum)
			return left_sum;
		else if (right_sum>=left_sum and right_sum>=cross_sum)
			return right_sum;
		else return cross_sum; 
	}
}
int main(int argc, char const *argv[])
{
	cin>>m;
	for (int i=0;i<m;i++)
		cin>>a[i];
	int max_1;
	max_1=find_max_sub_array_(0,m-1);
	if (max_1<=0)
		cout<<"Game Over";
	else
		cout<<max_1;
	return 0;
}