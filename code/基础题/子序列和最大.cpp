#include<iostream>
#include<string.h> 
using namespace std;
int num[100000];
int main(){
	int n,m;
	cin>>n;
	int Case=1;
	while(n--){
		memset(num,0,sizeof(num));
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>num[i];
		}
		int tem_num=0,max=0;int marki=0,markj=0;
		int cont=0;
		for(int i=0;i<m;i++){
			tem_num=tem_num+num[i];
			if(tem_num>max){
				max=tem_num;
				marki=cont;
				markj=i;
			}
			else if(tem_num<0){
					tem_num=0;
					cont=(i+1);
			}
		}
		cout<<"Case"<<Case++<<":"<<endl;
		cout<<max<<" "<<marki+1<<" "<<markj+1<<endl;
	}
}
