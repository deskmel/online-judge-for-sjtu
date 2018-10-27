#include <iostream>
#include <cmath>
using namespace std;
char *expression=new char [105];
long long datastack[105],top1=-1;
int opstack[105],top2=-1;
enum token {OPAREN,ADD,SUB,MULTI,DIV,EXP,MINUS,CPAREN,VALUE,EOL};
token getOp(long long &value,token lastOp)
{
	while (*expression)
	{
		while (*expression && *expression==' ')
			++expression;
		if (*expression<='9' && *expression>='0')
		{
			value=0;
			while (*expression>='0' & *expression<='9')
			{
				value=value*10+*expression-'0';
				++expression;
			}
			return VALUE;
		}
		switch (*expression)
		{
			case '(': ++expression ; return OPAREN;
			case ')': ++expression ; return CPAREN;
			case '+': ++expression ; return ADD;
			case '-': ++expression ; if (lastOp==VALUE || lastOp==CPAREN) return SUB; else return MINUS;
			case '*': ++expression ; return MULTI;
			case '/': ++expression ; return DIV;
			case '^': ++expression ; return EXP;
		}
	}
	return EOL;
}
void BinaryOp(int op,long long *dataStack,bool &flag)
{
	long long num1,num2;
	if (top1==-1)
		{flag=false;}
	else num2=datastack[top1--];
	if (top1==-1)

		{flag=false;}
	else num1=datastack[top1--];
	switch(op)
	{
		case 2: dataStack[++top1]=(num1 + num2); 
                          break;
		case 3: dataStack[++top1]=(num1 - num2);
		                 break;
		case 4: dataStack[++top1]=(num1 * num2);
		                 break;
		case 5: if (num2==0) {flag=false;} else dataStack[++top1]=(num1 / num2);
						 break;
		case 6: dataStack[++top1]=(pow(num1,num2)); 
						 break;
		case 7: datastack[++top1]=(num1 - num2);
     }
}
int result()
{	int topOp;
	long long currentValue,result_value;
	token lastOp;
	token llastOp=OPAREN;
	bool flag=true;
	while (true)
	{

		lastOp=getOp(currentValue,llastOp);
		llastOp=lastOp;
		if (lastOp==EOL || !flag) break;
		switch(lastOp)
		{
			case VALUE:datastack[++top1]=(currentValue);break;
			case MINUS:datastack[++top1]=0;opstack[++top2]=7;break;
			case CPAREN:
				if (top2==-1)
					{flag=false;}
				while (top2!=-1 && ((topOp=opstack[top2--])!=1))
					BinaryOp(topOp,datastack,flag);
				if (topOp!=1) {flag=false;}
				break;
			case OPAREN:opstack[++top2]=1;break;
			case EXP:
			while (top2!=-1 && opstack[top2]>6)
				BinaryOp(opstack[top2--],datastack,flag);
			opstack[++top2]=6;break;
			case MULTI:case DIV:
			while (top2!=-1 && opstack[top2]>=4)
				BinaryOp(opstack[top2--],datastack,flag);
			opstack[++top2]=(lastOp==MULTI)?4:5;break;
			case ADD:case SUB:
			while (top2!=-1 && opstack[top2]!=1)
				BinaryOp(opstack[top2--],datastack,flag);
			opstack[++top2]=(lastOp==ADD)?2:3;
		}
	}
	while (top2!=-1)
		BinaryOp(opstack[top2--],datastack,flag);
	if (top1==-1)
	{

		cout<<"Error"<<endl;
		return 0;
	}
	result_value=datastack[top1--];
	if (top1!=-1)
	{

		flag=false;
	}
	if (flag)
	cout<<result_value;
	else cout<<"Error"<<endl;
}
 int main(int argc, char const *argv[])
{
	cin.getline(expression,105);
		result();
	return 0;
}