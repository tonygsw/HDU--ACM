#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","w",stdout);
    int n=rand()%100+1;
    cout<<n<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<rand()%2000+1<<" "<<rand()%2000+1<<endl;
    }
}
