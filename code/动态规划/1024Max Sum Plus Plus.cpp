#include <stdio.h>  
#include <vector>  
#include <string.h>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <limits.h>  
#include <stack>  
#include <queue>  
#include <set>  
#include <map>  
using namespace std;  
  
const int MAX_N = 1000001;  
int dp[MAX_N], MAX[MAX_N], arr[MAX_N];  
  
int main()  
{  
    int n, m, maxSum;  
    while (~scanf("%d %d", &m, &n))  
    {  
        memset(MAX, 0, sizeof(int) * (n+1));  
        memset(dp, 0, sizeof(int) * (n+1));  
        for (int i = 1; i <= n; i++)  
        {  
            scanf("%d", arr+i);  
        }  
        for (int i = 1; i <= m; i++)  
        {  
            maxSum = INT_MIN;  
            for (int j = i; j <= n; j++)  
            {  
                dp[j] = max(dp[j-1]+arr[j], MAX[j-1]+arr[j]);  
                MAX[j-1] = maxSum;  //not overflow here  
                maxSum = max(maxSum, dp[j]);  
            }  
        }  
        printf("%d\n", maxSum);  
    }  
    return 0;  
}
