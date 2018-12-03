#include "driver.hh"
#include "jardinRendering.hh"
#include <iostream>

Driver::Driver(JardinRendering * J) {
    monJardin = J;
}

Driver::~Driver() {
	delete monJardin;
}

/* EXEMPLE
void    Driver::changerPositionTortue0(int x, int y) {
    monJardin->changePosition(0,x,y);
}

float    Driver::obtenirOrientationTortue1() {
    monJardin->orientation(1,o);
}
/*/
