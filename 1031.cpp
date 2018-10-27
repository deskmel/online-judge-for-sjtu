#include <iostream>
using namespace std;
int H[105][105][3];
int n;
int queue[10005][2];
int head,tail;
void enqueue(int x,int y)
{
	queue[tail][0]=x;
	queue[tail][1]=y;
	tail+=1;
}

void bfs()
{
	enqueue(0,0);
	while (head != tail)
	{
		int posx=queue[head][0];
		int posy=queue[head][1];
		
	}
}

int main(int argc, char const *argv[])
{
	 cin>>n;
	 for (int i=0;i++;i<n)
	 {
	 	for (int j=0;j++;j<n)
	 	{
	 		cin>>H[i][j][0];
	 	}
	 }


	return 0;
}