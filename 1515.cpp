#include <iostream>
#include <stdio.h>
using namespace std;
int m,n;
int pos1_x,pos1_y,pos2_x,pos2_y;
int M[1005][1005];
bool M1[1005][1005];
bool M2[1005][1005];
int M11[1005][1005];
int M22[1005][1005];
int queue[1000005][2];
int queue1[1000005][2];
int head1,tail1;
int head,tail;
void enqueue(int px,int py,int sum)
{
	queue[tail][0]=px;
	queue[tail][1]=py;
	tail+=1;
	M1[px][py]=true;
	M11[px][py]=sum;
}
void enqueue1(int px1,int py1,int sum)
{
	queue1[tail1][0]=px1;
	queue1[tail1][1]=py1;
	tail1+=1;
	M2[px1][py1]=true;
	M22[px1][py1]=sum;
}
int bfs(int px,int py,int px1,int py1)
{
	int sum=0;
	head=tail=0;
	head1=tail1=0;
	enqueue(px,py,0);
	enqueue1(px1,py1,0);
	int min_t1=0,min_t2=0,min_t=0;
	bool firstflag1=true,firstflag2=true,flag=true;
	int step1=0,step2=0;
	while (head!=tail || head1!=tail1)
	{

		if (head!=tail)
		{
		int qx=queue[head][0];
		int qy=queue[head][1];
		step1=M11[qx][qy];
		if (qx>0 && M[qx-1][qy]!=1 && !M1[qx-1][qy])
			enqueue(qx-1,qy,M11[qx][qy]+1);
		if (qx<n-1 && M[qx+1][qy]!=1  && !M1[qx+1][qy])
			enqueue(qx+1,qy,M11[qx][qy]+1);
		if (qy>0 && M[qx][qy-1]!=1  && !M1[qx][qy-1])
			enqueue(qx,qy-1,M11[qx][qy]+1);
		if (qy<m-1 && M[qx][qy+1]!=1  && !M1[qx][qy+1])
			enqueue(qx,qy+1,M11[qx][qy]+1);
		if (M[qx][qy]==4)
		{

			if (firstflag1)
			{
				min_t1=sum;
				firstflag1=false;
			}
			if (M2[qx][qy])
			{
				
				if (flag)
					min_t=M11[qx][qy]+M22[qx][qy],flag=false;
				else
					min_t=min(min_t,M11[qx][qy]+M22[qx][qy]);
			}
		}
		head+=1;
		}
		if (head1!=tail1)
		{
		int qx1=queue1[head1][0];
		int qy1=queue1[head1][1];
		step2=M22[qx1][qy1];
		if (qx1>0 && M[qx1-1][qy1]!=1 && !M2[qx1-1][qy1])
			enqueue1(qx1-1,qy1,M22[qx1][qy1]+1);
		if (qx1<n-1 && M[qx1+1][qy1]!=1  && !M2[qx1+1][qy1])
			enqueue1(qx1+1,qy1,M22[qx1][qy1]+1);
		if (qy1>0 && M[qx1][qy1-1]!=1  && !M2[qx1][qy1-1])
			enqueue1(qx1,qy1-1,M22[qx1][qy1]+1);
		if (qy1<m-1 && M[qx1][qy1+1]!=1  && !M2[qx1][qy1+1])
			enqueue1(qx1,qy1+1,M22[qx1][qy1]+1);
		if (M[qx1][qy1]==4)
		{
			if (firstflag2)
			{
				min_t2=sum;
				firstflag2=false;
			}
			if (M1[qx1][qy1])
			{
				
				if (flag)
					min_t=M11[qx1][qy1]+M22[qx1][qy1],flag=false;
				else
					min_t=min(min_t,M11[qx1][qy1]+M22[qx1][qy1]);
			}

		}
		head1+=1;
		}
		if ((min(step1,step2)+min(min_t1,min_t2))>min_t && min_t!=0)
			{break;}

	}		

	return min_t;
}
int main(int argc, char const *argv[])
{
	cin>>m>>n;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			cin>>M[i][j];
			if (M[i][j]==2)
			{
				pos1_x=i;pos1_y=j;
			}
			else if (M[i][j]==3)
			{
				pos2_x=i;pos2_y=j;
			}
			else continue;
		}
	cout<<bfs(pos1_x,pos1_y,pos2_x,pos2_y)<<endl;
	return 0;
}