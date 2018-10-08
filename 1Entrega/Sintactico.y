%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "y.tab.h"

#define TERCETOS "intermedia.txt"

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
    
 TS_reg tabla_simbSinta[100];

char listaDeTipos[][100]={"."};
char listaDeIDs[][100]={"."};

int cant_entradaSint = 0;
int cantidadTipos=0;              
int cantidadIDs=0;     
char* yytext;


void agregarTipo(char * );
void agregarIDs(char * );


int busca_en_TSinta(char*);
void busca_Var_Existe(char*);
int graba_TSinta();
int inserta_TSinta(char*,char*);

// TERCETO DECLARACIONES
typedef struct terceto{
  char* operacion;
  int t1, t2;
  int numeroTerceto;
} t_terceto;

//Variables para tercetos
t_terceto  asignacion_terceto,
      expresion_terceto, 
      termino_terceto, 
      factor_terceto, 
      concatenacion_terceto,
      factor_terceto_aux,
      expresion_terceto_aux,
      condicion_terceto;
t_terceto *vectorTercetos;
int indiceTerceto = 0;


t_terceto crearTerceto(char*,int,int);
t_terceto* buscarTerceto(t_terceto t);
void mostrarTerceto(t_terceto terceto);
void escribirArchivoTercetos();
void escribirTerceto(t_terceto t1);

%}

%union {
  int intval;
  double doubleval;
  char *str_val;
}

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
	{printf(" Fin COMPILADOR ok\n"); graba_TSinta(); escribirArchivoTercetos(); };

est_declaracion:
	DECVAR {printf("     DECLARACIONES\n");} declaraciones ENDDEC {printf(" Fin de las Declaraciones\n"); 
                                                                  
                                                                  }
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

asignacion: ID OP_AS expresion {
              printf("    ASIGNACION\n");
              printf("La variable recuperada es : %s y el UNO %s y %f\n",yytext , $<str_val>1,$<doubleval>1);
              t_terceto tAux = crearTerceto($<str_val>1,-1,-1); 
              crearTerceto(":=", tAux.numeroTerceto, expresion_terceto.numeroTerceto);
              //mostrarTerceto(tAux);
            };


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
         termino {expresion_terceto = termino_terceto;} | expresion OP_SURES termino;

termino: 
       factor {termino_terceto = factor_terceto;}
       | termino OP_MULTDIV factor 
        {termino_terceto = crearTerceto(yytext, termino_terceto.numeroTerceto, factor_terceto.numeroTerceto);} 
        ;

factor: 
      ID {
          //busca_Var_Existe(yytext);
          printf("LLEGO EL LEXEMA DEL ID  : %s\n",yytext);
          factor_terceto = crearTerceto(yytext,-1,-1);
          }
      | CONST_REAL {
          printf("PASO UNA CONSTANTE REAL %s O EL DOUBLE:  %f\n", yytext, $<doubleval>1);
          factor_terceto = crearTerceto("FLOAT",-1,-1);
          }
      | CONST_STR  
          {
          printf("PASO UNA CONSTANTE STRING ");
          }
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
  //TERCETO
  //openFile(TERCETOS, &intermedia);
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



//Buscamos si fue creada la variable
int busca_en_TSinta(char* nombre)
{
    int i;
    for(i = 0; i<cant_entradaSint; i++)
    {
          if(!strcmp(tabla_simbSinta[i].nombre, nombre))
          {
                 return i;
          }
    }
    
    return -1;
}
//Buscamos si fue creada la variable para usarla
void busca_Var_Existe(char* var)
{int i;
printf("-----------------------------Entra a buscar variables declaradas----------------------------------\n");
printf("VAR:%s\n",var);
    
    for(i = 0; i<cant_entradaSint; i++)
    {
      printf("Orden: %i - Tabla:%s - Variable%s \n", i,tabla_simbSinta[i].valor, var );
          if(!strcmp(tabla_simbSinta[i].nombre, var))
          {
            printf("Tabla:%s",tabla_simbSinta[i].nombre);
            return;
          }
    }
    printf("Variable no declarada: %s\n\n", var);
            yyerror(var);
}

int inserta_TSinta(char* tipo,char* valor)
{
   if((busca_en_TSinta(yytext)) == -1)
     {
    TS_reg reg;
    strcpy(reg.nombre, yytext);
    strcpy(reg.tipo, tipo);
    strcpy(reg.valor, valor);
    reg.longitud = strlen(yytext);
    reg.posicion = cant_entradaSint;
    tabla_simbSinta[cant_entradaSint++] = reg;
    
    return cant_entradaSint-1;
   }
}

int graba_TSinta()
{
    
     int i;
     char* TS_file = "ts.txt";
     
     if((pf_TS = fopen(TS_file, "a+")) == NULL)
     {
               printf("\nE \nE \nE \nE \nE \nE \nE \nE Error al grabar la tabla de simbolos \nE \nE \nE \nE \nE \nE \nE \nE \nE \nE \nE \nE \nE ");
               exit(1);
     }
     
     fprintf(pf_TS, "POSICION \t\t\t NOMBRE \t\t TIPO \t\t VALOR \t\t LONGITUD \n");
     
      for(i = 0; i < cant_entradaSint; i++)
      {
           fprintf(pf_TS,"%d \t\t\t\t %s \t\t\t", tabla_simbSinta[i].posicion, tabla_simbSinta[i].nombre);
           
          
            if(tabla_simbSinta[i].tipo != NULL)
               fprintf(pf_TS,"%s \t\t\t", tabla_simbSinta[i].tipo);
           
          
            if(tabla_simbSinta[i].valor != NULL)
               fprintf(pf_TS,"%s \t\t\t", tabla_simbSinta[i].valor);
           
            fprintf(pf_TS,"%d \n", tabla_simbSinta[i].longitud);
      }    
     fclose(pf_TS);
}


//TERCETOS
//Crea el terceto con los indices de los tercetos. Si no existen tiene -1
t_terceto crearTerceto(char* operacion,int t1,int t2){
  t_terceto result;
  result.operacion = operacion;
  result.t1 = t1;
  result.t2 = t2;
  //t_terceto *aux = buscarTerceto(result);
  //if(indiceTerceto > 0 && aux != NULL){
   // result = *aux;
  //}
  //else{   
    result.numeroTerceto = indiceTerceto++;
    vectorTercetos = (t_terceto*) realloc(vectorTercetos, sizeof(t_terceto) * indiceTerceto);
    vectorTercetos[indiceTerceto-1] = result;
  //}
  return result;
}

//Muestra el Terceto
void mostrarTerceto(t_terceto t){
  printf("terceto de operacion: [%d] %d %s %d\n", t.numeroTerceto, t.t1, t.operacion, t.t2);
}


//Busca un terceto en el vector de tercetos
t_terceto* buscarTerceto(t_terceto t){
  int i;
  for (i = 0; i < indiceTerceto; ++i) 
    if(strcmp(vectorTercetos[i].operacion, t.operacion) == 0 && vectorTercetos[i].t1 == -1 && vectorTercetos[i].t2 == -1)
      return &(vectorTercetos[i]); 
  return NULL;
}

//Escribe todos los Tercetos
void escribirArchivoTercetos(){
  int i;
  for(i = 0; i < indiceTerceto; i++)
    escribirTerceto(vectorTercetos[i]);
}

//Escribe un terceto en el archivo
void escribirTerceto(t_terceto t){
  printf("terceto a escribir en archivo:");
  mostrarTerceto(t);
  FILE* arch = fopen(TERCETOS, "a+");
  if(strcmp(t.operacion, "BI")==0)
    fprintf(arch, "[%d] (%s, [%d], -)\n", t.numeroTerceto, t.operacion, t.t2);
  else if(t.t1 == -1 && t.t2 == -1)
    fprintf(arch, "[%d] (%s, _, _)\n", t.numeroTerceto, t.operacion);
  else if(t.t2 == -1)
    fprintf(arch, "[%d] (%s, [%d], _)\n", t.numeroTerceto, t.operacion, t.t1);
  else
    fprintf(arch, "[%d] (%s, [%d], [%d])\n", t.numeroTerceto, t.operacion, t.t1, t.t2);
  //printf("[%d] (%s, [%d])", t.numeroTerceto, t.operacion, t.(*t1).numeroTerceto); 
  fclose(arch);
}
