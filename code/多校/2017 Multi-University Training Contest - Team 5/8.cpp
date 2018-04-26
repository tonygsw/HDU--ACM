/*
#include<iostream>
#include<cmath>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<cstdio>
#include<stdio.h>
using namespace std;
#define ll long long
ll num[10005];ll n,m;
ll bi[10005];
ll exist[10005];
ll c(ll n,ll m)
{
	ll ans=1;
	for(int i=0;i<m;i++)
		ans=ans*(n-i)/(i+1);
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int totalnum=0;
		memset(num,0,sizeof(num));
		memset(exist,0,sizeof(exist));
		scanf("%I64d%I64d",&n,&m);
		for(int i=0;i<=m;i++)
			scanf("%I64d",&bi[i]);
		num[1]=bi[1];
		totalnum+=bi[1];
		exist[0]=bi[0];
		for(int i=2;i<=m;i++)
		{
            for (int j=m;j>=0;j--)  
            {  
                if(exist[j]==0)continue;  
                if (num[i-1]==0) break;  
                for (int k=1;k<=num[i-1];k++)  
                    if(j+k*(i-1)<=m)
                        exist[j+k*(i-1)]+=exist[j]*c(num[i-1],k);
            }
			num[i]=bi[i]-exist[i];
			totalnum+=(i*num[i]);
			if(totalnum==m)break;
		}
		int flag=0;
		for(int i=1;i<=m;i++)
		{
			if(num[i]!=0)
				for(int j=1;j<=num[i];j++)
				{
					if(flag==0)cout<<i;
					else	cout<<" "<<i;
					flag++;
				}
		}
		cout<<endl;
	}
}*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define max_n 10010
using namespace std;
int a[max_n], b[max_n], dp[max_n], c[max_n];
//dp[i]��ʾ���Ӻ�Ϊi���Ӽ�������

int main() {
    int t, n, m;
    scanf("%d", &t);
    while(t--) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(dp, 0, sizeof(dp));
        scanf("%d %d", &n, &m);
        for(int i = 0; i <= m; i++)
            scanf("%d", &b[i]);
        dp[0] = 1; //��ʼ��ֵ
        int p = 0, sum = 0;
        for(int i = 1; i <= m; i++) {
            c[i] = b[i] - dp[i];//A������ֵΪi�ĸ���
            for(int j = 0; j < c[i]; j++) {
                a[p++] = i; //��A���и�ֵ
                for(int k = m; k>= i; k--) { //�����01���� 
                    dp[k] += dp[k - i]; //��Ϊk��A�Ӽ��������ȥ����B����
                }
            }
        }
        for(int i = 0; i < p; i++) {
            if(i > 0) printf(" ");
            printf("%d", a[i]);//���A����
        }
        printf("\n");
    }
    return 0;
}
