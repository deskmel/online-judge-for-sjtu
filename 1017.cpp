 #include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int NEW=1,NNEW=0;
	int MID=0;
	int OLD=0;
	for (int i=0;i<d;i++)
	{
		NNEW=OLD*c+MID*b+NEW*a;
		OLD=OLD+=MID;
		MID=NEW;
		NEW=NNEW;
	}
	cout<<NEW+MID+OLD<<endl;

	
	return 0;
}