%{

#include "scanner.hh"
#include <string>
#include <cstdlib>

#define YY_NO_UNISTD_H

using token = yy::Parser::token;

#undef  YY_DECL
#define YY_DECL int Scanner::yylex( yy::Parser::semantic_type * const lval, yy::Parser::location_type *loc )

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option c++
%option yyclass="Scanner"
%option noyywrap

%%

%{
    yylval = lval;
%}

"+"	{
	return token::ADD;
}

"-"	{
	return token::SUBS;
}

"*"	{
	return token::MULT;
}

"/"	{
	return token::DIV;
}

"="	{
	return token::EQU;
}

"("	{
	return token::PAR_OPEN;
}

")"	{
	return token::PAR_CLOSE;
}

"fin"	{
	return token::FIN;
}

":"	{
	return token::DEUXPOINTS;
}

("#"[0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F])	{
	yylval->build<std::string>(yytext);
	return token::HEXACOULEUR;
}

"main"		{return token::MAIN;}
"fonction"	{return token::FONCTION;}
"fin fonction"	{return token::FINFONCTION;}

"à gauche"	{return token::DIRECTIONGAUCHE;}
"à droite"	{return token::DIRECTIONDROITE;}
"devant"	{return token::DIRECTIONDEVANT;}
"derriere"	{return token::DIRECTIONDERRIERE;}

"carapace"	{return token::CARAPACE;}
"motif"		{return token::MOTIF;}

"avancer"	{return token::AVANCER;}
"reculer"	{return token::RECULER;}
"sauter"	{return token::SAUTER;}
"tourner"	{return token::TOURNER;}

"fois"		{return token::FOIS;}

"tortues"	{return token::TORTUES;}
"couleur"	{return token::COULEUR;}
"jardin"	{return token::JARDIN;}

"mur"		{return token::MUR;}
"vide"		{return token::VIDE;}

"si"		{return token::SI;}
"sinon"		{return token::SINON;}
"fin si"	{return token::FINSI;}


"tant que"	{return token::TANTQUE;}
"fin tant que"	{return token::FINTANTQUE;}
"repete"	{return token::REPETE;}
"fin repete"	{return token::FINREPETE;}

[a-zA-Z]([a-zA-Z0-9])*	{
	yylval->build<std::string>(yytext);
	return token::NOMFONCTION;
}

'"./"([%-9A-}])+'	{
	yylval->build<std::string>(yytext);
	return token::FILE;
}


("@"[1-9]([0-9])*)	{
	yylval->build<std::string>(yytext);
	return token::NUMEROTORTUE;
}


[0-9]+      {
	yylval->build<int>(std::atoi(yytext));
	return token::NUMBER;
}
	{
	
}
((" "|"\t")*(--(.*))?"\n")+	{
    	loc->lines();
	yylval->build<std::string>(yytext);
	return token::NL;
}

(" "|"\t")+	{
	return token::SPACE;
}

.           {
	return token::RESTE;
}

%%
