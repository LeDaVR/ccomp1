#include "SFML/Graphics.hpp"

using namespace sf;

class AutoSprite{

private:

    Texture textura;
    Sprite sprite;
    
    std::string imagen;
    Color color;
    Vector2f posicion;
    Vector2f dimensiones;

public:

	AutoSprite();
    AutoSprite(std::string);
    void ajustarPosicion(float,float);
    void escalar(float,float);
    void cambiarColor(int,int,int,int);
	void setImagen(std::string);
	void pseudoDimensiones(float,float);
	
    Texture getTexture();
    Sprite getSprite();
    std::string getImagen();
    float getTamanio(char);
    float getPosicion(char);
} ;
