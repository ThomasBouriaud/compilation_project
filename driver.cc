#include "driver.hh"
#include "jardinRendering.hh"
#include <iostream>
#include <algorithm>

Driver::Driver(JardinRendering * J) {
    monJardin = J;
}

Driver::~Driver() {
	delete monJardin;
}


void Driver::avancer(int x) {
    for(size_t i = 0 ; i < monJardin->getTortues().size() ; i++) {
    	avancer((int)i, x);
    }
}

void Driver::avancer(int numtortue, int x) {
	Tortue* t = monJardin->getTortues().at(numtortue);
	int posX = 0;
	int posY = 0;
	//std::cout << "Pos tortue(" << posX*x + t->getX() << "," << posY*x + t->getY() << ") orientation:" << monJardin->orientation(numtortue) << std::endl;
	switch((int)t->getOrientation()) {
		case 0:
			posY = -1;
			break;
		case 1:
			posX = 1;
			break;
		case 2:
			posY = 1;
			break;
		case 3:
			posX = -1;
			break;
	}
	for(int i = 0; i < x; i++){
		if(vide(numtortue, t->getOrientation())){
			monJardin->changePosition(numtortue, posX*1 + t->getX(), posY*1 + t->getY());
			std::cout << "Pos tortue(" << t->getX() << "," << t->getY() << ") orientation:" << monJardin->orientation(numtortue) << std::endl;
		}
	}
}

void Driver::reculer(int x) {
    for(size_t i = 0 ; i < monJardin->getTortues().size() ; i++) {
    	reculer((int)i, x);
    }
}

void Driver::reculer(int numtortue, int x) {
	Tortue* t = monJardin->getTortues().at(numtortue);
	int posX = 0;
	int posY = 0;
	//std::cout << "Pos tortue(" << posX*x + t->getX() << "," << posY*x + t->getY() << ") orientation:" << monJardin->orientation(numtortue) << std::endl;
	switch((int)t->getOrientation()) {
		case 0:
			posY = 1;
			break;
		case 1:
			posX = -1;
			break;
		case 2:
			posY = -1;
			break;
		case 3:
			posX = 1;
			break;
	}
	int ori = int(t->getOrientation());
	int derriere = ((ori-2)%4 + 4) % 4;
	for(int i = 0; i < x; i++){
		if(vide(numtortue, derriere)){
			monJardin->changePosition(numtortue, posX*1 + t->getX(), posY*1 + t->getY());
			//std::cout << "Pos tortue(" << t->getX() << "," << t->getY() << ") orientation:" << monJardin->orientation(numtortue) << std::endl;
		}
	}
}

void Driver::tourner(int x, float o) {
	for(size_t i = 0 ; i < monJardin->getTortues().size() ; i++) {
    	tourner((int)i, x, o);
    }
}
void Driver::tourner(int numtortue, int x, float o) {
	int i_o = int(o);
	int i_oriCurrent = int(monJardin->orientation(numtortue));
	int i_newOri = (i_oriCurrent+(i_o*x)%4+4)%4;
	//std::cout << "o=" << i_o << ", i_oriCurrent=" << i_oriCurrent << ", i_newOri=" << i_newOri << std::endl;
	monJardin->changeOrientation(numtortue, float(i_newOri));
}

bool Driver::mur(int numtortue, float o) {
	Tortue* t = monJardin->getTortues().at(numtortue);
	int dirX = 0;
	int dirY = 0;
	int posTortueX = t->getX();
	int posTortueY = t->getY();
	switch(int(o)) {
		case 0:
			dirY = -1;
			break;
		case 1:
			dirX = 1;
			break;
		case 2:
			dirY = 1;
			break;
		case 3:
			dirX = -1;
			break;
	}
	if(monJardin->estMur(posTortueX + dirX, posTortueY + dirY)){
		return true;
	}
	return false;
}

bool Driver::vide(int numtortue, float o) {
	Tortue* t = monJardin->getTortues().at(numtortue);
	int dirX = 0;
	int dirY = 0;

	switch(int(o)) {
		case 0:
			dirY = -1;
			break;
		case 1:
			dirX = 1;
			break;
		case 2:
			dirY = 1;
			break;
		case 3:
			dirX = -1;
			break;
	}
	int posTortueX = t->getX() + dirX;
	int posTortueY = t->getY() + dirY;
	
	return vide(numtortue, posTortueX, posTortueY);
}

bool Driver::vide(int numtortue, int x, int y) {
	//std::cout << "vide: posX=" << posTortueX << ", posTortueY=" << posTortueY << std::endl;
	int xMax = monJardin->tailleJardin().width();
	int yMax = monJardin->tailleJardin().height();
	//std::cout << "xMax=" << xMax << ", yMax=" << yMax << std::endl;
	if((x < 0) || (x >= xMax) || (y < 0) || (y >= yMax)) {
		return false;
	}
	if(monJardin->estMur(x, y)){
		return false;
	}
	
	for(size_t i = 0 ; i < monJardin->getTortues().size() ; i++) {
		Tortue* t = monJardin->getTortues().at(i);
		if((t->getX() == x) && (t->getY() == y)) {
			return false;
		}
	}
	return true;
}


void Driver::sauter(int x) {
	for(size_t i = 0 ; i < monJardin->getTortues().size() ; i++) {
		sauter((int)i, x);
	}
}
void Driver::sauter(int numtortue, int x) {
	Tortue* t = monJardin->getTortues().at(numtortue);
	int dirX = 0;
	int dirY = 0;
	int posX = t->getX();
	int posY = t->getY();
	int ori = (int)t->getOrientation();
	switch(ori) {
	case 0:
		dirY = -1;
		break;
	case 1:
		dirX = 1;
		break;
	case 2:
		dirY = 1;
		break;
	case 3:
		dirX = -1;
		break;
	}
	if(vide(numtortue, posX+x*dirX, posY+x*dirY)){
		std::cout << "YO, moi je suis en " << posX << " " << posY << " je me tp en " << posX+x*dirX << " " << posY+x*dirY << std::endl;
		monJardin->changePosition(numtortue, posX+x*dirX, posY+x*dirY);
		//std::cout << "Pos tortue(" << t->getX() << "," << t->getY() << ") orientation:" << monJardin->orientation(numtortue) << std::endl;
	}
}

void Driver::modifCouleurCarapace(std::string rgb) {
	for(size_t i = 0 ; i < monJardin->getTortues().size() ; i++) {
		modifCouleurCarapace((int)i, rgb);
	}
}
void Driver::modifCouleurCarapace(int numtortue, std::string rgb) {
	std::string r1 = rgb.substr(1,1);
	std::string r2 = rgb.substr(2,2);	
	std::string g1 = rgb.substr(3,3);
	std::string g2 = rgb.substr(4,4);	
	std::string b1 = rgb.substr(5,5);
	std::string b2 = rgb.substr(6,6);
	std::cout << "Couleur = " << r1 << ", " << r2 << ", "<< g1 << ", "<< g2 << ", "<< b1 << ", "<< b2 << std::endl;
	//couleurCarapace(numtortue, );
}

void Driver::modifCouleurMotif(std::string rgb) {}
void Driver::modifCouleurMotif(int numtortue, std::string rgb) {}

void Driver::nombreTortue(int nb) {}

void Driver::newJardin(std::string file) {}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float Driver::obtenirOrientationTortue(int numtortue) {
    return monJardin->orientation(numtortue);
}

void Driver::changerCouleurCarapace(int numtortue, int r, int g, int b) {
	monJardin->changeCouleurCarapace(numtortue, r, g, b);
}

void Driver::changerCouleurMotif(int numtortue, int r, int g, int b) {
	monJardin->changeCouleurMotif(numtortue, r, g, b);
}

int Driver::obtenirPositionX(int numtortue) {
	return monJardin->getTortues().at(numtortue)->getX();
}

int Driver::obtenirPositionY(int numtortue) {
	return monJardin->getTortues().at(numtortue)->getY();
}

QColor Driver::obtenirCouleurCarapace(int numtortue) {
	return monJardin->couleurCarapace(numtortue);
}

QColor Driver::obtenirCouleurMotif(int numtortue) {
	return monJardin->couleurMotif(numtortue);
}
