/*
#include<math.h>
#include<cmath>
#include<string>
#Include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
int main()
{

}*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
#include<cstring>
#include<stdio.h>
using namespace std;
#define ll long long
int vis[10];
ll quickpower(ll a, ll b)
{
	ll ans = 1;
	while (b != 0)
	{
		if (b & 1) ans = ans*a;
		b >>= 1;
		a = a*a;
	}
	return ans;
}
string change(ll a)
{
	string ans;
	while (a != 0)
	{
		char tem = a % 10 + 48;
		ans += tem;
		a = a / 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

ll get(ll a)
{
	string b = change(a);
	for (ll i = 0;i <b.length();i++)
	{
		vis[b[i] - '0']++;
		if (vis[b[i] - '0'] > 2)
			return b.length() - 1 - i;
	}
	return -1;
}

int main()
{
	ll n;
	while (cin >> n)
	{
		while (1)
		{
			memset(vis, 0, sizeof(vis));
			ll x = get(n);
			cout << n << " " << x << endl;
			if (x == -1)
				break;
			else
			{
				ll num = quickpower(10, x);
				n -= (n%num)+1;
			}
		}
		cout << n << endl;
	}
}
