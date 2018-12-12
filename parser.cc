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

    #undef  yylex
    #define yylex scanner.yylex

#line 63 "parser.cc" // lalr1.cc:413


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
#line 149 "parser.cc" // lalr1.cc:479

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
      case 80: // operation
      case 81: // nombre
        value.copy< float > (other.value);
        break;

      case 7: // NUMBER
        value.copy< int > (other.value);
        break;

      case 68: // paramAction
        value.copy< std::map<std::string, int> > (other.value);
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 8: // COMMENTAIRE
      case 9: // NOMFONCTION
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
      case 80: // operation
      case 81: // nombre
        value.copy< float > (v);
        break;

      case 7: // NUMBER
        value.copy< int > (v);
        break;

      case 68: // paramAction
        value.copy< std::map<std::string, int> > (v);
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 8: // COMMENTAIRE
      case 9: // NOMFONCTION
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
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const float v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const int v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::map<std::string, int> v, const location_type& l)
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
      case 80: // operation
      case 81: // nombre
        value.template destroy< float > ();
        break;

      case 7: // NUMBER
        value.template destroy< int > ();
        break;

      case 68: // paramAction
        value.template destroy< std::map<std::string, int> > ();
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 8: // COMMENTAIRE
      case 9: // NOMFONCTION
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
      case 80: // operation
      case 81: // nombre
        value.move< float > (s.value);
        break;

      case 7: // NUMBER
        value.move< int > (s.value);
        break;

      case 68: // paramAction
        value.move< std::map<std::string, int> > (s.value);
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 8: // COMMENTAIRE
      case 9: // NOMFONCTION
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
      case 80: // operation
      case 81: // nombre
        value.move< float > (that.value);
        break;

      case 7: // NUMBER
        value.move< int > (that.value);
        break;

      case 68: // paramAction
        value.move< std::map<std::string, int> > (that.value);
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 8: // COMMENTAIRE
      case 9: // NOMFONCTION
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
      case 80: // operation
      case 81: // nombre
        value.copy< float > (that.value);
        break;

      case 7: // NUMBER
        value.copy< int > (that.value);
        break;

      case 68: // paramAction
        value.copy< std::map<std::string, int> > (that.value);
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 8: // COMMENTAIRE
      case 9: // NOMFONCTION
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
      case 80: // operation
      case 81: // nombre
        yylhs.value.build< float > ();
        break;

      case 7: // NUMBER
        yylhs.value.build< int > ();
        break;

      case 68: // paramAction
        yylhs.value.build< std::map<std::string, int> > ();
        break;

      case 3: // NL
      case 4: // HEXACOULEUR
      case 5: // FILE
      case 6: // NUMEROTORTUE
      case 8: // COMMENTAIRE
      case 9: // NOMFONCTION
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
#line 102 "parser.yy" // lalr1.cc:859
    {
		std::cout << "main sans rien après : " << std::endl;
		YYACCEPT;
	}
#line 1101 "parser.cc" // lalr1.cc:859
    break;

  case 3:
#line 106 "parser.yy" // lalr1.cc:859
    {
		std::cout << "main : " << std::endl;
		YYACCEPT;
	}
#line 1110 "parser.cc" // lalr1.cc:859
    break;

  case 5:
#line 110 "parser.yy" // lalr1.cc:859
    {}
#line 1116 "parser.cc" // lalr1.cc:859
    break;

  case 7:
#line 114 "parser.yy" // lalr1.cc:859
    {
		std::cout << "no other fct than main";
	}
#line 1124 "parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 117 "parser.yy" // lalr1.cc:859
    {
		std::cout << "fonction : " << yystack_[5].value.as< std::string > () << std::endl;
	}
#line 1132 "parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 122 "parser.yy" // lalr1.cc:859
    {
		std::cout << "com:" << yystack_[0].value.as< std::string > () << std::endl;
	}
#line 1140 "parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 127 "parser.yy" // lalr1.cc:859
    {
		std::cout << "empty content >> " << std::endl;
	}
#line 1148 "parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 130 "parser.yy" // lalr1.cc:859
    {
		std::cout << "cmd >> " << std::endl;
	}
#line 1156 "parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 133 "parser.yy" // lalr1.cc:859
    {
		std::cout << "cdt >> " << std::endl;
	}
#line 1164 "parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 136 "parser.yy" // lalr1.cc:859
    {
		std::cout << "bcl >> " << std::endl;
	}
#line 1172 "parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 139 "parser.yy" // lalr1.cc:859
    {
		std::cout << "appel fct >> " << std::endl;
	}
#line 1180 "parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 144 "parser.yy" // lalr1.cc:859
    {
		std::cout << "pas de param >> " << std::endl;
	}
#line 1188 "parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 147 "parser.yy" // lalr1.cc:859
    {
		std::cout << "param hexa >> " << std::endl;
	}
#line 1196 "parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 150 "parser.yy" // lalr1.cc:859
    {
		std::cout << "param num tortue >> " << std::endl;
	}
#line 1204 "parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 153 "parser.yy" // lalr1.cc:859
    {
		std::cout << "param ope >> " << std::endl;
	}
#line 1212 "parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 158 "parser.yy" // lalr1.cc:859
    {
		std::cout << "mouvement >> ";
	}
#line 1220 "parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 161 "parser.yy" // lalr1.cc:859
    {
		std::cout << "nombreTortues >> ";
	}
#line 1228 "parser.cc" // lalr1.cc:859
    break;

  case 29:
#line 164 "parser.yy" // lalr1.cc:859
    {
		std::cout << "couleur >> ";
	}
#line 1236 "parser.cc" // lalr1.cc:859
    break;

  case 30:
#line 167 "parser.yy" // lalr1.cc:859
    {
		std::cout << "jardin >> ";
	}
#line 1244 "parser.cc" // lalr1.cc:859
    break;

  case 31:
#line 172 "parser.yy" // lalr1.cc:859
    {
		std::cout << "avancer >> ";
	}
#line 1252 "parser.cc" // lalr1.cc:859
    break;

  case 32:
#line 175 "parser.yy" // lalr1.cc:859
    {
		std::cout << "reculer >> ";
	}
#line 1260 "parser.cc" // lalr1.cc:859
    break;

  case 33:
#line 178 "parser.yy" // lalr1.cc:859
    {
		std::cout << "sauter >> ";
	}
#line 1268 "parser.cc" // lalr1.cc:859
    break;

  case 34:
#line 181 "parser.yy" // lalr1.cc:859
    {
		std::cout << "tourner >> ";
	}
#line 1276 "parser.cc" // lalr1.cc:859
    break;

  case 35:
#line 186 "parser.yy" // lalr1.cc:859
    {
		std::cout << "pas de parametres >> ";
	}
#line 1284 "parser.cc" // lalr1.cc:859
    break;

  case 36:
#line 189 "parser.yy" // lalr1.cc:859
    {
		std::cout << "parametre nombre >> ";
		driver.m_map.insert(std::pair<std::string,float>(std::string("operation"),yystack_[0].value.as< float > ()));
	}
#line 1293 "parser.cc" // lalr1.cc:859
    break;

  case 37:
#line 193 "parser.yy" // lalr1.cc:859
    {
		std::cout << "parametre fois >> ";
		driver.m_map.insert(std::pair<std::string,float>(std::string("operation"),yystack_[2].value.as< float > ()));
	}
#line 1302 "parser.cc" // lalr1.cc:859
    break;

  case 38:
#line 197 "parser.yy" // lalr1.cc:859
    {
		std::cout << "parametre nombre numero tortue : " << yystack_[0].value.as< std::string > () << " >> ";
		driver.m_map.insert(std::pair<std::string,float>(std::string("operation"),yystack_[2].value.as< float > ()));
		float nb = std::stof(yystack_[0].value.as< std::string > ().substr(1));
		driver.m_map.insert(std::pair<std::string,float>(std::string("numtortue"),nb));
	}
#line 1313 "parser.cc" // lalr1.cc:859
    break;

  case 39:
#line 203 "parser.yy" // lalr1.cc:859
    {
		std::cout << "parametre nombre fois numero tortue : " << yystack_[0].value.as< std::string > () << " >> ";
		driver.m_map.insert(std::pair<std::string,float>(std::string("operation"),yystack_[4].value.as< float > ()));
		float nb = std::stof(yystack_[0].value.as< std::string > ().substr(1));
		driver.m_map.insert(std::pair<std::string,float>(std::string("numtortue"),nb));
	}
#line 1324 "parser.cc" // lalr1.cc:859
    break;

  case 40:
#line 209 "parser.yy" // lalr1.cc:859
    {
		std::cout << "parametre tortue : " << yystack_[0].value.as< std::string > () << " >> ";
		float nb = std::stof(yystack_[0].value.as< std::string > ().substr(1));
		driver.m_map.insert(std::pair<std::string,float>(std::string("numtortue"),nb));
	}
#line 1334 "parser.cc" // lalr1.cc:859
    break;

  case 41:
#line 217 "parser.yy" // lalr1.cc:859
    {
		std::cout << "jardin file:" << yystack_[0].value.as< std::string > ();
	}
#line 1342 "parser.cc" // lalr1.cc:859
    break;

  case 42:
#line 222 "parser.yy" // lalr1.cc:859
    {
		std::cout << "si simple";
	}
#line 1350 "parser.cc" // lalr1.cc:859
    break;

  case 43:
#line 225 "parser.yy" // lalr1.cc:859
    {
		std::cout << "si sinon";
	}
#line 1358 "parser.cc" // lalr1.cc:859
    break;

  case 44:
#line 230 "parser.yy" // lalr1.cc:859
    {
		std::cout << "tant que";
	}
#line 1366 "parser.cc" // lalr1.cc:859
    break;

  case 45:
#line 233 "parser.yy" // lalr1.cc:859
    {
		std::cout << "repete fois" << std::endl;
	}
#line 1374 "parser.cc" // lalr1.cc:859
    break;

  case 46:
#line 236 "parser.yy" // lalr1.cc:859
    {
		std::cout << "repete sans fois";
	}
#line 1382 "parser.cc" // lalr1.cc:859
    break;

  case 47:
#line 241 "parser.yy" // lalr1.cc:859
    {}
#line 1388 "parser.cc" // lalr1.cc:859
    break;

  case 48:
#line 242 "parser.yy" // lalr1.cc:859
    {}
#line 1394 "parser.cc" // lalr1.cc:859
    break;

  case 49:
#line 245 "parser.yy" // lalr1.cc:859
    {
		std::cout << "mur dir horizontal >> ";
	}
#line 1402 "parser.cc" // lalr1.cc:859
    break;

  case 50:
#line 248 "parser.yy" // lalr1.cc:859
    {
		std::cout << "mur dir verticale >> ";
	}
#line 1410 "parser.cc" // lalr1.cc:859
    break;

  case 51:
#line 251 "parser.yy" // lalr1.cc:859
    {
		std::cout << "mur dir horizontal et tortue >> ";
	}
#line 1418 "parser.cc" // lalr1.cc:859
    break;

  case 52:
#line 254 "parser.yy" // lalr1.cc:859
    {
		std::cout << "mur dir verticale et tortue >> ";
	}
#line 1426 "parser.cc" // lalr1.cc:859
    break;

  case 53:
#line 259 "parser.yy" // lalr1.cc:859
    {
		std::cout << "positif >> ";
	}
#line 1434 "parser.cc" // lalr1.cc:859
    break;

  case 54:
#line 262 "parser.yy" // lalr1.cc:859
    {
		std::cout << "negation >> ";
	}
#line 1442 "parser.cc" // lalr1.cc:859
    break;

  case 55:
#line 268 "parser.yy" // lalr1.cc:859
    {
		std::cout << "nb tortue";
	}
#line 1450 "parser.cc" // lalr1.cc:859
    break;

  case 56:
#line 273 "parser.yy" // lalr1.cc:859
    {
		std::cout << "couleur carapace >> ";
	}
#line 1458 "parser.cc" // lalr1.cc:859
    break;

  case 57:
#line 276 "parser.yy" // lalr1.cc:859
    {
		std::cout << "couleur motif >> ";
	}
#line 1466 "parser.cc" // lalr1.cc:859
    break;

  case 58:
#line 279 "parser.yy" // lalr1.cc:859
    {
		std::cout << "couleur rien donc carapace >> ";
	}
#line 1474 "parser.cc" // lalr1.cc:859
    break;

  case 59:
#line 284 "parser.yy" // lalr1.cc:859
    {
		std::cout << "paramcouleur hexa:" << yystack_[0].value.as< std::string > ();
	}
#line 1482 "parser.cc" // lalr1.cc:859
    break;

  case 60:
#line 287 "parser.yy" // lalr1.cc:859
    {
		std::cout << "paramcouleur hexa:" << yystack_[2].value.as< std::string > () << ", numero tortue:" << yystack_[0].value.as< std::string > ();
	}
#line 1490 "parser.cc" // lalr1.cc:859
    break;

  case 61:
#line 292 "parser.yy" // lalr1.cc:859
    {
		std::cout << "direction gauche";
	}
#line 1498 "parser.cc" // lalr1.cc:859
    break;

  case 62:
#line 295 "parser.yy" // lalr1.cc:859
    {
		std::cout << "direction droite";
	}
#line 1506 "parser.cc" // lalr1.cc:859
    break;

  case 63:
#line 300 "parser.yy" // lalr1.cc:859
    {
		std::cout << "direction devant";
	}
#line 1514 "parser.cc" // lalr1.cc:859
    break;

  case 64:
#line 303 "parser.yy" // lalr1.cc:859
    {
		std::cout << "direction derriere";
	}
#line 1522 "parser.cc" // lalr1.cc:859
    break;

  case 65:
#line 308 "parser.yy" // lalr1.cc:859
    {
		/*std::cout << "nombre >> ";*/
		yylhs.value.as< float > () = yystack_[0].value.as< float > ();
	}
#line 1531 "parser.cc" // lalr1.cc:859
    break;

  case 66:
#line 312 "parser.yy" // lalr1.cc:859
    {
		yylhs.value.as< float > () = - yystack_[0].value.as< float > ();
	}
#line 1539 "parser.cc" // lalr1.cc:859
    break;

  case 67:
#line 315 "parser.yy" // lalr1.cc:859
    {
		yylhs.value.as< float > () = yystack_[1].value.as< float > ();
	}
#line 1547 "parser.cc" // lalr1.cc:859
    break;

  case 68:
#line 318 "parser.yy" // lalr1.cc:859
    {
		yylhs.value.as< float > () = yystack_[2].value.as< float > () * yystack_[0].value.as< float > ();
		//std::cout << "multiplication: ";
	}
#line 1556 "parser.cc" // lalr1.cc:859
    break;

  case 69:
#line 322 "parser.yy" // lalr1.cc:859
    {
		if(yystack_[0].value.as< float > ()==0){
			std::cout << "ERREUR : division par zéro!!!";
			//YYERROR;
		}else{
			yylhs.value.as< float > () = yystack_[2].value.as< float > () / yystack_[0].value.as< float > ();
			//std::cout << "division: ";
		}
	}
#line 1570 "parser.cc" // lalr1.cc:859
    break;

  case 70:
#line 331 "parser.yy" // lalr1.cc:859
    {
		yylhs.value.as< float > () = yystack_[2].value.as< float > () + yystack_[0].value.as< float > ();
		//std::cout << "somme: ";
	}
#line 1579 "parser.cc" // lalr1.cc:859
    break;

  case 71:
#line 335 "parser.yy" // lalr1.cc:859
    {
		yylhs.value.as< float > () = yystack_[2].value.as< float > () - yystack_[0].value.as< float > ();
		//std::cout << "soustraction: ";
	}
#line 1588 "parser.cc" // lalr1.cc:859
    break;

  case 72:
#line 341 "parser.yy" // lalr1.cc:859
    {
		std::cout << "entier: " << yystack_[0].value.as< int > () << std::endl;
		yylhs.value.as< float > () = yystack_[0].value.as< int > ();
	}
#line 1597 "parser.cc" // lalr1.cc:859
    break;


#line 1601 "parser.cc" // lalr1.cc:859
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


  const signed char  Parser ::yypact_ninf_ = -72;

  const signed char  Parser ::yytable_ninf_ = -1;

  const signed char
   Parser ::yypact_[] =
  {
      24,   -72,   -12,    13,   -72,    15,   -72,    24,    32,   -72,
      67,    56,    49,    50,    51,    55,    63,    65,    70,    71,
      71,    71,    72,    57,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,     3,   -72,    92,     4,    10,    82,    82,    10,    12,
     -72,   -72,   -72,    30,    67,    67,    67,    67,   -72,   -72,
     -72,    10,    10,   -72,   -17,    67,   -72,    76,    77,    78,
     -72,   -72,    79,    81,    35,    83,    41,   -72,    84,   -72,
     -72,    71,   -72,    56,    56,    56,    49,    49,   -72,    58,
      49,    10,    10,    10,    10,    56,   100,   104,   104,   -72,
      67,    86,    87,    67,    67,    88,    -5,   -72,    73,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,    56,    20,    20,    56,    56,    90,
     -72,    91,    93,   -72,    39,   -72,   -72,   -72,    94,    95,
     -72,    85,    89,    67,   113,   111,   102,   -72,   116,   119,
     -72,   -72,    56,   -72,   105,    67,   -72,   -72,    96,    67,
      56,   -72,    56,    98,    97,   -72,    67,   -72,    73,   -72
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       0,    10,     0,     0,     5,     0,     1,     0,     0,     6,
       0,    11,    20,     0,     0,     0,     0,     0,     0,    35,
      35,    35,     0,     0,    12,    27,    30,    14,    16,    28,
      29,     0,    18,     0,     0,     0,    53,    53,     0,     0,
      31,    32,    33,     0,     2,     0,     0,     0,    21,    23,
      72,     0,     0,    25,    65,     0,    41,    59,     0,     0,
      58,    55,     0,     0,     0,     0,     0,    40,    36,    61,
      62,    35,     3,    11,    11,    11,    20,    20,    66,     0,
      20,     0,     0,     0,     0,    11,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,    34,     7,    13,
      15,    17,    22,    24,    67,    26,    70,    71,    68,    69,
      19,    60,    56,    57,    11,     0,     0,    11,    11,     0,
      38,    37,     0,     4,     0,    63,    64,    47,    49,    50,
      48,     0,     0,     0,     0,     0,     0,    42,     0,     0,
      44,    46,    11,    39,     0,     0,    51,    52,     0,     0,
      11,    45,    11,     0,     0,    43,     0,     8,     7,     9
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -72,   122,   -72,   -72,   -28,   -72,   -10,   -71,   -72,   -72,
     -72,   -72,   -38,   -72,   -72,   -72,   -72,   -72,   -15,   -72,
     -72,   -72,   101,    16,   -72,   -72,   -72,   -19,    99,   -72,
     -23,   -72
  };

  const short int
   Parser ::yydefgoto_[] =
  {
      -1,     3,    98,     7,   123,   158,     4,    23,    45,    46,
      47,    55,    32,    76,    77,    80,    24,    25,    40,    26,
      27,    28,    63,   127,    64,    29,    30,    60,   128,   129,
      53,    54
  };

  const unsigned char
   Parser ::yytable_[] =
  {
      11,   120,    99,   100,   101,    41,    42,    48,    57,    49,
      50,     5,    61,     6,   110,    66,    68,    50,    67,    50,
     121,    58,    59,    81,    82,    83,    84,     1,    78,    79,
      69,    70,   125,   126,    72,    73,    74,    75,   102,   103,
      69,    70,   105,   124,    51,    85,   131,   132,    52,    91,
      92,    51,     8,    51,    10,    52,    97,    52,   106,   107,
     108,   109,     2,    94,    95,    12,   136,   137,   112,   113,
       1,   148,    31,    33,    34,    13,    14,    15,    35,   153,
     114,   154,    16,   117,   118,    17,    36,    18,    37,    19,
      20,    21,    22,    38,    39,    43,    44,    56,    62,    86,
      87,    88,    89,    90,   104,    93,   111,    96,    57,   115,
     116,   122,   133,   119,   134,   140,   135,   138,   139,   143,
     144,   141,   146,   142,   145,   147,   155,   149,   151,     9,
     159,     0,   130,     0,     0,   150,   156,     0,    65,   152,
       0,     0,    71,     0,     0,     0,   157
  };

  const short int
   Parser ::yycheck_[] =
  {
      10,     6,    73,    74,    75,    20,    21,     4,     4,     6,
       7,    23,    35,     0,    85,    38,    39,     7,     6,     7,
      25,    17,    18,    40,    41,    42,    43,     3,    51,    52,
      10,    11,    12,    13,    44,    45,    46,    47,    76,    77,
      10,    11,    80,   114,    41,    55,   117,   118,    45,    14,
      15,    41,    37,    41,    22,    45,    71,    45,    81,    82,
      83,    84,    38,    22,    23,     9,    27,    28,    87,    88,
       3,   142,    23,    23,    23,    19,    20,    21,    23,   150,
      90,   152,    26,    93,    94,    29,    23,    31,    23,    33,
      34,    35,    36,    23,    23,    23,    39,     5,    16,    23,
      23,    23,    23,    22,    46,    22,     6,    23,     4,    23,
      23,    38,    22,    25,    23,    30,    23,    23,    23,     6,
       9,    32,     6,   133,    22,     6,    28,    22,    32,     7,
     158,    -1,   116,    -1,    -1,   145,    39,    -1,    37,   149,
      -1,    -1,    43,    -1,    -1,    -1,   156
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,    38,    51,    56,    23,     0,    53,    37,    51,
      22,    56,     9,    19,    20,    21,    26,    29,    31,    33,
      34,    35,    36,    57,    66,    67,    69,    70,    71,    75,
      76,    23,    62,    23,    23,    23,    23,    23,    23,    23,
      68,    68,    68,    23,    39,    58,    59,    60,     4,     6,
       7,    41,    45,    80,    81,    61,     5,     4,    17,    18,
      77,    80,    16,    72,    74,    72,    80,     6,    80,    10,
      11,    78,    56,    56,    56,    56,    63,    64,    80,    80,
      65,    40,    41,    42,    43,    56,    23,    23,    23,    23,
      22,    14,    15,    22,    22,    23,    23,    68,    52,    57,
      57,    57,    62,    62,    46,    62,    80,    80,    80,    80,
      57,     6,    77,    77,    56,    23,    23,    56,    56,    25,
       6,    25,    38,    54,    57,    12,    13,    73,    78,    79,
      73,    57,    57,    22,    23,    23,    27,    28,    23,    23,
      30,    32,    56,     6,     9,    22,     6,     6,    57,    22,
      56,    32,    56,    57,    57,    28,    39,    56,    55,    54
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    50,    51,    52,    51,    53,    51,    54,    55,    54,
      56,    57,    58,    57,    59,    57,    60,    57,    61,    57,
      62,    63,    62,    64,    62,    65,    62,    66,    66,    66,
      66,    67,    67,    67,    67,    68,    68,    68,    68,    68,
      68,    69,    70,    70,    71,    71,    71,    72,    72,    73,
      73,    73,    73,    74,    74,    75,    76,    76,    76,    77,
      77,    78,    78,    79,    79,    80,    80,    80,    80,    80,
      80,    80,    81
  };

  const unsigned char
   Parser ::yyr2_[] =
  {
       0,     2,     7,     0,    10,     0,     3,     0,     0,    10,
       1,     0,     0,     4,     0,     4,     0,     4,     0,     5,
       0,     0,     4,     0,     4,     0,     4,     1,     1,     1,
       1,     2,     2,     2,     4,     0,     2,     4,     4,     6,
       2,     3,     7,    11,     7,     9,     7,     4,     4,     1,
       1,     3,     3,     0,     2,     3,     5,     5,     3,     1,
       3,     1,     1,     1,     1,     1,     2,     3,     3,     3,
       3,     3,     1
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
  "paramAction", "jardin", "condition", "boucle", "composanteCondition",
  "conditionParametres", "negation", "nombreTortues", "couleur",
  "paramCouleur", "directionHorizontale", "directionVerticale",
  "operation", "nombre", YY_NULLPTR
  };


  const unsigned short int
   Parser ::yyrline_[] =
  {
       0,   102,   102,   106,   106,   110,   110,   114,   117,   117,
     122,   127,   130,   130,   133,   133,   136,   136,   139,   139,
     144,   147,   147,   150,   150,   153,   153,   158,   161,   164,
     167,   172,   175,   178,   181,   186,   189,   193,   197,   203,
     209,   217,   222,   225,   230,   233,   236,   241,   242,   245,
     248,   251,   254,   259,   262,   268,   273,   276,   279,   284,
     287,   292,   295,   300,   303,   308,   312,   315,   318,   322,
     331,   335,   341
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
#line 2039 "parser.cc" // lalr1.cc:1167
#line 346 "parser.yy" // lalr1.cc:1168


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
