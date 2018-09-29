%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "y.tab.h"
int yystopparser=0;
FILE  *yyin;
FILE* pf_TS;
 typedef struct{
        int posicion;
        char nombre[30];
        char tipo[20];
        char valor[100];
        int longitud;
        } TS_reg;
    
 TS_reg tabla_simb[100];

char listaDeTipos[][100]={"."};
char listaDeIDs[][100]={"."};

int cant_entradaSint = 0;
int cantidadTipos=0;              
int cantidadIDs=0;     
char* yytext;


void agregarTipo(char * );
void agregarIDs(char * );


int busca_en_TSinta(char*);
int graba_TSinta();
int inserta_TSinta(char*,char*);


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
	DECVAR {printf("     DECLARACIONES\n");} declaraciones ENDDEC {printf(" Fin de las Declaraciones\n"); graba_TSinta();}
        ; 


declaraciones:                    
             declaracion
             | declaraciones declaracion
           ;

declaracion:  
           lista_var PCOMA type 
           ;
type: REAL{agregarTipo(yytext);} | STRING{agregarTipo(yytext);}

lista_var:  
   ID {agregarIDs(yytext); }
   | lista_var COMA ID  {agregarIDs(yytext); }
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
	printf("\n \n \n \n \n \nNo se puede abrir el archivo: %s\n \n  \n  \n \n \n \n \n \n ", argv[1]);
  }
  else
  {
	yyparse();
  }
  fclose(yyin);
  return 0;
}

int yyerror(char const *line)
{
  printf("Syntax Error\n");   
  exit (1);
}

/**********************TIPO y IDS***************************/
void agregarTipo(char * tipo)
{
  strcpy(listaDeTipos[cantidadTipos],tipo);
  cantidadTipos++;
}

void agregarIDs(char * idValue)
{
  strcpy(listaDeIDs[cantidadIDs],idValue);
  cantidadIDs++;
  printf("IDDDDDDDDDDDDDDDD==== %s\n",idValue);
  inserta_TSinta("ID", idValue);
}



//Buscamos que no la hayamos guardado
int busca_en_TSinta(char* nombre)
{
    int i;
    for(i = 0; i<cant_entradaSint; i++)
    {
          if(!strcmp(tabla_simb[i].nombre, nombre))
          {
                 return i;
          }
    }
    
    return -1;
}


int inserta_TSinta(char* tipo,char* valor)
{
   if((yylval = busca_en_TSinta(yytext)) == -1)
     {
    TS_reg reg;
    strcpy(reg.nombre, yytext);
    strcpy(reg.tipo, tipo);
    strcpy(reg.valor, valor);
    reg.longitud = strlen(yytext);
    reg.posicion = cant_entradaSint;
    tabla_simb[cant_entradaSint++] = reg;
    
    return yylval = cant_entradaSint-1;
   }
   return yylval;
}

int graba_TSinta()
{
    printf("\n******************************************************************************************************************************************************************\n");
     printf("\n GRABA EN TS \n");
     printf("\n******************************************************************************************************************************************************************\n");
     int i;
     char* TS_file = "ts.txt";
     
     if((pf_TS = fopen(TS_file, "w")) == NULL)
     {
               printf("\nE \nE \nE \nE \nE \nE \nE \nE Error al grabar la tabla de simbolos \nE \nE \nE \nE \nE \nE \nE \nE \nE \nE \nE \nE \nE ");
               exit(1);
     }
     
     fprintf(pf_TS, "POSICION \t\t NOMBRE \t\t TIPO \t\t VALOR \t\t LONGITUD \n");
     
      for(i = 0; i < cant_entradaSint; i++)
      {
           fprintf(pf_TS,"%d \t\t\t\t %s \t\t\t", tabla_simb[i].posicion, tabla_simb[i].nombre);
           
          
            if(tabla_simb[i].tipo != NULL)
               fprintf(pf_TS,"%s \t\t\t", tabla_simb[i].tipo);
           
          
            if(tabla_simb[i].valor != NULL)
               fprintf(pf_TS,"%s \t\t\t", tabla_simb[i].valor);
           
            fprintf(pf_TS,"%d \n", tabla_simb[i].longitud);
      }    
     fclose(pf_TS);
}
