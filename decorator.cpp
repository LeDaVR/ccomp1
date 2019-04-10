#include <iostream>

class TiendaAbstracta{
    public:
       
        virtual void mostrar() = 0;
};


class Tienda : public TiendaAbstracta{
    public:   
        void mostrar()
        {
            std::cout << " Tienda ";
        }
};


class Tiendadecorator : public TiendaAbstracta
{
	protected:
        TiendaAbstracta* _tiendaAbstracta;
    public:
        Tiendadecorator(TiendaAbstracta* tiendaAbstracta)
        {
            _tiendaAbstracta = tiendaAbstracta;
        }
        
        virtual void mostrar() = 0;
        
    
};

class BordeDecorator : public Tiendadecorator
{
    public:
        BordeDecorator(TiendaAbstracta* tiendaAbstracta) : Tiendadecorator(tiendaAbstracta){}
        
        virtual void mostrar()
        {
            std::cout << "|";
            _tiendaAbstracta->mostrar();
            std::cout << "|";
        }
};

class BotonDeAyuda : public Tiendadecorator
{
    public:
        BotonDeAyuda(TiendaAbstracta* tiendaAbstracta) : Tiendadecorator (tiendaAbstracta){}
        
        virtual void mostrar()
        {
            _tiendaAbstracta->mostrar();
            std::cout << "[Boton de Ayuda]";
        }
};

int main()
{
	Tienda* tienda;
	tienda = new Tienda;
	
    BotonDeAyuda tiendaconbotondeayuda(tienda);
    tiendaconbotondeayuda.mostrar();
    std::cout << std::endl;

    BordeDecorator ventanaConBotonDeAyudaYBorde(&tiendaconbotondeayuda);
    ventanaConBotonDeAyudaYBorde.mostrar();
    std::cout << std::endl;
    tienda->mostrar();
        
    return 0;
}
