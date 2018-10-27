#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	vector<string> text;
	vector<string> command;
	vector<string> out;
	string i;
	do
	{
		getline(cin,i);
		text.push_back(i);
	}
	while (i!="******");
	bool flag=true;
	while (true)
	{
		cin>>i;
		int a,b;
		if (i=="ins")
			{
				cin>>a>>b;
				if (a>text.size() or b>text[a-1].size()+1)
				{
					out.push_back("Error!");
				}
				else
				{	
					getline(cin,i);
					if (b==text[a-1].size()+1)
					{
						text[a-1]=text[a-1]+i;
					}
					else
					text[a-1].insert(b-1,i);
				}
			}


		else if (i=="list") 
			{
				cin>>a>>b;
				if (a<1 or b>text.size() or a>b)
					out.push_back("Error!");
				else
				{
					for (int i=a;i<=b;i++)
					{
						out.push_back(text[i-1]);
					}
				}
			}
		else if (i=="del")
			{
				cin>>a>>b;
				int num;
				cin>>num;
				if (a<1 or b>text.size() or a>b)
					out.push_back("Error!");
				else
				{
					text[a].erase(b,num);
				}
			}
		else if (i=="quit")
			{
				break;
			}
		else
			out.push_back("Error!");
		}
	for (int i=0;i<out.size();i++)
	{
		cout<<out[i]<<endl;
	}
	for (int i=0;i<text.size()-1;i++)
		cout<<text[i]<<endl;
	return 0;
}