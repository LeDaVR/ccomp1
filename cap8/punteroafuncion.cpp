#include <iostream>
using namespace std;
void ascendente(int *a,int len){
	for(int i=0;i<len;i++)
		for(int j=i+1;j<len;j++){
			if(*(a+i)>*(a+j)){
				int temp=*(a+i);
				*(a+i)=*(a+j);
				*(a+j)=temp;
			}
		}
}
void descendente(int *a,int len){
	for(int i=0;i<len;i++)
		for(int j=i+1;j<len;j++){
			if(*(a+i)<*(a+j)){
				int temp=*(a+i);
				*(a+i)=*(a+j);
				*(a+j)=temp;
			}
		}
}
int main(){
	int array[10]={9,8,7,4,5,6,1,2,3,10};
	void (*funpo) (int *,int);
	cout<<"ordenamiento descendente o ascendente"<<endl;
	string b;
	cin>>b;
	if(b=="ascendente"){
		funpo=ascendente;
	}else
		funpo=descendente;
	funpo(array,10);
	for(int i=0;i<10;i++)
		cout<<*(array+i)<<" ";
	return 0;
}
