#include<bits/stdc++.h>
using namespace std;
int num[3000];
int f(int a,int b,int n)
{
	num[1]=1;num[2]=1;
	int cnt=0;
	int i=3;
	for(;i<=n;i++)
	{
		num[i]=(a*num[i-1]+b*num[i-2])%7;
		if(num[i-1]==1&&num[i]==1)break;
		if(num[i]==0&&num[i-1]==0){
			cnt=1;break;
		}
	}
	cout<<"i="<<i<<" "; 
	if(cnt==1) return 0;
	if(i>n)return num[n];
	i=i-2;
	n=n%(i);
	if(n==0)n=i;
	return num[n];
}
int main()
{
	long long n,a,b;
	while(cin>>a>>b>>n&&(a!=0||b!=0||n!=0))
	{
		cout<<f(a,b,n)<<endl;
	}
 	return 0;
} 
