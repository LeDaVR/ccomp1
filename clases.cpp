#include <iostream>
using namespace std;
class punto{
	private:
		int x,y;
	public:
		punto(int,int);
		void setpunto(int,int);
		void imprimir();
};
punto::punto(int x=0,int y=0){
	this->x=x;
	this->y=y;
}
void punto::setpunto(int x,int y){
	this->x=x;
	this->y=y;
}
void punto::imprimir(){
	cout<<x<<" "<<y<<endl;
}
class arrpunto{
	puntos **a;
	
};
int main(){
	
}

