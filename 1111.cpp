#include <iostream>
#include <string.h>
using namespace std;
char pre[30];
char in[30];
char heap[10000];
void get_heap(int l_pre,int r_pre,int l_in,int r_in,int i)
{
	if (l_pre==r_pre)
		heap[i]=pre[l_pre];
	if (l_pre<r_pre)
	{
		heap[i]=pre[l_pre];
		int len=0;
		for (int j=0;j<=r_in-l_in;j++)
		{
		if (in[j+l_in]==pre[l_pre])
		{
			len=j;
			break;
		}
		}
		get_heap(l_pre+1,l_pre+len,l_in,l_in+len-1,i*2);
		get_heap(l_pre+len+1,r_pre,l_in+len+1,r_in,i*2+1);
	}
}
int main(int argc, char const *argv[])
{
	cin.getline(pre,30);
	cin.getline(in,30);
	int len=strlen(pre);
	get_heap(0,len-1,0,len-1,1);
	int count=0;
	int index=1;
	while (count<len)
	{
		if (heap[index]=='\0')
			cout<<"NULL"<<' ';
		else 
		{
			cout<<heap[index]<<' ';
			count++;
		}
		index+=1;
	}
	return 0;
}