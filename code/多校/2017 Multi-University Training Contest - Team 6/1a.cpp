#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;
class node{
    public:
    	int en;
        int ch[26];
        int be;
        void init(){be=0,en=0;memset(ch,0,sizeof(ch));}
};
node tre[100005];
char str[100005];
char str1[100005];
int cnt=1;
void build(char *a)
{
    int now=0;
    int len=strlen(a);
    for(int i=0;i<len;i++)
    {
        int id=a[i]-'a';
        if(tre[now].ch[id]==0)tre[now].ch[id]=cnt++;
        now=tre[now].ch[id];
        tre[now].be++;
    }
    now=0;
    for(int i=0;i<len;i++)
	{
		int id=a[len-1-i]-'a';
		if(tre[now].ch[id]==0)tre[now].ch[id]=cnt++;
		now=tre[now].ch[id];
		tre[now].en++;
	}
}
int dfs1(char *a)
{
	int len=strlen(a);int now=0;
	for(int i=0;i<len;i++)
	{
		int tem=a[i]-'a';
		if(tre[now].ch[tem]==0)
			return 0;
		else
			now=tre[now].ch[tem];
		if(tre[now].be==0)return 0;
	}
	return tre[now].be;
}
int dfs2(char *b)
{
	int len=strlen(b);
	int now=0;
	for(int i=len-1;i>=0;i--)
	{
		int tem=b[i]-'a';
		if(tre[now].ch[tem]==0)
			return 0;
		else
			now=tre[now].ch[tem];
		if(tre[now].en==0)return 0;
	}
	return tre[now].en;
}
int minn(int a,int b)
{
	if(a>b)return b;
	else return a;
}
int main()
{
	int t,num1,num2;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<100005;i++)
			tre[i].init();
		scanf("%d%d",&num1,&num2);
		for(int i=0;i<num1;i++)
		{
			scanf("%s",str);
			build(str);
		}
		for(int i=0;i<num2;i++)
		{
			scanf("%s %s",str,str1);
			int ans1=dfs1(str);
			int ans2=dfs2(str1);
			int ans=minn(ans1,ans2);
			cout<<ans<<endl;
		}
	}
}
