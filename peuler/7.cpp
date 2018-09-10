#include <iostream>
using namespace std;

bool primo(int it){
	int c=0;
	for(int ciclo=it;ciclo>0;ciclo--){
		if(it%ciclo==0){
			c=c+1;
		}
	}	
	if(c<=2){
		return true;
	}else{
		return false;
	}
}
int main(){
	int cant;cout<<"ingrese el numero primo:"<<endl;cin>>cant;
	int emp=0;
	int comp=2;
	while(emp!=cant){
		if(primo(comp)==true){
			emp++;	
			cout << "#"<<emp<<"es"<<comp<<endl;	
		}
		comp++;	
	}
	cout <<"respuesta"<<comp-1;
	return 0;
}
