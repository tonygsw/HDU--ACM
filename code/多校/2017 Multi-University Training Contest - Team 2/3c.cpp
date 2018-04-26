#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<cmath>
#include<string>
#include<string.h>
#include<stdio.h>
#include<cstdio> //freopen("2.txt","w",stdout);
#define ll long long
const ll mod=1e9+7;
ll ai[250005];
ll maxai[250005];
int bi[250005];
using namespace std;
inline ll maxx(ll a,ll b)
{
	if(a>b)return a;
	else return b;
 } 
inline bool camp(ll a,ll b)
{
	if(a>b)return true;
	else return false;
}
int main()
{
	int n,tem;
	ll tema;
	while(~scanf("%d",&n))
	{
		ll ans=0,max=0,maxj=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&tema);
			ai[i]=tema-i;
			if(max<=ai[i])
			{
				max=ai[i];
				maxj=i;
			}
		}
	/*	for(int i=1;i<=n;i++)
			cout<<ai[i]<<" ";
		cout<<endl;
	*/	
//	cout<<max<<" "<<maxj<<endl;
		memset(bi,0,sizeof(bi));
		ll flagmax=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&tem);
			bi[tem]++;
			if(tem<=maxj)
			{
				flagmax++;
				bi[tem]=0;
			}
		}
	//	cout<<"flagmax="<<flagmax<<endl;

		ans+=flagmax*max%mod;
		ai[n+1]=max-(n+1);	
	
		//sort(ai+maxj+1,ai+n+2,camp);
		/*for(int i=maxj+1;i<=n+1;i++)
			cout<<"ai[i]="<<ai[i]<<" ";
		cout<<endl;
		*/
		maxai[n+1]=ai[n+1];
		for(int i=n;i>=1;i--)
			maxai[i]=maxx(maxai[i+1],ai[i]); 
	//	for(int i=1;i<=n+1;i++)
	//		cout<<"hah="<<maxai[i]<<" ";
	//	cout<<endl;
		for(int i=maxj;i<=n;i++)
		{
			if(bi[i]!=0)
			{
				ll za=0;
				ans+=maxai[i]*bi[i]%mod;
				ans=ans%mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
