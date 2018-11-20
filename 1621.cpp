#include <iostream>
using namespace std;
char M[1000][1000];
int N;
int main(int argc, char const *argv[])
{
	cin>>N;
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
			cin>>M[i][j];
	
	return 0;
}