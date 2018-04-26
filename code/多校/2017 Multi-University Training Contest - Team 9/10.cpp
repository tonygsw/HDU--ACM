#include<iostream>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<cstdio>
#include<string.h>
#include<stdio.h>
using namespace std;
#define ll long long
char a[2505];char b[2505];
bool hou()
{
	int i,j;int flag=0;
	i=strlen(a)-1;j=strlen(b)-1; 
	while(i>=0&&j>=0)
	{
		if(b[j]!='.'&&b[j]!='*')
		{
			if(a[i]!=b[j])
			{
				flag=1;
				break;
			}
			else
			{
				i--;j--;
			}
		}
		if(b[j]=='.')
		{
			b[j]=a[i];
			j--;i--;
		}
		if(b[j]=='*')
		{
			if(b[j-1]=='.')b[j]=a[i-1];
			else b[j]=b[j-1];
			if(b[j]!=a[i])
			{
				j--;
			}
			else
			{
				while(b[j]==a[i]&&i>=0)i--;
				j=j-2;
			}
		}
	}
	if(i!=-1||j!=-1||flag==1)return false;
	else return true;
}
bool qian()
{
	int i=0,j=0;
	int flag=0;
	while(i<strlen(a)||j<strlen(b))
	{
		if(b[j]!='.'&&b[j]!='*')
		{
			if(a[i]!=b[j])
			{
				flag=1;
				break;
			}
			else
			{
				i++;
				j++;
			}
		}
		else if(b[j]=='.')
		{
			if(i<strlen(a))
			{
				b[j]=a[i];
				j++;i++;
			}
			else return false;
		}
		else
		{
			b[j]=b[j-1];
			if(b[j]!=a[i])j++;
			else
			{
				while(b[j]==a[i])i++;
				j++;
			}
		}
	}
	if(flag==1)return false;
	else return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",&a,&b);
		int  teml=0;
		for(int i=0;i<strlen(b);i++)
			if(b[i]!='*')teml++;
		if(teml>strlen(a))
		{
			cout<<"no"<<endl;
			continue;
		}
		else
		{
			int i=0,j=0,ff=1;
			for(;i<strlen(a)&&j<strlen(b);)
			{
				if(b[j]=='*')j++;
				else
				{
					if(b[j]=='.')
					{
						i++;j++;
					}
					else if(b[j]!=a[i])
					{
						ff=0;
						break;
					}
					else
					{
						i++;
						j++;
					}
				}
			}
			if(ff==1)
			{
				cout<<"yes"<<endl;
				continue;
			}
		}
		if(qian()||hou())cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}
/*
100
acbbc
a.b*c
aaabbbcccddd
.*.*.*.*.*.*c.*d.*.*
aaaaabb
a.*...



100
acbbc
a.b*c
yes
aaabbbcccddd
.*.*.*.*.*.*c.*d.*.*
yes
aaaaabb
a.*...
yes
bb
b
no
abc
abc
yes
aaabbb
a*bbb.*

*/
