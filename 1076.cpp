#include <iostream>
using namespace std;
int sum,m,n;
int edge[103][103];
bool visited[103];
int len=0;
int leaves_heap[103][3];
int leaves[103];
void insert(int k,int node1,int node2)
{
	leaves_heap[++len][0]=k;
	leaves_heap[len][1]=node1;
	leaves_heap[len][2]=node2;
	int j=len;
	while (j/2>0)
	{
		if (leaves_heap[j/2][0]>k)
		{
			int tmp;
			tmp=leaves_heap[j][0];leaves_heap[j][0]=leaves_heap[j/2][0];leaves_heap[j/2][0]=tmp;
			tmp=leaves_heap[j][1];leaves_heap[j][1]=leaves_heap[j/2][1];leaves_heap[j/2][1]=tmp;
			tmp=leaves_heap[j][2];leaves_heap[j][2]=leaves_heap[j/2][2];leaves_heap[j/2][2]=tmp;
			j/=2;
		}
		else break;
	}
}
void push_up(int i)
{
	int k=i;
	if (i*2<=len&&leaves_heap[i*2][0]<leaves_heap[i][0] )
		k=i*2;
	if (i*2+1<=len&&leaves_heap[i*2+1][0]<leaves_heap[k][0])
		k=i*2+1;
	if (k!=i)
	{
		int tmp;
		tmp=leaves_heap[k][0];leaves_heap[k][0]=leaves_heap[i][0];leaves_heap[i][0]=tmp;
		tmp=leaves_heap[k][1];leaves_heap[k][1]=leaves_heap[i][1];leaves_heap[i][1]=tmp;
		tmp=leaves_heap[k][2];leaves_heap[k][2]=leaves_heap[i][2];leaves_heap[i][2]=tmp;
		push_up(k);
	}
}
void show()
{
	for (int i=1;i<=len;i++)
		cout<<leaves_heap[i][0]<<' '<<leaves_heap[i][1]<<' '<<leaves_heap[i][2]<<endl;
}
int pop_and_add()
{
	int node1=leaves_heap[1][1];
	int node2=leaves_heap[1][2];
	edge[node1][node2]=edge[node2][node1]=0;
	sum-=leaves_heap[1][0];
	leaves_heap[1][0]=leaves_heap[len][0];
	leaves_heap[1][1]=leaves_heap[len][1];
	leaves_heap[1][2]=leaves_heap[len][2];
	len--;
	push_up(1);
	if ((--leaves[node1])==0)
	{
		for (int i=0;i<=n;i++)
			if (edge[node1][i])
			{
				insert(edge[node1][i],i,leaves_heap[1][1]);
			}
	}
	show();
}
void bfs()
{
	int queue[102],head=0,tail=0;
	queue[tail++]=1;
	while (head!=tail)
	{
		int node=queue[head++];
		for (int i=0;i<=n;i++)
		{
			if (edge[node][i]!=0 && !visited[i])
			{
				queue[tail++]=i;
				leaves[node]++;
			}
		}
		visited[node]=true;
	}
}

int main(int argc, char const *argv[])
{
	
	cin>>n>>m;
	for (int i=1;i<n;i++)
	{
		int node1,node2;
		cin>>node1>>node2;
		cin>>edge[node1][node2];
		edge[node2][node1]=edge[node1][node2];
		sum+=edge[node1][node2];
	}
	bfs();
	for (int i=1;i<=n;i++)
		{
			if (!leaves[i])
			{
				for (int j=1;j<=n;j++)
					if (edge[i][j])
					{
						insert(edge[i][j],j,i);
					}
			}
		}
	for (int i=0;i<m;i++)
		pop_and_add();
	cout<<sum;

	return 0;
}