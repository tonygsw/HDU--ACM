#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int tree[800005];int data[200005];
int maxx(int x,int y)
{
	if(x>y)return x;
	return y;
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		tree[k]=data[r];
		return;
	}
	else
	{
		build(2*k,l,(l+r)/2);
		build(2*k+1,(l+r)/2+1,r);
		tree[k]=maxx(tree[2*k],tree[2*k+1]);
	}
}
void update(int k,int l,int r,int p,int num)
{
	if(l==r)
	{
		tree[k]=num;
		return;
	}
	int mid=(l+r)/2;
	if(mid>=p)update(2*k,l,mid,p,num);
	else update(2*k+1,mid+1,r,p,num);
	tree[k]=maxx(tree[2*k],tree[2*k+1]);
}
int query(int k,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql)return 0;
	if(l>=ql&&r<=qr)
	{
		return tree[k];
	}
	int ans=0;
	int mid=(l+r)/2;
	ans=maxx(ans,query(2*k+1,mid+1,r,ql,qr));
	ans=maxx(ans,query(2*k,l,mid,ql,qr));
	return ans;
}
int main()
{
	int m,n;
	char a;int l;int r;
	while(~scanf("%d%d",&n,&m))
	{
		memset(tree,0,sizeof(tree));
		memset(data,0,sizeof(data));
		for(int i=1;i<=n;i++)
			scanf("%d",&data[i]);
		build(1,1,n);
		for(int J=1;J<=m;J++)
		{
			//cout<<"j=="<<J<<endl;
			cin>>a>>l>>r;
			//scanf("%c%d%d",&a,&l,&r);
			if(a=='Q')
			{
				int ans=query(1,1,n,l,r);
				printf("%d\n",ans);
			}
			else if(a=='U')update(1,1,n,l,r);
		}
	}
	return 0;
}
