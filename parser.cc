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
      case 7: // NUMBER
      case 68: // paramAction
      case 69: // paramNumTortue
      case 79: // directionHorizontale
      case 81: // operation
      case 82: // nombre
        value.copy< int > (other.value);
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 8: // COMMENTAIRE
      case 9: // NOMFONCTION
      case 78: // paramCouleur
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
      case 7: // NUMBER
      case 68: // paramAction
      case 69: // paramNumTortue
      case 79: // directionHorizontale
      case 81: // operation
      case 82: // nombre
        value.copy< int > (v);
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 8: // COMMENTAIRE
      case 9: // NOMFONCTION
      case 78: // paramCouleur
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
      case 7: // NUMBER
      case 68: // paramAction
      case 69: // paramNumTortue
      case 79: // directionHorizontale
      case 81: // operation
      case 82: // nombre
        value.template destroy< int > ();
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 8: // COMMENTAIRE
      case 9: // NOMFONCTION
      case 78: // paramCouleur
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
      case 7: // NUMBER
      case 68: // paramAction
      case 69: // paramNumTortue
      case 79: // directionHorizontale
      case 81: // operation
      case 82: // nombre
        value.move< int > (s.value);
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 8: // COMMENTAIRE
      case 9: // NOMFONCTION
      case 78: // paramCouleur
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
      case 7: // NUMBER
      case 68: // paramAction
      case 69: // paramNumTortue
      case 79: // directionHorizontale
      case 81: // operation
      case 82: // nombre
        value.move< int > (that.value);
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 8: // COMMENTAIRE
      case 9: // NOMFONCTION
      case 78: // paramCouleur
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
      case 7: // NUMBER
      case 68: // paramAction
      case 69: // paramNumTortue
      case 79: // directionHorizontale
      case 81: // operation
      case 82: // nombre
        value.copy< int > (that.value);
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 8: // COMMENTAIRE
      case 9: // NOMFONCTION
      case 78: // paramCouleur
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
      case 7: // NUMBER
      case 68: // paramAction
      case 69: // paramNumTortue
      case 79: // directionHorizontale
      case 81: // operation
      case 82: // nombre
        yylhs.value.build< int > ();
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 8: // COMMENTAIRE
      case 9: // NOMFONCTION
      case 78: // paramCouleur
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
#line 106 "parser.yy" // lalr1.cc:859
    {
		std::cout << "main sans rien après : " << std::endl;
		YYACCEPT;
	}
#line 1067 "parser.cc" // lalr1.cc:859
    break;

  case 3:
#line 110 "parser.yy" // lalr1.cc:859
    {
		std::cout << "main : " << std::endl;
		YYACCEPT;
	}
#line 1076 "parser.cc" // lalr1.cc:859
    break;

  case 5:
#line 114 "parser.yy" // lalr1.cc:859
    {}
#line 1082 "parser.cc" // lalr1.cc:859
    break;

  case 7:
#line 118 "parser.yy" // lalr1.cc:859
    {
		std::cout << "no other fct than main";
	}
#line 1090 "parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 121 "parser.yy" // lalr1.cc:859
    {
		std::cout << "fonction : " << yystack_[5].value.as< std::string > () << std::endl;
	}
#line 1098 "parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 126 "parser.yy" // lalr1.cc:859
    {
		/*std::cout << "com:" << $1 << std::endl;*/
	}
#line 1106 "parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 131 "parser.yy" // lalr1.cc:859
    {
		std::cout << "fin du main >> " << std::endl;
	}
#line 1114 "parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 134 "parser.yy" // lalr1.cc:859
    {
		std::cout << "cmd >> " << std::endl;
	}
#line 1122 "parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 137 "parser.yy" // lalr1.cc:859
    {
		std::cout << "cdt >> " << std::endl;
	}
#line 1130 "parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 140 "parser.yy" // lalr1.cc:859
    {
		std::cout << "bcl >> " << std::endl;
	}
#line 1138 "parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 143 "parser.yy" // lalr1.cc:859
    {
		std::cout << "appel fct >> " << std::endl;
	}
#line 1146 "parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 148 "parser.yy" // lalr1.cc:859
    {
		std::cout << "pas de param >> " << std::endl;
	}
#line 1154 "parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 151 "parser.yy" // lalr1.cc:859
    {
		std::cout << "param hexa >> " << std::endl;
	}
#line 1162 "parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 154 "parser.yy" // lalr1.cc:859
    {
		std::cout << "param num tortue >> " << std::endl;
	}
#line 1170 "parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 157 "parser.yy" // lalr1.cc:859
    {
		std::cout << "param ope >> " << std::endl;
	}
#line 1178 "parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 162 "parser.yy" // lalr1.cc:859
    {
		std::cout << "mouvement >> ";
	}
#line 1186 "parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 165 "parser.yy" // lalr1.cc:859
    {
		std::cout << "nombreTortues >> ";
	}
#line 1194 "parser.cc" // lalr1.cc:859
    break;

  case 29:
#line 168 "parser.yy" // lalr1.cc:859
    {
		std::cout << "couleur >> ";
	}
#line 1202 "parser.cc" // lalr1.cc:859
    break;

  case 30:
#line 171 "parser.yy" // lalr1.cc:859
    {
		std::cout << "jardin >> ";
	}
#line 1210 "parser.cc" // lalr1.cc:859
    break;

  case 31:
#line 176 "parser.yy" // lalr1.cc:859
    {
		if(yystack_[0].value.as< int > () == -1){
			driver.avancer(yystack_[1].value.as< int > ());
			std::cout << "avancer de " << yystack_[1].value.as< int > () << " sur toutes les tortues! ";
		} else{
			driver.avancer(yystack_[0].value.as< int > (), yystack_[1].value.as< int > ());
			std::cout << "avancer de " << yystack_[1].value.as< int > () << " sur la tortue:" << yystack_[0].value.as< int > () << "! ";
		}
	}
#line 1224 "parser.cc" // lalr1.cc:859
    break;

  case 32:
#line 185 "parser.yy" // lalr1.cc:859
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
#line 1241 "parser.cc" // lalr1.cc:859
    break;

  case 33:
#line 197 "parser.yy" // lalr1.cc:859
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
#line 1256 "parser.cc" // lalr1.cc:859
    break;

  case 34:
#line 207 "parser.yy" // lalr1.cc:859
    {
		std::cout << "tourner >> ";
		if(yystack_[0].value.as< int > () == -1){
			driver.tourner(yystack_[1].value.as< int > (), yystack_[2].value.as< int > ());
		} else{
			driver.tourner(yystack_[0].value.as< int > (), yystack_[1].value.as< int > (), yystack_[2].value.as< int > ());
		}
	}
#line 1269 "parser.cc" // lalr1.cc:859
    break;

  case 35:
#line 217 "parser.yy" // lalr1.cc:859
    {
		std::cout << "pas de parametres >> ";
		yylhs.value.as< int > ()=1;
	}
#line 1278 "parser.cc" // lalr1.cc:859
    break;

  case 36:
#line 221 "parser.yy" // lalr1.cc:859
    {
		std::cout << "parametre nombre >> ";
		yylhs.value.as< int > ()=yystack_[0].value.as< int > ();
	}
#line 1287 "parser.cc" // lalr1.cc:859
    break;

  case 37:
#line 228 "parser.yy" // lalr1.cc:859
    {
		std::cout << "pas de tortue >> ";
		yylhs.value.as< int > ()=-1;
	}
#line 1296 "parser.cc" // lalr1.cc:859
    break;

  case 38:
#line 232 "parser.yy" // lalr1.cc:859
    {
		yylhs.value.as< int > ()=std::atoi((yystack_[0].value.as< std::string > ().substr(1)).c_str());
	}
#line 1304 "parser.cc" // lalr1.cc:859
    break;

  case 39:
#line 238 "parser.yy" // lalr1.cc:859
    {
		std::cout << "jardin file:" << yystack_[0].value.as< std::string > ();
	}
#line 1312 "parser.cc" // lalr1.cc:859
    break;

  case 40:
#line 243 "parser.yy" // lalr1.cc:859
    {
		std::cout << "si simple";
	}
#line 1320 "parser.cc" // lalr1.cc:859
    break;

  case 41:
#line 246 "parser.yy" // lalr1.cc:859
    {
		std::cout << "si sinon";
	}
#line 1328 "parser.cc" // lalr1.cc:859
    break;

  case 42:
#line 251 "parser.yy" // lalr1.cc:859
    {
		std::cout << "tant que";
	}
#line 1336 "parser.cc" // lalr1.cc:859
    break;

  case 43:
#line 254 "parser.yy" // lalr1.cc:859
    {
		std::cout << "repete fois" << std::endl;
	}
#line 1344 "parser.cc" // lalr1.cc:859
    break;

  case 44:
#line 257 "parser.yy" // lalr1.cc:859
    {
		std::cout << "repete sans fois";
	}
#line 1352 "parser.cc" // lalr1.cc:859
    break;

  case 45:
#line 262 "parser.yy" // lalr1.cc:859
    {}
#line 1358 "parser.cc" // lalr1.cc:859
    break;

  case 46:
#line 263 "parser.yy" // lalr1.cc:859
    {}
#line 1364 "parser.cc" // lalr1.cc:859
    break;

  case 47:
#line 266 "parser.yy" // lalr1.cc:859
    {
		std::cout << "mur dir horizontal >> ";
	}
#line 1372 "parser.cc" // lalr1.cc:859
    break;

  case 48:
#line 269 "parser.yy" // lalr1.cc:859
    {
		std::cout << "mur dir verticale >> ";
	}
#line 1380 "parser.cc" // lalr1.cc:859
    break;

  case 49:
#line 272 "parser.yy" // lalr1.cc:859
    {
		std::cout << "mur dir horizontal et tortue >> ";
	}
#line 1388 "parser.cc" // lalr1.cc:859
    break;

  case 50:
#line 275 "parser.yy" // lalr1.cc:859
    {
		std::cout << "mur dir verticale et tortue >> ";
	}
#line 1396 "parser.cc" // lalr1.cc:859
    break;

  case 51:
#line 280 "parser.yy" // lalr1.cc:859
    {
		std::cout << "positif >> ";
	}
#line 1404 "parser.cc" // lalr1.cc:859
    break;

  case 52:
#line 283 "parser.yy" // lalr1.cc:859
    {
		std::cout << "negation >> ";
	}
#line 1412 "parser.cc" // lalr1.cc:859
    break;

  case 53:
#line 289 "parser.yy" // lalr1.cc:859
    {
		std::cout << "nb tortue";
	}
#line 1420 "parser.cc" // lalr1.cc:859
    break;

  case 54:
#line 294 "parser.yy" // lalr1.cc:859
    {
		std::cout << "couleur carapace >> ";
		if(yystack_[0].value.as< int > () == -1){
			driver.modifCouleurCarapace(yystack_[1].value.as< std::string > ());
		} else{
			driver.modifCouleurCarapace(yystack_[0].value.as< int > (), yystack_[1].value.as< std::string > ());
		}
		
	}
#line 1434 "parser.cc" // lalr1.cc:859
    break;

  case 55:
#line 303 "parser.yy" // lalr1.cc:859
    {
		std::cout << "couleur motif >> ";
		if(yystack_[0].value.as< int > () == -1){
			driver.modifCouleurCarapace(yystack_[1].value.as< std::string > ());
		} else{
			driver.modifCouleurCarapace(yystack_[0].value.as< int > (), yystack_[1].value.as< std::string > ());
		}
	}
#line 1447 "parser.cc" // lalr1.cc:859
    break;

  case 56:
#line 311 "parser.yy" // lalr1.cc:859
    {
		std::cout << "couleur rien donc carapace >> ";
		if(yystack_[0].value.as< int > () == -1){
			driver.modifCouleurCarapace(yystack_[1].value.as< std::string > ());
		} else{
			driver.modifCouleurCarapace(yystack_[0].value.as< int > (), yystack_[1].value.as< std::string > ());
		}
	}
#line 1460 "parser.cc" // lalr1.cc:859
    break;

  case 57:
#line 321 "parser.yy" // lalr1.cc:859
    {
		std::cout << "paramcouleur hexa:" << yystack_[0].value.as< std::string > ();
	}
#line 1468 "parser.cc" // lalr1.cc:859
    break;

  case 58:
#line 326 "parser.yy" // lalr1.cc:859
    {
		std::cout << "direction gauche";
		yylhs.value.as< int > ()=-1;
	}
#line 1477 "parser.cc" // lalr1.cc:859
    break;

  case 59:
#line 330 "parser.yy" // lalr1.cc:859
    {
		std::cout << "direction droite";
		yylhs.value.as< int > ()=1;
	}
#line 1486 "parser.cc" // lalr1.cc:859
    break;

  case 60:
#line 336 "parser.yy" // lalr1.cc:859
    {
		std::cout << "direction devant";
	}
#line 1494 "parser.cc" // lalr1.cc:859
    break;

  case 61:
#line 339 "parser.yy" // lalr1.cc:859
    {
		std::cout << "direction derriere";
	}
#line 1502 "parser.cc" // lalr1.cc:859
    break;

  case 62:
#line 344 "parser.yy" // lalr1.cc:859
    {
		/*std::cout << "nombre >> ";*/
		yylhs.value.as< int > () = yystack_[0].value.as< int > ();
	}
#line 1511 "parser.cc" // lalr1.cc:859
    break;

  case 63:
#line 348 "parser.yy" // lalr1.cc:859
    {
		yylhs.value.as< int > () = - yystack_[0].value.as< int > ();
	}
#line 1519 "parser.cc" // lalr1.cc:859
    break;

  case 64:
#line 351 "parser.yy" // lalr1.cc:859
    {
		yylhs.value.as< int > () = yystack_[1].value.as< int > ();
	}
#line 1527 "parser.cc" // lalr1.cc:859
    break;

  case 65:
#line 354 "parser.yy" // lalr1.cc:859
    {
		yylhs.value.as< int > () = yystack_[2].value.as< int > () * yystack_[0].value.as< int > ();
		//std::cout << "multiplication: ";
	}
#line 1536 "parser.cc" // lalr1.cc:859
    break;

  case 66:
#line 358 "parser.yy" // lalr1.cc:859
    {
		if(yystack_[0].value.as< int > ()==0){
			std::cout << "ERREUR : division par zéro!!!";
			//YYERROR;
		}else{
			yylhs.value.as< int > () = yystack_[2].value.as< int > () / yystack_[0].value.as< int > ();
			//std::cout << "division: ";
		}
	}
#line 1550 "parser.cc" // lalr1.cc:859
    break;

  case 67:
#line 367 "parser.yy" // lalr1.cc:859
    {
		yylhs.value.as< int > () = yystack_[2].value.as< int > () + yystack_[0].value.as< int > ();
		//std::cout << "somme: ";
	}
#line 1559 "parser.cc" // lalr1.cc:859
    break;

  case 68:
#line 371 "parser.yy" // lalr1.cc:859
    {
		yylhs.value.as< int > () = yystack_[2].value.as< int > () - yystack_[0].value.as< int > ();
		//std::cout << "soustraction: ";
	}
#line 1568 "parser.cc" // lalr1.cc:859
    break;

  case 69:
#line 377 "parser.yy" // lalr1.cc:859
    {
		std::cout << "entier: " << yystack_[0].value.as< int > () << std::endl;
		yylhs.value.as< int > () = yystack_[0].value.as< int > ();
	}
#line 1577 "parser.cc" // lalr1.cc:859
    break;


#line 1581 "parser.cc" // lalr1.cc:859
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


  const signed char  Parser ::yypact_ninf_ = -74;

  const signed char  Parser ::yytable_ninf_ = -1;

  const signed char
   Parser ::yypact_[] =
  {
      15,   -74,    -6,    21,   -74,   -18,   -74,    15,     2,   -74,
      39,    70,    26,    28,    36,    47,    53,    54,    58,    59,
      59,    59,    61,     5,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,     7,   -74,    80,     8,     9,    72,    72,     9,     9,
      69,    69,    69,    19,    39,    39,    39,    39,   -74,   -74,
     -74,     9,     9,   -74,    -2,    39,   -74,   -74,    71,    74,
      69,   -74,    75,    73,    18,    78,    44,   -74,    87,   -74,
     -74,   -74,   -74,   -74,    59,   -74,    70,    70,    70,    26,
      26,   -74,    56,    26,     9,     9,     9,     9,    70,   103,
     103,   -74,   -74,    39,    85,    86,    39,    39,    88,   -74,
      69,    76,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,    69,    69,    70,    52,    52,    70,
      70,    89,   -74,    92,   -74,   -74,   -74,    41,   -74,   -74,
     -74,    93,    94,   -74,    82,    90,    39,   101,    96,   -74,
     113,   114,   -74,   -74,    70,    99,    39,   -74,   -74,    91,
      39,    70,   -74,    70,    97,    95,   -74,    39,   -74,    76,
     -74
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       0,    10,     0,     0,     5,     0,     1,     0,     0,     6,
       0,    11,    20,     0,     0,     0,     0,     0,     0,    35,
      35,    35,     0,     0,    12,    27,    30,    14,    16,    28,
      29,     0,    18,     0,     0,     0,    51,    51,     0,     0,
      37,    37,    37,     0,     2,     0,     0,     0,    21,    23,
      69,     0,     0,    25,    62,     0,    39,    57,     0,     0,
      37,    53,     0,     0,     0,     0,     0,    36,     0,    31,
      32,    33,    58,    59,    35,     3,    11,    11,    11,    20,
      20,    63,     0,    20,     0,     0,     0,     0,    11,     0,
       0,    56,    52,     0,     0,     0,     0,     0,     0,    38,
      37,     7,    13,    15,    17,    22,    24,    64,    26,    67,
      68,    65,    66,    19,    37,    37,    11,     0,     0,    11,
      11,     0,    34,     0,     4,    54,    55,     0,    60,    61,
      45,    47,    48,    46,     0,     0,     0,     0,     0,    40,
       0,     0,    42,    44,    11,     0,     0,    49,    50,     0,
       0,    11,    43,    11,     0,     0,    41,     0,     8,     7,
       9
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -74,   117,   -74,   -74,   -32,   -74,   -10,   -73,   -74,   -74,
     -74,   -74,   -52,   -74,   -74,   -74,   -74,   -74,   -13,   -40,
     -74,   -74,   -74,    98,    10,   -74,   -74,   -74,   -17,   100,
     -74,   -29,   -74
  };

  const short int
   Parser ::yydefgoto_[] =
  {
      -1,     3,   101,     7,   124,   159,     4,    23,    45,    46,
      47,    55,    32,    79,    80,    83,    24,    25,    40,    69,
      26,    27,    28,    63,   130,    64,    29,    30,    60,   131,
     132,    53,    54
  };

  const unsigned char
   Parser ::yytable_[] =
  {
      11,    70,    71,   102,   103,   104,    61,    41,    42,    66,
      67,    48,    57,    49,    50,   113,    50,     5,     1,     8,
      91,     6,    81,    82,    10,    58,    59,   105,   106,    72,
      73,   108,    94,    95,    75,    76,    77,    78,    84,    85,
      86,    87,     1,   127,    44,    88,   134,   135,    51,    31,
      51,    33,    52,     2,    52,   109,   110,   111,   112,    34,
     122,   100,    72,    73,   128,   129,    97,    98,   138,   139,
      35,   149,   114,   115,   125,   126,    36,    37,   154,    12,
     155,    38,    39,   116,    43,    56,   119,   120,    62,    13,
      14,    15,    68,    99,    89,    93,    16,    90,    92,    17,
      96,    18,   107,    19,    20,    21,    22,    57,   117,   118,
     145,   136,   142,   121,   123,   137,   140,   141,   146,   147,
     148,   150,   143,   152,     9,   156,   144,   160,   133,     0,
       0,     0,     0,     0,   157,    65,   151,     0,     0,     0,
     153,     0,     0,    74,     0,     0,     0,   158
  };

  const short int
   Parser ::yycheck_[] =
  {
      10,    41,    42,    76,    77,    78,    35,    20,    21,    38,
      39,     4,     4,     6,     7,    88,     7,    23,     3,    37,
      60,     0,    51,    52,    22,    17,    18,    79,    80,    10,
      11,    83,    14,    15,    44,    45,    46,    47,    40,    41,
      42,    43,     3,   116,    39,    55,   119,   120,    41,    23,
      41,    23,    45,    38,    45,    84,    85,    86,    87,    23,
     100,    74,    10,    11,    12,    13,    22,    23,    27,    28,
      23,   144,    89,    90,   114,   115,    23,    23,   151,     9,
     153,    23,    23,    93,    23,     5,    96,    97,    16,    19,
      20,    21,    23,     6,    23,    22,    26,    23,    23,    29,
      22,    31,    46,    33,    34,    35,    36,     4,    23,    23,
       9,    22,    30,    25,    38,    23,    23,    23,    22,     6,
       6,    22,    32,    32,     7,    28,   136,   159,   118,    -1,
      -1,    -1,    -1,    -1,    39,    37,   146,    -1,    -1,    -1,
     150,    -1,    -1,    43,    -1,    -1,    -1,   157
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,    38,    51,    56,    23,     0,    53,    37,    51,
      22,    56,     9,    19,    20,    21,    26,    29,    31,    33,
      34,    35,    36,    57,    66,    67,    70,    71,    72,    76,
      77,    23,    62,    23,    23,    23,    23,    23,    23,    23,
      68,    68,    68,    23,    39,    58,    59,    60,     4,     6,
       7,    41,    45,    81,    82,    61,     5,     4,    17,    18,
      78,    81,    16,    73,    75,    73,    81,    81,    23,    69,
      69,    69,    10,    11,    79,    56,    56,    56,    56,    63,
      64,    81,    81,    65,    40,    41,    42,    43,    56,    23,
      23,    69,    23,    22,    14,    15,    22,    22,    23,     6,
      68,    52,    57,    57,    57,    62,    62,    46,    62,    81,
      81,    81,    81,    57,    78,    78,    56,    23,    23,    56,
      56,    25,    69,    38,    54,    69,    69,    57,    12,    13,
      74,    79,    80,    74,    57,    57,    22,    23,    27,    28,
      23,    23,    30,    32,    56,     9,    22,     6,     6,    57,
      22,    56,    32,    56,    57,    57,    28,    39,    56,    55,
      54
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    50,    51,    52,    51,    53,    51,    54,    55,    54,
      56,    57,    58,    57,    59,    57,    60,    57,    61,    57,
      62,    63,    62,    64,    62,    65,    62,    66,    66,    66,
      66,    67,    67,    67,    67,    68,    68,    69,    69,    70,
      71,    71,    72,    72,    72,    73,    73,    74,    74,    74,
      74,    75,    75,    76,    77,    77,    77,    78,    79,    79,
      80,    80,    81,    81,    81,    81,    81,    81,    81,    82
  };

  const unsigned char
   Parser ::yyr2_[] =
  {
       0,     2,     7,     0,    10,     0,     3,     0,     0,    10,
       1,     0,     0,     4,     0,     4,     0,     4,     0,     5,
       0,     0,     4,     0,     4,     0,     4,     1,     1,     1,
       1,     3,     3,     3,     5,     0,     2,     0,     2,     3,
       7,    11,     7,     9,     7,     4,     4,     1,     1,     3,
       3,     0,     2,     3,     6,     6,     4,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     3,     3,     3,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "$end", "error", "$undefined", "NL", "HEXACOULEUR", "FILE",
  "NUMEROTORTUE", "NUMBER", "COMMENTAIRE", "NOMFONCTION",
  "DIRECTIONGAUCHE", "DIRECTIONDROITE", "DIRECTIONDEVANT",
  "DIRECTIONDERRIERE", "MUR", "VIDE", "NON", "CARAPACE", "MOTIF", "JARDIN",
  "COULEUR", "TORTUES", "DEUXPOINTS", "SPACE", "SPACEUNNECESSARY", "FOIS",
  "SI", "SINON", "FINSI", "TANTQUE", "FINTANTQUE", "REPETE", "FINREPETE",
  "AVANCER", "RECULER", "SAUTER", "TOURNER", "MAIN", "FONCTION",
  "FINFONCTION", "ADD", "SUBS", "MULT", "DIV", "EQU", "PAR_OPEN",
  "PAR_CLOSE", "FIN", "RESTE", "NEG", "$accept", "debut", "$@1", "$@2",
  "fonction", "$@3", "newLine", "contenu", "$@4", "$@5", "$@6", "$@7",
  "parametreFonction", "$@8", "$@9", "$@10", "commande", "mouvement",
  "paramAction", "paramNumTortue", "jardin", "condition", "boucle",
  "composanteCondition", "conditionParametres", "negation",
  "nombreTortues", "couleur", "paramCouleur", "directionHorizontale",
  "directionVerticale", "operation", "nombre", YY_NULLPTR
  };


  const unsigned short int
   Parser ::yyrline_[] =
  {
       0,   106,   106,   110,   110,   114,   114,   118,   121,   121,
     126,   131,   134,   134,   137,   137,   140,   140,   143,   143,
     148,   151,   151,   154,   154,   157,   157,   162,   165,   168,
     171,   176,   185,   197,   207,   217,   221,   228,   232,   238,
     243,   246,   251,   254,   257,   262,   263,   266,   269,   272,
     275,   280,   283,   289,   294,   303,   311,   321,   326,   330,
     336,   339,   344,   348,   351,   354,   358,   367,   371,   377
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
      45,    46,    47,    48,    49
    };
    const unsigned int user_token_number_max_ = 304;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 2019 "parser.cc" // lalr1.cc:1167
#line 383 "parser.yy" // lalr1.cc:1168


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
