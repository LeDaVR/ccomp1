#include<iostream>
using namespace std;
int len(char *a){
	int c=0;
	while(*(a+c)!='\0')
		c++;
	return c;
}
void cont(char *a){
	for(int i=0;i<len(a);i++){
		int cont=0;
			for(int j=0;j<len(a);j++){
				if(*(a+j)==*(a+i))
					cont++;
			}
			int cont2=0;
			for(int k=0;k<i;k++)
				if(*(a+k)==*(a+i)){
				 cont2=1;
				 break;
				}
			if(cont2==0)
				cout<<*(a+i)<<" esta "<<cont<<" veces "<<endl;
	}
}
int main(){
	char a[]="holaoooooo";
	cont(a);
	return 0;
}
