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
FILE* pf_asm;
 typedef struct{
        int posicion;
        char nombre[30];
        char tipo[20];
        char valor[100];
        int longitud;
        } TS_reg;
    
 TS_reg tabla_simbSinta[100];

char listaDeTipos[][100]={"."};
int listaDeIDs[100];

int cant_entradaSint = 0;
int cantidadTipos=0;              
int cantidadIDs=0;     
char* yytext;
char stringVarAux[5];

void agregarTipo(char * );
void agregarIDs(char * );
char* get_nombre_cte_string_asm(char* cte);

int busca_en_TSinta(char*);
void busca_Var_Existe(char*);
int graba_TSinta();
int inserta_TSinta(char*,char*);
//grabar archivo assembler
int grabar_archivo_asm();

// TERCETO DECLARACIONES
typedef struct terceto{
  char* operacion[5];
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
      expresion_between_aux,
      expresion_sum_terceto,
      expresion_cont_terceto,
      expresion_cont_terceto_uno,
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
  char * doubleval;
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
	{printf(" Fin COMPILADOR ok\n"); graba_TSinta(); escribirArchivoTercetos(); grabar_archivo_asm(); };

est_declaracion:
	DECVAR {printf("     DECLARACIONES\n");} declaraciones ENDDEC {printf(" Fin de las Declaraciones\n"); 
                                                                  
                                                                  }
        ; 


declaraciones:                    
             declaracion
             | declaraciones declaracion
           ;

declaracion: lista_var{printf("lista de var\n");} PCOMA 
              type{ printf("TIPO\n" );} 
           ;
type: REAL{agregarTipo(yytext);
         } | STRING{agregarTipo(yytext);}

lista_var:  
   ID {agregarIDs(yytext); }
   | lista_var COMA ID  {agregarIDs(yytext); }
   ;

bloque:          {printf(" Inicia BLOQUE\n");} sentencia | bloque sentencia ;

sentencia:      ciclow| seleccion | asignacion | teclado | reglaaverage

teclado:        READ ID | WRITE CONST_STR | WRITE ID ;

reglabetween:   BETWEEN{printf(" Regla BETWEEN\n");} P_A 
                expresion{expresion_terceto_aux = expresion_terceto;} COMA C_A 
                expresion{expresion_between_aux = crearTerceto(">=", expresion_terceto_aux.numeroTerceto, expresion_terceto.numeroTerceto);} PCOMA 
                expresion{crearTerceto("==",expresion_between_aux.numeroTerceto,crearTerceto("<=", expresion_terceto_aux.numeroTerceto, expresion_terceto.numeroTerceto).numeroTerceto);
                          } C_C P_C;



reglaaverage:   AVERAGE{printf(" Regla AVERAGE\n");} P_A C_A listaexpresiones C_C P_C { 
               
                t_terceto t_div = crearTerceto("/", expresion_sum_terceto.numeroTerceto, expresion_cont_terceto.numeroTerceto);
                t_terceto t_avg = crearTerceto("avg", -1, -1);
                crearTerceto("=",t_avg.numeroTerceto,t_div.numeroTerceto);

                }
listaexpresiones: listaexpresiones COMA expresion {
                          
                //Sumamos a Sum y asignamos el valor
                t_terceto t_suma = crearTerceto("+", expresion_sum_terceto.numeroTerceto, expresion_terceto.numeroTerceto); 
                crearTerceto("=", expresion_sum_terceto.numeroTerceto, t_suma.numeroTerceto); 
                
                //lo asignamos a las estructuras
                t_terceto t_cont = crearTerceto("+",expresion_cont_terceto.numeroTerceto, expresion_cont_terceto_uno.numeroTerceto);
                crearTerceto("=",expresion_cont_terceto.numeroTerceto,t_cont.numeroTerceto);
                
                } 
listaexpresiones: expresion  { 
                  
                //expresion_terceto_aux = expresion_terceto;
                //Creo las variables 
                expresion_sum_terceto = crearTerceto("sum",-1,-1); 
                expresion_cont_terceto = crearTerceto("cont",-1,-1); 

                //Sumamos a Sum y asignamos el valor
                t_terceto t_suma = crearTerceto("+", expresion_sum_terceto.numeroTerceto, expresion_terceto.numeroTerceto); 
                crearTerceto("=", expresion_sum_terceto.numeroTerceto, t_suma.numeroTerceto); 
                
                //Creamos el 1 para poder incrementar y lo asignamos a las estructuras
                expresion_cont_terceto_uno = crearTerceto("1",-1,-1);
                t_terceto t_cont = crearTerceto("+",expresion_cont_terceto.numeroTerceto, expresion_cont_terceto_uno.numeroTerceto);
                crearTerceto("=",expresion_cont_terceto.numeroTerceto,t_cont.numeroTerceto);
                
                }


ciclow:         WHILE condicion{ printf("     CONDICION DEL WHILE\n");}bloque ENDW ;

asignacion: ID OP_AS expresion {
              busca_Var_Existe($<str_val>1);
              //printf("    ASIGNACION\n");
              //printf("La variable recuperada es : %s y el UNO %s y %f\n",yytext , $<str_val>1,$<doubleval>1);
              t_terceto tAux = crearTerceto($<str_val>1,-1,-1); 
              crearTerceto(":=", tAux.numeroTerceto, expresion_terceto.numeroTerceto);
              //mostrarTerceto(tAux);
            }


seleccion: 
    	  IF  condicion THEN bloque ENDIF{printf("     IF\n");} 
	| IF  condicion THEN bloque ELSE bloque ENDIF {printf("     IF con ELSE\n");};

condicion: 
         comparacion 
         |comparacion OP_LOG comparacion 
         | OP_NOT comparacion
	 ;

comparacion:  expresion{expresion_terceto_aux = expresion_terceto;}
         OP_COMPARACION{strcpy(stringVarAux,yytext);}  expresion 
         {crearTerceto(stringVarAux, expresion_terceto_aux.numeroTerceto, expresion_terceto.numeroTerceto);}
        | reglabetween  ;

expresion:
         termino {expresion_terceto = termino_terceto;} 
         |  expresion {expresion_terceto = termino_terceto;} 
            OP_SURES {strcpy(stringVarAux,yytext);} 
            termino {expresion_terceto = crearTerceto(stringVarAux, expresion_terceto.numeroTerceto, termino_terceto.numeroTerceto);} 

termino: 
       factor {termino_terceto = factor_terceto;}
       | termino OP_MULTDIV{strcpy(stringVarAux,yytext);} 
          factor{termino_terceto = crearTerceto(stringVarAux, termino_terceto.numeroTerceto, factor_terceto.numeroTerceto);} 
        ;

factor: 
      ID {
          busca_Var_Existe(yytext);
          printf("LLEGO EL LEXEMA DEL ID  : %s\n",yytext);
          factor_terceto = crearTerceto($<str_val>1,-1,-1);
          }
      | CONST_REAL {
          
          printf("PASO UNA CONSTANTE REAL %s\n", $<doubleval>1);
          factor_terceto = crearTerceto($<doubleval>1,-1,-1);
          
          }
      | CONST_STR  
          {
          printf("PASO UNA CONSTANTE STRING ");
          }
      | reglaaverage
      ;

%%
int main(int argc,char *argv[])
{
  fflush(stdout);

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
  for (int i = 0; i < cantidadIDs; i++)
  {
   
    strcpy(tabla_simbSinta[ listaDeIDs[i] ].tipo, tipo);
    listaDeIDs[i] = 0;
  }
  cantidadIDs=0;


}

void agregarIDs(char * idValue)
{
  listaDeIDs[cantidadIDs] = inserta_TSinta("ID", idValue);
  cantidadIDs++;
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
    
    for(i = 0; i<cant_entradaSint; i++)
    {
      
          if(!strcmp(tabla_simbSinta[i].nombre, var))
          {
            if(!strcmp(tabla_simbSinta[i].tipo,"REAL")){
              return;  
            }else{
              printf("\n Tipo Incompatible: %s\n", var);
            yyerror(var);
            }
            
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
  strcpy(result.operacion, operacion);
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
  //printf("terceto de operacion: [%d] %d %s %d\n", t.numeroTerceto, t.t1, t.operacion, t.t2);
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
  //printf("terceto a escribir en archivo:");
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



int grabar_archivo_asm()
{
     int i;
     char aux_cte[31];

     char* Asm_file = "Final.txt";
     
     if((pf_asm = fopen(Asm_file, "w")) == NULL)
     {
               printf("Error al grabar el archivo de intermedio \n");
               exit(1);
     }
     
      fprintf(pf_asm, ".MODEL LARGE \n");
    fprintf(pf_asm, ".386 \n");
    fprintf(pf_asm, ".STACK 200h \n");
    fprintf(pf_asm, ".DATA \n");

    for(i=0; i<cant_entradaSint; i++)
    {
      strcpy(aux_cte, get_nombre_cte_string_asm(tabla_simbSinta[i].nombre));
      //if(!strcmp(tabla_simb[i].tipo, "CONST_REAL"))
      //{
      //  fprintf(pf_asm, "\t_%s dd %s \n", aux_cte, tabla_simb[i].valor);
      //}
      //else 
        if(!strcmp(tabla_simbSinta[i].tipo, "STRING"))
      {
        //cad1 db ìprimer cadenaî,í$í, 37 dup (?)
        //_aux1 db MAXTEXTSIZE dup(?), ë$í 
        fprintf(pf_asm, "\t_%s db  %d dup (?) '$'\n", aux_cte,30 );//30 - Tabla_simb[i].longitud);
      }
      //Si descomentamos esto solo pone lo que sean variables
      else if(!strcmp(tabla_simbSinta[i].tipo, "REAL"))
      {
        fprintf(pf_asm, "\t_%s dd ? \n", aux_cte);
      }
    }

     fprintf(pf_asm, ".CODE \n");
     fprintf(pf_asm, "\t mov AX,@DATA \n");
     fprintf(pf_asm, "\t mov DS,AX \n");
   /*
     *
     *
     *
    */
   fprintf(pf_asm, "\t mov ax, 4C00h \n");
   fprintf(pf_asm, "\t int 21h \n");
   fprintf(pf_asm, "\t END \n");
     
     fclose(pf_asm);
}


char* get_nombre_cte_string_asm(char* cte)
{
  /*Para quitar caracteres raros para asm*/
  char aux[31];
  int  i=0;
  
  while(*cte != '\0')
  {
    if(*cte != ' ' && *cte != '\"' && *cte != '.' && *cte != '+' && *cte != '-' && *cte != '*' && *cte != '/' && *cte != ','
      && *cte != '&' && *cte != '|' && *cte != '!' && *cte != '(' && *cte != ')' && *cte != '[' && *cte != ']'
      && *cte != ':' && *cte != '=' && *cte != '<' && *cte != '>' && *cte != '@' && *cte != '%' && *cte != '$')
    {
      aux[i] = *cte;
      i++;
    }
    cte++;
  }
  aux[i] = '\0';
  
  return aux;
}