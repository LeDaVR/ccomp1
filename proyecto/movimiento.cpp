#include "movimiento.h"
#include <SFML/Audio.hpp>


Clock reloj;

//----------------------------------------------------------------CLASS SPRITEARRAY
//constructor defecto
SpriteArray::SpriteArray(){
	size=0;
	escena=new AutoSprite[size];

}

//constructor argumento
SpriteArray::SpriteArray(const SpriteArray &_escena){
	size=_escena.getSize();
	escena=new AutoSprite[size];
	for(int i=0;i<size;i++)
		escena[i]=_escena.escena[i];
}

//destructor
SpriteArray::~SpriteArray(){
	delete[] escena;
}

// redimensionar
void SpriteArray::redimensionar(const int _size){
		AutoSprite *temp=new AutoSprite[_size];
		int minsize=(_size>size)?size:_size;
		for(int i=0;i<minsize;i++)
			temp[i]=escena[i];
		delete[] escena;
		escena=temp;
		size=_size;
}

//aniadir
void SpriteArray::addSprite(AutoSprite autosprite){
	redimensionar(size+1);
	escena[size-1]=autosprite;
	
}

//aniadir en una posicion
void SpriteArray::posicionarSprite(const AutoSprite autosprite,const int pos){
	redimensionar(size+1);
	for(int i=size-1;i>pos;i--)
		escena[i]=escena[i-1];
	escena[pos]=autosprite;
}

//remover 
void SpriteArray::removeSprite(const int pos){
	for(int i=pos;i<size-1;i++)
		escena[i]=escena[i+1];
	redimensionar(size-1);
}

//ajustar vista
void SpriteArray::setview(sf::RenderWindow&a,int objeto){
	sf::View view(sf::Vector2f(350.f, 300.f), sf::Vector2f(640.f,480.f));
	int centerx=escena[objeto].getPosicion('X')+escena[objeto].getTamanio('X')/2;
	int centery=escena[objeto].getPosicion('Y')+escena[objeto].getTamanio('Y')/2;
	view.setCenter(sf::Vector2f(centerx,centery));
	a.setView(view);
}

//mostrar 
void SpriteArray::mostrar(sf::RenderWindow &a){
	a.clear();
	for(int i=0;i<size;i++)
		a.draw(escena[i].getSprite());
	a.display();
}

bool SpriteArray::checkPosition(int x1,int x2,int y1,int y2){
	if(escena[size-1].getPosicion('X')>x1&&
	   escena[size-1].getPosicion('X')<x2&&
	   escena[size-1].getPosicion('Y')>y1&&
	   escena[size-1].getPosicion('Y')<y2)
		return true;
	return false;
}

//size
int SpriteArray::getSize()const {
	return size;
}
//--------------------------------------------------------------CLASS ESCENA

Escena::Escena() : SpriteArray(){
	aux=0;
	velocidadMov=10; // a menor numero mas velocidad
}

bool Escena::basecolision1(AutoSprite a,int cantidad,char eje){
	char eje2;
	if(eje=='X')
		eje2='Y';
	else if(eje=='Y')
		eje2='X';
	for(int j=1;j<size;j++){
		if(escena[j].getTamanio('X')==0&&escena[j].getTamanio('Y')==0)
			continue;
		int arrx[5],x=0;
		for(int i=0;i<5;i++){
			arrx[i]=a.getTamanio(eje2)*i/4+a.getPosicion(eje2);
			if(arrx[i]>=escena[j].getPosicion(eje2)&&arrx[i]<=escena[j].getPosicion(eje2)+escena[j].getTamanio(eje2)&&&escena[j]!=&a)
				x++;
		}
		int aux1=a.getPosicion(eje)-cantidad;
		int aux2=escena[j].getPosicion(eje)+escena[j].getTamanio(eje);
		int aux3=a.getPosicion(eje)+a.getTamanio(eje);
		int aux4=escena[j].getTamanio(eje)+escena[j].getPosicion(eje);
		if(x>0&&aux1<=aux2&&aux3>aux4||a.getPosicion(eje)<escena[0].getPosicion(eje))
			return false;
	}
	return true;
}

bool Escena::basecolision2(AutoSprite a,int cantidad,char eje){
	char eje2;
	if(eje=='X')
		eje2='Y';
	else if(eje=='Y')
		eje2='X';
	for(int j=1;j<size;j++){
		if(escena[j].getTamanio('X')==0&&escena[j].getTamanio('Y')==0)
			continue;
		int arrx[5],x=0;
		for(int i=0;i<5;i++){
			arrx[i]=a.getTamanio(eje2)*i/4+a.getPosicion(eje2);
			if(arrx[i]>=escena[j].getPosicion(eje2)&&arrx[i]<=escena[j].getPosicion(eje2)+escena[j].getTamanio(eje2)&&&escena[j]!=&a)
				x++;
		}
		int aux1=a.getPosicion(eje)+a.getTamanio(eje)+cantidad;
		int aux2=escena[j].getPosicion(eje);
		int aux3=a.getPosicion(eje);
		int aux4=escena[j].getPosicion(eje);
		if(x>0&&aux1>=aux2&&aux3<aux4||a.getPosicion(eje)+a.getTamanio(eje)>escena[0].getPosicion(eje)+escena[0].getTamanio(eje))
			return false;				
	}
	return true;
}

bool Escena::rightcolision(AutoSprite a,int cantidad){
	return Escena::basecolision2(a,cantidad,'X');
}
bool Escena::leftcolision(AutoSprite a,int cantidad){
	return basecolision1(a,cantidad,'X');
}
bool Escena::upcolision(AutoSprite a,int cantidad){
	return basecolision1(a,cantidad,'Y');
}
bool Escena::downcolision(AutoSprite a,int cantidad){
	return basecolision2(a,cantidad,'Y');
}

//mover personaje
void Escena::mover(int velocidadx,int velocidady){
	int x=escena[size-1].getPosicion('X');
	int y=escena[size-1].getPosicion('Y');
	std::string img =escena[size-1].getImagen();

	if(aux<velocidadMov){
		img[4]='1';
	}
	else if (aux<velocidadMov*2){
		img[4]='2';
	}
	else if (aux<velocidadMov*3){
		img[4]='0';
	}
	else{
		aux=0;
	}	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&upcolision(escena[size-1],velocidady)){
		y-=velocidady;
		escena[size-1].ajustarPosicion(x,y);
		img[5]='u';
		escena[size-1].setImagen(img);
		aux++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&downcolision(escena[size-1],velocidady)){
		y+=velocidady;	
		escena[size-1].ajustarPosicion(x,y);
		img[5]='d';
		escena[size-1].setImagen(img);
		aux++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&leftcolision(escena[size-1],velocidadx)){
		x-=velocidadx;
		escena[size-1].ajustarPosicion(x,y);		
		img[5]='l';
		escena[size-1].setImagen(img);
		aux++;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&rightcolision(escena[size-1],velocidadx)){
		x+=velocidadx;	
		escena[size-1].ajustarPosicion(x,y);
		img[5]='r';
		escena[size-1].setImagen(img);
		aux++;
	}
}


// clase Carrera ------------------
Carrera::Carrera(){
	fondo.setImagen("img/fondocarrera.jpg");
	tronco.setImagen("img/tronco.png");
	aguila.setImagen("img/aguila.jpg");
	cuy.setImagen("img/0rvenado.png");
	fondo.escalar(3000,480);
	tronco.escalar(60,50);
	tronco.ajustarPosicion(600,430);
	aguila.escalar(250,150);
	aguila.ajustarPosicion(400,200);
	cuy.escalar(110,65);
	cuy.ajustarPosicion(0,415);
	addSprite(fondo);
	addSprite(tronco);
	addSprite(aguila);
	addSprite(cuy);
}

void Carrera::moverAguila(int velocidad){
	int y = escena[2].getPosicion('Y');
	int x = escena[2].getPosicion('X')-velocidad;
	escena[2].ajustarPosicion(x,y);	
}

void Carrera::setviewcuy(sf::RenderWindow&a){
	sf::View view(sf::Vector2f(150.f,480.f), sf::Vector2f(640.f,480.f));
	view.setCenter(sf::Vector2f(escena[3].getPosicion('X')+200,240));
	a.setView(view);
}

void Carrera::movercuy(int numero,int velocidady,sf::RenderWindow &a){
	int x=escena[3].getPosicion('X')+numero;
	int y=escena[3].getPosicion('Y');
	std::string img=escena[3].getImagen();
	if(aux<velocidadMov){
		img[4]='1';
	}
	else if (aux<velocidadMov*2){
		img[4]='2';
	}
	else if (aux<velocidadMov*3){
		img[4]='0';
	}
	else{
		aux=0;
	}	
	if(rightcolision(escena[3],1)){
		escena[3].ajustarPosicion(x,y);
		escena[3].setImagen(img);
		aux++;
	}

	if(escena[3].getPosicion('X')>=1600)
		escena[3].ajustarPosicion(200,y);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			for(int i=0;i<10;i++){
				y-=velocidady+i;
				x+=8;
				escena[3].ajustarPosicion(x,y);	
				setviewcuy(a);
					int b=i;
				mostrar(a);
			}
			for(int i=0;i<10;i++){
				y+=velocidady+i;
				x+=8;
				escena[3].ajustarPosicion(x,y);
				setviewcuy(a);
				mostrar(a);
			}
	}
}


//------------------------------------------------------CLASS MENU

//constructor
Menu::Menu(){
	filas=0;
	columnas=0;
}
Menu::Menu(int filas,int columnas){
	setTam(filas,columnas);
}
void Menu::setTam(int filas,int columnas){
	this->filas=filas;
	this->columnas=columnas;
}
//mover menu
void Menu::mover(int velocidadx,int velocidady){
	int x=escena[size-1].getPosicion('X');
	int y=escena[size-1].getPosicion('Y');
	int fx=escena[1].getPosicion('X');
	int fy=escena[1].getPosicion('Y');
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&y>fy){
			y-=velocidady;
			escena[size-1].ajustarPosicion(x,y);
			Tiempo::esperarSeg(0.4);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&y<fy+velocidady*(filas-1)){
			y+=velocidady;	
			escena[size-1].ajustarPosicion(x,y);
			Tiempo::esperarSeg(0.4);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&x>fx){
			x-=velocidadx;
			escena[size-1].ajustarPosicion(x,y);
			Tiempo::esperarSeg(0.4);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&x<fx+velocidadx*(columnas-1)){
			x+=velocidadx;	
			escena[size-1].ajustarPosicion(x,y);
			Tiempo::esperarSeg(0.4);
	}
}


//--------------CLASS TIEMPO
Tiempo::Tiempo(){
	tiempo = new Time;
	*tiempo = reloj.getElapsedTime();
}

Tiempo::~Tiempo(){
	delete tiempo;
}

float Tiempo::getTime(){ // todo esto para que salga 1.1 osea un decimal :v
	float temp=tiempo->asSeconds();
	temp =temp *100000;
	int a = temp/100000;
	temp = temp-(a*100000);
	int b = temp/10000;
	temp = a+b*0.1;
	return temp;
}

void Tiempo::setTime(){
	*tiempo = reloj.getElapsedTime();
}

void Tiempo::esperarSeg(float tiemp){
	*tiempo = reloj.getElapsedTime() ;
	float aux = getTime()+tiemp;

		while(getTime() < aux){

			*tiempo = reloj.getElapsedTime() ;
		}
}




