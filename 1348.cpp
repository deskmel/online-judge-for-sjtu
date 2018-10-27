#include <iostream>
#include <iomanip>
using namespace std;

int N,M;
long long song_li[100000];
long long  queue_male[1000000],head1,tail1;
long long  queue_female[1000000],head2,tail2;
long double wait_male,wait_female;
int divide(long long *a,int l,int r)
{
	int d=a[r];
	int q=l-1;
	int cmp;
	for (int i=l;i<r;i++)
	{
		if (a[i]<=d)
		{
			q++;
			cmp=a[i];
			a[i]=a[q];
			a[q]=cmp;
		}
	}
	q++;
	a[r]=a[q];
	a[q]=d;
	return q;
}
void quick_sort(long long *a,int l,int r)
{
	int mid=divide(a,l,r);
	if (mid-l>1)
		quick_sort(a,l,mid-1);
	if (r-mid>1)
		quick_sort(a,mid+1,r);
}
long long time_1;
int main(int argc, char const *argv[])
{
	cin>>N;
	for (int i=0;i<N;i++)
		cin>>song_li[i];
	int tmp;
	cin>>M;
	for (int i=0;i<M;i++)
	{
		cin>>tmp;
		if (tmp==1)
			cin>>queue_male[tail1++];
		else cin>>queue_female[tail2++];
	}
	quick_sort(queue_male,0,tail1-1);
	quick_sort(queue_female,0,tail2-1);
	for (int i=0;i<N-1;i++)
	{
		while (head1!=tail1 && head2!=tail2 && queue_male[head1]<=time_1 && queue_female[head2]<=time_1)
		{
			wait_male+=time_1-queue_male[head1++];
			wait_female+=time_1-queue_female[head2++];
		}
		time_1+=song_li[i];
	}
	while (head1!=tail1)
	{
		wait_male+=time_1-queue_male[head1++];
	}
	while (head2!=tail2)
	{
		wait_female+=time_1-queue_female[head2++];
	}
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<wait_male/tail1<<' '<<wait_female/tail2<<endl;
	return 0;
}