#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZESE 80

typedef struct _nodo {
   char valor;
   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Pila;

void Push(Pila *pila, char v)
{
   pNodo nuevo;
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->valor = v;
   nuevo->siguiente = *pila;
   *pila = nuevo;
}

char Pop(Pila *pila)
{
   pNodo nodo;
   char v;
   nodo = *pila;
   if(!nodo) return 0;
   *pila = nodo->siguiente;
   v = nodo->valor;
   free(nodo);
   return v;
}

char operandos[SIZESE][SIZESE];
int  topd=0;
void pushd(char *opnd)
{
    strcpy(operandos[++topd],opnd);
}
char *popd()
{
    return(operandos[topd--]);
}
int empty(int t)
{
    if( t == 0) return(1);
    return(0);
}
void readkb(char buf[]){
  fgets(buf, SIZESE, stdin);
}
void split(){
  char str[SIZESE];
}

void strrev(char *p)
{
  char *q = p;
  while(q && *q) ++q;
  for(--q; p < q; ++p, --q)
    *p = *p ^ *q,
    *q = *p ^ *q,
    *p = *p ^ *q;
}

int main()
{
    Pila pila = NULL;
    pNodo p;
    char prefijo[SIZESE],ch,str[SIZESE],operando1[SIZESE],operando2[SIZESE],opr[2];
    printf("Digite una expresion en Prefijo (ejemplo (-*AB/CD)) :");
    int i=0,k=0;
    readkb(prefijo);
    printf(" Dada la expresion en Prefijo : %s",prefijo);
    strrev(prefijo);
    while( (ch=prefijo[i++]) != '\0')
    {
      if(isalnum(ch))
      {
        str[0]=ch; str[1]='\0';
        pushd(str);
      }else{
        Push(&pila,ch);
        strcpy(operando2,popd());
        strcpy(operando1,popd());
        strcpy(str,"(");
        strcat(str,operando2);
        ch=Pop(&pila);
        opr[0]=ch;opr[1]='\0';
        strcat(str,opr);
        strcat(str,operando1);
        strcat(str,")");
        pushd(str);
      }

    }
    printf(" Se traduce en la expresion en infijo: %s \n",operandos[topd] );
}
