#include<iostream>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<cstdio>
#include<string.h>
#include<stdio.h>
using namespace std;
#define ll long long
ll fast_mod(ll a, ll b){
    ll res = 1;
    while(b!=0) {
        if(b&1) res=(res*a);
        a=(a*a);
        b>>=1;
    }
    return res;
}
ll n,k;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d%I64d",&n,&k);
		if(k==1)
		{
			if(n%2==0)printf("3\n");//cout<<3<<endl;
			else printf("1\n");//cout<<1<<endl;
		}
		else
		{
			int level=1;ll total=1,kk=k;ll sy=0;
			while(1)
			{
				if(total>n)break;
				total+=kk;
				kk=kk*k;
				level++;
				if(n>=total)sy=n-total;
				if(kk<=0)break;
			}
			level=level-1;
			ll c=sy/k,sy1=sy%k;
			int len=fast_mod(k,level-1);
			if(len==0)len=k;
			ll ans=0;
			if(sy%2==0)ans=0;
			else ans=1;
			ll location2=sy;ll location3=len;
			ll k1=k+1,k2=sy1,k3=1;
			k2=(location2-(location2/k)*k-1)+k2+1;
			if(location2%k==0)location2=location2/k;
			else location2=location2/k+1;
			int flag1=0,flag2=0;
			if(k2==0)
			{
				while(1)
				{
					if(location2%2==1)ans=ans^(k1);
					if((len-location2)%2!=0)ans=ans^k3;
					k1=k*k1+1;
					k3=k*k3+1;
					if(location2!=1)location2=location2/k;
					location3=location3/k;
					if(location3<=1)break;
				}
			}
			else
			{
				while(1)
				{
					if(location2!=1&&(location2-1)%2==1)ans=ans^(k1);
					ans=ans^k2;
					if((len-location2)%2!=0)ans=ans^k3;
					k2=(location2-(location2/k)*k-1)*k1+k2+(k-(location2-(location2/k)*k))*(k1/(k+1));
					k1=k*k1+1;
					k3=k*k3+1;
					if(location2!=1)location2=location2/k;
					location3=location3/k;
					if(location3<=1)break;
				}
			}
			ans=ans^n;
			printf("%I64d\n",ans);//cout<<ans<<endl;
		}
	}
}
/*
4
1000000000000000000 
123456789876543212
*/
