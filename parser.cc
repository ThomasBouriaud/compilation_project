// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "parser.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.hh"

// User implementation prologue.

#line 51 "parser.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 19 "parser.yy" // lalr1.cc:413

    #include <iostream>
    
    #include "scanner.hh"
    #include "driver.hh"
    #include <map>

    #undef  yylex
    #define yylex scanner.yylex

#line 64 "parser.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 150 "parser.cc" // lalr1.cc:479

  /// Build a parser object.
   Parser :: Parser  (Scanner &scanner_yyarg, Driver &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

   Parser ::~ Parser  ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
   Parser ::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
   Parser ::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 8: // NUMBER
      case 60: // paramAction
      case 61: // paramNumTortue
      case 71: // directionHorizontale
      case 73: // operation
      case 74: // nombre
        value.copy< int > (other.value);
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 7: // PARAM
      case 9: // COMMENTAIRE
      case 10: // NOMFONCTION
      case 70: // paramCouleur
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 8: // NUMBER
      case 60: // paramAction
      case 61: // paramNumTortue
      case 71: // directionHorizontale
      case 73: // operation
      case 74: // nombre
        value.copy< int > (v);
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 7: // PARAM
      case 9: // COMMENTAIRE
      case 10: // NOMFONCTION
      case 70: // paramCouleur
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const int v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
   Parser ::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
   Parser ::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 8: // NUMBER
      case 60: // paramAction
      case 61: // paramNumTortue
      case 71: // directionHorizontale
      case 73: // operation
      case 74: // nombre
        value.template destroy< int > ();
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 7: // PARAM
      case 9: // COMMENTAIRE
      case 10: // NOMFONCTION
      case 70: // paramCouleur
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
   Parser ::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 8: // NUMBER
      case 60: // paramAction
      case 61: // paramNumTortue
      case 71: // directionHorizontale
      case 73: // operation
      case 74: // nombre
        value.move< int > (s.value);
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 7: // PARAM
      case 9: // COMMENTAIRE
      case 10: // NOMFONCTION
      case 70: // paramCouleur
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
   Parser ::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
   Parser ::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
   Parser ::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
   Parser ::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
   Parser ::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
   Parser ::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
   Parser ::symbol_type
   Parser ::make_NL (const std::string& v, const location_type& l)
  {
    return symbol_type (token::NL, v, l);
  }

   Parser ::symbol_type
   Parser ::make_HEXACOULEUR (const std::string& v, const location_type& l)
  {
    return symbol_type (token::HEXACOULEUR, v, l);
  }

   Parser ::symbol_type
   Parser ::make_FILE (const std::string& v, const location_type& l)
  {
    return symbol_type (token::FILE, v, l);
  }

   Parser ::symbol_type
   Parser ::make_NUMEROTORTUE (const std::string& v, const location_type& l)
  {
    return symbol_type (token::NUMEROTORTUE, v, l);
  }

   Parser ::symbol_type
   Parser ::make_PARAM (const std::string& v, const location_type& l)
  {
    return symbol_type (token::PARAM, v, l);
  }

   Parser ::symbol_type
   Parser ::make_NUMBER (const int& v, const location_type& l)
  {
    return symbol_type (token::NUMBER, v, l);
  }

   Parser ::symbol_type
   Parser ::make_COMMENTAIRE (const std::string& v, const location_type& l)
  {
    return symbol_type (token::COMMENTAIRE, v, l);
  }

   Parser ::symbol_type
   Parser ::make_NOMFONCTION (const std::string& v, const location_type& l)
  {
    return symbol_type (token::NOMFONCTION, v, l);
  }

   Parser ::symbol_type
   Parser ::make_DIRECTIONGAUCHE (const location_type& l)
  {
    return symbol_type (token::DIRECTIONGAUCHE, l);
  }

   Parser ::symbol_type
   Parser ::make_DIRECTIONDROITE (const location_type& l)
  {
    return symbol_type (token::DIRECTIONDROITE, l);
  }

   Parser ::symbol_type
   Parser ::make_DIRECTIONDEVANT (const location_type& l)
  {
    return symbol_type (token::DIRECTIONDEVANT, l);
  }

   Parser ::symbol_type
   Parser ::make_DIRECTIONDERRIERE (const location_type& l)
  {
    return symbol_type (token::DIRECTIONDERRIERE, l);
  }

   Parser ::symbol_type
   Parser ::make_MUR (const location_type& l)
  {
    return symbol_type (token::MUR, l);
  }

   Parser ::symbol_type
   Parser ::make_VIDE (const location_type& l)
  {
    return symbol_type (token::VIDE, l);
  }

   Parser ::symbol_type
   Parser ::make_NON (const location_type& l)
  {
    return symbol_type (token::NON, l);
  }

   Parser ::symbol_type
   Parser ::make_CARAPACE (const location_type& l)
  {
    return symbol_type (token::CARAPACE, l);
  }

   Parser ::symbol_type
   Parser ::make_MOTIF (const location_type& l)
  {
    return symbol_type (token::MOTIF, l);
  }

   Parser ::symbol_type
   Parser ::make_JARDIN (const location_type& l)
  {
    return symbol_type (token::JARDIN, l);
  }

   Parser ::symbol_type
   Parser ::make_COULEUR (const location_type& l)
  {
    return symbol_type (token::COULEUR, l);
  }

   Parser ::symbol_type
   Parser ::make_TORTUES (const location_type& l)
  {
    return symbol_type (token::TORTUES, l);
  }

   Parser ::symbol_type
   Parser ::make_DEUXPOINTS (const location_type& l)
  {
    return symbol_type (token::DEUXPOINTS, l);
  }

   Parser ::symbol_type
   Parser ::make_SPACE (const location_type& l)
  {
    return symbol_type (token::SPACE, l);
  }

   Parser ::symbol_type
   Parser ::make_SPACEUNNECESSARY (const location_type& l)
  {
    return symbol_type (token::SPACEUNNECESSARY, l);
  }

   Parser ::symbol_type
   Parser ::make_FOIS (const location_type& l)
  {
    return symbol_type (token::FOIS, l);
  }

   Parser ::symbol_type
   Parser ::make_SI (const location_type& l)
  {
    return symbol_type (token::SI, l);
  }

   Parser ::symbol_type
   Parser ::make_SINON (const location_type& l)
  {
    return symbol_type (token::SINON, l);
  }

   Parser ::symbol_type
   Parser ::make_FINSI (const location_type& l)
  {
    return symbol_type (token::FINSI, l);
  }

   Parser ::symbol_type
   Parser ::make_TANTQUE (const location_type& l)
  {
    return symbol_type (token::TANTQUE, l);
  }

   Parser ::symbol_type
   Parser ::make_FINTANTQUE (const location_type& l)
  {
    return symbol_type (token::FINTANTQUE, l);
  }

   Parser ::symbol_type
   Parser ::make_REPETE (const location_type& l)
  {
    return symbol_type (token::REPETE, l);
  }

   Parser ::symbol_type
   Parser ::make_FINREPETE (const location_type& l)
  {
    return symbol_type (token::FINREPETE, l);
  }

   Parser ::symbol_type
   Parser ::make_AVANCER (const location_type& l)
  {
    return symbol_type (token::AVANCER, l);
  }

   Parser ::symbol_type
   Parser ::make_RECULER (const location_type& l)
  {
    return symbol_type (token::RECULER, l);
  }

   Parser ::symbol_type
   Parser ::make_SAUTER (const location_type& l)
  {
    return symbol_type (token::SAUTER, l);
  }

   Parser ::symbol_type
   Parser ::make_TOURNER (const location_type& l)
  {
    return symbol_type (token::TOURNER, l);
  }

   Parser ::symbol_type
   Parser ::make_MAIN (const location_type& l)
  {
    return symbol_type (token::MAIN, l);
  }

   Parser ::symbol_type
   Parser ::make_FONCTION (const location_type& l)
  {
    return symbol_type (token::FONCTION, l);
  }

   Parser ::symbol_type
   Parser ::make_FINFONCTION (const location_type& l)
  {
    return symbol_type (token::FINFONCTION, l);
  }

   Parser ::symbol_type
   Parser ::make_ADD (const location_type& l)
  {
    return symbol_type (token::ADD, l);
  }

   Parser ::symbol_type
   Parser ::make_SUBS (const location_type& l)
  {
    return symbol_type (token::SUBS, l);
  }

   Parser ::symbol_type
   Parser ::make_MULT (const location_type& l)
  {
    return symbol_type (token::MULT, l);
  }

   Parser ::symbol_type
   Parser ::make_DIV (const location_type& l)
  {
    return symbol_type (token::DIV, l);
  }

   Parser ::symbol_type
   Parser ::make_EQU (const location_type& l)
  {
    return symbol_type (token::EQU, l);
  }

   Parser ::symbol_type
   Parser ::make_PAR_OPEN (const location_type& l)
  {
    return symbol_type (token::PAR_OPEN, l);
  }

   Parser ::symbol_type
   Parser ::make_PAR_CLOSE (const location_type& l)
  {
    return symbol_type (token::PAR_CLOSE, l);
  }

   Parser ::symbol_type
   Parser ::make_FIN (const location_type& l)
  {
    return symbol_type (token::FIN, l);
  }

   Parser ::symbol_type
   Parser ::make_RESTE (const location_type& l)
  {
    return symbol_type (token::RESTE, l);
  }

   Parser ::symbol_type
   Parser ::make_NEG (const location_type& l)
  {
    return symbol_type (token::NEG, l);
  }



  // by_state.
  inline
   Parser ::by_state::by_state ()
    : state (empty_state)
  {}

  inline
   Parser ::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
   Parser ::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
   Parser ::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
   Parser ::symbol_number_type
   Parser ::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
   Parser ::stack_symbol_type::stack_symbol_type ()
  {}


  inline
   Parser ::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 8: // NUMBER
      case 60: // paramAction
      case 61: // paramNumTortue
      case 71: // directionHorizontale
      case 73: // operation
      case 74: // nombre
        value.move< int > (that.value);
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 7: // PARAM
      case 9: // COMMENTAIRE
      case 10: // NOMFONCTION
      case 70: // paramCouleur
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 8: // NUMBER
      case 60: // paramAction
      case 61: // paramNumTortue
      case 71: // directionHorizontale
      case 73: // operation
      case 74: // nombre
        value.copy< int > (that.value);
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 7: // PARAM
      case 9: // COMMENTAIRE
      case 10: // NOMFONCTION
      case 70: // paramCouleur
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
   Parser ::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
   Parser ::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
   Parser ::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline  Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
   Parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
   Parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 8: // NUMBER
      case 60: // paramAction
      case 61: // paramNumTortue
      case 71: // directionHorizontale
      case 73: // operation
      case 74: // nombre
        yylhs.value.build< int > ();
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 7: // PARAM
      case 9: // COMMENTAIRE
      case 10: // NOMFONCTION
      case 70: // paramCouleur
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 107 "parser.yy" // lalr1.cc:859
    {
		std::cout << "main sans rien après : " << std::endl;
		YYACCEPT;
	}
#line 1080 "parser.cc" // lalr1.cc:859
    break;

  case 3:
#line 111 "parser.yy" // lalr1.cc:859
    {
		std::cout << "main : " << std::endl;
		YYACCEPT;
	}
#line 1089 "parser.cc" // lalr1.cc:859
    break;

  case 4:
#line 115 "parser.yy" // lalr1.cc:859
    {}
#line 1095 "parser.cc" // lalr1.cc:859
    break;

  case 6:
#line 116 "parser.yy" // lalr1.cc:859
    {}
#line 1101 "parser.cc" // lalr1.cc:859
    break;

  case 7:
#line 120 "parser.yy" // lalr1.cc:859
    {
		std::cout << "no other fct than main";
	}
#line 1109 "parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 123 "parser.yy" // lalr1.cc:859
    {
		std::cout << "fonction : " << yystack_[6].value.as< std::string > () << std::endl;
	}
#line 1117 "parser.cc" // lalr1.cc:859
    break;

  case 9:
#line 128 "parser.yy" // lalr1.cc:859
    {
		/*std::cout << "com:" << $1 << std::endl;*/
	}
#line 1125 "parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 133 "parser.yy" // lalr1.cc:859
    {
		std::cout << "fin du main >> " << std::endl;
	}
#line 1133 "parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 136 "parser.yy" // lalr1.cc:859
    {
		std::cout << "cmd >> " << std::endl;
	}
#line 1141 "parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 139 "parser.yy" // lalr1.cc:859
    {
		std::cout << "cdt >> " << std::endl;
	}
#line 1149 "parser.cc" // lalr1.cc:859
    break;

  case 13:
#line 142 "parser.yy" // lalr1.cc:859
    {
		std::cout << "bcl >> " << std::endl;
	}
#line 1157 "parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 145 "parser.yy" // lalr1.cc:859
    {
		std::cout << "appel fct >> " << std::endl;
	}
#line 1165 "parser.cc" // lalr1.cc:859
    break;

  case 15:
#line 150 "parser.yy" // lalr1.cc:859
    {
		std::cout << "pas de param >> " << std::endl;
	}
#line 1173 "parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 153 "parser.yy" // lalr1.cc:859
    {
		std::cout << "param ope >> " << std::endl;
	}
#line 1181 "parser.cc" // lalr1.cc:859
    break;

  case 17:
#line 158 "parser.yy" // lalr1.cc:859
    {
		std::cout << "mouvement >> ";
	}
#line 1189 "parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 161 "parser.yy" // lalr1.cc:859
    {
		std::cout << "nombreTortues >> ";
	}
#line 1197 "parser.cc" // lalr1.cc:859
    break;

  case 19:
#line 164 "parser.yy" // lalr1.cc:859
    {
		std::cout << "couleur >> ";
	}
#line 1205 "parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 167 "parser.yy" // lalr1.cc:859
    {
		std::cout << "jardin >> ";
	}
#line 1213 "parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 172 "parser.yy" // lalr1.cc:859
    {
		if(yystack_[0].value.as< int > () == -1){
			driver.avancer(yystack_[1].value.as< int > ());
			std::cout << "avancer de " << yystack_[1].value.as< int > () << " sur toutes les tortues! ";
		} else{
			driver.avancer(yystack_[0].value.as< int > (), yystack_[1].value.as< int > ());
			std::cout << "avancer de " << yystack_[1].value.as< int > () << " sur la tortue:" << yystack_[0].value.as< int > () << "! ";
		}
	}
#line 1227 "parser.cc" // lalr1.cc:859
    break;

  case 22:
#line 181 "parser.yy" // lalr1.cc:859
    {
		std::cout << "reculer >> ";
		
		if(yystack_[0].value.as< int > () == -1){
			driver.reculer(yystack_[1].value.as< int > ());
			std::cout << "recule de " << yystack_[1].value.as< int > () << " sur toutes les tortues! ";
		} else{
			driver.reculer(yystack_[0].value.as< int > (), yystack_[1].value.as< int > ());
			std::cout << "recule de " << yystack_[1].value.as< int > () << " sur la tortue:" << yystack_[0].value.as< int > () << "! ";
		}
		
	}
#line 1244 "parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 193 "parser.yy" // lalr1.cc:859
    {
		std::cout << "sauter >> ";
		if(yystack_[0].value.as< int > () == -1){
			driver.sauter(yystack_[1].value.as< int > ());
			std::cout << "sauter de " << yystack_[1].value.as< int > () << " sur toutes les tortues! ";
		} else{
			driver.sauter(yystack_[0].value.as< int > (), yystack_[1].value.as< int > ());
			std::cout << "sauter de " << yystack_[1].value.as< int > () << " sur la tortue:" << yystack_[0].value.as< int > () << "! ";
		}
	}
#line 1259 "parser.cc" // lalr1.cc:859
    break;

  case 24:
#line 203 "parser.yy" // lalr1.cc:859
    {
		std::cout << "tourner >> ";
		if(yystack_[0].value.as< int > () == -1){
			driver.tourner(yystack_[1].value.as< int > (), yystack_[2].value.as< int > ());
		} else{
			driver.tourner(yystack_[0].value.as< int > (), yystack_[1].value.as< int > (), yystack_[2].value.as< int > ());
		}
	}
#line 1272 "parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 213 "parser.yy" // lalr1.cc:859
    {
		std::cout << "pas de parametres >> ";
		yylhs.value.as< int > ()=1;
	}
#line 1281 "parser.cc" // lalr1.cc:859
    break;

  case 26:
#line 217 "parser.yy" // lalr1.cc:859
    {
		std::cout << "parametre nombre >> ";
		yylhs.value.as< int > ()=yystack_[0].value.as< int > ();
	}
#line 1290 "parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 221 "parser.yy" // lalr1.cc:859
    {
		std::cout << "parametre nombre >> ";
		yylhs.value.as< int > ()=yystack_[2].value.as< int > ();
	}
#line 1299 "parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 225 "parser.yy" // lalr1.cc:859
    {
		std::cout << "space param >> ";
		yylhs.value.as< int > ()=1;
	}
#line 1308 "parser.cc" // lalr1.cc:859
    break;

  case 29:
#line 229 "parser.yy" // lalr1.cc:859
    {
		std::cout << "space param fois >> ";
		yylhs.value.as< int > ()=1;
	}
#line 1317 "parser.cc" // lalr1.cc:859
    break;

  case 30:
#line 236 "parser.yy" // lalr1.cc:859
    {
		std::cout << "pas de tortue >> ";
		yylhs.value.as< int > ()=-1;
	}
#line 1326 "parser.cc" // lalr1.cc:859
    break;

  case 31:
#line 240 "parser.yy" // lalr1.cc:859
    {
		std::cout << "OULAAAA >> ";
		yylhs.value.as< int > ()=std::atoi((yystack_[0].value.as< std::string > ().substr(1)).c_str())-1;
	}
#line 1335 "parser.cc" // lalr1.cc:859
    break;

  case 32:
#line 247 "parser.yy" // lalr1.cc:859
    {
		std::cout << "jardin file:" << yystack_[0].value.as< std::string > ();
	}
#line 1343 "parser.cc" // lalr1.cc:859
    break;

  case 33:
#line 252 "parser.yy" // lalr1.cc:859
    {
		std::cout << "si simple";
	}
#line 1351 "parser.cc" // lalr1.cc:859
    break;

  case 34:
#line 255 "parser.yy" // lalr1.cc:859
    {
		std::cout << "si sinon";
	}
#line 1359 "parser.cc" // lalr1.cc:859
    break;

  case 35:
#line 260 "parser.yy" // lalr1.cc:859
    {
		std::cout << "tant que";
	}
#line 1367 "parser.cc" // lalr1.cc:859
    break;

  case 36:
#line 263 "parser.yy" // lalr1.cc:859
    {
		std::cout << "repete fois" << std::endl;
	}
#line 1375 "parser.cc" // lalr1.cc:859
    break;

  case 37:
#line 266 "parser.yy" // lalr1.cc:859
    {
		std::cout << "repete sans fois";
	}
#line 1383 "parser.cc" // lalr1.cc:859
    break;

  case 38:
#line 271 "parser.yy" // lalr1.cc:859
    {}
#line 1389 "parser.cc" // lalr1.cc:859
    break;

  case 39:
#line 272 "parser.yy" // lalr1.cc:859
    {}
#line 1395 "parser.cc" // lalr1.cc:859
    break;

  case 40:
#line 275 "parser.yy" // lalr1.cc:859
    {
		std::cout << "mur dir horizontal >> ";
	}
#line 1403 "parser.cc" // lalr1.cc:859
    break;

  case 41:
#line 278 "parser.yy" // lalr1.cc:859
    {
		std::cout << "mur dir verticale >> ";
	}
#line 1411 "parser.cc" // lalr1.cc:859
    break;

  case 42:
#line 281 "parser.yy" // lalr1.cc:859
    {
		std::cout << "mur dir horizontal et tortue >> ";
	}
#line 1419 "parser.cc" // lalr1.cc:859
    break;

  case 43:
#line 284 "parser.yy" // lalr1.cc:859
    {
		std::cout << "mur dir verticale et tortue >> ";
	}
#line 1427 "parser.cc" // lalr1.cc:859
    break;

  case 44:
#line 289 "parser.yy" // lalr1.cc:859
    {
		std::cout << "positif >> ";
	}
#line 1435 "parser.cc" // lalr1.cc:859
    break;

  case 45:
#line 292 "parser.yy" // lalr1.cc:859
    {
		std::cout << "negation >> ";
	}
#line 1443 "parser.cc" // lalr1.cc:859
    break;

  case 46:
#line 298 "parser.yy" // lalr1.cc:859
    {
		std::cout << "nb tortue";
	}
#line 1451 "parser.cc" // lalr1.cc:859
    break;

  case 47:
#line 303 "parser.yy" // lalr1.cc:859
    {
		std::cout << "couleur carapace >> ";
		if(yystack_[0].value.as< int > () == -1){
			driver.modifCouleurCarapace(yystack_[1].value.as< std::string > ());
		} else{
			driver.modifCouleurCarapace(yystack_[0].value.as< int > (), yystack_[1].value.as< std::string > ());
		}
		
	}
#line 1465 "parser.cc" // lalr1.cc:859
    break;

  case 48:
#line 312 "parser.yy" // lalr1.cc:859
    {
		std::cout << "couleur motif >> ";
		if(yystack_[0].value.as< int > () == -1){
			driver.modifCouleurCarapace(yystack_[1].value.as< std::string > ());
		} else{
			driver.modifCouleurCarapace(yystack_[0].value.as< int > (), yystack_[1].value.as< std::string > ());
		}
	}
#line 1478 "parser.cc" // lalr1.cc:859
    break;

  case 49:
#line 320 "parser.yy" // lalr1.cc:859
    {
		std::cout << "couleur rien donc carapace >> ";
		if(yystack_[0].value.as< int > () == -1){
			driver.modifCouleurCarapace(yystack_[1].value.as< std::string > ());
		} else{
			driver.modifCouleurCarapace(yystack_[0].value.as< int > (), yystack_[1].value.as< std::string > ());
		}
	}
#line 1491 "parser.cc" // lalr1.cc:859
    break;

  case 50:
#line 330 "parser.yy" // lalr1.cc:859
    {
		std::cout << "paramcouleur hexa:" << yystack_[0].value.as< std::string > ();
		yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
	}
#line 1500 "parser.cc" // lalr1.cc:859
    break;

  case 51:
#line 336 "parser.yy" // lalr1.cc:859
    {
		std::cout << "direction gauche";
		yylhs.value.as< int > ()=-1;
	}
#line 1509 "parser.cc" // lalr1.cc:859
    break;

  case 52:
#line 340 "parser.yy" // lalr1.cc:859
    {
		std::cout << "direction droite";
		yylhs.value.as< int > ()=1;
	}
#line 1518 "parser.cc" // lalr1.cc:859
    break;

  case 53:
#line 346 "parser.yy" // lalr1.cc:859
    {
		std::cout << "direction devant";
	}
#line 1526 "parser.cc" // lalr1.cc:859
    break;

  case 54:
#line 349 "parser.yy" // lalr1.cc:859
    {
		std::cout << "direction derriere";
	}
#line 1534 "parser.cc" // lalr1.cc:859
    break;

  case 55:
#line 354 "parser.yy" // lalr1.cc:859
    {
		/*std::cout << "nombre >> ";*/
		yylhs.value.as< int > () = yystack_[0].value.as< int > ();
	}
#line 1543 "parser.cc" // lalr1.cc:859
    break;

  case 56:
#line 358 "parser.yy" // lalr1.cc:859
    {
		yylhs.value.as< int > () = - yystack_[0].value.as< int > ();
	}
#line 1551 "parser.cc" // lalr1.cc:859
    break;

  case 57:
#line 361 "parser.yy" // lalr1.cc:859
    {
		yylhs.value.as< int > () = yystack_[1].value.as< int > ();
	}
#line 1559 "parser.cc" // lalr1.cc:859
    break;

  case 58:
#line 364 "parser.yy" // lalr1.cc:859
    {
		yylhs.value.as< int > () = yystack_[2].value.as< int > () * yystack_[0].value.as< int > ();
		//std::cout << "multiplication: ";
	}
#line 1568 "parser.cc" // lalr1.cc:859
    break;

  case 59:
#line 368 "parser.yy" // lalr1.cc:859
    {
		if(yystack_[0].value.as< int > ()==0){
			std::cout << "ERREUR : division par zéro!!!";
			//YYERROR;
		}else{
			yylhs.value.as< int > () = yystack_[2].value.as< int > () / yystack_[0].value.as< int > ();
			//std::cout << "division: ";
		}
	}
#line 1582 "parser.cc" // lalr1.cc:859
    break;

  case 60:
#line 377 "parser.yy" // lalr1.cc:859
    {
		yylhs.value.as< int > () = yystack_[2].value.as< int > () + yystack_[0].value.as< int > ();
		//std::cout << "somme: ";
	}
#line 1591 "parser.cc" // lalr1.cc:859
    break;

  case 61:
#line 381 "parser.yy" // lalr1.cc:859
    {
		yylhs.value.as< int > () = yystack_[2].value.as< int > () - yystack_[0].value.as< int > ();
		//std::cout << "soustraction: ";
	}
#line 1600 "parser.cc" // lalr1.cc:859
    break;

  case 62:
#line 387 "parser.yy" // lalr1.cc:859
    {
		std::cout << "entier: " << yystack_[0].value.as< int > () << std::endl;
		yylhs.value.as< int > () = yystack_[0].value.as< int > ();
	}
#line 1609 "parser.cc" // lalr1.cc:859
    break;

  case 63:
#line 391 "parser.yy" // lalr1.cc:859
    {
		yylhs.value.as< int > () = 1;
	}
#line 1617 "parser.cc" // lalr1.cc:859
    break;


#line 1621 "parser.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
   Parser ::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char  Parser ::yypact_ninf_ = -45;

  const signed char  Parser ::yytable_ninf_ = -29;

  const signed char
   Parser ::yypact_[] =
  {
       1,   -45,    13,    39,   -45,   -27,   -45,     1,    19,   -45,
      41,    11,    25,    31,    38,    44,    47,    66,    67,    68,
      68,    68,    69,    40,    41,   -45,   -45,    41,    41,   -45,
     -45,     8,    41,    60,    56,     8,    77,    77,     8,    21,
      72,    72,    72,    15,    41,    11,    11,    11,   -45,   -45,
       8,     8,    25,    35,    11,   -45,   -45,    73,    74,    72,
     -45,    76,    80,     4,    81,    12,    27,    82,    93,   -45,
     -45,   -45,   -45,   -45,    68,    70,   -45,   -45,   -45,   -45,
      58,   -45,     8,     8,     8,     8,   -45,   103,   103,   -45,
     -45,    41,    84,    86,    41,    41,    85,    87,    88,   -45,
      72,    91,   -45,   -45,   -45,   -45,   -45,   -45,    72,    72,
      11,    75,    75,    11,    11,    89,   -45,   -45,   -45,   106,
     -45,   -45,    24,   -45,   -45,   -45,    94,    95,   -45,    92,
      96,    41,    97,    99,   -45,   111,   118,   -45,   -45,    11,
      41,    41,   -45,   -45,   100,    11,    11,   -45,    98,   105,
      41,   -45,    70,   -45
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       6,     9,     0,     0,     4,     0,     1,     6,     0,     5,
       0,    10,    15,     0,     0,     0,     0,     0,     0,    25,
      25,    25,     0,     0,     0,    17,    20,     0,     0,    18,
      19,     0,     0,     0,     0,     0,    44,    44,     0,     0,
      30,    30,    30,     0,     2,    10,    10,    10,    63,    62,
       0,     0,    15,    55,    10,    32,    50,     0,     0,    30,
      46,     0,     0,     0,     0,     0,    63,    26,     0,    21,
      22,    23,    51,    52,    25,     7,    11,    12,    13,    56,
       0,    16,     0,     0,     0,     0,    14,     0,     0,    49,
      45,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      30,     0,     3,    57,    60,    61,    58,    59,    30,    30,
      10,     0,     0,    10,    10,     0,    29,    27,    24,     0,
      47,    48,     0,    53,    54,    38,    40,    41,    39,     0,
       0,     0,     0,     0,    33,     0,     0,    35,    37,    10,
       0,     0,    42,    43,     0,    10,    10,    36,     0,     0,
       0,    34,     7,     8
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -45,   119,   -45,   -25,   -10,   -44,    83,   -45,   -45,   -13,
     -36,   -45,   -45,   -45,   102,    16,   -45,   -45,   -45,    -5,
     101,   -45,   -26,   -45
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
      -1,     3,     7,   102,     4,    23,    32,    24,    25,    40,
      69,    26,    27,    28,    62,   125,    63,    29,    30,    59,
     126,   127,    52,    53
  };

  const short int
   Parser ::yytable_[] =
  {
      11,    76,    77,    78,     1,    70,    71,    41,    42,    60,
      86,     8,    65,    67,    45,    48,    49,    46,    47,    92,
      93,    12,    54,    89,    79,    80,    72,    73,    66,    49,
     -28,    13,    14,    15,    75,    95,    96,     5,    16,     6,
       2,    17,    10,    18,     1,    19,    20,    21,    22,    31,
      50,    97,   133,   134,    51,    33,   104,   105,   106,   107,
      56,   100,    34,    50,   118,    55,   122,    51,    35,   129,
     130,    36,   120,   121,    57,    58,    82,    83,    84,    85,
      44,   110,   108,   109,   113,   114,    72,    73,   123,   124,
      37,    38,    39,    43,    61,   144,    68,    87,    88,    99,
      90,   148,   149,    91,    94,   103,    98,    56,   111,   101,
     112,   115,   131,   116,   117,   119,   132,   142,   135,   136,
     140,   139,   141,   137,   143,     0,     9,   153,   128,   138,
     145,   146,     0,   147,   151,    81,     0,     0,   150,    64,
     152,     0,     0,     0,    74
  };

  const short int
   Parser ::yycheck_[] =
  {
      10,    45,    46,    47,     3,    41,    42,    20,    21,    35,
      54,    38,    38,    39,    24,     7,     8,    27,    28,    15,
      16,    10,    32,    59,    50,    51,    11,    12,     7,     8,
       3,    20,    21,    22,    44,    23,    24,    24,    27,     0,
      39,    30,    23,    32,     3,    34,    35,    36,    37,    24,
      42,    24,    28,    29,    46,    24,    82,    83,    84,    85,
       4,    74,    24,    42,   100,     5,   110,    46,    24,   113,
     114,    24,   108,   109,    18,    19,    41,    42,    43,    44,
      40,    91,    87,    88,    94,    95,    11,    12,    13,    14,
      24,    24,    24,    24,    17,   139,    24,    24,    24,     6,
      24,   145,   146,    23,    23,    47,    24,     4,    24,    39,
      24,    26,    23,    26,    26,    24,    10,     6,    24,    24,
      23,   131,    23,    31,     6,    -1,     7,   152,   112,    33,
     140,   141,    -1,    33,    29,    52,    -1,    -1,    40,    37,
     150,    -1,    -1,    -1,    43
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,    39,    52,    55,    24,     0,    53,    38,    52,
      23,    55,    10,    20,    21,    22,    27,    30,    32,    34,
      35,    36,    37,    56,    58,    59,    62,    63,    64,    68,
      69,    24,    57,    24,    24,    24,    24,    24,    24,    24,
      60,    60,    60,    24,    40,    55,    55,    55,     7,     8,
      42,    46,    73,    74,    55,     5,     4,    18,    19,    70,
      73,    17,    65,    67,    65,    73,     7,    73,    24,    61,
      61,    61,    11,    12,    71,    55,    56,    56,    56,    73,
      73,    57,    41,    42,    43,    44,    56,    24,    24,    61,
      24,    23,    15,    16,    23,    23,    24,    24,    24,     6,
      60,    39,    54,    47,    73,    73,    73,    73,    70,    70,
      55,    24,    24,    55,    55,    26,    26,    26,    61,    24,
      61,    61,    56,    13,    14,    66,    71,    72,    66,    56,
      56,    23,    10,    28,    29,    24,    24,    31,    33,    55,
      23,    23,     6,     6,    56,    55,    55,    33,    56,    56,
      40,    29,    55,    54
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    51,    52,    52,    53,    52,    52,    54,    54,    55,
      56,    56,    56,    56,    56,    57,    57,    58,    58,    58,
      58,    59,    59,    59,    59,    60,    60,    60,    60,    60,
      61,    61,    62,    63,    63,    64,    64,    64,    65,    65,
      66,    66,    66,    66,    67,    67,    68,    69,    69,    69,
      70,    71,    71,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    74,    74
  };

  const unsigned char
   Parser ::yyr2_[] =
  {
       0,     2,     7,     9,     0,     3,     0,     0,     9,     1,
       0,     3,     3,     3,     4,     0,     3,     1,     1,     1,
       1,     3,     3,     3,     5,     0,     2,     4,     2,     4,
       0,     2,     3,     7,    11,     7,     9,     7,     4,     4,
       1,     1,     3,     3,     0,     2,     3,     6,     6,     4,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     3,
       3,     3,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "$end", "error", "$undefined", "NL", "HEXACOULEUR", "FILE",
  "NUMEROTORTUE", "PARAM", "NUMBER", "COMMENTAIRE", "NOMFONCTION",
  "DIRECTIONGAUCHE", "DIRECTIONDROITE", "DIRECTIONDEVANT",
  "DIRECTIONDERRIERE", "MUR", "VIDE", "NON", "CARAPACE", "MOTIF", "JARDIN",
  "COULEUR", "TORTUES", "DEUXPOINTS", "SPACE", "SPACEUNNECESSARY", "FOIS",
  "SI", "SINON", "FINSI", "TANTQUE", "FINTANTQUE", "REPETE", "FINREPETE",
  "AVANCER", "RECULER", "SAUTER", "TOURNER", "MAIN", "FONCTION",
  "FINFONCTION", "ADD", "SUBS", "MULT", "DIV", "EQU", "PAR_OPEN",
  "PAR_CLOSE", "FIN", "RESTE", "NEG", "$accept", "debut", "$@1",
  "fonction", "newLine", "contenu", "parametreFonction", "commande",
  "mouvement", "paramAction", "paramNumTortue", "jardin", "condition",
  "boucle", "composanteCondition", "conditionParametres", "negation",
  "nombreTortues", "couleur", "paramCouleur", "directionHorizontale",
  "directionVerticale", "operation", "nombre", YY_NULLPTR
  };


  const unsigned short int
   Parser ::yyrline_[] =
  {
       0,   107,   107,   111,   115,   115,   116,   120,   123,   128,
     133,   136,   139,   142,   145,   150,   153,   158,   161,   164,
     167,   172,   181,   193,   203,   213,   217,   221,   225,   229,
     236,   240,   247,   252,   255,   260,   263,   266,   271,   272,
     275,   278,   281,   284,   289,   292,   298,   303,   312,   320,
     330,   336,   340,   346,   349,   354,   358,   361,   364,   368,
     377,   381,   387,   391
  };

  // Print the state stack on the debug stream.
  void
   Parser ::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
   Parser ::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
   Parser ::token_number_type
   Parser ::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
    };
    const unsigned int user_token_number_max_ = 305;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 2053 "parser.cc" // lalr1.cc:1167
#line 396 "parser.yy" // lalr1.cc:1168


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
