#include <iostream>
using namespace std;
int main(){
	unsigned int a=1;
	unsigned int b=1;
	unsigned int c;
	unsigned int contador=0;
	for(unsigned int i=2;;i++){
		if(c<=4000000){
			c=a+b;
			a=b;
			b=c;
			if(c%2==0){
				contador=contador+c;
			}
		}else{break;
		}
	}
	cout << contador;
	return 0;
}
