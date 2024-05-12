%{
#include <stdio.h>
void yyerror(const char *s);
int yylex(void);
int yyparse(void);
%}

%union {
    int num;
}
%token <num> NUMBER
%left '+' '-'
%left '*' '/'
%type <num> AE
%type <num> E

%%

AE : E { printf("The result is %d\n", $$); }
E  : E '*' E { $$ = $1 * $3; } 
   | E '/' E { $$ = $1 / $3; } 
   | E '+' E { $$ = $1 + $3; }
   | E '-' E { $$ = $1 - $3; }
   | NUMBER  { $$ = $1; }
   ;

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("Error: %s\n", s);
}
