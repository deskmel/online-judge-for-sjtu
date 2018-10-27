#include <iostream>
#include <string.h>
using namespace std;
int stack[40000];
int stack1[40000];
int top1=-1,top2=-1;
char tmp[10000];
int main(int argc, char const *argv[])
{
	for (int i=0;i<40000;i++)
		stack[i]=-1;
	bool flag=true;
	while (cin>>tmp)
	{
		if (strcmp(tmp,"begin")==0)
		{
			stack[++top1]=0;
		}
		else if (strcmp(tmp,"if")==0)
			stack[++top1]=1;
		else if (strcmp(tmp,"then")==0)
		{
			if (top1==-1 || stack[top1]!=1) 
			{
				flag=false;
			}
			else stack[top1]=2;
		}
		else if (strcmp(tmp,"end")==0)
		{
			do
			{
				if (top1==-1 || stack[top1]==1)
					{
						flag=false;break;
					}
				if (stack[top1--]==0)
					break;
			}
			while (true);
			if (!flag) break;
		}
		else if (strcmp(tmp,"else")==0)
		{
			if (top1==-1 || stack[top1--]!=2)
				flag=false;
		}
		if (!flag) break;
	}
	while (flag and top1!=-1)
	{
		if (stack[top1--]!=2) flag=false;
	}
	if (flag) cout << "Match!" << '\n';
	else cout << "Error!" << '\n';
	return 0;
}