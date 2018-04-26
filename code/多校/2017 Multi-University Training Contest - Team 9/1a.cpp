#include<iostream>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<cstdio>
#include<stdio.h>
using namespace std;
#define ll long long
int main()
{

    ll total=1;
    for(int i=1;i<1000;i++)
    {
        total=total*i;
        cout<<i<<"  "<<total<<endl;
        if(total<=0)break;
    }
}
