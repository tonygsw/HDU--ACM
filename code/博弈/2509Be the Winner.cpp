#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n,tem,flag,k=0;
    while(cin>>n)
    {
        k=0,flag=0;
        for(int i=0;i<n;i++)
        {
            cin>>tem;
            flag=flag^tem;
            if(tem>1)k=1;
        }
        if(k==1)
        {
            if(flag==0)cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
        else
        {
            if(n&1==1)cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
    }
}
