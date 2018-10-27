#include <iostream>
using namespace std;
int r[1024],l[1024],r[1024];
void bfs
int main(int argc, char const *argv[])
{
	int n;
	int x,y,z;
	cin>>x>>y>>z;
	r[x]=1;
	r[y]=(r[x]*2);
	r[z]=(r[x]*2+1);
	l[x]=y;
	r[x]=z;
	for (int i<n/2)
	{
		cin>>x>>y>>z;
		l[x]=y;
		r[x]=z;
		r[y]=r[x]*2;
		r[z]=r[x]*2+1;
	}
	return 0;
}