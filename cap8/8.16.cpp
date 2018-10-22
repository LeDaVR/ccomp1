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
int mem[100];
int main(){
	int registrodeinstruccion;	
	int m=0;
	cout<<"-----BIENVENIDO A SIMPLETRON--------------"<<endl;
	cout<<"-----INTRODUZCA SU INSTRUCCION------------"<<endl;
	cout<<"-----DE 4 DIGITOS Y -9999 PARA TERMINAR---"<<endl;
	cout<<"------------------------------------------"<<endl;
	cout<<"-OPERACIONES INEXISTENTES SERAN IGNORADAS-"<<endl;
	while(mem[m-1]!=-9999){
		if(m<10)
			cout<<0<<m<<'?'<<" ";
		else
			cout<<m<<'?'<<" ";
		cin>>registrodeinstruccion;
		if((registrodeinstruccion>=-9999&&registrodeinstruccion<=-1000)||(registrodeinstruccion<=9999&&registrodeinstruccion>=1000)){
			mem[m]=registrodeinstruccion;
			m++;
		}
	}
	mem[m-1]=0;
	simpletron(mem);
	return 0;
}
void simpletron(int *mem){
	int acumulador=0;
	int contadorintruccions=0;
	while(contadorintruccions<100){
		int codigodeoperacion=*(mem+contadorintruccions)/100;
		int operando=*(mem+contadorintruccions)%100;
		if(alto==codigodeoperacion){
			cout<<"Termino la ejecucion de simpletron"<<endl<<"MEMORIA"<<endl;
			cout<<"     00    10    20    30    40    50    60    70    80    90"<<endl;
			for(int i=0;i<100;i++){
				if(i%10==0||i==0){
					cout<<endl;
					cout<<i/10;	
				}
				if(mem[i]>=1000)
					cout<<"  "<<mem[i];	
				else if(mem[i]<=-1000)
					cout<<" -"<<mem[i];	
				else if(mem[i]>=100)
					cout<<"  0"<<mem[i];	
				else if(mem[i]<=-100)
					cout<<" -0"<<mem[i];
				else if(mem[i]>=10)
					cout<<"  00"<<mem[i];
				else if(mem[i]<=-10)
					cout<<" -00"<<mem[i];
				else if(mem[i]<=-1)
					cout<<" -000"<<mem[i];
				else if(mem[i]>=0)
					cout<<"  000"<<mem[i];			
			}
			break;
		}
		if(acumulador>9999||acumulador<-9999){
			cout<<"------los resultados excedieron el rango---"<<endl;
			cout<<"-----Ejecucion terminada de manera forzosa-"<<endl;
			break;
		}
		switch(codigodeoperacion){
			case lee:{
				cout<<"ingrese el numero"<<endl;
				cin>>*(mem+operando);
				if(*(mem+operando)/10000!=0){
					cout<<"------error dato incorrecto------";
					return;	
				}
				break;
			}
			case escribe:{
				cout<<*(mem+operando)<<endl;	
				break;
			}
			case carga:{
				acumulador=*(mem+operando);
				break;
			}
			case almacena:{
				*(mem+operando)=acumulador;
				break;
			}
			case suma:{
				acumulador+=*(mem+operando);	
				break;
			}	
			case resta:{
				acumulador-=*(mem+operando);
				break;
			}
			case divide:{
				if(*(mem+operando)==0){
					cout<<"intento de dividir entre 0"<<endl;
					cout<<"Ejecucion terminada de manera forzosa"<<endl;
					return;	
				}
				acumulador/=*(mem+operando);
				break;
			}
			case multiplica:{
				acumulador*=*(mem+operando);
				break;
			}
			case bifurca:{
				contadorintruccions=operando-1;
				break;
			}
			case bifurcaneg:{
				if(acumulador<0)
					contadorintruccions=operando-1;
				break;
			}
			case bifurcacero:{
				if(acumulador==0)
					contadorintruccions=operando-1;
				break;
			}
			default:{
				return;
			}	
		}
		contadorintruccions++;
	}
}
