#include <iostream>
using namespace std;
class Motor{
	public:
		Motor(){}
		virtual void encender()=0;
		virtual void acelerar()=0;
		virtual void apagar()=0;
};

class Motorcomun : public Motor{
	public:
	Motorcomun(){
		cout<<"creando motor comun"<<endl;
	}
	void encender(){
		cout<<"encendiendo motor comun"<<endl;	
	}
	void acelerar(){
		cout<<"acelerando motor comun"<<endl;
	}
	void apagar(){
		cout<<"apagando motor comun"<<endl;
	}
};

class Motoreconomico : public Motor{
	public:
	Motoreconomico(){
		cout<<"creando motor economico"<<endl;
	}
	void encender(){
		cout<<"encendiendo motor economico"<<endl;	
	}
	void acelerar(){
		cout<<"acelerando motor economico"<<endl;
	}
	void apagar(){
		cout<<"apagando motor economico"<<endl;
	}
};

class Motorelectrico{
	private:
		bool conectado;
	public:
		Motorelectrico(){
			cout<<"creando motor electrico"<<endl;
			conectado=false;
		}
		void conectar() {
		    cout<<"Conectando motor electrico"<<endl;
		    this->conectado = true;
		}
		
		void activar() {
		    if (conectado==false) {
		       cout<<"nose puede activar porque no esta conectado el motor electrico"<<endl;
		    } else
		        cout<<"Esta conectado, activando motor electrico"<<endl;
		}
		
		void moverMasRapido() {
		    if (conectado==false) {
		       cout<<"el motor electrico porque no esta conectado..."<<endl;
		    } else {
		        cout<<"Moviendo mas rapido...aumentando voltaje"<<endl;
		    }
		}
		
		void detener() {
		    if (conectado==false) {
		        cout<<"No se puede detener motor electrico porque no esta conectado"<<endl;
		    } else
		        cout<<"Deteniendo motor electrico"<<endl;
		}
		
		void desconectar() {
		    cout<<"Desconectando motor electrico"<<endl;
		    this->conectado = false;
		}
};

class MotorelectricoAdapter : public Motor{
	private:
		Motorelectrico motorelectrico;
	public:
		void encender(){
			motorelectrico.conectar();
			motorelectrico.activar();
		}
		void acelerar(){
			motorelectrico.moverMasRapido();
		}
		void apagar(){
			motorelectrico.detener();
			motorelectrico.desconectar();
		}
};
int main(){
	Motorcomun motorcomun;
	motorcomun.encender();
	motorcomun.acelerar();
	motorcomun.apagar();
	
	MotorelectricoAdapter electrico;
	electrico.encender();
	electrico.acelerar();
	electrico.apagar();
}

