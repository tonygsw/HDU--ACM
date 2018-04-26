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
    int n=100000;int m=100000;
    cout<<n<<" "<<m<<endl;
    for(int i=0;i<n;i++)
        cout<<rand()%maxn+1<<" ";
    cout<<endl;
    for(int i=1;i<n;)
    {
        int x=rand()%n+1;int y=rand()%n+1;
        if(x!=y)
        {
            cout<<x<<" "<<y<<endl;
            i++;
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<rand()%n+1<<" "<<rand()%n+1<<" "<<rand()%maxn<<" "<<rand()%maxn<<endl;
    }
}
