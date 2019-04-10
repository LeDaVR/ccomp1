#include "terreno.h"
#include <sstream>
//---------------------------------------------------CLASS INVENTARIO

//constructor de inventario
Inventario::Inventario(int f,int c): Menu(f,c){

	fuente.loadFromFile("coolveticarg.ttf");
	texto.setFont(fuente);
	factual=0;
	cactual=0;
	dinero=1000;
	matriz = new std::string*[f];
	for(int i=0;i<f;i++)
		matriz[i]=new std::string[c];
	for(int i=0;i<f;i++)
		for(int j=0;j<c;j++)
			matriz[i][j]=" ";
	regadera.setImagen("img/regadera.png");regadera.ajustarPosicion(50+600,25);regadera.escalar(100,100);
	pala.setImagen("img/pala.png");pala.ajustarPosicion(50+400,25);pala.escalar(100,100);
	hacha.setImagen("img/hacha.png");hacha.ajustarPosicion(50,25);hacha.escalar(100,100);
	combo.setImagen("img/combo.png");combo.ajustarPosicion(50+200,25);combo.escalar(100,100);
	fondo.setImagen("img/invmenu.jpg");
	select.setImagen("img/SELECCIONAR.png");
	select.escalar(100,100);
	select.ajustarPosicion(50,25);
	vacio.setImagen(" ");vacio.escalar(100,100);
	addSprite(fondo);
	addSprite(hacha);     matriz[0][0]=hacha.getImagen();
	addSprite(combo);     matriz[0][1]=combo.getImagen();
	addSprite(pala);      matriz[0][2]=pala.getImagen();
	addSprite(regadera);  matriz[0][3]=regadera.getImagen();
	for(int i=1;i<filas;i++)
		for(int j=0;j<columnas;j++){
				matriz[i][j]=vacio.getImagen();
				vacio.ajustarPosicion(50+200*j,25+150*i);
				addSprite(vacio);
		}
	addSprite(select);
}

void Inventario::mostrar(sf::RenderWindow& a){
	a.clear();
	for(int i=0;i<size;i++)
		a.draw(escena[i].getSprite());
	std::ostringstream ss;
	ss<<dinero;
	texto.setString("DINERO: "+ss.str());
	a.draw(texto);
	a.display();
}
//cambia el escenario al inventario
void Inventario::mostrarinventario(int &escenario,int &escenariotemp){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		escenariotemp=escenario;
		escenario=3;		
	}
}

//mover inventario
void Inventario::mover(int velocidadx,int velocidady){
	int x=escena[size-1].getPosicion('X');
	int y=escena[size-1].getPosicion('Y');
	int fx=escena[1].getPosicion('X');
	int fy=escena[1].getPosicion('Y');
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&y>fy){
			y-=velocidady;
			escena[size-1].ajustarPosicion(x,y);
			factual--;
			Tiempo::esperarSeg(0.3);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&y<fy+velocidady*(filas-1)){
			y+=velocidady;	
			escena[size-1].ajustarPosicion(x,y);
			factual++;
			Tiempo::esperarSeg(0.3);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&x>fx){
			x-=velocidadx;
			escena[size-1].ajustarPosicion(x,y);
			cactual--;
			Tiempo::esperarSeg(0.3);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&x<fx+velocidadx*(columnas-1)){
			x+=velocidadx;	
			escena[size-1].ajustarPosicion(x,y);
			cactual++;
			esperarSeg(0.3);
	}
}

//aniadir objeto al inventario
void Inventario::addItem(AutoSprite item){
	AutoSprite iditem=item;
	iditem.escalar(100,100);
	for(int i=1;i<filas;i++)
		for(int j=0;j<columnas;j++)
			if(matriz[i][j]==" "){
				matriz[i][j]=iditem.getImagen();
				iditem.ajustarPosicion(50+200*j,25+150*i);
				escena[4*i+j+1]=iditem;	
				return;
			}
}
void Inventario::setDinero(int _dinero){
	dinero=_dinero;
}
int Inventario::getDinero(){
	return dinero;
}

//seleccion actual

std::string Inventario::getselect()const{
	return matriz[factual][cactual];
}

void Inventario::removecurrentItem(){
	matriz[factual][cactual]=" ";
	int spriteactual=(4*factual)+cactual+1;
	AutoSprite transparente("img/transparente.png");
	escena[spriteactual].setImagen(transparente.getImagen());
}

void Inventario::sell(){
	std::string currentimg=matriz[factual][cactual];
	if(currentimg=="img/ppapa.png"||currentimg=="img/ptomate.png"||currentimg=="img/pmaiz.png"){
		removecurrentItem();
		dinero+=300;
	}
}
//destructor
Inventario::~Inventario(){
	for(int i=0;i<filas;i++)
		delete[] matriz[i];
	delete[] matriz;
}

//----------------------------------------------------CLASS ESCENARIOPRINCIPAL

//constructor
EscenarioPrincipal::EscenarioPrincipal() : Escena(){
	ppapa.setImagen("img/ppapa.png");
	pmaiz.setImagen("img/pmaiz.png");
	ptomate.setImagen("img/ptomate.png");
	fondo.setImagen("img/fondo.jpg");
	persona.setImagen("img/0dpersona.png");
	casaex.setImagen("img/casaex.jpg");
	tierra.setImagen("img/0dtierra.jpg");
	minijuegos.setImagen("img/carreraFachada.png");
	fondo.escalar(1200,1200);
	persona.escalar(50,100);
    persona.ajustarPosicion(600,200);
    casaex.ajustarPosicion(700,0);
    casaex.escalar(500,300);
	minijuegos.escalar(150,200);
	minijuegos.ajustarPosicion(1050,1000);
    addSprite(fondo);
    addSprite(casaex);
	addSprite(minijuegos);
    addSprite(persona);
    for(int i=0;i<6;i++)
    	for(int j=0;j<6;j++){
    		tierra.ajustarPosicion(j*100,600+i*100);
    		posicionarSprite(tierra,size-1);
		}
}

//interaccion del terreno
void EscenarioPrincipal::changeTerreno(Inventario* inv){
	std::string img=inv->getselect();
	std::string imgparcela;
	int pos=1;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			pos++;
			imgparcela=escena[pos+1].getImagen();
			if(checkTerreno(i,j)){
				if(img=="img/combo.png"){
					escena[1+pos].setImagen("img/0dtierra.jpg");
					escena[1+pos].pseudoDimensiones(0,0);
				}
				if(img=="img/pala.png"&&imgparcela=="img/0dtierra.jpg")
					escena[1+pos].setImagen("img/ds0tierra.jpg");

				if(img=="img/regadera.png"&&imgparcela[5]=='s'&&imgparcela[6]<51){
					imgparcela[5]='m';
					escena[1+pos].setImagen(imgparcela);
				}
				if(imgparcela[4]=='d'&&(img=="img/papa.png"||img=="img/tomate.png"||img=="img/maiz.png")){
					imgparcela[4]=img[4];
					escena[1+pos].setImagen(imgparcela);
					inv->removecurrentItem();
				}
				if(img=="img/hacha.png"&&imgparcela[6]=='3'){
					if(imgparcela[4]=='m')
						inv->addItem(pmaiz);
					else if(imgparcela[4]=='t')
						inv->addItem(ptomate);
					else if(imgparcela[4]=='p')
						inv->addItem(ppapa);
					escena[1+pos].setImagen("img/0dtierra.jpg");
					escena[1+pos].pseudoDimensiones(0,0);
				}
			}
		}
	}
}
bool EscenarioPrincipal::checkTerreno(float i,float j){
	std::string direccion=escena[size-1].getImagen();
	int x1=50;
	int x2=110;
	int y1=550;
	int y2=610;
	std::string direcciones="lrud";
	for(int m=0;m<4;m++){
		char dactual=direcciones[m];
		if(m==1){
			x1=-90;x2=-50;
		}
		if(m==2){
			x1=0;x2=50;y1=650;y2=710;
		}
		if(m==3){
			y1=490;y2=550;
		}
		if(checkPosition(j*100+x1,j*100+x2,y1+i*100,y2+i*100)&&
		   dactual==direccion[5])
	  		return true;
	}
	return false;
}

void EscenarioPrincipal::nextDay(){
	std::string posimg;
	int pos=1;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			pos++;
			posimg=escena[pos+1].getImagen();
			if(posimg=="img/dm0tierra.jpg")
				escena[pos+1].setImagen("img/ds0tierra.jpg");
			else if(posimg[5]=='m'){
				posimg[5]='s';
				if(posimg[6]=='0'){
					escena[pos+1].pseudoDimensiones(100,100);
					posimg[6]='1';
				}
				else if(posimg[6]=='1')
					posimg[6]='2';
				else if(posimg[6]=='2')
					posimg[6]='3';
				escena[pos+1].setImagen(posimg);
			}
				
		}
	}
}

//-------------------------------------------------CLASS TIENDA

//constructor de tienda
Tienda::Tienda(int filas,int columnas) : Menu(filas,columnas){
	fondo.setImagen("img/fondotienda.jpg");
	select.setImagen("img/SELECCIONAR.png");
	tomate.setImagen("img/tomate.png");
	papa.setImagen("img/papa.png");
	maiz.setImagen("img/maiz.png");
	tomate.ajustarPosicion(100,480);
	papa.ajustarPosicion(300,480);
	maiz.ajustarPosicion(500,480);
	tomate.escalar(100,100);
	papa.escalar(100,100);
	maiz.escalar(100,100);
	select.ajustarPosicion(100,480);
	select.escalar(100,100);
	addSprite(fondo);
	addSprite(tomate);
	addSprite(papa);
	addSprite(maiz);
	addSprite(select);
}


//retorna el autosprite comprado
AutoSprite Tienda::comprar(Inventario* inv){
	for(int i=1;i<size-1;i++){
		if(escena[size-1].getPosicion('X')==escena[i].getPosicion('X')&&inv->getDinero()>=200){
			inv->setDinero(inv->getDinero()-200);
			return escena[i];
		}
	}
	AutoSprite vacio(" ");
	return vacio;
}


