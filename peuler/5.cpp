#include <iostream>
using namespace std;
int main(){
	unsigned long long int vale=0;
	for(unsigned long long int i=20;vale<20;i=i+20){
		vale=0;
		for(int j=1;j<21;j++){
			if(i%j==0){
				vale=vale+1;
			}
		}
		if(vale==20){
			cout<<i;
		}
		
	}
}
