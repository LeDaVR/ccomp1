#include<iostream>
using namespace std;
int len(char x[]){
	int a=0;
	while(x[a]!='\0'){
		a++;
	}
	return a;
}
int main(){
	char a[]={};
	cin>> a;
	cout<< len(a);
	cout<< a[4];
	return 0;

}
