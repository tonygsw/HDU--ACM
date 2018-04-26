#include<iostream>
using namespace std;
int main(){
	int group;
	cin>>group;
	for(int i=0;i<group;i++){
		int n,m,total=0,price;
		cin>>n>>m;
		for(int j=0;j<n;j++){
			cin>>price;
			total+=price;
		}
		for(int j=0;j<m;j++){
			cin>>price;
			if(price>total) cout<<1;
			else cout<<0;
		}
		cout<<endl;
	}
}
