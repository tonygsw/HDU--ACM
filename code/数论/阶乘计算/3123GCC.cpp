#include<iostream>
#include<string.h>
using namespace std;
#define ll long long
ll t,m,num;
char n[105];
void trans()
{
	num=0;
	ll length=strlen(n);
	for(int i=0;i<length;i++)
		num=num*10+(n[i]-'0');
}
int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%s%d",n,&m);
		//cin>>n>>m;
		ll len=0;
		num=10000005;
		if(strlen(n)<7)
			trans();
		if(num>m)len=m;
		else len=num;
		ll sum=1,ans=1;
		for(int i=1;i<=len;i++)
		{
			ans=(ans*i)%m;
			if(!ans)break;
			sum=(sum+ans)%m;
		}
		cout<<sum%m<<endl;
	}
}
