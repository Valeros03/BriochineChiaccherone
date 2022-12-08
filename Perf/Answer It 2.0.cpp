#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Button.h"
#include "Textbox.h"

void turnoGiocatore();
int poszioneRandomRisposta();
int generatoreDomandeRandom();
int turno();
void rispostaEsatta();
int gioco();
int risultato();
void rispostaSbagliata(char a[]);
int mainMenu();

char distrattoreUno[200][100];
char distrattoreDue[200][100];
char distrattoreTre[200][100];
char distrattoreQuattro[200][100];
char matDomande[200][200];
char posizioneCorretta[4][100];
char matRisposte[200][100];
int numeroGiocatori=0;
int width=1260;
int height=900;
int numeroDomande=0;
int click;
int click1;
int click2;
bool FullScreen=false;

int unicita[201];
std::string pos1;
std::string pos2;
std::string pos3;
std::string pos4;
std::string domanda;

typedef struct giocatore {

	std::string nome="";
	int punteggio=0;
	int numeroGiocatore;


}giocatore;
giocatore giocatori[20];



void associatoreGiocatoreNumero(){
	for (int i = 0; i<10; i++){
		giocatori[i].numeroGiocatore=i+1;
		giocatori[i].nome="";
	}
}

void caricaDomande() {
	
	FILE* file;
	FILE* fileDue;
	FILE* fileDistrattoreUno;
	FILE* fileDistrattoreDue;
	FILE* fileDistrattoreTre;
	FILE* fileDistrattoreQuattro;

	file=fopen("Data\\dcvc.txt", "r");
	for (int i = 0; i < 200; i++) {

		fgets(matDomande[i], 200, file);
		for (int q = 0; q < 200; q++) {

			if ((matDomande[i][q] > 65 && matDomande[i][q] < 92) || (matDomande[i][q] > 97 && matDomande[i][q] < 124) || matDomande[i][q] == 64 || matDomande[i][q] == 97 || matDomande[i][q] == 33 || (matDomande[i][q] > 48 && matDomande[i][q] < 59) || (matDomande[i][q] > 130 & matDomande[i][q] < 152)) {

				matDomande[i][q] = matDomande[i][q] - 1;
				
			}
		}
	}

	fileDue=fopen( "Data\\cbin.txt", "r");
	for (int i = 0; i < 200; i++) {
		fgets(matRisposte[i], 100, fileDue);
		for (int q = 0; q < 100; q++) {
			if (matRisposte[i][q] > 65 && matRisposte[i][q] < 92 || matRisposte[i][q]>97 && matRisposte[i][q] < 124 || matRisposte[i][q] == 64 || matRisposte[i][q] == 97 || matRisposte[i][q] == 33 || matRisposte[i][q]>48 && matRisposte[i][q] < 59) {

				matRisposte[i][q] = matRisposte[i][q] - 1;

			}
		}

	}
	fileDistrattoreUno=fopen("Data\\Ansvin.txt", "r");
	for (int i = 0; i < 200; i++) {
		fgets(distrattoreUno[i], 100, fileDistrattoreUno);
		for (int q = 0; q < 100; q++) {
			if (distrattoreUno[i][q] > 65 && distrattoreUno[i][q] < 92 || distrattoreUno[i][q]>97 && distrattoreUno[i][q] < 124 || distrattoreUno[i][q] == 64 || distrattoreUno[i][q] == 97 || distrattoreUno[i][q] == 33 || distrattoreUno[i][q]>48 && distrattoreUno[i][q] < 59) {

				distrattoreUno[i][q] =distrattoreUno[i][q] - 1;

			}
		}
		
	}
	fileDistrattoreDue=fopen("Data\\Bnsvin.txt", "r");
	for (int i = 0; i < 200; i++) {
		fgets(distrattoreDue[i], 100, fileDistrattoreDue);
		for (int q = 0; q < 100; q++) {
			if (distrattoreDue[i][q] > 65 && distrattoreDue[i][q] < 92 || distrattoreDue[i][q]>97 && distrattoreDue[i][q] < 124 || distrattoreDue[i][q] == 64 || distrattoreDue[i][q] == 97 ||distrattoreDue[i][q] == 33 || distrattoreDue[i][q]>48 && distrattoreDue[i][q] < 59) {

				distrattoreDue[i][q] =distrattoreDue[i][q] - 1;

			}
		}
		
	}
	fileDistrattoreTre=fopen("Data\\qnsvin.txt", "r");
	for (int i = 0; i < 200; i++) {
		fgets(distrattoreTre[i], 100, fileDistrattoreTre);
		for (int q = 0; q < 100; q++) {
			if (distrattoreTre[i][q] > 65 && distrattoreTre[i][q] < 92 || distrattoreTre[i][q]>97 && distrattoreTre[i][q] < 124 || distrattoreTre[i][q] == 64 || distrattoreTre[i][q] == 97 ||distrattoreTre[i][q] == 33 || distrattoreTre[i][q]>48 && distrattoreTre[i][q] < 59) {

				distrattoreTre[i][q] =distrattoreTre[i][q] - 1;
            }
			}
	}
	fileDistrattoreQuattro=fopen("Data\\wnsvin.txt", "r");
	for (int i = 0; i < 200; i++) {
		fgets(distrattoreQuattro[i], 100, fileDistrattoreQuattro);
			for (int q = 0; q < 100; q++) {
			if (distrattoreQuattro[i][q] > 65 && distrattoreQuattro[i][q] < 92 || distrattoreQuattro[i][q]>97 && distrattoreQuattro[i][q] < 124 || distrattoreQuattro[i][q] == 64 || distrattoreQuattro[i][q] == 97 ||distrattoreQuattro[i][q] == 33 || distrattoreQuattro[i][q]>48 && distrattoreQuattro[i][q] < 59) {

				distrattoreQuattro[i][q] =distrattoreQuattro[i][q] - 1;
            }
			}
	}

}

int main(){
	inizio:
		
    numeroGiocatori=0;
	associatoreGiocatoreNumero();
	
	if (mainMenu()!=30){
	if(gioco()==36){
		goto inizio;
	}
}
	
}
int mainMenu()
{
	caricaDomande();
	bool prep=false;
	bool playing = false;
	sf::Music musa;
     	musa.openFromFile("Data\\Sound\\musa1.wav");
	    
	    if(click%2==0){
        musa.setVolume(50);
       }else{
       	musa.setVolume(0);
	   }
	musa.play();
        sf::SoundBuffer buttonOver;
        buttonOver.loadFromFile("Data\\Sound\\overButton.wav");
    sf::Sound overButton;
    overButton.setBuffer(buttonOver);
    overButton.setVolume(40);
    sf::SoundBuffer buttonClick;
        buttonClick.loadFromFile("Data\\Sound\\clickButton.wav");
    sf::Sound clickButton;
    clickButton.setBuffer(buttonClick);
    if(click1%2==0){
    clickButton.setVolume(40);
}else{
	clickButton.setVolume(0);
}
	menu: 

	sf::RenderWindow window(sf::VideoMode(width, height), "Answer It!");

    sf::Image icon;
    icon.loadFromFile("icon.png"); // File/Image/Pixel
    window.setIcon(400,300, icon.getPixelsPtr());
    sf::Texture texture;
    if(!texture.loadFromFile("sfondo1.jpg")){
    std::cout<<"error loading sfondo.jpg";
	}
	
	sf::Sprite sprite(texture);
	sprite.setScale(
    window.getSize().x / sprite.getLocalBounds().width, 
    window.getSize().y / sprite.getLocalBounds().height);
    
    
	sf::Font sometime;
	sometime.loadFromFile("Sometime.otf");
	sf::Font arial;
	arial.loadFromFile("arial.ttf");
	sf::Text gameName("Answer It!", arial, 70);
	
	gameName.setPosition(250.f,0.f);
	gameName.setOutlineThickness(10);
	gameName.setOutlineColor(sf::Color::Black);
	
	
    Button play(" Play", {200,50}, 30, sf::Color::White, sf::Color::Red);
    Button opzioni(" Option", {200,50}, 30, sf::Color::White, sf::Color::Red);
    play.setFont(sometime);
    play.setPosition({300,400});
    opzioni.setFont(sometime);
    opzioni.setPosition({300,525});
    bool menu=true;
    bool opzione=false;
    	
        	
    if (menu==true){
	
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type){
            	case sf::Event::Closed:
            		window.close();
            		return 30;
            		break;
     	      		    
            	case sf::Event::MouseMoved:
            		
				    if(play.isSelected(window)){
				    play.setBackColor(sf::Color::Yellow);
						
			        }else{
				    play.setBackColor(sf::Color::White);
				    }
				    if(opzioni.isSelected(window)){
				    	opzioni.setBackColor(sf::Color::Yellow);
				    	
					}else{
						opzioni.setBackColor(sf::Color::White);
					}
						break;
				    case sf::Event::MouseButtonPressed:
					
			     	if (play.isSelected(window)){
			     		clickButton.play();
					    window.close();
					    prep=true;
					    menu=false;
					    opzione=false;
					}
					if(opzioni.isSelected(window)){
						clickButton.play();
						window.close();
						menu=false;
						prep=false;
						opzione=true;
					    }
						break;    
				}
					
        } 
        window.clear();
        window.draw(sprite);
        play.drawTO(window);
        opzioni.drawTO(window);
        window.draw(gameName);
        window.display();
    }
}


    
    
if(prep==true){

         
        sf::RenderWindow preparazione(sf::VideoMode(width, height), "Answer It!");
        sf::Image icon;
        icon.loadFromFile("icon.png"); // File/Image/Pixel
        preparazione.setIcon(400,300, icon.getPixelsPtr());
        bool pronto=false;
        sf::Sprite sprite(texture);
	    sprite.setScale(
        preparazione.getSize().x / sprite.getLocalBounds().width, 
        preparazione.getSize().y / sprite.getLocalBounds().height);
        
                Textbox nome1(20, sf::Color::Black, false);
                Textbox nome2(20, sf::Color::Black, false);
                Textbox nome3(20, sf::Color::Black, false);
                Textbox nome4(20, sf::Color::Black, false);
                Textbox nome5(20, sf::Color::Black, false);
                Textbox nome6(20, sf::Color::Black, false);
                Textbox nome7(20, sf::Color::Black, false);
                Textbox nome8(20, sf::Color::Black, false);
                Textbox nome9(20, sf::Color::Black, false);
                Textbox nome10(20, sf::Color::Black, false);
                
                sf::Text giocatore1("Giocatore 1",sometime, 20);
                sf::Text giocatore2("Giocatore 2",sometime, 20);
                sf::Text giocatore3("Giocatore 3",sometime, 20);
                sf::Text giocatore4("Giocatore 4",sometime, 20);
                sf::Text giocatore5("Giocatore 5",sometime, 20);
                sf::Text giocatore6("Giocatore 6",sometime, 20);
                sf::Text giocatore7("Giocatore 7",sometime, 20);
                sf::Text giocatore8("Giocatore 8",sometime, 20);
                sf::Text giocatore9("Giocatore 9",sometime, 20);
                sf::Text giocatore10("Giocatore 10",sometime, 20);
                
                giocatore1.setPosition(0,100);
                giocatore2.setPosition(0,175);
                giocatore3.setPosition(0,250);
                giocatore4.setPosition(0,325);
                giocatore5.setPosition(0,400);
                giocatore6.setPosition(0,475);
                giocatore7.setPosition(0,550);
                giocatore8.setPosition(0,625);
                giocatore9.setPosition(0,700);
                giocatore10.setPosition(0,775);
                
            	nome1.setFont(sometime);
            	nome2.setFont(sometime);
            	nome3.setFont(sometime);
            	nome4.setFont(sometime);
            	nome5.setFont(sometime);
            	nome6.setFont(sometime);
            	nome7.setFont(sometime);
            	nome8.setFont(sometime);
            	nome9.setFont(sometime);
            	nome10.setFont(sometime);
            	
            	nome1.setPosition({30,100+30});
            	nome2.setPosition({30,175+30});
            	nome3.setPosition({30,250+30});
            	nome4.setPosition({30,325+30});
            	nome5.setPosition({30,400+30});
            	nome6.setPosition({30,475+30});
            	nome7.setPosition({30,550+30});
            	nome8.setPosition({30,625+30});
            	nome9.setPosition({30,700+30});
            	nome10.setPosition({30,775+30});
            	
            	nome1.setLimit(true, 20);
            	nome2.setLimit(true, 20);
            	nome3.setLimit(true, 20);
            	nome4.setLimit(true, 20);
            	nome5.setLimit(true, 20);
            	nome6.setLimit(true, 20);
            	nome7.setLimit(true, 20);
            	nome8.setLimit(true, 20);
            	nome9.setLimit(true, 20);
            	nome10.setLimit(true, 20);
            	
            Button indietro(" Back",{100,50}, 25, sf::Color::White,sf::Color::Green);
            indietro.setFont(sometime);
            indietro.setOutline(5,sf::Color::Red);
            indietro.setPosition({5,5});
            
            Button continua(" Continue",{170,60},40,sf::Color::White, sf::Color::Blue);
            continua.setFont(sometime);
            continua.setPosition({700,450});
            
            Button domande5("5 Domande",{200,60},30, sf::Color::White, sf::Color::Green);
             domande5.setFont(sometime);
			 domande5.setPosition({200+362.5,100});
             
             
            Button domande10("10 Domande",{200,60},30, sf::Color::White, sf::Color::Blue);
            domande10.setFont(sometime);
			domande10.setPosition({450+362.5,100});
            
            
            Button domande20("20 Domande",{200,60},30, sf::Color::White, sf::Color::Cyan);
             domande20.setFont(sometime);
             domande20.setPosition({200+362.5,200});
            
            Button domande50("50 Domande",{200,60},30, sf::Color::White, sf::Color::Red);
            domande50.setFont(sometime);
             domande50.setPosition({450+362.5,200});
             
            Button domande100("100 Domande",{200,60},30, sf::Color::White, sf::Color::Black);
            domande100.setFont(sometime);
               domande100.setPosition({688.5,350});
               
               
            while(preparazione.isOpen())
			{
				
			
				preparazione.clear();
            preparazione.draw(sprite);
				
            	sf::Event ev;
     	      while(preparazione.pollEvent(ev))
			   {
     	      	switch(ev.type){
     	      		case sf::Event::Closed:
     	      			preparazione.close();
     	      			return 30;
     	      			break;
     	      		case sf::Event::TextEntered:	
     	      		    nome1.typedOn(ev);
     	      		    nome2.typedOn(ev);
     	      		    nome3.typedOn(ev);
     	      		    nome4.typedOn(ev);
     	      		    nome5.typedOn(ev);
     	      		    nome6.typedOn(ev);
     	      		    nome7.typedOn(ev);
     	      		    nome8.typedOn(ev);
     	      		    nome9.typedOn(ev);
     	      		    nome10.typedOn(ev);
     	      		    
     	      		    giocatori[0].nome=nome1.getText();
     	      		    giocatori[1].nome=nome2.getText();
     	      		    giocatori[2].nome=nome3.getText();
     	      		    giocatori[3].nome=nome4.getText();
     	      		    giocatori[4].nome=nome5.getText();
     	      		    giocatori[5].nome=nome6.getText();
     	      		    giocatori[6].nome=nome7.getText();
     	      		    giocatori[7].nome=nome8.getText();
     	      		    giocatori[8].nome=nome9.getText();
     	      		    giocatori[9].nome=nome10.getText();
     	      		    
     	      		    
     	      		    break;
     	      		case sf::Event::MouseMoved:
     	      			if(continua.isSelected(preparazione)){
     	      				continua.setBackColor(sf::Color::Green);
					    }else{
						continua.setBackColor(sf::Color::White);
					    }
					    if(indietro.isSelected(preparazione)){
					   	indietro.setBackColor(sf::Color::Red);
					    }else{
					   	indietro.setBackColor(sf::Color::White);
					    }
					    
					if(domande5.isSelected(preparazione)){
						domande5.setBackColor(sf::Color::Yellow);
					}else{
					   	domande5.setBackColor(sf::Color::White);
					}
					if(domande10.isSelected(preparazione)){
						domande10.setBackColor(sf::Color::Yellow);
					}else{
					   	domande10.setBackColor(sf::Color::White);
					}
					if(domande20.isSelected(preparazione)){
						domande20.setBackColor(sf::Color::Yellow);
					}else{
					   	domande20.setBackColor(sf::Color::White);
					}
					if(domande50.isSelected(preparazione)){
						domande50.setBackColor(sf::Color::Yellow);
					}else{
					   	domande50.setBackColor(sf::Color::White);
					}
					if(domande100.isSelected(preparazione)){
						domande100.setBackColor(sf::Color::Yellow);
					}else{
					   	domande100.setBackColor(sf::Color::White);
					}
					   break;
					   
					case sf::Event::MouseButtonPressed:
						if(pronto==true && (nome1.isPiena || nome2.isPiena || nome3.isPiena || nome4.isPiena || nome5.isPiena || nome6.isPiena || nome7.isPiena || nome8.isPiena || nome9.isPiena || nome10.isPiena)){
						
						if (continua.isSelected(preparazione)){
							clickButton.play();
					    	preparazione.close();
					    	prep=false;
					    	opzione=false;
						}
					    }
					    if(domande5.isSelected(preparazione)){
					    	numeroDomande=5;
					    	pronto=true;
					    	domande100.setOutline(0,sf::Color::White);
					    	domande10.setOutline(0,sf::Color::White);
					    	domande20.setOutline(0,sf::Color::White);
					    	domande50.setOutline(0,sf::Color::White);
					    	domande5.setOutline(5,sf::Color::Green);
					    	clickButton.play();
						}
						if(domande10.isSelected(preparazione)){
					    	numeroDomande=10;
					    	pronto=true;
					    	domande5.setOutline(0,sf::Color::White);
					    	domande100.setOutline(0,sf::Color::White);
					    	domande20.setOutline(0,sf::Color::White);
					    	domande50.setOutline(0,sf::Color::White);
					    	domande10.setOutline(5,sf::Color::Green);
					    	clickButton.play();
						}
						if(domande20.isSelected(preparazione)){
					    	numeroDomande=20;
					    	pronto=true;
					    	domande5.setOutline(0,sf::Color::White);
					    	domande10.setOutline(0,sf::Color::White);
					    	domande100.setOutline(0,sf::Color::White);
					    	domande50.setOutline(0,sf::Color::White);
					    	domande20.setOutline(5,sf::Color::Green);
					    	clickButton.play();
						}
						if(domande50.isSelected(preparazione)){
					    	numeroDomande=50;
					    	pronto=true;
					    	domande5.setOutline(0,sf::Color::White);
					    	domande10.setOutline(0,sf::Color::White);
					    	domande20.setOutline(0,sf::Color::White);
					    	domande100.setOutline(0,sf::Color::White);
					    	domande50.setOutline(5,sf::Color::Green);
					    	clickButton.play();
						}
						if(domande100.isSelected(preparazione)){
					    	numeroDomande=100;
					    	pronto=true;
					    	domande5.setOutline(0,sf::Color::White);
					    	domande10.setOutline(0,sf::Color::White);
					    	domande20.setOutline(0,sf::Color::White);
					    	domande50.setOutline(0,sf::Color::White);
					    	domande100.setOutline(5,sf::Color::Green);
					    	clickButton.play();
						}
						if (nome1.isOver(preparazione)){
							nome1.setSelected(true);
						}else{
							nome1.setSelected(false);
						}
						if (nome2.isOver(preparazione)){
							nome2.setSelected(true);
						}else{
						    nome2.setSelected(false);
					    }
						if (nome3.isOver(preparazione)){
							nome3.setSelected(true);
						}else{
							nome3.setSelected(false);
						}
						if (nome4.isOver(preparazione)){
							nome4.setSelected(true);
						}else{
							nome4.setSelected(false);
						}
						if (nome5.isOver(preparazione)){
							nome5.setSelected(true);
						}else{
							nome5.setSelected(false);
						}
						if (nome6.isOver(preparazione)){
							nome6.setSelected(true);
						}else{
							nome6.setSelected(false);
						}
						if (nome7.isOver(preparazione)){
							nome7.setSelected(true);
						}else{
							nome7.setSelected(false);
						}
						if (nome8.isOver(preparazione)){
							nome8.setSelected(true);
						}else{
						    nome8.setSelected(false);
						}
						if (nome9.isOver(preparazione)){
							nome9.setSelected(true);
						}else{
							nome9.setSelected(false);
						}
						if (nome10.isOver(preparazione)){
							nome10.setSelected(true);
						}else{
							nome10.setSelected(false);
						}
						
						if(indietro.isSelected(preparazione)){
						preparazione.close();
						clickButton.play();
					    prep=false;
					    menu=true;
	                    goto menu;
	                }
					    break;
					    
				}
				  
			}
        nome1.drawTo(preparazione);
        nome2.drawTo(preparazione);
        nome3.drawTo(preparazione);
        nome4.drawTo(preparazione);
        nome5.drawTo(preparazione);
        nome6.drawTo(preparazione);
        nome7.drawTo(preparazione);
        nome8.drawTo(preparazione);
        nome9.drawTo(preparazione);
        nome10.drawTo(preparazione);
        preparazione.draw(giocatore1);
        preparazione.draw(giocatore2);
        preparazione.draw(giocatore3);
        preparazione.draw(giocatore4);
        preparazione.draw(giocatore5);
        preparazione.draw(giocatore6);
        preparazione.draw(giocatore7);
        preparazione.draw(giocatore8);
        preparazione.draw(giocatore9);
        preparazione.draw(giocatore10);
        domande5.drawTO(preparazione);
        domande10.drawTO(preparazione);
        domande20.drawTO(preparazione);
        domande50.drawTO(preparazione);
        domande100.drawTO(preparazione);
        continua.drawTO(preparazione);
        indietro.drawTO(preparazione);
        preparazione.display();      
					     
		}
		for (int i=0; i<10;i++){
				if (giocatori[i].nome!=""){
					numeroGiocatori++;
				}
			}
	}
	
	
if(opzione==true){
	sf::RenderWindow option(sf::VideoMode(width, height),"Answer It!");
	sf::Sprite sprite(texture);
	    sprite.setScale(
        option.getSize().x / sprite.getLocalBounds().width, 
        option.getSize().y / sprite.getLocalBounds().height);
	
	
	sf::Text audioSet("Opzioni Audio", sometime,40);
	audioSet.setOutlineThickness(3);
	audioSet.setOutlineColor(sf::Color::Green);
	audioSet.setPosition({200,100});
	
	sf::Text graphicSet("Opzioni Grafiche", sometime,40);
	graphicSet.setOutlineThickness(3);
	graphicSet.setOutlineColor(sf::Color::Red);
	graphicSet.setPosition({600,100});
	
	Button music("Musica: On",{200,70},30,sf::Color::White,sf::Color::Green);
	if (click%2!=0){
		music.updateButton("Musica: Off");
	}
	music.setFont(sometime);
	music.setPosition({200,200});
	
	Button suoni("Suoni: On",{200,70},30,sf::Color::White,sf::Color::Green);
	if (click1%2!=0){
		suoni.updateButton("Suoni: Off");
	}
	suoni.setFont(sometime);
	suoni.setPosition({200,300});
	
	Button indietro(" Back",{100,50}, 25, sf::Color::White,sf::Color::Green);
            indietro.setFont(sometime);
            indietro.setOutline(5,sf::Color::Red);
            indietro.setPosition({5,5});
            
	Button HD("1280x720",{150,60},30,sf::Color::White,sf::Color::Red);
	Button FullHD("1920x1080",{150,60},30,sf::Color::White,sf::Color::Red);
	Button SD("800x600",{150,60},30,sf::Color::White,sf::Color::Red);
	HD.setFont(sometime);
	FullHD.setFont(sometime);
	SD.setFont(sometime);
	HD.setPosition({650,200});
	if(width==1260 && height==900){
	HD.setOutline(5,sf::Color::Red);
}
    if(width==800 && height==600){
    	SD.setOutline(5,sf::Color::Red);
    }
    
    if(width==1920 && height==1080){
    	FullHD.setOutline(5,sf::Color::Red);
    }
	FullHD.setPosition({810,200});
	SD.setPosition({490,200});
	
	
	
	Button fullScreen("FullScreen",{150,60},30,sf::Color::White,sf::Color::Red);
	if (click1%2!=0){
		fullScreen.updateButton("Finestra");
	}
	fullScreen.setFont(sometime);
	fullScreen.setPosition({650,300});
	
	while(option.isOpen()){
		
		
		   sf::Event eve;
	  while(option.pollEvent(eve)){
	  	switch (eve.type){
	  		case sf::Event::Closed:
	  			option.close();
	  			return 30;
	  			break;
	  		case sf::Event::MouseMoved:
			  	if(music.isSelected(option)){
			  		music.setBackColor(sf::Color::Yellow);
			  		
				  }else{
				  	music.setBackColor(sf::Color::White);
				  }
				  if (indietro.isSelected(option)){
				  indietro.setBackColor(sf::Color::Red);
				  }else{
				  	indietro.setBackColor(sf::Color::White);
				  }
				  if(suoni.isSelected(option)){
			  		suoni.setBackColor(sf::Color::Yellow);
			  		
				  }else{
				  	suoni.setBackColor(sf::Color::White);
				  }
				  if(HD.isSelected(option)){
				  	HD.setBackColor(sf::Color::Yellow);
				  }else{
				  	HD.setBackColor(sf::Color::White);
				  }
				  if(SD.isSelected(option)){
				  	SD.setBackColor(sf::Color::Yellow);
				  }else{
				  	SD.setBackColor(sf::Color::White);
				  }
				  if(FullHD.isSelected(option)){
				  	FullHD.setBackColor(sf::Color::Yellow);
				  }else{
				  	FullHD.setBackColor(sf::Color::White);
				  }
				  if(fullScreen.isSelected(option)){
				  	fullScreen.setBackColor(sf::Color::Yellow);
				  }else{
				  	fullScreen.setBackColor(sf::Color::White);
				  }
				  
				  break;
			case sf::Event::MouseButtonPressed:
			   if(music.isSelected(option) && click%2==0){
			   	music.updateButton("Musica: Off");
			   	musa.setVolume(0);
			   	clickButton.play();
			   	click++;
			   }else if(music.isSelected(option) && click%2!=0){
			   	music.updateButton("Musica: On");
			   	musa.setVolume(50);
			   	clickButton.play();
			   	click++;
			   }
			   if(suoni.isSelected(option) && click1%2==0){
			   	suoni.updateButton("Suoni: Off");
			   	clickButton.setVolume(0);
			   	click1++;
			   }else if(suoni.isSelected(option) && click1%2!=0){
			   	suoni.updateButton("Suoni: On");
			   	clickButton.setVolume(40);
			   	clickButton.play();
			   	click1++;
			   }
			   if(SD.isSelected(option)){
			   	HD.setOutline(0,sf::Color::White);
			   	FullHD.setOutline(0,sf::Color::White);
			   	SD.setOutline(5,sf::Color::Red);
			   	clickButton.play();
			   	width=800;
			   	height=600;
			   }
			   if(HD.isSelected(option)){
			   	SD.setOutline(0,sf::Color::White);
			   	FullHD.setOutline(0,sf::Color::White);
			   	HD.setOutline(5,sf::Color::Red);
			   	clickButton.play();
			   	width=1280;
			   	height=720;
			   }
			   if(FullHD.isSelected(option)){
			   	SD.setOutline(0,sf::Color::White);
			   	HD.setOutline(0,sf::Color::White);
			   	FullHD.setOutline(5,sf::Color::Red);
			   	clickButton.play();
			   	width=1920;
			   	height=1080;
			   }
			   if(fullScreen.isSelected(option) && click2%2==0){
			   	fullScreen.updateButton("Finestra");
			   	FullScreen=true;
			   	clickButton.play();
			   	click2++;
			   	goto menu;
			   	
			   	
			   }else if(fullScreen.isSelected(option) && click2%2!=0){
			   	fullScreen.updateButton("FullScreen");
			   	clickButton.play();
			   	FullScreen=false;
			   	click2++;
			   	goto menu;
			   	
			   }
			   if(indietro.isSelected(option)){
			   	   opzione=false;
			   	   prep=false;
			   	   menu=true;
			   	   clickButton.play();
			   	   goto menu;
			   	   option.close();
			   }
			   break;	  
		  }
	  }
		
		
		option.clear();
		option.draw(sprite);
		option.draw(audioSet);
		option.draw(graphicSet);
		music.drawTO(option);
		HD.drawTO(option);
		SD.drawTO(option);
		FullHD.drawTO(option);
		fullScreen.drawTO(option);
		suoni.drawTO(option);
		indietro.drawTO(option);
		option.display();
	}
	
}	
	
	
}


int turno(int numeroGiocatore){
	
	         int risposta=5;
	         char m[2];
	         
	         sf::SoundBuffer clickButton;
	         clickButton.loadFromFile("Data\\Sound\\clickButton.wav");
	         sf::Sound buttonClick;
	         buttonClick.setBuffer(clickButton);
	         buttonClick.setVolume(40);
	         
	         itoa(numeroGiocatore+1,m,10);
	         std::string n=m;
		     sf::Time tempo = sf::seconds(0.01f);
	         sf::RenderWindow game(sf::VideoMode(width, height), "Answer It!");
	         sf::Font sometime;
	         sometime.loadFromFile("sometime.otf");
             sf::Text toccaA("tocca al giocatore" + n + " " + giocatori[numeroGiocatore].nome,sometime,30);
             toccaA.setPosition(20,20);
	         sf::Font arial;
	         arial.loadFromFile("arial.ttf");
	          sf::Texture texture;
              if(!texture.loadFromFile("sfondo1.jpg")){
             std::cout<<"error loading sfondo.jpg";
	          }
	         sf::Sprite sprite(texture);
	         sf::Text domande(domanda, arial, 20);
	         domande.setPosition(234,100);
	         Button risp1(pos1,{220,50},15,sf::Color::White, sf::Color::Black);
	         Button risp2(pos2,{220,50},15,sf::Color::White, sf::Color::Black);
	         Button risp3(pos3,{220,50},15,sf::Color::White, sf::Color::Black);
	         Button risp4(pos4,{220,50},15,sf::Color::White, sf::Color::Black);
	         
	         risp1.setFont(arial);
	         risp2.setFont(arial);
	         risp3.setFont(arial);
	         risp4.setFont(arial);
	         
	         risp1.setPosition({200,540});
	         risp2.setPosition({200,640});
	         risp3.setPosition({700,540});
	         risp4.setPosition({700,640});
	         
	         
	         while(game.isOpen()){
	         	
	         	sf::Event risp;    
	         		
	         		while(game.pollEvent(risp)){
	         			switch(risp.type){
	         			
	         				 
     	      		    case sf::Event::Closed:
     	      			game.close();
     	      			return 40;
     	      			numeroGiocatori=0;
     	      			
     	      			break;
	         		    case sf::Event::MouseMoved:
	         		    	if (risp1.isSelected(game)){
	         		    		risp1.setBackColor(sf::Color::Yellow);
							 }else{
							 	risp1.setBackColor(sf::Color::White);
							 }
							 
							 if (risp2.isSelected(game)){
	         		    		risp2.setBackColor(sf::Color::Yellow);
							 }else{
							 	risp2.setBackColor(sf::Color::White);
							 }
							 
							 if (risp3.isSelected(game)){
	         		    		risp3.setBackColor(sf::Color::Yellow);
							 }else{
							 	risp3.setBackColor(sf::Color::White);
						}
							if (risp4.isSelected(game)){
	         		    		risp4.setBackColor(sf::Color::Yellow);
							}else{
							 	risp4.setBackColor(sf::Color::White);
							}
							break;
					    	case sf::Event::MouseButtonPressed:
						    if(risp1.isSelected(game)){
						    	buttonClick.play();
							risposta=0;
							game.close();
					        }
					        
					        if(risp2.isSelected(game)){
					        	buttonClick.play();
					    	risposta=1;
					    	
							game.close();
					     	}
					     	
					     	if(risp3.isSelected(game)){
					     		buttonClick.play();
							risposta=2;
							
							game.close();
					     	}
					     	
					    	if(risp4.isSelected(game)){
					    		buttonClick.play();
							risposta=3;
							
							game.close();
						    }
						    break;
						    
				 } 
				 //clock        
				 }
		  
    
    
    game.clear();
    game.draw(sprite);
    game.draw(toccaA);
    game.draw(domande);
	risp1.drawTO(game);
	risp2.drawTO(game);
	risp3.drawTO(game);
	risp4.drawTO(game);
	game.display();	
	
}
return risposta;	
}


int gioco(){
	int k;
	
	for(int i=0; i<numeroDomande; i++){
		for (k=0; k<10; k++){
	
	int u = poszioneRandomRisposta();
	int j = generatoreDomandeRandom();
	domanda=matDomande[j];
	if(domanda.length()>70 && domanda.substr(71,71)==" "){
		domanda = domanda.substr(0,70)+"\n"+domanda.substr(70,domanda.length());
	}else if (domanda.length()>70 && domanda.substr(71,71)!=" "){
		domanda = domanda.substr(0,domanda.substr(55,70).find(" ")+55)+"\n"+domanda.substr(domanda.substr(55,70).find(" ")+55,domanda.length());
	}
	memcpy(posizioneCorretta[0], distrattoreUno[j], sizeof(posizioneCorretta[u]));
	memcpy(posizioneCorretta[1], distrattoreDue[j], sizeof(posizioneCorretta[u]));
	memcpy(posizioneCorretta[2], distrattoreTre[j], sizeof(posizioneCorretta[u]));
	memcpy(posizioneCorretta[3], distrattoreQuattro[j], sizeof(posizioneCorretta[u]));
	memcpy(posizioneCorretta[u], matRisposte[j], sizeof(posizioneCorretta[u]));
	pos1=posizioneCorretta[0];
	pos2=posizioneCorretta[1];
	pos3=posizioneCorretta[2];
	pos4=posizioneCorretta[3];
	if(u==0){
		pos1=posizioneCorretta[u];
	}else if(u==1){
		pos2=posizioneCorretta[u];
	}else if(u==2){
		pos3=posizioneCorretta[u];
	}else if(u==3){
		pos4=posizioneCorretta[u];
	}
	
	  //controllo lunghezza della stringa stringa1(massimo 75 caratteri)
	if (pos1.length()>25 && pos1.length()<51 && pos1.substr(26,26)==" "){
		pos1= pos1.substr(0,25)+"\n"+pos1.substr(25,pos1.length());
		
	}else if(pos1.length()>25 && pos1.length()<51 && pos1.substr(26,26)!=" "){
		pos1= pos1.substr(0,pos1.substr(15,25).find(" ")+15)+"\n"+pos1.substr(pos1.substr(15,25).find(" ")+15,pos1.length());
		
	    }else if (pos1.length()>50 && pos1.substr(26,26)==" " && pos1.substr(51,51)==" "){
		pos1 = pos1.substr(0,25)+"\n"+pos1.substr(25,50)+"\n"+pos1.substr(50,pos1.length());
		
	    }else if(pos1.length()>50 && pos1.substr(26,26)==" " && pos1.substr(51,51)!=" "){
		pos1= pos1.substr(0,25)+"\n"+pos1.substr(25,pos1.substr(40,50).find(" ")+40)+"\n"+pos1.substr(pos1.substr(40,50).find(" ")+40,pos1.length());
	
	    }else if(pos1.length()>50 && pos1.substr(26,26)!=" " && pos1.substr(51,51)==" "){
		pos1= pos1.substr(0,pos1.substr(15,25).find(" ")+15)+"\n"+pos1.substr(pos1.substr(15,25).find(" ")+15,50)+"\n"+pos1.substr(50,pos1.length());
	
	    }else if(pos1.length()>50 && pos1.substr(26,26)!=" " && pos1.substr(51,51)!=" "){
		pos1= pos1.substr(0,pos1.substr(15,25).find(" ")+15)+"\n"+pos1.substr(pos1.substr(15,25).find(" ")+15,pos1.substr(40,50).find(" ")+40)+"\n"+pos1.substr(pos1.substr(40,50).find(" ")+40,pos1.length());
	}
	//controllo lunghezza della stringa stringa2
	
	if (pos2.length()>25 && pos2.length()<51 && pos2.substr(26,26)==" "){
		pos2= pos2.substr(0,25)+"\n"+pos2.substr(25,pos2.length());
		
	}else if(pos2.length()>25 && pos2.length()<51 && pos2.substr(26,26)!=" "){
		pos2= pos2.substr(0,pos2.substr(15,25).find(" ")+15)+"\n"+pos2.substr(pos2.substr(15,25).find(" ")+15,pos2.length());
		
	}else if (pos2.length()>50 && pos2.substr(26,26)==" " && pos2.substr(51,51)==" "){
		pos2 = pos2.substr(0,25)+"\n"+pos2.substr(25,50)+"\n"+pos2.substr(50,pos2.length());
		
	    }else if(pos2.length()>50 && pos2.substr(26,26)==" " && pos2.substr(51,51)!=" "){
		pos2= pos2.substr(0,25)+"\n"+pos2.substr(25,pos2.substr(40,50).find(" ")+40)+"\n"+pos2.substr(pos2.substr(40,50).find(" ")+40,pos2.length());
	
	    }else if(pos2.length()>50 && pos2.substr(26,26)!=" " && pos2.substr(51,51)==" "){
		pos2= pos2.substr(0,pos2.substr(15,25).find(" ")+15)+"\n"+pos2.substr(pos2.substr(15,25).find(" ")+15,50)+"\n"+pos2.substr(50,pos2.length());
	
	    }else if(pos2.length()>50 && pos2.substr(26,26)!=" " && pos2.substr(51,51)!=" "){
		pos2= pos2.substr(0,pos2.substr(15,25).find(" ")+15)+"\n"+pos2.substr(pos2.substr(15,25).find(" ")+15,pos2.substr(40,50).find(" ")+40)+"\n"+pos2.substr(pos2.substr(40,50).find(" ")+40,pos2.length());
	}
    
    //controllo lunghezza della stringa stringa3
	if (pos3.length()>25 && pos3.length()<51 && pos3.substr(26,26)==" "){
		pos3 = pos3.substr(0,25)+"\n"+pos3.substr(25,pos3.length());
		
	}else if(pos3.length()>25 && pos3.length()<51 && pos3.substr(26,26)!=" "){
		pos3 = pos3.substr(0,pos3.substr(15,25).find(" ")+15)+"\n"+pos3.substr(pos3.substr(15,25).find(" ")+15,pos3.length());
		
	}else if (pos3.length()>50 && pos2.substr(26,26)==" " && pos3.substr(51,51)==" "){
		pos3 = pos3.substr(0,25)+"\n"+pos3.substr(25,50)+"\n"+pos3.substr(50,pos3.length());
		
	}else if(pos3.length()>50 && pos3.substr(26,26)==" " && pos3.substr(51,51)!=" "){
		pos3 = pos3.substr(0,25)+"\n"+pos3.substr(25,pos3.substr(40,50).find(" ")+40)+"\n"+pos3.substr(pos3.substr(40,50).find(" ")+40,pos3.length());
	
	}else if(pos3.length()>50 && pos3.substr(26,26)!=" " && pos3.substr(51,51)==" "){
		pos3 = pos3.substr(0,pos3.substr(15,25).find(" ")+15)+"\n"+pos3.substr(pos3.substr(15,25).find(" ")+15,50)+"\n"+pos3.substr(50,pos3.length());
	
	}else if(pos3.length()>50 && pos3.substr(26,26)!=" " && pos3.substr(51,51)!=" "){
		pos3 = pos3.substr(0,pos3.substr(15,25).find(" ")+15)+"\n"+pos3.substr(pos3.substr(15,25).find(" ")+15,pos3.substr(40,50).find(" ")+40)+"\n"+pos3.substr(pos3.substr(40,50).find(" ")+40,pos3.length());
	}
	
	//controllo lunghezza della stringa stringa4
	if(pos4.length()>25 && pos4.length()<51 && pos4.substr(26,26)==" "){
	pos4 = pos4.substr(0,25)+"\n"+pos4.substr(25,pos4.length());
	
    }else if(pos4.length()>25 && pos4.length()<51 && pos4.substr(26,26)!=" "){
    	pos4 = pos4.substr(0,pos4.substr(15,25).find(" ")+15)+"\n"+pos4.substr(pos4.substr(15,25).find(" ")+15,pos4.length());
    	
	}else if (pos3.length()>50 && pos2.substr(26,26)==" " && pos3.substr(51,51)==" "){
		pos3 = pos3.substr(0,25)+"\n"+pos3.substr(25,50)+"\n"+pos3.substr(50,pos3.length());
		
	}else if(pos4.length()>50 && pos4.substr(26,26)==" " && pos4.substr(51,51)!=" "){
		pos4 = pos4.substr(0,25)+"\n"+pos4.substr(25,pos4.substr(40,50).find(" ")+40)+"\n"+pos4.substr(pos4.substr(40,50).find(" ")+40,pos4.length());
	
	}else if(pos4.length()>50 && pos4.substr(26,26)!=" " && pos4.substr(51,51)==" "){
		pos4 = pos4.substr(0,pos4.substr(15,25).find(" ")+15)+"\n"+pos4.substr(pos4.substr(15,25).find(" ")+15,50)+"\n"+pos4.substr(50,pos4.length());
	
	}else if(pos4.length()>50 && pos4.substr(26,26)!=" " && pos4.substr(51,51)!=" "){
		pos4 = pos4.substr(0,pos4.substr(15,25).find(" ")+15)+"\n"+pos4.substr(pos4.substr(15,25).find(" ")+15,pos4.substr(40,50).find(" ")+40)+"\n"+pos4.substr(pos4.substr(40,50).find(" ")+40,pos4.length());
	}
	if(giocatori[k].nome!=""){
	
	    int f=turno(k);
		if(f==u){
			rispostaEsatta();
			giocatori[k].punteggio++;
		}else if(f!=u && f!=40){
			rispostaSbagliata(posizioneCorretta[u]);
		}else if(f==40){
			return 0;
		}
	}
	    }
	    k=0;
	   
       }   
	    risultato();
    
}
void rispostaEsatta(){
	
	sf::RenderWindow corretto(sf::VideoMode(width, height), "Answer It!");
	sf::Texture texture;
    if(!texture.loadFromFile("sfondo 2.jpg")){
    std::cout<<"error loading sfondo.jpg";
	}
	
	sf::Sprite sprite(texture);
	sprite.setScale(
    corretto.getSize().x / sprite.getLocalBounds().width, 
    corretto.getSize().y / sprite.getLocalBounds().height);
	
	sf::Font sometime;
	sometime.loadFromFile("sometime.otf");
	sf::Font arial;
	arial.loadFromFile("arial.ttf");
    
    sf::Text haiIndovinato("Risposta Esatta! (Premi Enter per continuare...)",sometime, 50);
    haiIndovinato.setPosition(200,300);
    haiIndovinato.setFillColor(sf::Color::Green);
    
    sf::RectangleShape bgText;
    bgText.setSize({1000,200});
    bgText.setFillColor(sf::Color::Blue);
    bgText.setPosition(190,290);
    
    sf::SoundBuffer correctBuffer;
    correctBuffer.loadFromFile("Data\\Sound\\correct.wav");
    sf::Sound correct;
    correct.setBuffer(correctBuffer);
    if(click1%2==0){
    	correct.play();
	}
    
    while(corretto.isOpen()){
    	
    	sf::Event ev;
    	while(corretto.pollEvent(ev)){
    		
    	 switch(ev.type){
    	 	case sf::Event::Closed:
    	 	corretto.close();
    	 	break;
    	 	case sf::Event::KeyPressed:
    	 		if(sf::Keyboard::Return)
    	 	    corretto.close();
    	 	    break;
		 }
		}
    	
    	corretto.clear();
        corretto.draw(sprite);
        corretto.draw(bgText);
        corretto.draw(haiIndovinato);
    	corretto.display();	
	}	
}

void rispostaSbagliata(char a[150]){
	
	sf::RenderWindow sbagliato(sf::VideoMode(width, height), "Answer It!");
	sf::Texture texture;
    if(!texture.loadFromFile("sfondo.jpg")){
    std::cout<<"error loading sfondo.jpg";
	}
	
	sf::SoundBuffer wrongBuffer;
	wrongBuffer.loadFromFile("Data\\Sound\\wrong.wav");
	sf::Sound wrong;
	wrong.setBuffer(wrongBuffer);
	
	sf::Sprite sprite(texture);
	sprite.setScale(
    sbagliato.getSize().x / sprite.getLocalBounds().width, 
    sbagliato.getSize().y / sprite.getLocalBounds().height);
	
	sf::Font sometime;
	sometime.loadFromFile("sometime.otf");
	sf::Font arial;
	arial.loadFromFile("arial.ttf");
	
	
    std::string s=a;
    
    sf::Text corretta("risposta corretta: "+s,arial,20);
    corretta.setPosition(200,400);
    corretta.setFillColor(sf::Color::Red);
    
    sf::Text haiSbagliato("Risposta Sbagliata :(  (Premi Enter per continuare...)",sometime, 50);
    haiSbagliato.setPosition(200,300);
    haiSbagliato.setFillColor(sf::Color::Red);
    
    sf::RectangleShape bgText;
    bgText.setSize({1000,200});
    bgText.setFillColor(sf::Color::Yellow);
    bgText.setPosition(190,290);
    if(click1%2==0){
    wrong.play();
}
    while(sbagliato.isOpen()){
    	
    	sf::Event ev;
    	while(sbagliato.pollEvent(ev)){
    		
    	 switch(ev.type){
    	 	case sf::Event::Closed:
    	 	sbagliato.close();
    	 	break;
    	 	case sf::Event::KeyPressed:
    	 		if(sf::Keyboard::Return)
    	 	    sbagliato.close();
    	 	    break;
		 }
		}
    	
    	sbagliato.clear();
        sbagliato.draw(sprite);
        sbagliato.draw(bgText);
        sbagliato.draw(corretta);
        sbagliato.draw(haiSbagliato);
    	sbagliato.display();	
	}
	
}

int risultato(){
	char b[3];
	std::string s;
	for(int i=0; i<10; i++){
		if(giocatori[i].nome!=""){
		itoa(giocatori[i].punteggio,b,10);
		s=s+giocatori[i].nome+" "+b+"\n";
	}
	
	}
	
	sf::RenderWindow resoconto(sf::VideoMode(width, height), "Answer It!");
	sf::Texture texture;
    if(!texture.loadFromFile("sfondo1.jpg")){
    std::cout<<"error loading sfondo.jpg";
	}
	
	sf::Sprite sprite(texture);
	sprite.setScale(
    resoconto.getSize().x / sprite.getLocalBounds().width, 
    resoconto.getSize().y / sprite.getLocalBounds().height);
	
	
	sf::Font arial;
	arial.loadFromFile("arial.ttf");
	
	sf::Text fine("Punteggio: ", arial, 50);
	fine.setOutlineColor(sf::Color::Red);
	fine.setOutlineThickness(10.f);
	fine.setPosition(600,200);
	
	sf::Font sometime;
	sometime.loadFromFile("Sometime.otf");
	
	sf::Text giocatori(s, sometime, 30);
	giocatori.setPosition(600,400);
	
	Button backMenu("Main menu",{200,100}, 40, sf::Color::White, sf::Color::Green);
	backMenu.setFont(sometime);
	backMenu.setPosition({152.5,450});
	backMenu.setOutline(5,sf::Color::Red);
	
	while(resoconto.isOpen()){
		
		sf::Event ev;
		while(resoconto.pollEvent(ev)){
			switch(ev.type){
			   case sf::Event::Closed:
			   	resoconto.close();
			   	break;
			   case sf::Event::MouseMoved:
			     if(backMenu.isSelected(resoconto)){
			     	backMenu.setBackColor(sf::Color::Red);
				 }else{
				 	backMenu.setBackColor(sf::Color::White);
				 }
				 break;
				case sf::Event::MouseButtonPressed:
					if(backMenu.isSelected(resoconto)){
					resoconto.close();
					return 36;
				}
			}
		}
		
		resoconto.clear();
		resoconto.draw(sprite);
		resoconto.draw(fine);
		backMenu.drawTO(resoconto);
		resoconto.draw(giocatori);
		resoconto.display();
	}
}

int generatoreDomandeRandom() {
	srand(time(0));
	int r;
	do {
		r = rand() % 200 ;
	} while (unicita[r] != 0);
	unicita[r] = 1;
	return r;
}

int poszioneRandomRisposta() {
	srand(time(0));
	int t = rand() % 4;
	return t;
}

