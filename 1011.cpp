#include <iostream>
#include <iomanip>
using namespace std;
class MyComplex
{
	friend MyComplex operator+(MyComplex &z1,MyComplex &z2);
	friend MyComplex operator-(MyComplex &z1,MyComplex &z2);
	friend MyComplex operator*(MyComplex &z1,MyComplex &z2);
	friend MyComplex operator/(MyComplex &z1,MyComplex &z2);
	friend istream&  operator>>(istream& in,MyComplex &z1);
	friend ostream& operator<<(ostream& out,const MyComplex &z2);
private:
	double x,y;
public:
	MyComplex(double a=0,double b=0):x(a),y(b){}
	MyComplex& operator=(const MyComplex &a)
	{
		if (this==&a) return *this;
		x=a.x;
		y=a.y;
		return *this;
	}
	MyComplex& operator+=(MyComplex &a)
	{
		x+=a.x;
		y+=a.y;
		return *this;
	}
	MyComplex& operator-=(MyComplex &b)
	{
		x-=b.x;
		y-=b.y;
		return *this;
	}
	MyComplex& operator*=(MyComplex &c)
	{
		*this=(*this*c);
		return *this;
	}
	MyComplex& operator/=(MyComplex &d)
	{
		*this=(*this/d);
		return *this;
	}
};
MyComplex operator+(MyComplex &z1,MyComplex &z2)
{
	return MyComplex(z1.x+z2.x,z1.y+z2.y);
}
MyComplex operator-(MyComplex &z1,MyComplex &z2)
{
	return MyComplex(z1.x-z2.x,z1.y-z2.y);
}
MyComplex operator*(MyComplex &z1,MyComplex &z2)
{
	return MyComplex(z1.x*z2.x-z1.y*z2.y,(z1.x*z2.y+z1.y*z2.x));
}
MyComplex operator/(MyComplex &z1,MyComplex &z2)
{
	return MyComplex((z1.x*z2.x+z1.y*z2.y)/(z2.x*z2.x+z2.y*z2.y),(z1.y*z2.x-z1.x*z2.y)/(z2.x*z2.x+z2.y*z2.y));
}
istream& operator>>(istream& in,MyComplex &z1)
{
	in>>z1.x>>z1.y;
	return in;
}
ostream& operator<<(ostream &os,const MyComplex &z1)
{
	os<<setiosflags(ios::fixed)<<setprecision(2)<<z1.x<<' '<<z1.y;
	return os;
}
int main(int argc, char const *argv[])
{
	MyComplex z1;
  MyComplex z2;

  cin >> z1 >> z2;

  cout << z1 + z2 <<endl;
  cout << z1 - z2 <<endl;
  cout << z1 * z2 <<endl;
  cout << z1 / z2 <<endl;
  cout << (z1 += z2) <<endl;
  cout << (z1 -= z2) <<endl;
  cout << (z1 *= z2) <<endl;
  cout << (z1 /= z2) <<endl;

  return 0;
}