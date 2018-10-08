%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <assert.h>
#include "y.tab.h"
FILE  *yyin;
//int yylval;
//float yyfval; 
typedef struct{
      int posicion;
      char nombre[30];
      char tipo[20];
      char valor[100];
      int longitud;
      } TS_reg;
  


%}
%option noyywrap  
%option yylineno 

DIGITO				[0-9] 
LETRA				[a-zA-Z]
COMA                [","]
PCOMA               [":"] 
CONST_STR           \"({LETRA}|{DIGITO}|.)+\" 
COMENTARIOS         \-\/({LETRA}|{DIGITO}|.)+\/\-
CONST_REAL          {DIGITO}*"."{DIGITO}*|{DIGITO}*
ID					{LETRA}({LETRA}|{DIGITO}|_)*
OP_COMPARACION     	["<"|"="|">"|"<="|">="|"><"]
OP_SURES           	["+"|"-"]
OP_MULTDIV        	["*"|"/"]
OP_AS				[":="]
OP_LOG				["AND"|"OR"]
OP_NOT       ["NOT"]




%%
"program"		{ return PROGRAM;}
"endp"      { graba_TS(); return ENDP; }
"DECVAR"		{ return DECVAR; }
"ENDDEC"		{ return ENDDEC;}
"WRITE"			{ return WRITE;}
"READ"			{ return READ;}
"BETWEEN"		{ return BETWEEN;}
"AVG"			{ return AVERAGE;}
"REAL"			{ return REAL;}
"STRING"		{ return STRING;}
"if"			{ return IF;}
"then"   		{ return THEN;}
"else"   		{ return ELSE;}
"endif"	      	{ return ENDIF;}
"while"			{return WHILE;}
"endw"  		{ return ENDW;}
":="			{ yylval.str_val = strdup(yytext); 
            return OP_AS;}
"+"				{ return OP_SURES;}
"-"				{ return OP_SURES;}
"*"				{ return OP_MULTDIV;}
"/"				{ return OP_MULTDIV;}
">"				{ return OP_COMPARACION;}
">="			{ return OP_COMPARACION;}
"<"				{ return OP_COMPARACION;}
"<="			{ return OP_COMPARACION;}
"><"			{ return OP_COMPARACION;}
"="				{ return OP_COMPARACION;}
"AND"			{ return OP_LOG;}
"OR"			{ return OP_LOG;}
"NOT"           { return OP_NOT;}
":"				{ return PCOMA;}
{ID}			{ return ID; }
{CONST_STR}		{  
					if(!validar_longitud_string(yytext)) { 
	          yyterminate(); 
	        }
          inserta_TS("CONST_STR",yytext);
					return CONST_STR;
				}

{CONST_REAL}	{ 
                if(!validar_cota_real()){
                  yyterminate(); 
                } 
                inserta_TS("CONST_REAL",yytext); 
                return CONST_REAL;
              }
{COMA}			{ return COMA;}
{COMENTARIOS}	

"("				{ return P_A;}
")"				{ return P_C;}
"["				{ return C_A;}
"]"				{ return C_C;}



"\n"      		
"\t"		

%%

/***********************INICIO DECLARACIONES*****************************/
int cant_entradas = 0;
FILE* pf_TS;
TS_reg tabla_simb[100];

int validar_longitud_string(char*);
int validar_cota_real();

int busca_en_TS(char*);
int graba_TS();
int inserta_TS(char*,char*);



int validar_longitud_string(char* texto){
  char* p = texto;
  int idx = 0;
  while(idx++ < 30 && *p != '\n'){
    p++;
  }

  if(*p != '\n'){
    printf("SINTAX ERROR: STRING EXCEDE MAXIMO DE 30 CARACTERES (%s)\n", texto);    
    return 0;
  }

  return 1;
}

int validar_cota_real()
{
	float valor = atof(yytext);
	if(valor > 4294967295 || valor < -4294967296)
	{
		printf("SINTAX ERROR: REAL OVERFLOW\n");		
		return 0;
	}
	return 1;
}

//Buscamos que no la hayamos guardado
int busca_en_TS(char* nombre)
{
    int i;

    for(i = 0; i<cant_entradas; i++)
    {
          if(!strcmp(tabla_simb[i].nombre, nombre))
          {
            printf("y la posicion es:%d \n",i);
                 return i;
          }
    }
    
    return -1;
}


int inserta_TS(char* tipo,char* valor)
{
   if(busca_en_TS(yytext) == -1)
    {
    TS_reg reg;
    strcpy(reg.nombre, yytext);
    strcpy(reg.tipo, tipo);
    strcpy(reg.valor, valor);
    reg.longitud = strlen(yytext);
    reg.posicion = cant_entradas;
    tabla_simb[cant_entradas++] = reg;
    
    return cant_entradas-1;
   }
}

int graba_TS()
{
     printf("GRABA EN TS");
     int i;
     char* TS_file = "ts.txt";
     
     if((pf_TS = fopen(TS_file, "w+")) == NULL)
     {
               printf("Error al grabar la tabla de simbolos \n");
               exit(1);
     }
      fprintf(pf_TS, "POSICION \t\t\t NOMBRE \t\t TIPO \t\t VALOR \t\t LONGITUD \n");
      for(i = 0; i < cant_entradas; i++)
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