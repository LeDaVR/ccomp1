#include<iostream>
#include<math.h>
using namespace std;
const int lee 			=10;//A
const int escribe		=11;//B
const int nline			=12;//C
const int carga			=20;//14
const int almacena		=21;//15
const int suma			=30;//1E
const int resta			=31;//1F
const int divide		=32;//20
const int multiplica	=33;//21
const int bifurca		=40;//28
const int bifurcaneg	=41;//29
const int bifurcacero	=42;//2A
const int alto			=43;//2B
const int DEPURA		=44;//2C
const int modulo		=50;//32
const int ex			=51;//33
void simpletron(int*);
void depura();
int mem[1000];
int main(){
	int registrodeinstruccion;	
	int m=0;
	cout<<"-----BIENVENIDO A SIMPLETRON2.0-----------"<<endl;
	cout<<"-----INTRODUZCA SU INSTRUCCION------------"<<endl;
	cout<<"-----DE 5 DIGITOS Y -99999 PARA TERMINAR--"<<endl;
	cout<<"------------------------------------------"<<endl;
	cout<<"-OPERACIONES INEXISTENTES SERAN IGNORADAS-"<<endl;
	while(mem[m-1]!=-629145){
		if(m<10)
			cout<<0<<m<<'?'<<" ";
		else
			cout<<m<<'?'<<" ";
		cin>>hex>>mem[m];
		if((mem[m]>=-1048575&&mem[m]<=-40960)||(mem[m]<=1048575&&mem[m]>=40960)){
			m++;
		}
	}
	mem[m-1]=0;
	simpletron(mem);
	cout<<"Termino la ejecucion de simpletron";
	return 0;
}
void depura(){
	cout<<"MEMORIA"<<endl;
	cout<<"      00     01     02     03     04     05     06     07     08     09"<<endl;
	for(int i=0;i<1000;i++){
		if(i%10==0||i==0){
			cout<<endl;
			if(i/10<10||i/10>=10&&i/10<16)
				cout<<0;
			cout<<i/10;
		}
		if(mem[i]>=65536)
			cout<<"  "<<hex<<mem[i];
		else if(mem[i]<=-65536)
			cout<<" -"<<hex<<mem[i];		
		else if(mem[i]>=4096)
			cout<<"  0"<<hex<<mem[i];	
		else if(mem[i]<=-4096)
			cout<<" -0"<<hex<<mem[i];	
		else if(mem[i]>=256)
			cout<<"  00"<<hex<<mem[i];	
		else if(mem[i]<=-256)
			cout<<" -00"<<hex<<mem[i];
		else if(mem[i]>=16)
			cout<<"  000"<<hex<<mem[i];
		else if(mem[i]<=-16)
			cout<<" -000"<<hex<<mem[i];
		else if(mem[i]<=-1)
			cout<<" -0000"<<hex<<mem[i];
		else if(mem[i]>=0)
			cout<<"  0000"<<hex<<mem[i];			
	}
	cout<<endl;
}
void simpletron(int *mem){
	int acumulador=0;
	int contadorintruccions=0;
	int depuras;
	while(contadorintruccions<1000){
		int codigodeoperacion;
		int operando;
		int num=*(mem+contadorintruccions);
		int resi=0;
		int l=0;
		while(l<3){
			resi+=num%16*pow(16,l);
			num/=16;
			l++;
		}
		codigodeoperacion=num%16+(num/16)*16;
		operando=resi;
		if(alto==codigodeoperacion){
			depura();
			break;
		}
		if(acumulador>1048575||acumulador<-1048575){
			cout<<"------los resultados excedieron el rango---"<<endl;
			cout<<"-----Ejecucion terminada de manera forzosa-"<<endl;
			break;
		}
		switch(codigodeoperacion){
			case DEPURA:{
				if(operando==1)
					depuras=1;
				if(operando==0)
					depuras=0;
				break;
			}
			case lee:{
				cout<<"ingrese el numero"<<endl;
				cin>>hex>>*(mem+operando);
				if(*(mem+operando)/10000000!=0){
					cout<<"------error dato incorrecto------";
					return;	
				}
				break;
			}
			case escribe:{
				cout<<hex<<*(mem+operando)<<endl;	
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
			case modulo:{
				acumulador%=*(mem+operando);
				break;
			}
			case ex:{
				int number=acumulador;
				for(int i=2;i<=*(mem+operando);i++)
					acumulador*=number;
				break;
			}
			case nline:{
				cout<<endl;
				break;
			}
			default:{
				return;
			}	
		}
		if (depuras==1){
			depura();
		}
		contadorintruccions++;
		
	}
}
