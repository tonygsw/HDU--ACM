#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<math.h>  
#include<iostream>  
#include<algorithm>  
#include<stack>  
#include<queue>  
#include<vector>  
#include<set>  
#include<map>  
#include<string>  
#define nl n<<1  
#define nr (n<<1)|1  
using namespace std;  
typedef long long ll;  
typedef unsigned long long ull;  
typedef pair<int,int>P;  
const int INF=0x3f3f3f3f;  
const ll INFF=0x3f3f3f3f3f3f3f3f;  
const ll mod=1e9+7;  
ll mu[100005];  
void mobius()  
{  
    mu[1]=1;  
    for(int i=1;i<=100000;i++)  
        for(int j=i+i;j<=100000;j+=i)  
            mu[j]-=mu[i];  
}  
ll qpow(ll a,ll b)  
{  
    ll ans=1;  
    while(b)  
    {  
        if(b&1)  
            ans=(ans*a)%mod;  
        b>>=1;  
        a=(a*a)%mod;  
    }  
    return ans;  
}  
ll sum[200005];  
ll cnt[200005];  
int main()  
{  
    mobius();int ca=1;  
    int t;
    freopen("1009.in","r",stdin);
	scanf("%d",&t);  
    while(t--)  
    {  
        memset(cnt,0,sizeof(cnt));int n;  
        scanf("%d",&n);int maxx=INF;  
        for(int i=1;i<=n;i++)  
        {  
            int x;scanf("%d",&x);  
            cnt[x]++;  
            maxx=min(maxx,x);  
        }  
        ll ans=0;  
        for(int i=1;i<=200000;i++)sum[i]=sum[i-1]+cnt[i];  
        for(int i=2;i<=maxx;i++)  
        {  
            ll tmp=1;  
            for(int j=1;j*i<=100000;j++)  
            {  
                tmp=(tmp*qpow((ll)j,sum[i*j+i-1]-sum[i*j-1]))%mod;  
            } 
		//	cout<<tmp<<" "; 
            ans=(ans-tmp*mu[i]+mod)%mod;  
        }  
        printf("Case #%d: %lld\n",ca++,ans);  
    }  
    return 0;  
}  
