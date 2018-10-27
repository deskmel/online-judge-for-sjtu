#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const int maxn=200007;
int d[maxn];
ll cnt[maxn],times[maxn];
//cnt[i]存储的是 长度为i的序列的个数
//d[i]存储的是以i结尾的序列最长的长度
int main()
{
    int s,t;
    cin>>s>>t;
    memset(cnt,0,sizeof(cnt));
    int i,j,tmp,ans=1;
    cnt[1]=t-s+1;

    for(i=s;i<=t;i++)
        d[i]=times[i]=1; //初始化为1

    for(i=s;i<=t;i++) //遍历每个数作为起点
        for(j=1;j<=100;j++)    if( (i*j)%100 == 0) //假设增长率为j%
        {
            //则在此增长率下 得到的数为 tmp 可以看出,要让tmp为整数 必须i*j是100的倍数
            tmp = i + i*j/100;
            if( tmp <= t ) //如果这个tmp是在规定范围内的 我们就找到了一个解
            {
                if(d[i]+1 > d[tmp]) //这时要比较 看看要不要更新以tmp结尾的最长的长度
                {
                    d[tmp] = d[i] + 1;//以tmp为结尾的序列的长度 为 以i为结尾的序列的长度 再加上1 表示算上tmp
                    times[tmp] = times[i]; //发生了最长长度的更新 所以要重置 以tmp结尾的最长长度的重复次数为 i的
                }
                else if(d[i]+1==d[tmp]) //恰好是重复的最长长度
                {
                    times[tmp] += times[i];//则最长长度的次数 增加 以i结尾的最长长度重复次数
                }

                ans = max(ans,d[tmp]);  //更新ans
                //d[i]+1 表示以i结尾的序列长度+tmp所增加的1位 这个长度的子列数量要增加times[i]
                cnt[d[i]+1] += times[i];
            }
        }
    cout<<ans<<'\n'<<cnt[ans];
    return 0;
}

