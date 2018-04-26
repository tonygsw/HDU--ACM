#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int dp[1000][1000];
string a;
string b;
void d()
{
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=a.length();i++)
	{
		for(int j=1;j<=b.length();j++)
		{
			if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
}
int main()
{
	while(cin>>a>>b)
	{
		d();
		cout<<dp[a.length()][b.length()]<<endl;
	}
}
