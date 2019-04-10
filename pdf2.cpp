#include <iostream>
#include <math.h>
#include<stdlib.h>
using namespace std;

/*int sum( const int numbers [] , const int numbersLen ){
	int sum=0;
	for(int i=0;i<numbersLen ;++i){
		sum+=numbers [i];
	}
	return sum;
}*/
//4.6 [8 points]

int sum( const int numbers[], const int numbersLen) {
	 return numbersLen == 0 ? 0 : numbers[0] + sum(numbers + 1, numbersLen -1);
}





//6.1 [4 points]
void printArray ( const int arr [],const int len ){
	for(int i =0;i<len;++i){
		cout<<arr [i];
		if(i<len -1){
		cout<<",";
		}
	}
}

//6.5 [3 points]
void reverse(int numbers[], const int numbersLen) {
	for(int i = 0; i < numbersLen / 2; ++i) {
		int tmp = *(numbers + i);
		int indexFromEnd = numbersLen -i -1;
		*(numbers + i) = *(numbers + indexFromEnd);
		*(numbers + indexFromEnd) = tmp;
	}
}

int main(){
	//5.2 [6 points]
	int dartsInCircle = 0;
	int n=5;
	for(int i= 0; i<n; ++i) {
		double x = rand() / (double )RAND_MAX, y = rand() / (double )RAND_MAX; 
		if( sqrt(x*x + y*y) < 1 ) {
			++dartsInCircle;
		}
	}
}
