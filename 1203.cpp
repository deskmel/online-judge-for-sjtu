#include <iostream>
using namespace std;
template <class T> class link;
template <class T> link<T> operator+ (const link<T> &r1,const link<T> &r2);
template <class elemType>
class link
{
	friend link<elemType> operator+ <>(const link<elemType> &r1,const link<elemType> &r2);
private:
	elemType *value;
	int length;
public:
	link(int l,elemType *a):length(l)
	{
		value = new elemType [length];
		for (int i=0;i<length;i++)
		{
			value[i]=a[i];
		}
	}
	link(const link<elemType> &c)
	{
		length=c.length;
		value=new elemType [length];
		for (int i=0;i<length;i++)
		{
			value[i]=c.value[i];
		}
	}
	void print();
	~link()
	{
		delete [] value;
	}

};
template <class T>
void link<T>::print()
{
	for (int i=0;i<length;i++)
	{
		cout<<value[i]<<' ';
	}
}
template <class T>
link<T> operator+(const link<T> &a,const link<T> &b )
{
	T *value=new T [a.length+b.length];
	for (int i=0;i<a.length;i++)
	{
		value[i]=a.value[i];
	}
	for (int j=0;j<b.length;j++)
	{
		value[j+a.length]=b.value[j];
	}
	link<T> c=link<T>(a.length+b.length,value);
	return c;
}

int main()
{
	char a[10];
	cin>>a;
	int m,n;
	cin>>m>>n;
	if (a[0]=='i')
	{
		int *x=new int [m];
		int *y=new int [n];
		for (int i=0;i<m;i++)
		{
			cin>>x[i];
		}
		for (int j=0;j<n;j++)
		{
			cin>>y[j];
		}
		link<int> a_1(m,x);
		link<int> a_2(n,y);
		link<int> a_3(a_1+a_2);
		a_3.print();
	}
	else if (a[0]=='d')
	{
		double *x=new double [m];
		double *y=new double [n];
		for (int i=0;i<m;i++)
		{
			cin>>x[i];
		}
		for (int j=0;j<n;j++)
		{
			cin>>y[j];
		}
		link<double> a_1(m,x);
		link<double> a_2(n,y);
		link<double> a_3(a_1+a_2);
		a_3.print();
	}
	else
	{
		char *x=new char [m];
		char *y=new char [n];
		for (int i=0;i<m;i++)
		{
			cin>>x[i];
		}
		for (int j=0;j<n;j++)
		{
			cin>>y[j];
		}
		link<char> a_1(m,x);
		link<char> a_2(n,y);
		link<char> a_3(a_1+a_2);
		a_3.print();
	}

	return 0;
}