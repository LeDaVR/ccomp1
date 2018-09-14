#include <iostream>
using namespace std;
int div(int x){
	int c=0;
	for(int i=1;i<=x;i++){
		c=c+i;
	}
	return c;
}
int main(){
	int a;cin>>a;
	cout<<div(a);
	main();
	return 0;
}
