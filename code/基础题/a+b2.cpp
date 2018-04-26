#include<iostream>
#include<string>
#include<string.h>
#include<cmath>
using namespace std;
int a1[10005],b1[10005];
string a,b;
int conta=0,contb=0,c=0,jw=0;

void change(){
	for(int i=(a.length()-1);i>=0;i--){
	//	cout<<"a[i]="<<a[i]<<" ";
		a1[conta]=a[i]-'0';
		conta++;
	}
	for(int i=(b.length()-1);i>=0;i--){
	//	cout<<"b[i]="<<b[i]<<" ";
		b1[contb]=b[i]-'0';
		contb++;
	}
}
void add(){	
	for(int i=0;i<max(conta,contb);i++){
		c=a1[i]+b1[i]+jw;
			jw=c/10;
			c=c%10;
		a1[i]=c;
	}
}
int main(){
	int n;
	cin>>n;
	int cont=1;
	while(n--){
		conta=0,contb=0,c=0,jw=0;
		memset(a1,0,sizeof(a1));
		memset(b1,0,sizeof(b1));
		cin>>a>>b;
		string d=a; string e=b;
		if(a.length()<b.length()){
			string c=a;
			a=b;
			b=c;
		}
		change();  add();
		cout<<"Case "<<cont++<<":"<<endl<<d<<" + "<<e<<" = ";
		if(jw!=0) cout<<jw;
		for(int i=max(conta,contb)-1;i>=0;i--){
			cout<<abs(a1[i]);
		}
		cout<<endl;
		if(n!=0)cout<<endl;
	}
}
