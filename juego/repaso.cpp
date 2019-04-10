#include <iostream >
using namespace std;

void burbuja(int arr[]){
	for(int i=0;i<10;i++){
		for(int j=0;j<9;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void insercion(int arr[],int len){
	int pos;
	for(int i=0;i<len;i++){
		pos=i;
		while(pos>0&&arr[pos]<arr[pos-1]){
			int temp=arr[pos];
			arr[pos]=arr[pos-1];
			arr[pos-1]=temp;
			pos--;
		}
	}
}

void intercambiar(int &x, int &y){
	int temp=x;
	x=y;
	y=temp;
}
void quick(int arr[],int min,int max){
	int pivpos,i,j;
	pivpos=(min+max)/2;
	intercambiar(arr[pivpos],arr[max]);
	int piv=arr[max];
	i=min;
	j=max-1;
	
	while(i<=j){
		while(piv>arr[i]){
			i++;
			cout<<"aca"<<endl;
		}
		while(piv<arr[j]){
			j--;	
		}
		if(i<=j){
			intercambiar(arr[i],arr[j]);
			i++;
		}
	
	}
	if(piv<arr[i]){
		intercambiar(arr[max],arr[i]);
	}
	i++;
	if(min<j){
		quick(arr,min,j);
	}
	if(max>i){
		quick(arr,i,max);
	}
		
}

int maxdig(int arr[],int tam){
	int max=arr[0];
	int dig=0;
	for(int i=0;i<tam;i++){
		if(arr[i]>max)
			max=arr[i];
	}
	while(max>0){
		dig++;
		max/=10;
	}
	return dig;
}

/*void sort(int arr[],int tam){
	int max
}
void radix(int arr[],int tam){
	int comprobar=1;
	
	int radixlist[]
	for(int i=1;i<=dig;i++){

	}
}*/

void multiplicacion(int m1[20][20],int f1,int c1,int m2[20][20],int f2,int c2,int m3[20][20]){
	if (c1==f2){
		for(int i=0;i<f1;i++){
			for(int j=0;j<c2;j++){
				m3[i][j]=0;
				for(int k=0;k<c1;k++){
					m3[i][j]+=m1[i][k]*m2[k][j];
				}
			}
		}
	}
}

int main()
{
	/*int arr[10]={5,3,4,6,9,2,1,8,7,10};/*
	cout<<(5+6)/2<<endl;
	//burbuja(arr);
	//insercion(arr,10);
	quick(arr,0,9);
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}*/
	int arr[20][20]={2,3,4};
	arr[1][0]=8;
	arr[1][1]=9;
	arr[1][2]=6;	
	int arr2[20][20]={2,9};
	arr2[1][0]=6;
	arr2[1][1]=7;
	arr2[2][0]=5;
	arr2[2][1]=3;
	int arr3[20][20]={};
	multiplicacion(arr,2,3,arr2,3,2,arr3);
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cout<<arr3[i][j]<<" ";
		}
		cout<<endl;
	}
}

