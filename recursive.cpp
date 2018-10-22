#include <iostream>
using namespace std;
int recursivesum(int a[],int len){
	if(len==0){
		return 0;
	}else{
		return a[len-1]+recursivesum(a,len-1);
	}
}
int inv(int a[],int len){
	for(int i=0;i<len/2;i++){
		a[i]=a[i]+a[len-1-i];
		a[len-1-i]=a[i]-a[len-1-i];
		a[i]=a[i]-a[len-1-i];
	}
}
int len(char a[]){
	int c=0;
	while(a[c]!='\0'){
		c=c+1;
	}
	return c;
}
void mayus(char a[]){
	for(int i=0;i<len(a);i++){
		if(a[i]>96 && a[i]<123){
			a[i]=a[i]-32;
		}
	}
}
int main(){
	char a[]={};
	cin>>a;
	int j=0;
	a[0]=a[0]-32;
	cout<<a;
	return 0;
}
