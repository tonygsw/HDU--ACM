#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include <string>
#include<queue>
#include<vector>
#include<set>
#include<map>
#define LL long long
using namespace std;
const int N = 5005;
LL n;
LL m;
string s;
LL dp[N];
int go(int l, int r, int m, int k)
{
    for (; l <= r; l++)
        if (dp[k] - dp[l] <= m) return l;
    return 0;
}
int bins(int l, int r, int m,int k)
{
    
    while (l <= r)
    {
        if (r - l <= 5)
            return go(l, r, m,k);
        int mid = (l + r) / 2;
        if (dp[k] - dp[mid] <= m)
            r = mid;
        else l = mid + 1;
    }
    return 0;
}
int  main()
{
    cin.sync_with_stdio(false);
    //vector<LL> su;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> m;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int dif = 0,mxl=0,mxd=0;
            dp[0] = 0;
            for (int k = 1; i - k + 1 >= 0 && i + k < s.length(); k++)
            {
                int l = i - k + 1, r = i + k;
                dif += abs(s[l] - s[r]);
                dp[k] = dif;
                mxd = dif;
                mxl = k;
                //int len = bins(0, k, m,k);
                //ans = max(ans, k-len);
            }
            int st = 0, en = 1;
            while (en <= mxl)
            {
                if (dp[en]-dp[st] <= m) ans = max(ans, en - st),en++;
                else st++;
            }
            dif = 0, mxl = 0, mxd = 0;
            dp[0] = 0;
            for (int k = 1; i - k>= 0 && i + k < s.length(); k++)
            {
                int l = i - k, r = i + k;
                dif += abs(s[l] - s[r]);
                dp[k] = dif;
                mxd = dif;
                mxl = k;
                //int len = bins(0, k, m, k);
                //ans = max(ans, k - len);
            }
            st = 0, en = 1;
            while (en <= mxl)
            {
                if (dp[en] - dp[st] <= m) ans = max(ans, en - st), en++;
                else st++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
