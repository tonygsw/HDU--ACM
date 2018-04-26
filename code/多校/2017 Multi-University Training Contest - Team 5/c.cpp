#include<iostream>
#include<cmath>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<cstdio>
#include<stdio.h>
#include<map>
using namespace std;
#define ll long long
ll fast_mod(ll a, ll b) {
    ll res = 1;
    while(b != 0) {
        if(b&1) res = (res * a) % mod;
        a = (a*a) % mod;
        b >>= 1;
    }
    return res;
}
int main()
{

}
