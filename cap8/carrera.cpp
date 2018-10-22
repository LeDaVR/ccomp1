#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
void col(int i,int j){
	if(i==j)
		cout<< "BOOM!!"<<endl; 
}
void movtor(char *b,int *i,int realidad){
	int m=rand()%realidad+1;
	if(m>9)
	m=m%10;
	*(b+*i)='T';
	if(m<6){
		*(b+*i)='_';
		*i+=3;
		if(*i<=69)
			*(b+*i)='T';
		else
			*(b+69)='T';
	
	}
	if(m>8){
		*(b+*i)='_';
		if(*i>5){
			*i-=6;
			*(b+*i)='T';
		}else{
			*i=0;
			*(b+*i)='T';
		}	
	}
	if(m>5&&m<9){
		*(b+*i)='_';
		*i+=1;
		if(*i<=69)
			*(b+*i)='T';
		else
			*(b+69)='T';

	}
}
void movcon(char *b,int *i, int realidad){
	int m=rand()%realidad+1;
	if(m>9)
	m=m%10;
	*(b+*i)='L';
	if(m>0&&m<3){
		*(b+*i)='_';
		*i+=9;
		if(*i<=69)
			*(b+*i)='L';
		else
			*(b+69)='L';
	
	}
	if(m>2&&m<6){
		*(b+*i)='_';
		*i+=1;
		if(*i<=69)
			*(b+*i)='L';
		else
			*(b+69)='L';

	}
	if(m>5&&m<8){
		*(b+*i)='_';
		if(*i>1){
			*i-=2;
			*(b+*i)='L';
		}else{
			*i=0;
			*(b+*i)='L';
		}	
	}
	if(m==8){
		*(b+*i)='_';
		if(*i>11){
			*i-=12;
			*(b+*i)='L';
		}else{
			*i=0;
			*(b+*i)='L';
		}	
	}
			
}
int main()
{
	char a[70];
	char b[70];
	int conejo=0;
	int tortuga=0;
	int realidad;
	cout<<"escoja un numero para empezar"<<endl;
	cin>>realidad;
	a[0]='L';
	b[0]='T';
	for(int i=1;i<70;i++){
		*(a+i)='_';
		*(b+i)='_';
	}
	cout<<a<<endl;
	cout<<b<<endl;
	int i=clock()/500;
	cout<<"BANG !!!!!"<<endl<<"THEY'RE OFF !!!!!"<<endl;
    while(*(b+69)=='_'&&a[69]=='_'){
    	while(clock()<1000*i){
		}
		movtor(a,&tortuga,realidad);
		movcon(b,&conejo,realidad);
		i++;
		cout<<a<<endl;
		cout<<b<<endl;
		cout<<endl;
		col(tortuga,conejo);
	}
	if(a[69]!='_')
		cout<<"GANADOR LA TORTUGA"<<endl;
	else
		cout<<"GANADOR LA LIEBRE"<<endl;
    return 0;
}
