#include <iostream>
using namespace std;
int triple(int suma){
	for(int i=1;i<=suma;i++){
		for(int j=1;j<=suma;j++){
			for(int k=1;k<=suma;k++){
				if(i+j+k==suma){
					if(i*i+j*j==k*k){
						return i*j*k;	
					}
				}
			}
				
		}
		
	}
}
int main(){
	int suma;cin>>suma;
	int a,b,c;
	cout <<triple(suma);
}
