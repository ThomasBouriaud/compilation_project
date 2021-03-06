#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <QPoint>
#include <QColor>
#include <QSize>
#include <map>

class JardinRendering;

struct coordonnee {
	int x;
	int y;
};

class Driver {
private:      
    JardinRendering * monJardin;

public:
	Driver(JardinRendering * J);
    ~Driver();
    
    coordonnee getXY(int orientation);
    
    void avancer(int x);
    void avancer(int numtortue, int x);
    
    void reculer(int x);
    void reculer(int numtortue, int x);
    
    void tourner(int x, float o);
	void tourner(int numtortue, int x, float o);
	
	void sauter(int x);
	void sauter(int numtortue, int x);
	
	void modifCouleurCarapace(std::string rgb);
	void modifCouleurCarapace(int numtortue, std::string rgb);
	
	void modifCouleurMotif(std::string rgb);
	void modifCouleurMotif(int numtortue, std::string rgb);
	
	bool mur(int numtortue, float o);
	bool vide(int numtortue, float o);
	bool vide(int x, int y);
	
	int htoi(char s);

	void nombreTortue(int nb);
	
	void newJardin(std::string file);
	//////////////////////////////////////////////////////////////////

    float obtenirOrientationTortue(int numtortue);
	void changerCouleurCarapace(int numtortue, int r, int g, int b);
	void changerCouleurMotif(int numtortue, int r, int g, int b);
	int obtenirPositionX(int numtortue);
	int obtenirPositionY(int numtortue);
	QColor obtenirCouleurCarapace(int numtortue);
	QColor obtenirCouleurMotif(int numtortue);
};

#endif


