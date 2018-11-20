#include <iostream>
#include <math.h>
using namespace std;
int n,in,out;
int p[10000000];
int r[10000000];
bool line[10000][10000];
int find_set(int x)
{
	int start=x,ret,tmp;
	while (!p[x]==0) x=p[x];
	while (start!=x)
	{
		tmp=p[start];
		p[start]=x;
		start=tmp;
	}
	return x;
}
void link(int x,int y)
{
	if (r[x]>r[y])
		p[y]=x;
	else
	{
		p[x]=y;
		if (r[x]==r[y])
			r[y]+=1;
	}
}
void UNION(int x,int y)
{
	return link(find_set(x),find_set(y));
}


void createPuzzle(int n,int start,int end)
{
	while (find_set(start)!=find_set(end))
	{

		int pos,op,col,row;
		cin>>pos>>op;
		row=ceil(sqrt(double(pos*2+0.25))-0.5);
		col=pos-(row-1)*row/2;
		switch (op)
		{
			case 0: if (row==1 || col==1) break;
					else 
					{
						int pos_=(row-1)*(row-2)/2+col-1;
						if (pos_<=0) break;
						if (find_set(pos)!=find_set(pos_))
						{
							UNION(pos,pos_);
							line[pos][pos_]=true;
							line[pos_][pos]=true;
						}
					}
					break;
			case 1: if (row==1 || col==row) break;
					else
					{
						int pos_=(row-1)*(row-2)/2+col;
						if (pos_<=0) break;
						if (find_set(pos)!=find_set(pos_))
						{
							UNION(pos,pos_);
							line[pos][pos_]=true;
							line[pos_][pos]=true;
						}
					}
					break;
			case 2:if (row==n) break;
					else
					{
						int pos_=(row)*(row+1)/2+col;
						if (pos_<=0) break;
						if (find_set(pos)!=find_set(pos_))
						{
							UNION(pos,pos_);
							line[pos][pos_]=true;
							line[pos_][pos]=true;
						}
					}
					break;
			case 3:if (row==n) break;
					else
					{
						int pos_=(row)*(row+1)/2+col+1;
						if (pos_<=0) break;
						if (find_set(pos)!=find_set(pos_))
						{
							UNION(pos,pos_);
							line[pos][pos_]=true;
							line[pos_][pos]=true;
						}
					}
					break;
		}		
	}
}
int ans[10000000];
bool get[10000000];
bool flag=true;
int queue[1000000][2];
void dfs(int row,int col)
{
	int pos=row*(row-1)/2+col;
	int pos_0=(row-1)*(row-2)/2+col-1;
	int pos_1=(row-1)*(row-2)/2+col;
	int pos_2=(row+1)*row/2+col;
	int pos_3=(row+1)*row/2+col+1;
	if (flag && pos_0>0 &&row-1>0 && col-1>0 &&!get[pos_0] &&  line[pos][pos_0])
	{

		ans[pos]=pos_0;
		if (pos_0==out)
			flag=false;
		get[pos]=true;
		dfs(row-1,col-1);
		get[pos]=false;
	}
	if (flag && pos_1>0 &&row-1>0 &&!get[pos_1] && line[pos][pos_1])
	{
		ans[pos]=pos_1;
		if (pos_1==out)
			flag=false;
		get[pos]=true;
		dfs(row-1,col);
		get[pos]=false;
	}
	if (flag && pos_2>0 &&!get[pos_2] && line[pos][pos_2])
	{
		ans[pos]=pos_2;
		if (pos_2==out)
			flag=false;
		get[pos]=true;
		dfs(row+1,col);
		get[pos]=false;
	}
	if (flag && pos_3>0 &&!get[pos_3] && line[pos][pos_3])
	{

		ans[pos]=pos_3;
		if (pos_3==out)
			flag=false;
		get[pos]=true;
		dfs(row+1,col+1);
		get[pos]=false;
	}
	return ;
}
int main(int argc, char const *argv[])
{
	cin>>n>>in>>out;
	createPuzzle(n,in,out);
	int startrow=ceil(sqrt(double(in*2+0.25))-0.5);
	int startcol=in-(startrow-1)*startrow/2;
	dfs(startrow,startcol);
	int x=in;
	while (x!=out)
	{
		cout<<x<<' ';
		x=ans[x];
	}
	cout<<out;
	return 0;
} 