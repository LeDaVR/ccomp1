#include <iostream>
#define LIMIT 2000000
using namespace std;
int a[LIMIT];
int main(){
	long long int sum;
	for(long long int i=0;i<LIMIT;i++)
		a[i]=1;
	long long int b=2;
	while(b<=LIMIT/2){
		long long int mul=2;
		while(b*mul<=LIMIT){
			a[b*mul]=0;
			mul++;
		}
		b++;
	}
	for(long long int m=0;m<LIMIT;m++){
		if(a[m]==1){
			sum=sum+m;
		}
	}
	sum=sum-2;
	cout<<sum;
	return 0;
}
