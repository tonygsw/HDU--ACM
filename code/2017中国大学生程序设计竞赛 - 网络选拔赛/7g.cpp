#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<cmath>
#include<string>
#define ll long long
using namespace std;
int t;int num[30];    int L,R,l,r;
ll fast_mod(ll a, ll b)
{
    ll res = 1;
    while(b != 0) {
        if(b&1)res=(res*a);
        a=(a*a);
        b>>=1;
    }
    return res;
}
int kind=0;
void dfs(int len,int lentotal,int jin,int ju,int zf,int zy)
{
    if(len>ju)
    {
        ll ans=0;ll j=1;
        for(int i=lentotal-1;i>=0;i--)
        {
            ans+=num[i]*j;
            j=j*jin;
        }
        if(zf==1&&ans>=zy)kind++;
        else if(zf==0&&ans<=zy)kind++;
        return;
    }
    if(len==0)
    {
        for(int i=1;i<=jin;i++)
        {
            num[len]=i;
            num[lentotal-len-1]=i;
            dfs(len+1,lentotal,jin,ju,zf,zy);
        }
    }
    else
    {
        for(int i=0;i<=jin;i++)
        {
            num[len]=i;
            num[lentotal-len-1]=i;
            dfs(len+1,lentotal,jin,ju,zf,zy);
        }
    }
}
ll qiu(int k1,int k2,int jin)
{
    ll ans=0;
    for(int i=k1+1;i<k2;i++)
        ans+=fast_mod(jin,i-2);
    kind=0;
    int ju=0;
    if(k1%2==0)ju=k1/2+1;
    else ju=k1/2;
    dfs(0,k1,jin,ju,1,L);
   // cout<<"kind="<<kind<<endl;
    ans+=kind;
    kind=0;
    if(k2%2==0)ju=k2/2+1;
    else ju=k2/2;
    dfs(0,k2,jin,ju,0,R);
    ans+=kind;
    return ans;
}
int main()
{
    scanf("%d",&t);

    while(t--)
    {
		ll ans=0;
        ll temans=0; ll tem=0;
		scanf("%d%d%d%d",&L,&R,&l,&r);
        for(int i=l;i<=r;i++)
        {
            int k1=0,k2=0;
            for(;;k1++)
                if(fast_mod(i,k1)-1>=L)break;
            for(;;k2++)
                if(fast_mod(i,k2)-1>=R)break;
           // cout<<k1<<"  "<<k2<<endl;
            tem=qiu(k1,k2,i);
			temans+=tem;
            ans+=tem*i;
        }
        cout<<"ans="<<ans<<endl;
        ans+=(R-L+1)*(r-l+1)-tem;
        cout<<ans<<endl;
    }
}
