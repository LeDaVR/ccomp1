#include <iostream>
using namespace std;

int sum(int x){
	int cont=0;
	for(int i=1;i<=x;i++){
		cont=cont+i;
	}
	return cont*cont;
}
int cua(int x){
	int cuen=0;
	for(int i=1;i<=x;i++)
		cuen=cuen+i*i;
	return cuen;
}

int main(){
	int num;
	int resul;
	cout << "ingrese numero"<<endl;
	cin>>num;
	resul=sum(num)-cua(num);
	cout << resul;
	return 0;
}
