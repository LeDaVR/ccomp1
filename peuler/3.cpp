#include <iostream>
using namespace std;
int main(){
	int masg=0;
	unsigned long long int cumple;cout<<"numero";cin>>cumple;
	for(int i=1;i<=cumple/2;i++){
		if(cumple%i==0){
			int c=0;
			for(int comp=i;comp>0;comp--){
				if(i%comp==0){
					c=c+1;
				}
			}
			if((c<=2) && (i>=masg) ){
				masg=i;
			}			
		}
	}
	cout << masg;
}
