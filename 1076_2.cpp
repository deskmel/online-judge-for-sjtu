#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
	int left,right,data;
	
};
node tree[1015];
int f[105][105];
int flag[105];
void treedp(int i,int j){	//表示子树i保留j个结点的最大值
	if (j==0) f[i][j]=0;
	else if (tree[i].right==0 && tree[i].left==0) f[i][j]=tree[i].data;
	else{
		f[i][j]=0;
		for (int k=0;k<j;k++){
			if (f[tree[i].left][k]==0) treedp(tree[i].left,k);
			if (f[tree[i].right][j-k-1]==0) treedp(tree[i].right,j-k-1);
			f[i][j]=max(f[i][j],f[tree[i].left][k]+f[tree[i].right][j-k-1]+tree[i].data);
		}
	}
}

int main(int argc, char const *argv[])
{
	int n,q,start,endd,num;
	cin>>n>>q;
	for (int i=0;i<n-1;++i){
		int p=0;
		cin>>start>>endd>>num;
		for (int j=1;j<=n;j++){
			if (tree[j].left==endd || tree[j].right==endd) p=1;
		}
		if (p==0){
			if (tree[start].left==0) tree[start].left=endd;
			else if (tree[start].right==0) tree[start].right=endd;
			tree[endd].data=num;
			flag[endd]=1;
		}
		else{
			if (tree[endd].left==0) tree[endd].left=start;
			else if (tree[endd].right==0) tree[endd].right=start;
			tree[start].data=num;
			flag[start]=1;
		}
	}
	int gen;
	 for (int i=1;i<=n;i++)
        if (flag[i]==0) {gen=i;break;}
	treedp(1,q+1);
	cout<<(f[1][q+1])<<endl;
	return 0;
}