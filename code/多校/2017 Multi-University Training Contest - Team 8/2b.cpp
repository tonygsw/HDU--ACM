#include<iostream>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<cstdio>
#include<string.h>
#include<stdio.h>
using namespace std;
#define ll long long
ll fast_mod(ll a, ll b){
    ll res = 1;
    while(b!=0) {
        if(b&1) res=(res*a);
        a=(a*a);
        b>>=1;
    }
    return res;
}
int main()
{
}
