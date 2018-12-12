#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <QPoint>
#include <QColor>
#include <QSize>
#include <map>

class JardinRendering;

class Driver {
private:      
    JardinRendering * monJardin;

public:
	Driver(JardinRendering * J);
    ~Driver();
    
    void changerPositionTortue(int x, int y);
    void changerPositionTortue(int numtortue, int x, int y);
    
    std::map<std::string, float> m_map;

    float obtenirOrientationTortue(int numtortue);
	void changerCouleurCarapace(int numtortue, int r, int g, int b);
	void changerCouleurMotif(int numtortue, int r, int g, int b);
	QPoint obtenirPosition(int numtortue);
	QColor obtenirCouleurCarapace(int numtortue);
	QColor obtenirCouleurMotif(int numtortue);
};

#endif


