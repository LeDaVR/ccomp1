#include <iostream>
using namespace std;
int main(){
	int it=1;
	int cant;cout<<"ingrese numero de primos a mostrar:"<<endl;cin>>cant;
	while(cant>0){
		int c=0;
		for(int ciclo=it;ciclo>0;ciclo--){
			if(it%ciclo==0){
				c=c+1;
			}
		}	
		if(c<=2){
			cout << it <<endl;
			cant--;
		}
		it++;
	}
	return 0;
}
