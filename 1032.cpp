#include <iostream>
using namespace std;
int ACKER[4][1005];
int m,n;
int ACKERMAN(int m,int n)
{
	if (m==0)
		return n+1;
	else if (n==0)
		return ACKERMAN(m-1,1);
	else return ACKERMAN(m-1,ACKERMAN(m,n-1));
}
int main(int argc, char const *argv[])
{	cin>>m>>n;
	cout<<ACKERMAN(m,n);
}