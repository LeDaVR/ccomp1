#include <iostream>
#include <math.h>
using namespace std;
int main(){
	long int ac;
	long int a=999;
	long int b=999;
	for(a;a>=100;a--){
		for(b;b>=100;b--){
			unsigned long int c=a*b;
			unsigned long int w=c;
			unsigned long int cs=0;
			while(w>0){
				cs=cs+w%10;
				cs=cs*10;
				w=w/10;
			}
			cs=cs/10;
			if(cs==c && c>=ac){
				ac=c;
			}
		}
		b=999;
	}
	cout <<ac;
}
