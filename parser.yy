%skeleton "lalr1.cc"
%require "3.0"

%defines
%define parser_class_name { Parser }
%define api.value.type variant
%define parse.assert

%locations

%code requires{
    class Scanner;
    class Driver;
}

%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%code{
    #include <iostream>
    
    #include "scanner.hh"
    #include "driver.hh"
    #include <map>

    #undef  yylex
    #define yylex scanner.yylex
}

%token <std::string>	NL

/* ------------------------------------------- */
%token <std::string>	HEXACOULEUR
%token <std::string>	FILE
%token <std::string>	NUMEROTORTUE
%token <int>			NUMBER
%token <std::string>	COMMENTAIRE
%token <std::string>	NOMFONCTION

%token			DIRECTIONGAUCHE
%token			DIRECTIONDROITE
%token			DIRECTIONDEVANT
%token			DIRECTIONDERRIERE

%token			MUR
%token			VIDE
%token			NON

%token			CARAPACE
%token			MOTIF

%token			JARDIN
%token			COULEUR
%token			TORTUES

%token			DEUXPOINTS
%token			SPACE
%token			SPACEUNNECESSARY
%token			FOIS

%token			SI
%token			SINON
%token			FINSI

%token			TANTQUE
%token			FINTANTQUE
%token			REPETE
%token			FINREPETE

%token			AVANCER
%token			RECULER
%token			SAUTER
%token			TOURNER

%token			MAIN
%token			FONCTION
%token			FINFONCTION

/* ------------------------------------------- */

%token		ADD
%token		SUBS
%token		MULT
%token		DIV
%token		EQU
%token		PAR_OPEN
%token		PAR_CLOSE
%token		FIN
%token		RESTE

%type 		<float>	nombre
%type 		<float>	operation
%type 		<std::map<std::string, int>> paramAction

%right		EQU
%right		SUBS ADD
%right		DIV MULT
%precedence	NEG

%%

debut:
	FONCTION SPACE MAIN DEUXPOINTS newLine contenu FINFONCTION	{
		std::cout << "main sans rien après : " << std::endl;
		YYACCEPT;
	}
	| FONCTION SPACE MAIN DEUXPOINTS newLine contenu FINFONCTION newLine	{
		std::cout << "main : " << std::endl;
		YYACCEPT;
	} fonction
	| newLine	{} debut
	;
	
fonction:
	/* empty */	{
		std::cout << "no other fct than main";
	}
	| FONCTION SPACE NOMFONCTION DEUXPOINTS newLine contenu FINFONCTION newLine	{
		std::cout << "fonction : " << $3 << std::endl;
	} fonction
	;
newLine:
	NL	{
		std::cout << "com:" << $1 << std::endl;
	}
	;
contenu:
	/* empty */	{
		std::cout << "empty content >> " << std::endl;
	}
	| commande	{
		std::cout << "cmd >> " << std::endl;
	} newLine contenu
	| condition	{
		std::cout << "cdt >> " << std::endl;
	} newLine contenu
	| boucle	{
		std::cout << "bcl >> " << std::endl;
	} newLine contenu
	| NOMFONCTION parametreFonction	{
		std::cout << "appel fct >> " << std::endl;
	} newLine contenu
	;
parametreFonction:
	/* empty */	{
		std::cout << "pas de param >> " << std::endl;
	}
	| SPACE HEXACOULEUR	{
		std::cout << "param hexa >> " << std::endl;
	} parametreFonction
	| SPACE NUMEROTORTUE	{
		std::cout << "param num tortue >> " << std::endl;
	} parametreFonction
	| SPACE operation	{
		std::cout << "param ope >> " << std::endl;
	} parametreFonction
	;
commande:
	mouvement	{
		std::cout << "mouvement >> ";
	}
	| nombreTortues	{
		std::cout << "nombreTortues >> ";
	}
	| couleur	{
		std::cout << "couleur >> ";
	}
	| jardin	{
		std::cout << "jardin >> ";
	}
	;
mouvement:
	AVANCER paramAction	{
		std::cout << "avancer >> ";
	}
	| RECULER paramAction	{
		std::cout << "reculer >> ";
	}
	| SAUTER paramAction	{
		std::cout << "sauter >> ";
	}
	| TOURNER SPACE directionHorizontale paramAction	{
		std::cout << "tourner >> ";
	}
	;
paramAction:
	/* empty */	{
		std::cout << "pas de parametres >> ";
	}
	| SPACE operation	{
		std::cout << "parametre nombre >> ";
		driver.m_map.insert(std::pair<std::string,float>(std::string("operation"),$2));
	}
	| SPACE operation SPACE FOIS	{
		std::cout << "parametre fois >> ";
		driver.m_map.insert(std::pair<std::string,float>(std::string("operation"),$2));
	}
	| SPACE operation SPACE NUMEROTORTUE	{
		std::cout << "parametre nombre numero tortue : " << $4 << " >> ";
		driver.m_map.insert(std::pair<std::string,float>(std::string("operation"),$2));
		float nb = std::stof($4.substr(1));
		driver.m_map.insert(std::pair<std::string,float>(std::string("numtortue"),nb));

		std::map<std::string,float>::iterator it = driver.m_map.begin();
		for (it=driver.m_map.begin(); it!=driver.m_map.end(); ++it)
    			std::cout << it->first << " => " << it->second << '\n';
	}
	| SPACE operation SPACE FOIS SPACE NUMEROTORTUE	{
		std::cout << "parametre nombre fois numero tortue : " << $6 << " >> ";
		driver.m_map.insert(std::pair<std::string,float>(std::string("operation"),$2));
		float nb = std::stof($6.substr(1));
		driver.m_map.insert(std::pair<std::string,float>(std::string("numtortue"),nb));
	}
	| SPACE NUMEROTORTUE	{
		std::cout << "parametre tortue : " << $2 << " >> ";
		float nb = std::stof($2.substr(1));
		driver.m_map.insert(std::pair<std::string,float>(std::string("numtortue"),nb));
	}
	;

jardin:
	JARDIN SPACE FILE	{
		std::cout << "jardin file:" << $3;
	}
	;
condition:
	SI SPACE composanteCondition DEUXPOINTS newLine contenu FINSI	{
		std::cout << "si simple";
	}
	| SI SPACE composanteCondition DEUXPOINTS newLine contenu SINON DEUXPOINTS newLine contenu FINSI	{
		std::cout << "si sinon";
	}
	;
boucle:
	TANTQUE SPACE composanteCondition DEUXPOINTS newLine contenu FINTANTQUE	{
		std::cout << "tant que";
	}
	| REPETE SPACE operation SPACE FOIS DEUXPOINTS newLine contenu FINREPETE	{
		std::cout << "repete fois" << std::endl;
	}
	| REPETE SPACE operation DEUXPOINTS newLine contenu FINREPETE	{
		std::cout << "repete sans fois";
	}
	;
composanteCondition:
	negation MUR SPACE conditionParametres		{}
	| negation VIDE SPACE conditionParametres	{}
	;
conditionParametres:
	directionHorizontale	{
		std::cout << "mur dir horizontal >> ";
	}
	| directionVerticale	{
		std::cout << "mur dir verticale >> ";
	}
	| directionHorizontale SPACE NUMEROTORTUE	{
		std::cout << "mur dir horizontal et tortue >> ";
	}
	| directionVerticale SPACE NUMEROTORTUE	{
		std::cout << "mur dir verticale et tortue >> ";
	}
	;
negation:
	/* empty */	{
		std::cout << "positif >> ";
	}
	| NON SPACE	{
		std::cout << "negation >> ";
	}
	;

nombreTortues:
	TORTUES SPACE operation	{
		std::cout << "nb tortue";
	}
	;
couleur:
	COULEUR SPACE CARAPACE SPACE paramCouleur	{
		std::cout << "couleur carapace >> ";
	}
	| COULEUR SPACE MOTIF SPACE paramCouleur	{
		std::cout << "couleur motif >> ";
	}
	| COULEUR SPACE paramCouleur	{
		std::cout << "couleur rien donc carapace >> ";
	}
	;
paramCouleur:
	HEXACOULEUR	{
		std::cout << "paramcouleur hexa:" << $1;
	}
	| HEXACOULEUR SPACE NUMEROTORTUE	{
		std::cout << "paramcouleur hexa:" << $1 << ", numero tortue:" << $3;
	}
	;
directionHorizontale:
	DIRECTIONGAUCHE	{
		std::cout << "direction gauche";
	}
	| DIRECTIONDROITE	{
		std::cout << "direction droite";
	}
	;
directionVerticale:
	DIRECTIONDEVANT	{
		std::cout << "direction devant";
	}
	| DIRECTIONDERRIERE	{
		std::cout << "direction derriere";
	}
	;
operation:
	nombre {
		/*std::cout << "nombre >> ";*/
		$$ = $1;
	}
	| SUBS %prec NEG operation {
		$$ = - $2;
	}
	| PAR_OPEN operation PAR_CLOSE{
		$$ = $2;
	}
	| nombre MULT operation {
		$$ = $1 * $3;
		//std::cout << "multiplication: ";
	}
	| nombre DIV operation {
		if($3==0){
			std::cout << "ERREUR : division par zéro!!!";
			//YYERROR;
		}else{
			$$ = $1 / $3;
			//std::cout << "division: ";
		}
	}
	| nombre ADD operation {
		$$ = $1 + $3;
		//std::cout << "somme: ";
	}
	| nombre SUBS operation {
		$$ = $1 - $3;
		//std::cout << "soustraction: ";
	}
	;
nombre:
	NUMBER {
		std::cout << "entier: " << $1 << std::endl;
		$$ = $1;
	}
    	;
%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
