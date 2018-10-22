#include <iostream>
using namespace std;
bool ascendente(int a,int b){
	return a>b;
}
bool descendente(int a,int b){
	return a<b;
}
void ordenamiento(int *a,int len,bool (*funpo) (int,int)){
	for(int i=0;i<len;i++)
		for(int j=i+1;j<len;j++){
			if((*funpo) (*(a+i),*(a+j))){
				int temp=*(a+i);
				*(a+i)=*(a+j);
				*(a+j)=temp;
			}
		}
}
int main(){
	int array[10]={9,8,7,4,5,6,1,2,3,10};
	ordenamiento(array,10,descendente);
	for(int i=0;i<10;i++)
		cout<<*(array+i)<<" ";
	return 0;
}
