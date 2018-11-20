#include <iostream>
using namespace std;
int N;
class node 
{
public:
	node(int v):val(v),n(0),b(NULL),l(NULL){}
	int val;
	int n;
	node *b;
	node *l;
};
node* man[2000005];

int main(int argc, char const *argv[])
{
	cin>>N;
	node* man[1] = new node (1);
	for (int i=0;i<N;i++)
	{
		
	}

	return 0;
}