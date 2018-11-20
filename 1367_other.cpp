#include <iostream>
using namespace std;
struct trienode{
    trienode *zero, *one;
    trienode():zero(nullptr),one(nullptr){}
};
trienode *root;
int m,n,p,ans=0;
void insert(int x)
{
    trienode *p=root;
    int maxn=1<<29;
    while (maxn>0){
        if (x>=maxn){
            if (p->one) p=p->one;
            else p=(p->one=new trienode());
            x-=maxn;
        }
        else{
            if (p->zero) p=p->zero;
            else p=(p->zero=new trienode());
        }
        maxn>>=1;
    }
}
int find(int x){
    trienode *p=root;
    int maxn=1<<29,sum=0;
    while (maxn>0){
        if (x>=maxn){
            if (p->zero) {sum+=maxn; p=p->zero;}
            else p=p->one;
            x-=maxn;
        }
        else{
            if (p->one) {sum+=maxn; p=p->one;}
            else p=p->zero;
        }
        maxn>>=1;
    }
    return sum;
}
int main() {
    root=new trienode();
    cin>>n>>m;
    for (int i=0;i<n;++i){
        cin>>p;
        insert(p);
    }
    for (int i=0;i<m;++i){
        cin>>p;
        ans=max(ans,find(p));
    }
    cout<<ans;
    return 0;
}