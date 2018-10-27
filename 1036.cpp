#include <iostream>
using namespace std;
int n,time_for_work[100000];
long long time_for_work_1[100000];
int time_for_work_2[100000];
void time_Queue_1()
{
	long long sum=0;
	for (int i=3;i<n;i++)
	{
		time_for_work_1[i]=time_for_work_1[i]+time_for_work_1[i-3];
		sum+=time_for_work_1[i]-time_for_work[i];
	}
	long long time_max=0;
	for (int i=n-3;i<n;i++)
		time_max=max(time_for_work_1[i],time_max);
	cout<<sum<<' '<<time_max<<endl;
	return ;
}
int getminIndex(long long *a)
{
	if (a[0]<=a[1] && a[0]<=a[2]) return 0;
	else if (a[1]<=a[0]  &&a[1]<=a[2]) return 1;
	else return 2;
}
int time_Queue_2()
{
	long long sum=0,max_time=0;
	long long Queue_sum[3],Queue[3];
	for (int i=0;i<3;i++)
		Queue_sum[i]=Queue[i]=0;
	for (int i=0;i<n;i++)
	{
		int k=getminIndex(Queue);
		Queue_sum[k]+=Queue[k];
		Queue[k]+=time_for_work[i];
	}
	sum=Queue_sum[0]+Queue_sum[1]+Queue_sum[2];
	max_time=max(max(Queue[0],Queue[1]),Queue[2]);
	cout<<sum<<' '<<max_time;

}
int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>time_for_work[i];
		time_for_work_1[i]=time_for_work[i];
	}
	time_Queue_1();
	time_Queue_2();

	return 0;
}