#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e9;
int main()
{
    freopen("input.txt","w",stdout);
    srand((unsigned)time(NULL));
    int n=rand()%5+2;int m=rand()%10+1;
    cout<<n<<" "<<m<<endl;
    for(int i=1;i<=m;)
    {
        int x=rand()%n+1;int y=rand()%n+1;
        if(x!=y)
        {
            cout<<x<<" "<<y<<endl;
            i++;
        }
    }
    cout<<0<<" "<<0<<endl;
}
