#include <iostream>
using namespace std;
int m,n;
char M[1001][1001];

class node
{
public:
	int x,y;
	int num;
	node *next[4];

	node(int i,int j,int n):x(i),y(j),num(n){}
	~node();
};
node *nptr=new node(-1,-1,-1);
int nextnode(node *beg)
{
		beg->next[0]=(beg->x>0 and M[beg->x-1][beg->y]!='#')?new node(beg->x-1,beg->y,beg->num+1):nptr;
		beg->next[1]=(beg->y>0 and M[beg->x][beg->y-1]!='#')?new node(beg->x,beg->y-1,beg->num+1):nptr;
		beg->next[2]=(beg->x<n-1 and M[beg->x+1][beg->y]!='#')?new node(beg->x+1,beg->y,beg->num+1):nptr;
		beg->next[3]=(beg->y<n-1 and M[beg->x][beg->y]!='#')?new node(beg->x,beg->y+1,beg->num+1):nptr;
		M[beg->x][beg->y]='#';
		int k;
		int s;
		bool flag=true;
		for (int i=0;i<4;i++)
		{
			if (M[beg->next[i]->x][beg->next[i]->y]=='$')
			{
				return beg->next[i]->num;
			}
			else if (beg->next[i]!=nptr)
			{
				if (flag)
				{
					k=nextnode(beg->next[i]);
					flag=false;
				}
				else
				{
					s=nextnode(beg->next[i]);
					if (s!=-1)
					{
						if (k=-1)
							k=s;
						else
							k=min(k,s);
					}
				}
			}
		}
		return -1;
}
int main(int argc, char const *argv[])
{

	cin>>n>>m;
	int beg_x,beg_y;
	int des_x,des_y;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			cin>>M[i][j];
			if (M[i][j]=='@')
			{
				beg_x=i;
				beg_y=j;
			}
			else if (M[i][j]=='$')
			{
				des_x=i;
				des_y=j;
			}
		}
	node *beg=new node(beg_x,beg_y,0);
	int result=nextnode(beg);
	cout<<result;


	return 0;
}