/*
#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<cmath>
#include<string>
#define ll long long
using namespace std;
bool use[500];int deg[500];int n;
int ma[500][500];
int ss()
{
	memset(deg,0,sizeof(deg));
	for (int i = 1;i<=n;++i) {
	   use[i] = false;
	    for(int j=1;j<=n;j++)
	    {
	    	if(i!=j&&ma[i][j]!=0)deg[i]++;
		}
	}
	int ans = 0;
	while (true) {
	  int mx = -1, u;
	    for (int i = 1; i <= n; ++i) {
	      if (use[i])continue;
	        if (deg[i] >= mx)
			{
	          mx = deg[i];
	        	u = i;
	        }
	    }
	    if (mx <= 0)
	      break;
	    ++ans;
	    use[u] = true;
	    for (int i=1;i<=n;i++)
	    	if(ma[i][u]!=0)
	      		--deg[i];
	}
	return ans;
}
int main()
{
	int m;
	freopen("input.txt","r",stdin);
	freopen("w.txt","w",stdout);
	scanf("%d%d",&n,&m);
	int a,b;
	memset(ma,0,sizeof(ma));
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		ma[a][b]=1;
		ma[b][a]=1;
	}
	cout<<ss()<<endl;
}
/*
6 6
1 2
1 3
3 4
3 5
4 6
5 6
*/


#include <iostream>
#include <algorithm>
#include <cmath>
#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;
int in[3005];
int ma[3005][3005];
int main()
{
	int t,n;
	freopen("input.txt","r",stdin);
	freopen("r.txt","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(ma,0,sizeof(ma));
		int x=1;
		cin>>n;
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				cin>>ma[i][j];
				ma[j][i]=ma[i][j];
			}
		}
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(ma[i][j]==0&&ma[i][k]==0&&ma[j][k]==0)
					{
						flag=1;
						break;
					}
					if(ma[i][j]==1&&ma[i][k]==1&&ma[j][k]==1)
					{
						flag=1;
						break;
					}
				}
				if(flag==1)break;
			}
			if(flag==1)break;
		}
		if(flag==1) cout<<"Bad Team!"<<endl;
		else cout<<"Great Team!"<<endl;
	}
}
