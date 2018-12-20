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

coordonnee Driver::getXY(int orientation) {
	coordonnee ret;
	ret.x = 0;
	ret.y = 0;
	
	switch(orientation) {
		case 0:
			ret.y = -1;
			break;
		case 90:
			ret.x = 1;
			break;
		case 180:
			ret.y = 1;
			break;
		case -90:
			ret.x = -1;
			break;
	}
	
	return ret;
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
	
	coordonnee c = getXY((int)t->getOrientation());
	for(int i = 0; i < x; i++){
		if(vide(numtortue, t->getOrientation())){
			monJardin->changePosition(numtortue, c.x*1 + t->getX(), c.y*1 + t->getY());
			std::cout << "Avance : Pos tortue(" << t->getX() << "," << t->getY() << ") orientation:" << monJardin->orientation(numtortue) << std::endl;
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
	coordonnee c = getXY((int)t->getOrientation());
	//std::cout << "Recule : Pos tortue(" << t->getX() << "," << t->getY() << ") orientation:" << monJardin->orientation(numtortue) << std::endl;
	
	int ori = int(t->getOrientation());
	float derriere = 0.0;
	if(std::abs(ori) == 90)
		derriere = float(-ori);
	else
		derriere = float((ori+180)%360);
	for(int i = 0; i < x; i++){
		if(vide(numtortue, derriere)){
			monJardin->changePosition(numtortue, c.x*(-1) + t->getX(), c.y*(-1) + t->getY());
			std::cout << "Recule : Pos tortue(" << t->getX() << "," << t->getY() << ") orientation:" << monJardin->orientation(numtortue) << std::endl;
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
	int i_newOri = i_oriCurrent+int(o)*90;
	if(i_newOri < -90)
		i_newOri = 180;
	else if(i_newOri > 180)
		i_newOri = -90;
	//std::cout << "o=" << i_o << ", i_oriCurrent=" << i_oriCurrent << ", i_newOri=" << i_newOri << std::endl;
	monJardin->changeOrientation(numtortue, float(i_newOri));
}

bool Driver::mur(int numtortue, float o) {
	Tortue* t = monJardin->getTortues().at(numtortue);
	int posTortueX = t->getX();
	int posTortueY = t->getY();
	
	coordonnee c = getXY(o);
	
	if(monJardin->estMur(posTortueX + c.x, posTortueY + c.y)){
		return true;
	}
	return false;
}

bool Driver::vide(int numtortue, float o) {
	Tortue* t = monJardin->getTortues().at(numtortue);

	coordonnee c = getXY(o);
	
	int posTortueX = t->getX() + c.x;
	int posTortueY = t->getY() + c.y;
	//std::cout << "vid1: x=" << posTortueX << ", y=" << posTortueY << std::endl;
	
	return vide(posTortueX, posTortueY);
}

bool Driver::vide(int x, int y) {
	//std::cout << "vide: posX=" << x << ", posY=" << y << std::endl;
	int xMax = monJardin->tailleJardin().width();
	int yMax = monJardin->tailleJardin().height();
	//std::cout << "xMax=" << xMax << ", yMax=" << yMax << std::endl;
	if((x < 0) || (x >= xMax) || (y < 0) || (y >= yMax)) {
		return false;
	}
	//std::cout << "vide : il y a un mur" << std::endl;
	if(monJardin->estMur(x, y)){
		return false;
	}
	
	//std::cout << "vide : il y a une tortue à cet endroit" << std::endl;
	for(size_t i = 0 ; i < monJardin->getTortues().size() ; i++) {
		Tortue* t = monJardin->getTortues().at(i);
		if((t->getX() == x) && (t->getY() == y)) {
			return false;
		}
	}
	//std::cout << "vide return true" << std::endl;
	return true;
}


void Driver::sauter(int x) {
	for(size_t i = 0 ; i < monJardin->getTortues().size() ; i++) {
		sauter((int)i, x);
	}
}
void Driver::sauter(int numtortue, int x) {
	Tortue* t = monJardin->getTortues().at(numtortue);
	int posX = t->getX();
	int posY = t->getY();
	int ori = (int)t->getOrientation();
	coordonnee c = getXY(ori);
	if(vide(posX+x*c.x, posY+x*c.y)){
		monJardin->changePosition(numtortue, posX+x*c.x, posY+x*c.y);
		std::cout << "Sauter : Pos tortue(" << t->getX() << "," << t->getY() << ") orientation:" << monJardin->orientation(numtortue) << std::endl;
		//std::cout << "Pos tortue(" << t->getX() << "," << t->getY() << ") orientation:" << monJardin->orientation(numtortue) << std::endl;
	}
}

int Driver::htoi(char c)
{
    int ret = int(c)-48;
    if(ret > 9)
    	ret -= 7;
    if(ret > 15)
    	ret -= 32;
	//std::cout << ", ret=" << ret << std::endl;
    return ret;
}

void Driver::modifCouleurCarapace(std::string rgb) {
	for(size_t i = 0 ; i < monJardin->getTortues().size() ; i++) {
		modifCouleurCarapace((int)i, rgb);
	}
}

void Driver::modifCouleurCarapace(int numtortue, std::string rgb) {
	char r1 = rgb.substr(1,1).front();
	char r2 = rgb.substr(2,1).front();	
	char g1 = rgb.substr(3,1).front();
	char g2 = rgb.substr(4,1).front();	
	char b1 = rgb.substr(5,1).front();
	char b2 = rgb.substr(6,1).front();
	monJardin->changeCouleurCarapace(numtortue, htoi(r1)*16+htoi(r2), htoi(g1)*16+htoi(g2), htoi(b1)*16+htoi(b2));
}

void Driver::modifCouleurMotif(std::string rgb) {
	for(size_t i = 0 ; i < monJardin->getTortues().size() ; i++) {
		modifCouleurMotif((int)i, rgb);
	}
}
void Driver::modifCouleurMotif(int numtortue, std::string rgb) {
	char r1 = rgb.substr(1,1).front();
	char r2 = rgb.substr(2,1).front();	
	char g1 = rgb.substr(3,1).front();
	char g2 = rgb.substr(4,1).front();	
	char b1 = rgb.substr(5,1).front();
	char b2 = rgb.substr(6,1).front();
	monJardin->changeCouleurMotif(numtortue, htoi(r1)*16+htoi(r2), htoi(g1)*16+htoi(g2), htoi(b1)*16+htoi(b2));
}

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
