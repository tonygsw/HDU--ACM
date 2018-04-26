#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#include <stack>
using namespace std;
const int MAX = 10000 + 10;
int n;
vector <int> v[MAX];
stack <int> s;
int mark_stack[MAX];
int dfn[MAX];
int low[MAX];
int time1;
int sum;
void Tarjan(int rank){
    dfn[rank] = low[rank] = ++time1;
    s.push(rank);
    mark_stack[rank] = 1;
    int i;
    for(i=0;i<v[rank].size();i++){
        if(!dfn[v[rank][i]]){
            Tarjan(v[rank][i]);
            low[rank] = min(low[rank],low[v[rank][i]]);
        }
        else{
            if(mark_stack[v[rank][i]]){
                low[rank] = min(low[rank],dfn[v[rank][i]]);
            }
        }
    }
    if(low[rank] == dfn[rank]){
        sum++;
        int x = s.top();
        mark_stack[x] = 0;
        s.pop();
        while(x != rank){
            x = s.top();
            mark_stack[x] = 0;            
            s.pop();
        }
    }
    
}
int main(){
    int m;
    	freopen("input.txt","r",stdin);
	freopen("a.txt","w",stdout);
    while(cin>>n>>m,n+m){
        while(!s.empty()){
            s.pop();
        }
        int i;
        for(i=0;i<MAX;i++){
            v[i].clear();
        }
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(mark_stack,0,sizeof(mark_stack));
        while(m--){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
        }
        sum = 0;
        time1 = 0;
        for(i=1;i<=n;i++){
            if(!dfn[i]){
                if(sum){
                    sum++;
                    break;
                }
                else{
                    Tarjan(1);
                }
            }

        }
        if(sum == 1){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
