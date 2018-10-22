#include<iostream>
using namespace std;
const int lee 			=10;
const int escribe		=11;
const int carga			=20;
const int almacena		=21;
const int suma			=30;
const int resta			=31;
const int divide		=32;
const int multiplica	=33;
const int bifurca		=40;
const int bifurcaneg	=41;
const int bifurcacero	=42;
const int alto			=43;
void simpletron(int*);
int main(){
	cout<<"Simpletron programa a : halla la suma de los numeros hasta que ingrese un negativo"<<endl;
	//ejercicio a
	int mem[100]={1050,2050,4107,2160,3061,2161,4000,1161,4300};
	simpletron(mem);
	cout<<endl;
	//ejercicio b
	cout<<"Simpletron programa b : halla el promedio de 7 numeros "<<endl;
	int mem1[100]={2080,1050,4214,2050,3061,2161,2081,3082,2182,2083,3182,2180,2090,4200,2061,3283,2161,1161,4300};
	mem1[80]=1;
	mem1[81]=1;																	
	mem1[83]=6;
	simpletron(mem1);
	cout<<endl;
	//ejercicio c
	cout<<"Simpletron programa c : ingrese la cantidad de numeros y los numeros (resultado el mayor numero)"<<endl;
	int mem2[100]={1083,2080,4217,1050,2061,3150,4009,2050,2161,2081,3082,2182,2083,3182,2180,2090,4201,1161,4300};
	mem2[80]=1;
	mem2[81]=1;
	mem2[82]=0;
	simpletron(mem2);
	return 0;
}
void simpletron(int *mem){
	int acumulador=0;
	int i=0;
	while(i<100){
		int a=mem[i]/100;
		int b=mem[i]%100;
		switch(a){
			case lee:{
				int c;
				cout<<"ingrese el numero"<<endl;
				cin>>c;
				mem[b]=c;
				break;
			}
			case escribe:{
				cout<<endl<<"salida: ";
				cout<<mem[b]<<endl;	
				break;
			}
			case carga:{
				acumulador=mem[b];
				break;
			}
			case almacena:{
				mem[b]=acumulador;
				break;
			}
			case suma:{
				acumulador+=mem[b];	
				break;
			}	
			case resta:{
				acumulador-=mem[b];
				break;
			}
			case divide:{
				acumulador/=mem[b];
				break;
			}
			case multiplica:{
				acumulador*=mem[b];
				break;
			}
			case bifurca:{
				if(acumulador>0)
					i=b-1;
				break;
			}
			case bifurcaneg:{
				if(acumulador<0)
					i=b-1;
				break;
			}
			case bifurcacero:{
				if(acumulador==0)
					i=b-1;
				break;
			}
		}
		if(alto==a)
			break;
		i++;
	}
}
