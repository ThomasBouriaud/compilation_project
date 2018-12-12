#include "driver.hh"
#include "jardinRendering.hh"
#include <iostream>

Driver::Driver(JardinRendering * J) {
    monJardin = J;
}

Driver::~Driver() {
	delete monJardin;
}


void Driver::changerPositionTortue(int x, int y) {
    for(size_t i = 0 ; i < monJardin->getTortues().size() ; i++) {
    	monJardin->changePosition((int)i,x,y);
    }
}

void Driver::changerPositionTortue(int numtortue, int x, int y) {
    monJardin->changePosition(numtortue,x,y);
}

float Driver::obtenirOrientationTortue(int numtortue) {
    return monJardin->orientation(numtortue);
}

void Driver::changerCouleurCarapace(int numtortue, int r, int g, int b) {
	monJardin->changeCouleurCarapace(numtortue, r, g, b);
}

void Driver::changerCouleurMotif(int numtortue, int r, int g, int b) {
	monJardin->changeCouleurMotif(numtortue, r, g, b);
}

QPoint Driver::obtenirPosition(int numtortue) {
	return monJardin->position(numtortue);
}

QColor Driver::obtenirCouleurCarapace(int numtortue) {
	return monJardin->couleurCarapace(numtortue);
}

QColor Driver::obtenirCouleurMotif(int numtortue) {
	return monJardin->couleurMotif(numtortue);
}
