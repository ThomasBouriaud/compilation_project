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
%token <std::string>	PARAM
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

%type 		<int>	nombre
%type 		<int>	operation
%type 		<int>	paramAction
%type 		<int>	paramNumTortue
%type 		<int>	directionHorizontale
%type 		<std::string> paramCouleur

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
	| FONCTION SPACE MAIN DEUXPOINTS newLine contenu FINFONCTION newLine fonction {
		std::cout << "main : " << std::endl;
		YYACCEPT;
	}
	| newLine	{} debut
	| {}
	;
	
fonction:
	/* empty */	{
		std::cout << "no other fct than main";
	}
	| FONCTION SPACE NOMFONCTION DEUXPOINTS newLine contenu FINFONCTION newLine	fonction {
		std::cout << "fonction : " << $3 << std::endl;
	}
	;
newLine:
	NL	{
		/*std::cout << "com:" << $1 << std::endl;*/
	}
	;
contenu:
	/* empty */	{
		std::cout << "fin du main >> " << std::endl;
	}
	| commande newLine contenu	{
		std::cout << "cmd >> " << std::endl;
	}
	| condition	newLine contenu	{
		std::cout << "cdt >> " << std::endl;
	} 
	| boucle newLine contenu	{
		std::cout << "bcl >> " << std::endl;
	} 
	| NOMFONCTION parametreFonction newLine contenu	{
		std::cout << "appel fct >> " << std::endl;
	}
	;
parametreFonction:
	/* empty */	{
		std::cout << "pas de param >> " << std::endl;
	}
	| SPACE operation parametreFonction	{
		std::cout << "param ope >> " << std::endl;
	} 
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
	AVANCER paramAction paramNumTortue	{
		if($3 == -1){
			driver.avancer($2);
			std::cout << "avancer de " << $2 << " sur toutes les tortues! ";
		} else{
			driver.avancer($3, $2);
			std::cout << "avancer de " << $2 << " sur la tortue:" << $3 << "! ";
		}
	}
	| RECULER paramAction paramNumTortue	{
		std::cout << "reculer >> ";
		
		if($3 == -1){
			driver.reculer($2);
			std::cout << "recule de " << $2 << " sur toutes les tortues! ";
		} else{
			driver.reculer($3, $2);
			std::cout << "recule de " << $2 << " sur la tortue:" << $3 << "! ";
		}
		
	}
	| SAUTER paramAction paramNumTortue	{
		std::cout << "sauter >> ";
		if($3 == -1){
			driver.sauter($2);
			std::cout << "sauter de " << $2 << " sur toutes les tortues! ";
		} else{
			driver.sauter($3, $2);
			std::cout << "sauter de " << $2 << " sur la tortue:" << $3 << "! ";
		}
	}
	| TOURNER SPACE directionHorizontale paramAction paramNumTortue	{
		std::cout << "tourner >> ";
		if($5 == -1){
			driver.tourner($4, $3);
		} else{
			driver.tourner($5, $4, $3);
		}
	}
	;
paramAction:
	/* empty */		{
		std::cout << "pas de parametres >> ";
		$$=1;
	}
	| SPACE operation	{
		std::cout << "parametre nombre >> ";
		$$=$2;
	}
	| SPACE operation SPACE FOIS	{
		std::cout << "parametre nombre >> ";
		$$=$2;
	}
	| SPACE PARAM	{
		std::cout << "space param >> ";
		$$=1;
	}
	| SPACE PARAM SPACE FOIS	{
		std::cout << "space param fois >> ";
		$$=1;
	}
	;

paramNumTortue:
	/* empty */	{
		std::cout << "pas de tortue >> ";
		$$=-1;
	}
	| SPACE NUMEROTORTUE	{
		std::cout << "OULAAAA >> ";
		$$=std::atoi(($2.substr(1)).c_str())-1;
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
	COULEUR SPACE CARAPACE SPACE paramCouleur paramNumTortue	{
		std::cout << "couleur carapace >> ";
		if($6 == -1){
			driver.modifCouleurCarapace($5);
		} else{
			driver.modifCouleurCarapace($6, $5);
		}
		
	}
	| COULEUR SPACE MOTIF SPACE paramCouleur paramNumTortue	{
		std::cout << "couleur motif >> ";
		if($6 == -1){
			driver.modifCouleurCarapace($5);
		} else{
			driver.modifCouleurCarapace($6, $5);
		}
	}
	| COULEUR SPACE paramCouleur paramNumTortue	{
		std::cout << "couleur rien donc carapace >> ";
		if($4 == -1){
			driver.modifCouleurCarapace($3);
		} else{
			driver.modifCouleurCarapace($4, $3);
		}
	}
	;
paramCouleur:
	HEXACOULEUR	{
		std::cout << "paramcouleur hexa:" << $1;
		$$ = $1;
	}
	;
directionHorizontale:
	DIRECTIONGAUCHE	{
		std::cout << "direction gauche";
		$$=-1;
	}
	| DIRECTIONDROITE	{
		std::cout << "direction droite";
		$$=1;
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
	| PARAM {
		$$ = 1;
	}
	;

%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
