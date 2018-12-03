#ifndef DRIVER_H
#define DRIVER_H

#include <map>
#include <string>
#include <QPoint>
#include <QColor>
#include <QSize>

class JardinRendering;

class Driver {
private:      
    JardinRendering * monJardin;

public:
 Driver(JardinRendering * J);
    ~Driver();

/* EXEMPLE
    void    Driver::changerPositionTortue0(int x, int y);
    float    obtenirOrientationTortue1();
*/ 

};

#endif


