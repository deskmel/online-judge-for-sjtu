#include <iostream>
using namespace std;
char stack1[100],argu[200];
int datastack[100];
int head1=-1,head2=-1;
int value(char x)
{
	switch (x)
	{
		case '+':return 1;
		case '-':
		case '*':return 2;
		case '/':return 2;
		case '^':return 3;
	}	
}
bool compute()
{
	int tmp,p;
	char c=stack1[head1--];
	switch (c)
	{
		case '+': 
		{
			tmp=datastack[head2--];
			tmp+=datastack[head2--];
			datastack[++head2]=tmp;
		}return true;
		case '-':
		tmp=-datastack[head2--];
		tmp+=datastack[head2--];
		datastack[++head2]=tmp;
		return true;
		case '~':
		datastack[head2]=-datastack[head2];
		break;
		case '/':
		if (datastack[head2]==0)
			return false;
		else 
		{
			tmp=datastack[head2--];
			tmp=datastack[head2--]/tmp;
			datastack[++head2]=tmp;
			return true;
		}
		case '*':
		tmp=datastack[head2--];
		tmp*=datastack[head2--];
		datastack[++head2]=tmp;
		return true;
		case '^':
		tmp=datastack[head2--];
		p=datastack[head2--];
		if (tmp<0)
		{
			datastack[++head2]=0;
			return true;
		}
		else  if (tmp==0)
		{
			datastack[++head2]=1;
			return true;
		}
		else
		{
			while (tmp!=0)
			{
				p*=p;
				tmp--;
			}
			datastack[++head2]=p;
			return true;
		}
		
	}
}
int main(int argc, char const *argv[])
{
	char c;
	int index=0;
	cin.getline(argu,200);
	while (true)
	{
		int num=0;
		int prenum=0;
		c=argu[index++];
		if (c>='0' and c<='9')
		{
			num+=c-'0';
			while (argu[index]>='0' and argu[index]<='9')
			{
				c=argu[index++];
				num=num*10+c-'0';
			}
			datastack[++head2]=num;
		}
		else if (c==')')
		{
			while ()
			{

			}
		} 
		else if (c=='+')
		{
			if (head1==-1 or value(stack1[head1])<=value('+'))
			{
				stack1[++head1]='+';
			}
			else if (vaule(stack1[head1])>=vaule('+'))
			{
				if (!compute())
					{cout<<'Error!'<<endl;break;}
				 
			}
		}
		else if (c=='-')
		{
			if ((argu[prenum]>='0' and argu[prenum]<='9') or argu[prenum]==')' )
			{
				if (head1==-1 or vaule[stack1[head1]]<vaule('-'))
				{
					stack1[++head1]='-';
				}
				else
				{

				}
			}
			else
			{

			}
		}
		else if (c=='*')
		{

		}
		else if (c=='^')
		{

		}
		else if (c=='(')
		{
			stack1[++head1]='(';
		}
		else if (c==' ')
			continue;
		prenum=index;

	}
	
	return 0;
}