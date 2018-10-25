%option noinput
%option nounput
%option noyywrap
%option yylineno

%{
#include <iostream>
#include <cstdlib>
#include "ast.hpp"

using namespace std;

#include "parser.tab.hpp"

%}

%%

 /* Keywords */
"if"            { return if_token;       }
"else"          { return else_token;     }
"switch"        { return switch_token;   }
"case"          { return case_token;     }
"default"       { return default_token;  }
"for"           { return for_token;      }
"do"            { return do_token;       }
"while"         { return while_token;    }
"break"         { return break_token;    }
"continue"      { return continue_token; }
"goto"          { return goto_token;     }

"enum"          { return enum_token;     }
"return"        { return return_token;   }
"sizeof"        { return sizeof_token;   }
"struct"        { return struct_token;   }
"union"         { return union_token;    }

"auto"          { return auto_token;     }
"register"      { return register_token; }
"static"        { return static_token;   }
"extern"        { return extern_token;   }
"typedef"       { return typedef_token;  }

"const"         { return const_token;     }

 /* Types */
"void"          { return void_token; } 

"char"|"short"|"int"|"long"|"float"|"double"|"signed"|"unsigned" { return type_token; }

 /* Include header and define */
"#include"([ ]+)?((<(\\.|[^>])+>)|(\"(\\.|[^"])+\"))			 { return include_token; }
"#define"[ ]+[a-zA-z_][a-zA-z_0-9]*([ ]+[-]?[0-9]+("."[0-9]+)?)? { return define_token;  }

 /* Identifiers */
[_a-zA-Z][_a-zA-Z0-9]*	{
    yylval.s = new string(yytext);
    return id_token; 
}

 /* Strings */
["]([.]|[^\"])*["]                  { return string_const;  }

 /* Numeric literals */
[0-9]+                              { return val_const;     }
[0-9]+"."[0-9]+                     { return val_const;   }
['].[']                             { return val_const;    }
    

 /* Multi-character operators */
"||"        { return or_token;          }
"&&"        { return and_token;         }
"<="        { return leq_token;         }
">="        { return geq_token;         }
"=="        { return eq_token;          }
"!="        { return neq_token;         }
"<<"        { return lsh_token;         }
">>"        { return rsh_token;         }    
"->"        { return point_token;       }

"*="|"/="|"+="|"%="|">>="|"-="|"<<="|"&="|"^="|"|="  { return asgn_token; }
"++"|"--"   { return unary_token;   }


 /* One-character operators */
[-+*/:;=,.|'(){}\[\]%?&^!~&<>]       { return *yytext; }

 /* Single-line and multi-line comments */
"//"(\\.|[^\n])*[\n]            { }
[/][*]([^*]|[*]*[^*/])*[*]+[/]  { }


 /* Ignore white spaces, tabs, newlines */
[ \t\n]     { }


 /* Tokens unspecific for C language */
.   {
        cerr << "Lexical error: Unknown character '" << *yytext << "'." << endl;
        exit(EXIT_FAILURE);
    }

%%
