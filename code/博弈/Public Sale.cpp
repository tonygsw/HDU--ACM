#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdio.h>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(m>=n)
        {
            cout<<n;
            for(int i=n+1;i<=m;i++)
                cout<<" "<<i;
            cout<<endl;
        }
        else
        {
            if(n%(m+1)==0)cout<<"none"<<endl;
            else
            {
                cout<<n%(m+1)<<endl;
            }
        }

    }
}
