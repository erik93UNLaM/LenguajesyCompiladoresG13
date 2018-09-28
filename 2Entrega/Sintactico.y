%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
int yystopparser=0;
FILE  *yyin;

%}

%token PROGRAM
%token ENDP
%token DECVAR
%token ENDDEC
%token CONST_REAL
%token CONST_STR
%token REAL
%token STRING
%token IF THEN ELSE ENDIF
%token WHILE ENDW
%token OP_LOG
%token OP_NOT
%token ID
%token OP_COMPARACION
%token OP_AS
%token OP_SURES
%token OP_MULTDIV
%token COMA
%token P_A P_C
%token C_A C_C
%token READ
%token WRITE
%token BETWEEN
%token AVERAGE
%token PCOMA


%%
programa: PROGRAM {printf(" Inicia COMPILADOR\n");} est_declaracion bloque ENDP   
	{printf(" Fin COMPILADOR ok\n");};

est_declaracion:
	DECVAR {printf("     DECLARACIONES\n");} declaraciones ENDDEC {printf(" Fin de las Declaraciones\n");}
        ; 


declaraciones:                    
             declaracion
             | declaraciones declaracion
           ;

declaracion:  
           lista_var PCOMA type 
           ;
type: REAL | STRING

lista_var:  
   ID
   | lista_var COMA ID  
   ;

bloque:          {printf(" Inicia BLOQUE\n");} sentencia | bloque sentencia ;

sentencia:      ciclow | seleccion | asignacion | teclado | reglabetween| reglaaverage;

teclado:        READ ID | WRITE CONST_STR | WRITE ID ;

reglabetween:    BETWEEN P_A expresion COMA C_A expresion PCOMA expresion C_C P_C;



reglaaverage:   AVERAGE P_A C_A listaexpresiones C_C P_C
listaexpresiones: listaexpresiones COMA expresion
listaexpresiones: expresion


ciclow:         WHILE condicion{ printf("     CONDICION DEL WHILE\n");}bloque ENDW ;

asignacion: ID OP_AS expresion {printf("    ASIGNACION\n");};


seleccion: 
    	  IF  condicion THEN bloque ENDIF{printf("     IF\n");} 
	| IF  condicion THEN bloque ELSE bloque ENDIF {printf("     IF con ELSE\n");};

condicion: 
         comparacion 
         |comparacion OP_LOG comparacion 
         | OP_NOT comparacion
	 ;

comparacion:  expresion OP_COMPARACION expresion | reglabetween  ;

expresion:
         termino | expresion OP_SURES termino;

termino: 
       factor | termino OP_MULTDIV factor ;

factor: 
      ID 
      | CONST_REAL
      | CONST_STR  
      ;

%%
int main(int argc,char *argv[])
{
  if ((yyin = fopen(argv[1], "rt")) == NULL)
  {
	printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
  }
  else
  {
	yyparse();
  }
  fclose(yyin);
  return 0;
}

int yyerror(void)
     {
       printf("Syntax Error\n");
	 system ("Pause");
	 exit (1);
     }

