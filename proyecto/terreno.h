#ifndef TERRENO_H
#define TERRENO_H

#include "movimiento.h"


//----------------------------------------------------------------------------
class Inventario : public Menu{
	private:
		sf::Font fuente;
		sf::Text texto;
		AutoSprite fondo;
		AutoSprite select;
		AutoSprite hacha;
		AutoSprite pala;
		AutoSprite combo;
		AutoSprite regadera;
		AutoSprite vacio;
		int dinero;
		std::string **matriz;
		int factual,cactual;
		

	public:
		Inventario(int,int);
		~Inventario();
	
		void mostrar(sf::RenderWindow&);
		void mostrarinventario(int&,int&);
		void mover(int,int);
		void addItem(AutoSprite autosprite);
		void removecurrentItem();
		void setDinero(int);
		void sell();
		
		int getDinero();
		std::string getselect() const ;
};


//---------------------------------------------------------------------------
class EscenarioPrincipal : public Escena{
	private:
		AutoSprite ppapa;
		AutoSprite pmaiz;
		AutoSprite ptomate;	
		AutoSprite fondo;
		AutoSprite persona;
		AutoSprite casaex;
		AutoSprite tierra;
		AutoSprite minijuegos;
		bool checkTerreno(float,float);
	public:
		EscenarioPrincipal();
		void changeTerreno(Inventario*);
		void nextDay();

};
//----------------------------------------------------------------------
class Tienda : public Menu{
	private:
		AutoSprite fondo;
		AutoSprite select;
		AutoSprite tomate;
		AutoSprite maiz;
		AutoSprite papa;
	public:
		Tienda(int,int);
		AutoSprite comprar(Inventario*);
};
#endif

