
电院-IEEE-沈贯 2018/10/21 18:43:22
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
ll numstack[10000],numtop,optop,p,lastp=5,pri[10000];
char opstack[10000],expr[10000];
bool flag=true;
ll priority(char x)
{
    switch (x) {
        case '+':
            return 1;
        case '-':
            if (lastp>0) return 4;
            else return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '^':
            return 3;
        case '(':
            return 5;
        case ')':
            return 0;
        default: return -1;
    }
}
ll calc(char op,ll a,ll b){
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': if (b==0) {
                flag=false;
                return 0;
            }
            return a/b;
        case '^': ll t=1;
            if (a==1) return 1;
            if (b<0) return 0;
            for (int i=0;i<b;++i) t*=a; return t;
    }
}
int main() {
    cin.getline(expr,101);
    opstack[0]='(';
    pri[0]=5;
    optop=1;
    numtop=-1;
    expr[strlen(expr)]=')';
    for (int i=0;expr[i];++i){
        if (expr[i]==' ') continue;
        p=priority(expr[i]);
        if (p<0) {
            if (lastp>=0) {numtop++; numstack[numtop]=0;}
            numstack[numtop]=numstack[numtop]*10+expr[i]-48;
        }
        else{
            while (p<pri[optop-1]&&opstack[optop-1]!='('){
                if (pri[optop-1]!=4) {
                    numstack[numtop - 1] = calc(opstack[optop - 1], numstack[numtop - 1], numstack[numtop]);
                    if (!flag) break;
                    numtop--;
                }else
                    numstack[numtop]=-numstack[numtop];
                optop--;
            }
            if (p==0) {
                if (opstack[optop - 1] == '(') optop -= 1;
                else {
                    cout << "Error";
                    return 0;
                }
            }
            else {
                if (p==1&&expr[i]=='-') {
                    opstack[optop++] = '+';
                    pri[optop - 1] = 1;
                    opstack[optop++] = '-';
                    pri[optop - 1] = 4;
                }
                else{
                    opstack[optop++] = expr[i];
                    pri[optop - 1] = p;
                }
            }
        }
        if (!flag) break;
        lastp=p;
    }
    if (!optop&&flag&&numtop==0)
        cout<<numstack[0];
    else
        cout<<"Error";
    return 0;
}