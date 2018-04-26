#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<cmath>
#include<string>
#define ll long long
using namespace std;
int num[100];int len=0;
bool judge(int m,int k)
{
    len=0;
    while(m!=0)
    {
        num[++len]=(m%k);
        m=m/k;
    }
    for(int i=1;i<=(len/2);i++)
    {
        if(num[i]!=num[len-i+1])
            return false;
    }
    return true;
}
int main()
{
    freopen("1.txt","w",stdout);
    for(int i=1;i<=100;i++)
    {
        for(int j=2;j<=i;j++)
        {
            if(judge(i,j))cout<<i<<"  "<<j<<endl;
            //else cout<<i<<"  "<<j<<" "<<1<<endl;
        }
    }
}
