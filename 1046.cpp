#include <iostream>
using namespace std;
int N,P,Q;
int ls[100005];
int rs[100005];
int main(int argc, char const *argv[])
{
	scanf("%d %d %d\n",&N,&P,&Q);
	for (int i=0;i<N;i++)
	{
		int tmp;
		scanf("%d %d %d\n",&tmp,&ls[tmp],&rs[tmp]);
	}
	 
	return 0;
}