#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstdio>
#include<math.h>
#include<string.h>
using namespace std;
#define n  100005
#define ll long long
int p[n];int prime[n];bool mark[n];int cnt[1005];
int lenofprime=0;
int ans;
void get_oula()
{
    int i,j;
    p[1]=1;
    memset(p,0,sizeof(p));
    for(int i=2;i<n;i++)
    {
        if(!mark[i])
        {
            prime[lenofprime++]=i;
            p[i]=i-1;
        }
        for(int j=0;j<=lenofprime;j++)
        {
            if(i*prime[j]>n)break;
            mark[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                p[i*prime[j]]=p[i]*prime[j];
                break;
            }
            else
                p[i*prime[j]]=p[i]*(prime[j]-1);
        }
    }
}
ll get_not_prime(int nn,int m)
{
    int tt=0;
    int len=sqrt(nn);
    for(int i=2;i<=len;i++)
    {
        if(nn&&(nn%i==0))
        {
            cnt[tt++]=i;
            while(nn&&(nn%i==0))
                nn=nn/i;
        }
    }
    if(nn>1)cnt[tt++]=nn;
    ll ans=0,tem,flag;
    for(int i=1;i<(1<<tt);i++)
    {
        tem=1;flag=0;
        for(int j=0;j<tt;j++)
        {
            if(i&(1<<j))
                flag++,tem*=cnt[j];
        }
       // cout<<"t="<<tem<<endl;
        if(flag&1)
            ans+=m/tem;
        else
            ans-=m/tem;
    }
    return ans;
}
int main()
{
    get_oula();
    int t;
    scanf("%d",&t);int ca=1;
    while(t--)
    {
        int a,b,c,d,k;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        if(k==0)
            cout<<"Case "<<ca++<<": "<<0<<endl;
        else
        {
            b=b/k;d=d/k;
            int zuo=min(b,d);
            int you=max(b,d);
            ll ans=1;
            for(int i=1;i<=zuo;i++)
                ans+=p[i];
           // cout<<endl;
            ll  tem=(ll)zuo*(you-zuo);
            for(int i=zuo+1;i<=you;i++)
                tem=tem-get_not_prime(i,zuo);
            ans=ans+tem;
            cout<<"Case "<<ca++<<": "<<ans<<endl;
        }
    }
}
