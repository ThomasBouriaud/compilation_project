#include "driver.hh"
#include "jardinRendering.hh"
#include <iostream>

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
	monJardin->changePosition(numtortue, posX*x + t->getX(), posY*x + t->getY());
	//std::cout << "Pos tortue(" << posX*x + t->getX() << "," << posY*x + t->getY() << ") orientation:" << monJardin->orientation(numtortue) << std::endl;
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
	monJardin->changePosition(numtortue, posX*x + t->getX(), posY*x + t->getY());
	//std::cout << "Pos tortue(" << posX*x + t->getX() << "," << posY*x + t->getY() << ") orientation:" << monJardin->orientation(numtortue) << std::endl;
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

void Driver::sauter(int x) {}
void Driver::sauter(int numtortue, int x) {}

void Driver::modifCouleurCarapace(std::string rgb){}
void Driver::modifCouleurCarapace(int numtortue, std::string rgb){}

void Driver::modifCouleurMotif(std::string rgb){}
void Driver::modifCouleurMotif(int numtortue, std::string rgb){}

void Driver::mur(int numtortue, float o){}
void Driver::vide(int numtortue, float o){}

void Driver::nombreTortue(int nb){}

void Driver::newJardin(std::string file){}

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
