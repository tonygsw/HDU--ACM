#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
const int maxn=1e5+7;
int prime[maxn+5];
bool check[maxn+5];
int mu[maxn+5];

void init()
{
    mu[1]=1;
    int tot=0;
    for(int i=2;i<=maxn;i++)
    {
        if(!check[i])
        {
            prime[tot++]=i;
            mu[i]=-1;
        }
        for(int j=0;j<tot;j++)
        {
            if(i*prime[j]>maxn) break;
            check[i*prime[j]]=true;
            if(i%prime[j]==0)
            {
                mu[i*prime[j]]=0;
                break;
            }
            else
            {
                mu[i*prime[j]]=-mu[i];
            }
        }
    }
}

const int N=1e5+5;
const int mod=1e9+7;

int n;
int num[2*N];
LL F[N];
LL f[N];


LL qpow(LL x,LL n)
{
    LL ret=1;
    for(;n;n>>=1)
    {
        if(n&1) ret=ret*x%mod;
        x=x*x%mod; 
    }
    return ret;
}

int main()
{
    init();
    freopen("hh.txt","w",stdout);
    for(int i=0;i<maxn;i++)
    {
    	cout<<mu[i]<<" ";
    	if(i%10==0)cout<<endl; 
	}
    int T; 
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        memset(num,0,sizeof(num));
        memset(f,0,sizeof(f));
        int max_gcd=1e9,max_a=0;
        LL ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int t;
            scanf("%d",&t);
            num[t]++;
            max_gcd=min(t,max_gcd);
            max_a  =max(t,max_a  );
        }
        for(int i=1;i<2*N;i++)
            num[i]+=num[i-1];
        for(int i=2;i<=max_gcd;i++)
        {
            F[i]=1;
            for(int j=i;j<=max_a;j+=i)
                F[i]=F[i]*qpow(j/i,num[j+i-1]-num[j-1])%mod;
//            printf("F[%d]=%4lld\n",i,F[i]);
        }
    
//        //=================================
        for(int i=2;i<=max_gcd;i++)
            for(int j=1;i*j<=max_gcd;j++)
//                printf("f[%d]=%4lld,  mu[%d]=%d, F[%d]=%4lld\n",i,f[i],j,mu[j],i*j,F[i*j]),
                f[i]=(f[i]+mu[j]*F[i*j])%mod;
//                printf("f[%d]=%4lld\n",i,f[i]);
        for(int i=2;i<=max_gcd;i++)
            ans=(ans+f[i])%mod;
        //=================================
        printf("Case #%d: %lld\n",kase,ans); 
    }
}
