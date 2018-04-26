#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll c_ans[2005][2005];
long long POW(ll a, ll b){
    long long ans=1;
    while(b){
        if (b&1) {
            ans=(ans*a)%MOD;
        }
        a=(a*a)%MOD;
        b=b>>1;
    }
    return ans%MOD;
}
ll dp[2005];
void Init() {
    memset(c_ans, 0, sizeof(c_ans));
    for (int i=0; i<=2000; ++i) {
        c_ans[i][0]=1;
        for (int j=1; j<=i; ++j) c_ans[i][j]=(c_ans[i-1][j-1]+c_ans[i-1][j]) % MOD;
    }
}
int main() {
   	freopen("input.txt", "r", stdin);
   	freopen("1.txt","w",stdout); 
    Init();
    dp[1]=1;
    ll n,m;
    int T;
    cin>>T;
    ll ans;
    while (T--) {
        scanf("%lld%lld", &n, &m);
        int len=min(n,m-1);
        for (int k=2; k<=len; ++k) {
            ll tmp=POW(k, n);
            for (int j=1; j<k; ++j) {
                tmp=(tmp-c_ans[k][j]*dp[j]) % MOD;
            }
            tmp=tmp%MOD;
            if (tmp<0) tmp+=MOD;
            dp[k]=tmp;
        }
        ans=0;
        for (int i=1; i<=len; ++i) {
            ans = (ans + (c_ans[m][i] * dp[i] % MOD) * POW (m-i, n)) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
