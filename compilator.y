%{
    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <unistd.h>
    extern FILE* yyin;
    extern char* yytext;
    extern int yylineno;
    int fd, fd1;
    char buff[100];
   
    struct node
    {
        char tip[100];
        char id[100];
        int intval;
        char charval[100];
        float floatval;
        struct node *next;
    };

    struct node *head_variable=NULL;
    struct node *current_variable=NULL;
    struct node *head_function=NULL;
    struct node *current_function=NULL;

    int findV(char id[])
    {
        struct node *current_variable=head_variable;

        if(head_variable==NULL)  //nu avem nicio variabila inregistrata
            return 0; 
        
        while(strcmp(current_variable->id,id)!=0) //denumirile difera
        {
            if(current_variable->next==NULL) //nu avem nicio variabila inregistrata
                return 0;
            else 
                current_variable=current_variable->next;
        }

        return 1;   //daca ajungem aici, inseamna ca am gasit deja o variabila cu acelasi id
    }

    void insert_variable(char tip[],char id[],int intval,char charval[],float floatval)
    {
        if(findV(id)==1) //exista deja variabila cu acest nume
        {
            printf("(LINE %d) Sunt doua variabile cu acelasi nume: %s\n",yylineno,id);
            exit(1);
        }

        //daca ajungem aici, inseamna ca nu avem deja acest nume in program
        struct node *new=(struct node*)malloc(sizeof(struct node));
        strcpy(new->tip,tip);
        strcpy(new->id,id);
        new->intval=intval;
        strcpy(new->charval,charval);
        new->floatval=floatval;
        
        //adaugare variabila la final de lista
        if(head_variable==NULL)
            head_variable=new;
        else
        {
            struct node *current_variable=head_variable;
            while(current_variable->next !=NULL)
                current_variable=current_variable->next;
            current_variable->next=new;
        }
    }

    int findF(char id[])
    {
        struct node *current_function=head_function;

        if(head_function==NULL)  //nu avem nicio functie inregistrata
            return 0; 
        
        while(strcmp(current_function->id,id)!=0) //denumirile difera
        {
            if(current_function->next==NULL) //nu avem nicio variabila inregistrata
                return 0;
            else 
                current_function=current_function->next;
        }

        return 1;   //daca ajungem aici, inseamna ca am gasit deja o variabila cu acelasi id
    }

    void insertFunction(char tip[],char id[],int intval,char charval[],float floatval)
    {
        if(findF(id)==1) //exista deja functie cu acest nume
        {
            printf("(LINE %d) Sunt doua functii cu acelasi nume: %s\n",yylineno,id);
            exit(1);
        }

        //daca ajungem aici, inseamna ca nu avem deja acest nume in program
        struct node *new=(struct node*)malloc(sizeof(struct node));
        strcpy(new->tip,tip);
        strcpy(new->id,id);
        new->intval=intval;
        strcpy(new->charval,charval);
        new->floatval=floatval;

        //adaugare functie la final de lista
        if(head_function==NULL)
            head_function=new;
        else
        {
            struct node *current_function=head_function;
            while(current_function->next !=NULL)
                current_function=current_function->next;
            current_function->next=new;
        }
    }

    
   
%}

%union 
{
     int intv;
     char* strv;
     float floatval;
}

%start s

%token <strv> TIP BEGINP ENDP VOID
%token IF ELSE WHILE FOR
%token CLASS CLASS_TIP
%token<strv> BOOL_VARIABLE
%token <strv> ID CONST_STRING CHAR
%token <strv> ARRAY
%token <floatval> CONST_FLOAT
%token <intv> CONST_INT
%token LB RB
%token PLUS MINUS MUL DIV
%token LESS GREAT LESSEQ GREATEQ EQ
%token AND OR
%token<strv> PRINT TYPEOF EVAL


%type <strv>param
%type <strv>params
%type <strv>arg




%left '+' '-'
%left '*' '/'
%%

s : declaratiiTip declaratieFunctii declaratieClase program {printf("program corect sintactic\n");}
  ;

declaratiiTip : declaratiiTip declaratieTip ';'
              | declaratieTip ';'
              ;

declaratieTip : TIP ID { snprintf(buff,100,"(%s) %s \n",$1, $2); write(fd, buff, strlen(buff));insert_variable($1,$2,0,"",0);}
              | ARRAY ID { snprintf(buff,100,"(%s) %s\n",$1, $2); write(fd, buff, strlen(buff));insert_variable($1,$2,0,"",0);}
              | TIP ID '=' CONST_INT 
                    { 
                        if(strstr($1,"int")==NULL)
                        {
                            printf("(LINE %d) Variabila este de alt tip!",yylineno);
                            exit(1);
                        }
                        else
                            snprintf(buff,100,"(%s) %s = %d\n",$1, $2,$4); write(fd, buff, strlen(buff));insert_variable($1,$2,$4,"",0);
                    }
              | TIP ID '=' CONST_STRING 
                    { 
                        if(strstr($1,"char")==NULL)
                        {
                            printf("(LINE %d) Variabila este de alt tip!",yylineno);
                            exit(1);
                        }
                        else
                            snprintf(buff,100,"(%s) %s = %s\n",$1,$2,$4); write(fd, buff, strlen(buff));insert_variable($1,$2,0,$4,0);
                    }
              | TIP ID '=' CONST_FLOAT 
                    { 
                        if(strstr($1,"float")==NULL)
                        {
                            printf("(LINE %d) Variabila este de alt tip!",yylineno);
                            exit(1);
                        }
                        snprintf(buff,100,"(%s) %s = %f\n",$1,$2,$4); write(fd, buff, strlen(buff));insert_variable($1,$2,0,"",$4);
                    }
              | TIP ID '=' CHAR 
                    { 
                        if(strstr($1,"char")==NULL)
                        {
                            printf("(LINE %d) Variabila este de alt tip!",yylineno);
                            exit(1);
                        }
                        snprintf(buff,100,"(%s) %s = %s\n",$1,$2,$4); write(fd, buff, strlen(buff));insert_variable($1,$2,0,$4,0);
                    }
              | ARRAY ID '=' { snprintf(buff,100,"(%s) %s = {",$1,$2); write(fd, buff, strlen(buff));insert_variable($1,$2,0,"",0);}LB vars RB {write(fd," }\n",3);}
              ;

vars : vars ',' {write(fd,",",1);} var 
     | var
     ;

var : CONST_INT {snprintf(buff,100," %d",$1);write(fd,buff,strlen(buff));}
    | CONST_FLOAT {snprintf(buff,100," %f",$1);write(fd,buff,strlen(buff));}
    | CHAR {snprintf(buff,100," %s",$1);write(fd,buff,strlen(buff));}
    | BOOL_VARIABLE {snprintf(buff,100," %s",$1);write(fd,buff,strlen(buff));}
    ;

declaratieFunctii : declaratieFunctii declaratieFunctie
                  | declaratieFunctie
                  ;

declaratieFunctie : TIP ID '(' params ')' LB bloc RB { snprintf(buff,100,"(%s) %s (%s) \n",$1, $2,$4); write(fd1, buff, strlen(buff));insertFunction($1,$2,0,"",0);}
                  | TIP ID '(' ')' LB bloc RB { snprintf(buff,100,"(%s) %s\n",$1, $2); write(fd1, buff, strlen(buff));insertFunction($1,$2,0,"",0);}
                  | VOID ID '(' params ')' LB bloc RB { snprintf(buff,100,"(%s) %s (%s)\n",$1, $2,$4); write(fd1, buff, strlen(buff));insertFunction($1,$2,0,"",0);}
                  | VOID ID '(' ')' LB bloc RB { snprintf(buff,100,"(%s) %s\n",$1, $2); write(fd1, buff, strlen(buff));insertFunction($1,$2,0,"",0);}
                  ;

params : params ',' param {strcat($1,", ");strcat($1,$3); $$=$1;}
       | param {$$=$1;}
       ;

param : TIP ID {snprintf(buff,100,"(%s) %s ",$1, $2); strcpy($$,buff);}
      | ARRAY ID { snprintf(buff,100,"(%s) %s ",$1, $2);strcpy($$,buff);} 
      ;

declaratieClase : declaratieClasa declaratieClase
                | declaratieClasa
                ;

declaratieClasa : CLASS ID LB class_elems RB
                ;

class_elems : class_elem ';'
            | class_elems class_elem ';'
            ;

class_elem : CLASS_TIP TIP ID 
           | CLASS_TIP LB declaratiiTip declaratieFunctii RB
           | CLASS_TIP LB declaratiiTip RB
           ;
           
program : BEGINP bloc ENDP
        ;

bloc : instr 
     | instr  bloc 
     ;

instr : ID '=' CONST_INT ';' 
      | ID '=' CONST_FLOAT ';'
      | ID '=' CONST_STRING ';'
      | ID '=' CHAR ';'
      | ID '=' ID ';'
      | ID '=' expresie_math ';'
      | IF '(' expresie_bool ')' LB bloc RB
      | IF '(' expresie_bool ')' LB bloc RB ELSE LB bloc RB
      | WHILE '(' expresie_bool ')' LB bloc RB
      | FOR '(' TIP ID '=' CONST_INT{ if(strstr($3,"int")==NULL)
                                        {
                                            printf("(LINE %d) Variabila este de alt tip!",yylineno);
                                            exit(1);
                                        }
                                    } ';' expresie_bool ';' op_for ')' LB bloc RB
      | EVAL '(' arg ')' ';' {snprintf(buff,100,"%s (%s) \n", "Eval" ,$3); write(fd1, buff, strlen(buff));}
      | TYPEOF '(' arg ')' ';'  
      | declaratieTip ';'
      | apel_functie ';'
      | apel_clasa ';'
      ;

apel_clasa : ID '.' ID 
           | ID '.' apel_functie
           ;

arg : CONST_INT     
        {
            char conversion[100];
            sprintf(conversion,"%d",$1);
            $$=conversion;
        }
    | CONST_FLOAT 
        {
            char conversion[100];
            sprintf(conversion,"%f",$1);
            $$=conversion;
        }
    | expresie_math 
    | expresie_bool
    ;

apel_functie : ID '(' params2 ')'
             | ID '(' ')'
             ;

params2 : ID ',' params2
        | ID
        ;

expresie_bool : ID operator_bool ID
              | ID operator_bool CONST_INT
              | ID operator_bool CONST_FLOAT
              | '(' expresie_bool ')' operator_bool '(' expresie_bool ')'
              ;

operator_bool : LESS
              | LESSEQ
              | GREAT
              | GREATEQ
              | EQ
              | AND
              | OR
              ;

expresie_math : ID operator_math ID
              | ID operator_math CONST_INT
              | ID operator_math CONST_FLOAT
              | '(' expresie_math ')' operator_math '(' expresie_math ')'
              ;

operator_math : PLUS 
              | MINUS 
              | MUL 
              | DIV 
              ;

op_for : ID PLUS PLUS
       | ID MINUS MINUS
       ;

%%

void yyerror(char *s)
{
    printf("eroare: %s la linia: %d\n",s,yylineno);
}
int main(int argc,char** argv)
{
    fd = open ("symbol_table.txt", O_RDWR|O_TRUNC|O_CREAT);
    fd1 = open ("symbol_table_functions.txt", O_RDWR|O_TRUNC|O_CREAT);
    yyin=fopen(argv[1],"r");
    yyparse();
}