#include<iostream>
using namespace std;
void ordenar(int *a,int b){
	int temp;
	int c=1;
	while(c!=0){
		c=0;
		for(int i=b-1;i>0;i--){
			if (*(a+i)<*(a+i/2)){
				temp=*(a+i);
				*(a+i)=*(a+i/2);
				*(a+i/2)=temp;
				c++;
			}
			if (*(a+i)<*(a+i-1)){
				temp=*(a+i);
				*(a+i)=*(a+i-1);
				*(a+i-1)=temp;
				c++;
			}
		}	
	}
}
void invertir(int *a,int b){
	int tem;
	for(int i=0;i<b/2;i++){
		tem=*(a+i);
		*(a+i)=*(a+b-1-i);
		*(a+b-1-i)=tem;
	}
}
void primos(int *a,int b){
	int c;
	for(int i=0;i<b;i++){
		c=0;
		for(int j=2;j<*(a+i);j++){
			if(*(a+i)%j==0){
				c=1;
			}	
		}
		if(c!=1 && *(a+i)!=0)
			cout<<*(a+i)<<" ";
	}
}
void perfectos(int *a,int b){
	for(int i=0;i<b;i++){
		int c=0;
		for(int j=1;j<=*(a+i)/2;j++){
			if(*(a+i)%j==0)
				c+=j;
		}
		if(c==*(a+i))
			cout<<c<<" ";
	}
}
void mostrar(int *a,int b){
	cout<<"numeros perfectos:  ";
	perfectos(a,b);
	cout<<endl;
	cout<<"numeros primos:  ";
	primos(a,b);
	cout<<endl;
	invertir(a,b);
	cout<<"invertido: ";
	for(int i=0;i<b;i++)
		cout<<*(a+i)<<" ";
	ordenar(a,b);
	cout<<endl<<"Ordenado:";
	for(int i=0;i<b;i++)
		cout<<*(a+i)<<" ";
}
int main(){
	int a[15]={8,28,7,1,9,4,6,5,9,9,7,45,3,7,1};
	int b=15;
	mostrar(a,b);
	return 0;
}
