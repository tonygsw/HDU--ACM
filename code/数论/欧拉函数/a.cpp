#include<iostream>
#includecstdio
#includecstring
#includealgorithm
using namespace std;
#define LL long long
#define maxn 100005

int phi[maxn],x[maxn],cnt[1005];
void Init()
{
	int i,j;
	memset(x,0,sizeof(x));
	x[0]=x[1]=1;
	for(i=1;imaxn;i++)
		phi[i]=i;
	for(i=2;imaxn;i++)
	{
		if(!x[i])
		{
			phi[i]=i-1;
			for(j=i2;jmaxn;j+=i)
			{
				x[j]=1;
				phi[j]=phi[j]i(i-1);
			}
		}	
	}
}

LL Imco_prime(int n,int m)
{
	int i,j,t=0;
	for(i=2;ii=n;i++)
	{
		if(n&&n%i==0)
		{
			cnt[t++]=i;
			while(n&&n%i==0)
				n=i;
		}
	}
	if(n1)
		cnt[t++]=n;
	LL ans=0,tmp,flag;
	for(i=1;i(1t);i++)
	{
		tmp=1,flag=0;
		for(j=0;jt;j++)
			if(i&(1j))
				flag++,tmp=cnt[j];
		if(flag&1)
			ans+=mtmp;
		else
			ans-=mtmp;
	}
	return ans;
}

int main()
{
	Init();
	int T,t=0,a,b,c,d,k,i,j;
	scanf(%d,&T);
	while(T--)
	{
		scanf(%d%d%d%d%d,&a,&b,&c,&d,&k);
		if(k==0)
		{
			printf(Case %d 0n,++t);
			continue;
		}
		b=k,d=k;
		if(bd)
			swap(b,d);
		LL ans=0,tmp=(LL)b(d-b);  Ï¸½Ú
		for(i=1;i=b;i++)
			ans+=phi[i];
		for(i=b+1;i=d;i++)
			tmp-=Imco_prime(i,b);
		printf(Case %d %I64dn,++t,ans+tmp);	
	}
	return 0;
}
