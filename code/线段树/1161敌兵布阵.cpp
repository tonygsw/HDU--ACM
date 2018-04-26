#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int data[50000];int tree[200010];
void build(int k,int l,int r)
{
	if(l==r)
	{
		tree[k]=data[l];
		return;
	}
	else
	{
		build(2*k,l,(l+r)/2);
		build(2*k+1,(l+r)/2+1,r);
		tree[k]=tree[2*k]+tree[2*k+1];
	}
}
void update(int k,int l,int r,int p)
{
	if(l==r)
	{
		tree[k]=data[p];
		return;
	}
	else
	{
		int mid=(l+r)/2;
		if(mid>=p)update(2*k,l,mid,p);
		else update(2*k+1,mid+1,r,p);
		tree[k]=tree[2*k]+tree[2*k+1]; 
	}
}
int quary(int k,int l, int r,int be,int end)
{
	if(l>=be&&r<=end)
		return tree[k];
	int ans=0;
	int mid=(l+r)/2;
	if(mid>=be)ans=ans+quary(2*k,l,mid,be,end);
	if(mid<end) ans=ans+quary(2*k+1,mid+1,r,be,end);
	return ans;
}
int main()
{
	int t,n;char q[100];int qr;int ql;
	scanf("%d",&t);
	int ca=1;
	while(t--)
	{
		memset(data,0,sizeof(data));
		memset(tree,0,sizeof(tree));
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&data[i]);
		build(1,0,n-1);
		printf("Case %d:\n",ca++);
		while(scanf("%s",q)&&q[0]!='E')
		{
			scanf("%d%d",&ql,&qr);
			ql--;
			if(q[0]=='Q')
			{
				qr--;
				printf("%d\n",quary(1,0,n-1,ql,qr));
			}
			if(q[0]=='A')
			{
				data[ql]=data[ql]+qr;
				update(1,0,n-1,ql);
			}
			if(q[0]=='S')
			{
				data[ql]=data[ql]-qr;
				update(1,0,n-1,ql);
			}
		}
	}
	return 0;
}
