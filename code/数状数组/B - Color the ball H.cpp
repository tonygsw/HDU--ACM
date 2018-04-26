#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define ll long long
int num[100005];int n=0;
int lowbit(int x)
{
    return x&(-x);
}
void change(int x,int nu)
{
    for(;x<=n;x+=lowbit(x))
        num[x]+=nu;
}
int quary(int x)
{
    int ans=0;
    for(;x>0;x-=lowbit(x))
        ans+=num[x];
    return ans;
}
int main()
{
    int a,b;
    while(cin>>n&&n!=0)
    {
        memset(num,0,sizeof(num));
        int nn=n;
        while(nn--)
        {
            cin>>a>>b;
            change(a,1);
            change(b+1,-1);
        }
        cout<<quary(1);
        for(int i=2;i<=n;i++)
            cout<<" "<<quary(i);
        cout<<endl;
    }
}
