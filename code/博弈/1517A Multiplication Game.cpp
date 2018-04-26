#include<iostream>
#include<math.h>
#include<cmath>
#include<stdio.h>
using namespace std;
#define ll long long
int main()
{
   ll a;
    while(cin>>a)
    {
        bool flag=false;
        while(a!=1)
        {
            if(!flag)
            {
                if(a%9==0)a=a/9;
                else a=a/9+1;
            }
            else
            {
                if(a%2==0)a=a/2;
                else a=a/2+1;
            }
            flag=!flag;
        }
        if(flag)cout<<"Stan wins."<<endl;
        else cout<<"Ollie wins."<<endl;
    }
}
