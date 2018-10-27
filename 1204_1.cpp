#include <iostream>
#include <cstring>
using namespace std;
char text[110][2010];	char s[200];	int head=0;
void list(int num1,int num2)
{
	for (int i=(num1-1);i<=num2-1;i++)
		cout<<text[i]<<endl;
}
void del(int num1,int num2,int num3)
{

	int k=strlen(text[num1-1]);
	for (int i=0; i<(strlen(text[num1-1])-num3-num2+1);i++)
		text[num1-1][i+num2-1]=text[num1-1][i+num3+num2-1];
	for (int i=0; i<num3; i++)
		text[num1-1][k-1-i] = NULL;
}
void quit()
{
	for (int i=0;i<head;i++)
		cout<<text[i]<<endl;
}
void ins(int num1,int num2,char *t)
{
	for (int i=(strlen(text[num1-1])-1);i>=(num2-1);i--)
		text[num1-1][i+strlen(t)]=text[num1-1][i];
	for (int i=0; i<strlen(t); i++)
		text[num1-1][i+num2-1]=t[i];
}
int main(int argc, char const *argv[])
{
	char c;
	for (int i=0;i<100;i++)
	{
		cin.getline(text[i],2000);
		head++;
		if (strcmp(text[i],"******") == 0){
			head--;
			break;
		}

	}
	int i=0,j=0;
	while (cin>>s)
	{
		if (strcmp(s,"list")==0)
		{
			cin>>i>>j;
			if (i>head or j>head or i>j or i<1 or j<1)
				cout<<"Error!"<<endl;
			else 
				list(i,j);
		}
		else if (strcmp(s,"ins")==0)
		{
			char tmp[100];
			cin>>i>>j;
			c=cin.get();
			cin.getline(tmp,100);
			if (i>head or i<1 or j>strlen(text[i-1])+1 or j<1)
				cout<<"Error!"<<endl;
			else
			ins(i,j,tmp);

		}
		else if (strcmp(s,"del")==0)
		{
		int num;
		cin>>i>>j>>num;
		if (i<1 or j<1 or i>head or j>strlen(text[i-1]) or j+num-1>strlen(text[i-1]) )
			cout<<"Error!"<<endl;
		else
			del(i,j,num);
		}
		else if (strcmp(s,"quit")==0)
		{
			quit();
			break;
		}
	}
	
	return 0;
}