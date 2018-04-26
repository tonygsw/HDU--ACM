/*#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<cmath>
#include<string>
using namespace std;
#define ll long long
ll mod=1e9+7;
char s1[1000005];char s2[1000005];
int num[52][1000005];int num1[52][1000005];
int jilu[1000005];  int t;
int numoflen[52];
void findd()
{
    memset(jilu,0,sizeof(jilu));
    int tem=0,tem1;int temlen=strlen(s2);
    if(s2[temlen-1]>='a'&&s2[temlen]<='z')
        tem=s2[temlen-1]-'a';
    else
        tem=s2[temlen-1]-'A'+26;
    for(int i=0;i<numoflen[tem];i++)
    {
        jilu[temlen-1]++;
        int location=num[tem][i];
        int ca=1;
        for(int j=temlen-2;j>=0;j--)
        {
            if(s2[j]>='a'&&s2[j]<='z')
                tem1=s2[j]-'a';
            else
                tem1=s2[j]-'A'+26;
            if(location-ca<0)break;
            else
                if(num1[tem1][location-ca]==t)jilu[j]++;
                else break;
            ca++;
        }
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(numoflen,0,sizeof(numoflen));
        scanf("%s%s",&s1,&s2);
        for(int i=0;i<strlen(s1);i++)
        {
            if(s1[i]>='a'&&s1[i]<='z')
            {
                int tem=s1[i]-'a';
                num[tem][numoflen[tem]++]=i;
                num1[tem][i]=t;
            }
            else
            {
                int tem=s1[i]-'A'+26;
                num[tem][numoflen[tem]++]=i;
                num1[tem][i]=t;
            }
        }
        findd();
        int lens=strlen(s2);
        ll ans=0;
        for(int i=0;i<lens;i++)
            ans=(ans+(lens-i)*jilu[i]%mod)%mod;
        printf("%I64d\n",ans);//cout<<ans<<endl;
    }
}*/

#include<iostream>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
string p,t;
ll next1[1000005];
ll jilu[1000005];
void getnext1()
{
    int q,k;
    int m=p.length();
    next1[0]=-1;
    for(q=1,k=0;q<m;q++)
    {
        while(k>0&&p[q]!=p[k])
            k=next1[k-1];
        if(p[q]==p[k])
            k++;
        next1[q+1]=k;
    }
}
int kmp()
{
    ll n,m,i,q;
    n=t.length();m=p.length();
    getnext1();
    for(i=0,q=0;i<n;i++)
    {
    	int flag=0;
        while(q>0&&p[q]!=t[i])
        {
        	flag=1;
        	q=next1[q];
		}
        if(p[q]==t[i])
        {
            jilu[q]++;
            q++;
        }
    }
}
int main()
{
    int tt;
    cin.sync_with_stdio(false);
    cin>>tt;
    while(tt--)
    {
        cin>>t>>p;
        reverse(t.begin(),t.end());
        reverse(p.begin(),p.end());
        memset(jilu,0,sizeof(jilu));
        kmp(); 
		for(int i=p.length();i>0;i--)
			if((next1[i]-1)>=0)jilu[next1[i]-1]+=jilu[i-1];
		ll ans=0;
		for(int i=0;i<p.length();i++)
            ans=(ans+(i+1)*jilu[i]%mod)%mod;
        cout<<ans<<endl;
    }
}
