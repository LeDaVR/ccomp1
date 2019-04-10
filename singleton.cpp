#include <iostream>
using namespace std;

class Unico{
	Unico(){}
	public:
		Unico& Instancia(){
			static Unico instancia;
			return instancia;
		}
		void funca(){
			cout<<"adsasasdad"<<endl;
		}
};
int main(){
	Unico& c= c.Instancia();
	c.funca();
	Unico& d= d.Instancia();
	return 0;
}
