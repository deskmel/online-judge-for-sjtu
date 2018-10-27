#include <iostream>
#include <string.h>
using namespace std;
int n,m;
char op[10];
char code[10];
char ob[1000005];
int queue[1000000][2];
void _2INORDER(int i)
{
	if (i<m)
	{
		_2INORDER(i*2+1);
		cout<<ob[i];
		_2INORDER(i*2+2);
	}

}
void _2POSTORDER(int i)
{
	if (i<m)
	{
		_2POSTORDER(i*2+1);
		_2POSTORDER(i*2+2);
		cout<<ob[i];
	}
}
void _2PREORDER(int i)
{
	if (i<m)
	{
		cout<<ob[i];
		_2PREORDER(i*2+1);
		_2PREORDER(i*2+2);
	}
}
int left_len(int m)
{
	if (m==0)
		return 0;
	else
	{
		int k=1;
		int j=m;
		while (m)
		{
			m/=2;
			k*=2;
		}
		int left=min(j-(k/2)+1+(k/2-2)/2,(k-2)/2);
		return left;
	}
}
void INORDER2(int l,int r )
{
	int head=0,tail=0; 
	int left;
	queue[tail][0]=l;
	queue[tail][1]=r;
	tail+=1;
	while (head!=tail)
	{
		l=queue[head][0];
		r=queue[head][1];
		head++;
		left=left_len(r-l+1);
		cout<<ob[l+left];
		if (left!=0)
		{
			queue[tail][0]=l;
			queue[tail][1]=l+left-1;
			tail++;
		}
		if ((r-l-left-1)>=0) 
		{
			queue[tail][0]=l+left+1;
			queue[tail][1]=r;
			tail++;
		}
	}
}
void PREORDER2(int l,int r)
{
	int left=left_len(m);
	int head=0,tail=0; 
	queue[tail][0]=l;
	queue[tail][1]=r;
	tail+=1;
	while (head!=tail)
	{
		l=queue[head][0];
		r=queue[head][1];
		head++;
		left=left_len(r-l+1);
		cout<<ob[l];
		if (left!=0)
		{
			queue[tail][0]=l+1;
			queue[tail][1]=l+left;
			tail++;
		}
		if ((r-l-left-1)>=0) 
		{
			queue[tail][0]=l+left+1;
			queue[tail][1]=r;
			tail++;
		}
	}

}
void POSTORDER2(int l,int r)
{
	int left=left_len(m);
	int head=0,tail=0; 
	queue[tail][0]=l;
	queue[tail][1]=r;
	tail+=1;
	while (head!=tail)
	{
		l=queue[head][0];
		r=queue[head][1];
		head++;
		left=left_len(r-l+1);
		cout<<ob[r];
		if (left!=0)
		{
			queue[tail][0]=l;
			queue[tail][1]=l+left-1;
			tail++;
		}
		if ((r-l-left-1)>=0) 
		{
			queue[tail][0]=l+left;
			queue[tail][1]=r-1;
			tail++;
		}
	}

}
int main(int argc, char const *argv[])
{
	cin>>n;
	
	for (int i=0;i<n;i++)
	{
		cin>>m;
		cin>>op;
		cin>>code;
		cin>>ob;
		if (strcmp(code,"ENCODE")==0)
		{
			if (strcmp(op,"INORDER")==0)
			{
				_2INORDER(0);
				cout<<endl;
			}
			else if (strcmp(op,"POSTORDER")==0)
			{
				_2POSTORDER(0);
				cout<<endl;
			}
			else if (strcmp(op,"PREORDER")==0)
			{
				_2PREORDER(0);
				cout<<endl;
			}
		}
		else if (strcmp(code,"DECODE")==0)
		{
			if (strcmp(op,"INORDER")==0)
			{
				INORDER2(0,m-1);
				cout<<endl;
			}
			else if (strcmp(op,"POSTORDER")==0)
			{
				POSTORDER2(0,m-1);
				cout<<endl;
			}
			else if (strcmp(op,"PREORDER")==0)
			{
				PREORDER2(0,m-1);
				cout<<endl;
			}

		}

	}
	
	return 0;
}