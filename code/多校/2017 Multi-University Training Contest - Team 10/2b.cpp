#include<iostream>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<cstdio>
#include<string.h>
#include<vector>
#include<stdio.h>
#include<queue>
using namespace std;
#define ll long long
const ll maxn=1e5+5;
ll h[maxn];
int main()
{
    freopen("gui.txt","w",stdout);
    h[0]=2;h[1]=3;h[2]=6;
    cout<<h[0]<<" "<<h[1]<<" "<<h[2];
    for(int i=3;i<maxn;i++)
    {
        if(i%10==0)cout<<endl;
        h[i]=4*h[i-1]+17*h[i-2]-12*h[i-3]-16;
        cout<<" "<<h[i];
    }

}
