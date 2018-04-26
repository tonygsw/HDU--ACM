#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l,r;
	int sum;
	int add;
};
node tree[400005];
void pushup(int k)
{
	tree[k].sum=tree[2*k].sum+tree[2*k+1].sum;
	return;
}
void pushdown(int k)
{
	int tem=2*k;
	tree[tem].add=tree[k].add;
	tree[tem+1].add=tree[k].add;
	tree[tem].sum=tree[k].add*(tree[tem].r-tree[tem].l+1);
	tree[tem+1].sum=tree[k].add*(tree[tem+1].r-tree[tem+1].l+1);
	tree[k].add=0;
	return;
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		tree[k].sum=1;
		tree[k].l=tree[k].r=l;
		return;
	}
	else
	{
		build(2*k,l,(l+r)/2);
		build(2*k+1,(l+r)/2+1,r);
		tree[k].sum=tree[2*k].sum+tree[2*k+1].sum;
		tree[k].l=tree[2*k].l;
		tree[k].r=tree[2*k+1].r;
	}
}
void update(int k,int xl,int xr,int num)
{
	if(xr<tree[k].l||xl>tree[k].r)
		return;
	if(xl<=tree[k].l&&xr>=tree[k].r)
	{
		tree[k].add=num;
		tree[k].sum=num*(tree[k].r-tree[k].l+1);
		return;
	}
	if(tree[k].add)
		pushdown(k);
	update(2*k,xl,xr,num);
	update(2*k+1,xl,xr,num);
	pushup(k);
}
int query(int k,int ql,int qr)
{
	if(qr<tree[k].l||ql>tree[k].r)
		return 0;
	if(ql<=tree[k].l&&qr>=tree[k].r)
	{
		return tree[k].sum;
	}
	int ans=0;
	if(tree[k].add)
		pushdown(k);
	int tem=k<<1;	int mid=(tree[k].l+tree[k].r)/2;
	if(qr<=mid)
		ans+=query(ql,qr,tem);
	if(ql>=mid)
		ans+=query(ql,qr,tem+1);
	else
	{
		ans+=query(ql,mid,tem);
		ans+=query(mid+1,qr,tem+1);
	}
	return ans;
}
int main()
{
	int t,n,ca;
	int k=1;
	int left,right,sum;
	scanf("%d",&t);
	while(t--)
	{
		memset(tree,0,sizeof(tree));
		scanf("%d",&n);
		build(1,1,n);
		scanf("%d",&ca);
		for(int i=0;i<ca;i++)
		{
			scanf("%d%d%d",&left,&right,&sum);

			update(1,left,right,sum);
			//cout<<query(1,1,n)<<endl;
		}
		cout<<"Case "<<k++<<": The total value of the hook is "<<tree[1].sum<<"."<<endl;
	}
}
/*
10
1 11 2
6 73 3
40 49 1
97.
100
100 3
1 11 2
6 73 3
40 46 1
Case 1: The total value of the hook is 218.
227
*/
