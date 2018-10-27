#include <iostream>
#include <string.h>
using namespace std;
class stack
{
private:
	int size;
	int *S;
	int top;
	void doublespace()
	{
		int *tmp=S;
		S=new int [size*2];
		for (int i=0;i<size;i++)
		{
			S[i]=tmp[i];
		}
		size*=2;
		delete [] tmp;
	}
public:
	bool ifempty()
	{
		return top==-1;
	}
	int top1()
	{
		if (!this->ifempty())
			return S[top];
	}
	int pop()
	{
		if (!this->ifempty())
			return S[top--];
	}
	void push(int x)
	{
		if (top==size-1) doublespace();
		S[++top]=x;
	}
	stack() :top(-1),size(50){
		S=new int [size];
	}
	
};
int main(int argc, char const *argv[])
{
	char tmp[1000];
	stack s;
	bool flag=true;
	while (cin>>tmp)
	{
		if (strcmp(tmp,"begin")==0)
			s.push(0);
		else if (strcmp(tmp,"if")==0)
			s.push(1);
		else if (strcmp(tmp,"then")==0)
		{
			if (s.ifempty() || s.top1()!=1 )
				flag=false;
			else {s.pop();s.push(2);}
		}
		else if (strcmp(tmp,"end")==0)
		{
			do
			{
				if (s.ifempty() || s.top1()==1)
				{
					flag=false;
					break;
				}
				if (s.top1()==0)
				{
					s.pop();
					break;
				}
				else s.pop();
			}
			while (true);
			if (!flag) break;
		}
		else if (strcmp(tmp,"else")==0)
			if (s.ifempty() || s.pop()!=2) 
			{
				flag=false;
			}
		if (!flag) break;
	}
	while (!s.ifempty())
		cout<<s.pop()<<'\t';
	if (flag) cout<<"Match!"<<endl;
	else cout<<"Error!"<<endl;
	return 0;
}