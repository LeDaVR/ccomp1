#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
int main(/*int argc,char** argv*/)

{
    // Create the main window
    RenderWindow window(VideoMode(640,480,64), "SFML window");
    /*RectangleShape cuadrado;
    Vector2f tamano(50,50);
    cuadrado.setSize(tamano);
    cuadrado.setPosition(100,0);
    cuadrado.setFillColor(Color::Blue);	
    while(window.isOpen()){
    	Event evento;
    	while(window.pollEvent(evento)){
    		switch (evento.type){
    			case Event::Closed:
    				window.close();
    				break;
			}
		}
		window.clear();
		window.draw(cuadrado);
		window.display();
	}*/
    // Load a sprite to display
    Texture texture;
    if (!texture.loadFromFile("img/homero.png")){
        system ("echo no se pudo cargar la textura&pause");
        return EXIT_FAILURE;
    }      
    Sprite sprite1(texture);
    Vector2u textureSize = texture.getSize();
    Sprite sprite2(texture,IntRect(textureSize.x * .1, 0, textureSize.x, textureSize.y));
    //sprite2.setPosition(0,0);
    // Create a graphical text to display
    Font font;
    if (!font.loadFromFile("fuentes/Charlinefont.otf")){
    	system ("echo no se pudo cargar la fuente&pause");
    	return EXIT_FAILURE;
	}   
    Text text("ya esta anuma", font);
    // Load a music to play
    Text text2("una opcion xd",font);
    SoundBuffer buffer;
    if (!buffer.loadFromFile("audio/s1.wav")){
    	system ("echo no se pudo cargar el audio&pause");
    	return EXIT_FAILURE;
	}
    Music music;
    if (!music.openFromFile("audio/s1.wav")){
    	system ("echo no se pudo cargar el audio&pause");
    	return EXIT_FAILURE;
	}
    Sound sound;
    sound.setBuffer(buffer);
    // Play the music
    // Start the game loop
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        // Process events
        Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == Event::Closed)
                window.close();
            
        }
        window.clear();
        // Clear screen
        // Draw the sprite
        window.draw(sprite1);
        window.draw(text);
        // Draw the string
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
