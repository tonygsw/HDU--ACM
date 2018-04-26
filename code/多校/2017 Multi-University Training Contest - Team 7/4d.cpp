#include<iostream>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<string.h>
#include<cstdio>
using namespace std;
#define ll long long
int main()
{
    int t;ll num;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&num);
        if(num%2==0)
        {
            cout<<num/2+1<<endl;
        }
        else   cout<<num/2+2<<endl;
    }
}
