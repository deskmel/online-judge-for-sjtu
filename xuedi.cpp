#include <iostream>
#include <cstring>
using namespace std;
int minlen(char *str[],int num)
{
	int minlen;
	bool flag=true;//first 
	for (int i=0;i<num;i++)
	{
		if (flag){
			minlen=strlen(str[i]);
			flag=false;
		}
		else minlen=min(minlen,int(strlen(str[i])));
	}
	return minlen;
}
int main(int argc, char const *argv[])
{
	int num;
	cout<<"Please enter the num of the words"<<endl;
	cin>>num;
	char **str=new char*[num];
	cout<<"Please enter the words"<<endl;
	for (int i=0;i<num;i++)
	{
		str[i]=new char [20];
		cin>>str[i];
	}
	cout<<minlen(str,num);
	return 0;
}
