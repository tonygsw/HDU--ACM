#include<iostream>
#include<cmath>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<cstdio>
using namespace std;
#define ll long long
const ll mod=1e9+7;
class nodetem{
	public:
		int cs;
		int zm;
};
class node
{
	public:
		nodetem qz[36];
};
int camp(nodetem a,nodetem b)
{
	if(a.cs<b.cs)
		return 1;
	else return 0;
}
node st[100005];
bool iszero[30];
bool isshow[30];
ll lenofst=0;
string tem;
string t;
ll num[30];
ll power[100005];
void init()
{
    power[0] = 1;
    for (int i = 1 ; i < 100005 ; ++ i) {
        power[i] = power[i - 1] * 26 % mod;
    }
}
int main()
{
	init();
	ll numofzm;
	ll cas=1;
	freopen("2.txt","w",stdout);
	while(~scanf("%d",&numofzm))
	{
		lenofst=0;
		memset(st,0,sizeof(st));
		memset(num,0,sizeof(num));
		memset(isshow,0,sizeof(isshow));
		for(int i=0;i<numofzm;i++)//输入统计 
		{
			
			cin>>tem;
		//	scanf("%s",tem);
			ll len=tem.length();
			lenofst=max(len,lenofst);
			st[len-1].qz[tem[0]-'a'].cs++;
			st[len-1].qz[tem[0]-'a'].zm=tem[0]-'a';
			iszero[tem[0]-'a']=1;
			isshow[tem[0]-'a']=1;
			for(int k=0;k<len-1;k++)
			{
				ll kk=len-1-k;
				st[k].qz[tem[kk]-'a'].cs++;
				st[k].qz[tem[kk]-'a'].zm=tem[k]-'a';
				isshow[tem[k]-'a']=1;
			}
		}
		for(int k=0;k<lenofst-1;k++)//统计整理，进位 
		{
			for(int i=0;i<26;i++)
			{
				if(st[k].qz[i].cs>=26)
				{
					int tem=st[k].qz[i].cs/26;
					st[k].qz[i].cs=st[k].qz[i].cs%26;
					st[k+1].qz[i].cs+=tem;
				}
			}
		}
		int now=25,begin=0;
		int flag=0;int flagall=0;
		int judge=0;
		for(int i=0;i<26;i++)//统计出现的字母个数 
			if(isshow[i]==1)
			{
				flagall++;
			//	cout<<i<<" ";
				if(iszero[i]==0)flag++;	//统计可以为0的字母个数 
			}
	//		cout<<endl;
	//	cout<<"lenofst="<<lenofst<<" "<<flagall<<"  "<<flag<<endl;
		
		/*for(int i=0;i<lenofst;i++)
		{
			for(int j=0;j<26;j++)
				cout<<"st[i].qz[j].qz="<<st[i].qz[j].zm<<" "<<st[i].qz[j].cs<<"  ";
			cout<<endl;
			}
		*/
		
		
		for(int i=lenofst-1;i>=0;i--)//赋值 
		{
		
	/*	cout<<"------"<<endl;	
			for(int j=0;j<26;j++)
				cout<<"st[i].qz[j].qz="<<st[i].qz[j].zm<<" "<<st[i].qz[j].cs<<"  ";
			cout<<endl;
	*/	
			sort(st[i].qz,st[i].qz+26,camp);
			
	/*		cout<<"hhhhhhh"<<endl;
						for(int j=0;j<26;j++)
				cout<<"st[i].qz[j].qz="<<st[i].qz[j].zm<<" "<<st[i].qz[j].cs<<"  ";
			cout<<endl;
	*/		
			for(int k=25;k>=0;k--)
			{
				if(st[i].qz[k].cs==0)break;
				if(iszero[st[i].qz[k].zm]==0)
				{
					if(flag==1&&flagall==26)
						num[st[i].qz[k].zm]=0;
					else if(num[st[i].qz[k].zm]==0) 
						num[st[i].qz[k].zm]=now--;
					flag--;
				}
				else
				{
					if(num[st[i].qz[k].zm]==0)
						num[st[i].qz[k].zm]=now--;
				}
			}
		//	cout<<"now="<<now<<endl;
			if(now==1||now==25-flagall)break; 
		}
		ll ans=0;
		for(int i=lenofst-1;i>=0;i--)
		{
			for(int k=0;k<26;k++)
			{
				ans+=st[i].qz[k].cs*num[st[i].qz[k].zm]*power[i]%mod;
				ans=ans%mod;
			}
		}
		cout<<"Case #"<<cas++<<": "<<ans%mod<<endl;
	}
}
/*

*/
