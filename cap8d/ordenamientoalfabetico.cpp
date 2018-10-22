#include<iostream>
using namespace std;
/*primero recorremos las palabras con un for luego la comparamos con cada una de las palabras con otro for y finalmente comparamos las letras con otro for*/
int maylen(string a,string b){
	int c=0;
	int d=0;
	while(a[c]!='\0')
		c++;
	while(b[d]!='\0')
		d++;
	if(d>=c)
		return c;
	return d;
}
void ordenar(string *b,int tam){
	for(int i=0;i<tam;i++){
		for(int j=i+1;j<tam;j++){
			string fir=*(b+i);
			string sec=*(b+j);
			int cont=0;
			while(fir[cont]==sec[cont]){
				cont++;
			}
			if(fir[cont]>sec[cont]){
			*(b+i)=sec;
			*(b+j)=fir;
			}
		}			
		}
	cout<<endl;
	}
int main(){
	int b;
	cout<<"cantidad de palabras (menor que 20)"<<endl;
	cin>>b;
 	string a[]={"","","","","","","","","","","","","","","","","","","",""};
	for(int i=0;i<b;i++){
		cin>>*(a+i);
	}
 	ordenar(a,b);
 	for(int i=0;i<b;i++)	
 		cout<<a[i]<<endl;
 	return 0;
}
