#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/*Estructura que tiene el contenido*/

typedef struct DEncadenada {
   char elemento;
   struct DEncadenada *next;
   struct DEncadenada *back;
}grupo;

typedef grupo *pNodo;
typedef grupo *Lista;

/* Funciones con listas: */
void insertar(Lista *, char);
void Insertar(Lista *lista, int v);
void eliminar(Lista *, char);
void mostrarLista(Lista);

/*Funciones utilizadas*/
void menu();
char introducirDato();

/*Funcion main*/
int main()
{
   Lista lista = NULL;
   char a,c;
   int b;

   do
   {
       menu();
       a = introducirDato();

       switch(a)
       {
            case '1':
                system("CLS");
                printf("_____________________________________\n");
                printf("         Insertar Elemento\n\n");
                printf("\nIntroducir elemento: ");
                scanf("%d",&b);

                Insertar(&lista, b);
                mostrarLista(lista);
                system("PAUSE");
                system("CLS");
                break;

            case '2':
                system("CLS");
/*
                if(lista!=NULL)
                {
                   printf("_____________________________________n");
                   printf("         "Eliminar Elemento"nn");
                   mostrarLista(lista);
                   printf("n");
                   printf("Eliminar elemento: ");
                   scanf("%c",&c);

                   eliminar(&lista,c);
                   printf("n");

                }
*/
                mostrarLista(lista);

                system("PAUSE");
                system("CLS");
                break;
/*
            case '3':
                system("CLS");
                mostrarLista(lista);
                system("PAUSE");
                system("CLS");
                break;
*/
            case '4':
                system("CLS");
                printf("\n        Fin del programa\n");
                printf("_____________________________________n");

                a=' ';

                break;
       }
   }while(a!=' ');

   return 0;

}

/*Función de Menu de opciones*/

void menu()
{
    printf("\n   Listas Doblemente Encadenadas  \n");
    printf("\n_____________________________________");
    printf("\nInsertar Elemento.................[1]");
    printf("\nEliminar Elemento.................[2]");
    printf("\nMostrar Lista.....................[3]");
    printf("\nSalir.............................[4]");
    printf("\n_____________________________________");
}

/*Introducir el numero de inicio*/

char introducirDato()
{
   char ch;

   do{

      printf("\nAccion a realizar: ");
      fflush(stdin);
      ch=getche();
      if(!(ch>='1'&& ch<='4'))
      {
          printf("\nInserte un digito correcto");
      }
      printf("n");

   }while(!(ch>='1'&& ch<='4'));


   return ch;
}


/*Funcion para insertar elementos en la lista*/

void insertar(Lista *lista, char v)
{
   pNodo nuevo, actual;

   nuevo = (pNodo)malloc(sizeof(grupo));
   nuevo->elemento = v;
   actual = *lista;

   if(actual)
   {
        while(actual->back)
        {
            actual = actual->back;
        }
   }
   
   if(!actual || actual->elemento > v) {
      nuevo->next = actual;
      nuevo->back = NULL;

      if(actual)
      {
            actual->back = nuevo;
      }

      if(!*lista)
      {
            *lista = nuevo;
      }
   }
   else {
      while(actual->next &&actual->next->elemento <= v)
      {
            actual = actual->next;
      }

      nuevo->next = actual->next;
      actual->next = nuevo;
      nuevo->back = actual;

      if(nuevo->next)
      {
          nuevo->next->back = nuevo;
      }
   }
}

void Insertar(Lista *lista, int v) {
   pNodo nuevo, actual;

   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->valor = v;
   
   /* Colocamos actual en la primera posición de la lista */
   actual = *lista;
   if(actual) while(actual->anterior) actual = actual->anterior;
   
   /* Si la lista está vacía o el primer miembro es mayor que el nuevo */
   if(!actual || actual->valor > v) {
      /* Añadimos la lista a continuación del nuevo nodo */
      nuevo->siguiente = actual; 
      nuevo->anterior = NULL;
      if(actual) actual->anterior = nuevo;
      if(!*lista) *lista = nuevo;
   }
   else {
      /* Avanzamos hasta el último elemento o hasta que el siguiente tenga 
         un valor mayor que v */
      while(actual->siguiente ) 
         actual = actual->siguiente;
      /* Insertamos el nuevo nodo después del nodo anterior */
      nuevo->siguiente = actual->siguiente;
      actual->siguiente = nuevo;
      nuevo->anterior = actual;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}


/*Funcion para eliminar elemento en la lista*/

void eliminar(Lista *lista, char v)
{
   pNodo nodo;

   nodo = *lista;

   while(nodo && nodo->elemento < v)
   {
       nodo = nodo->next;
   }

   while(nodo && nodo->elemento > v)
   {
       nodo = nodo->back;
   }

   if(!nodo || nodo->elemento != v)
   {
       return;
   }

   if(nodo == *lista)
   {
        if(nodo->back)
        {
            *lista = nodo->back;
        }
        else
        {
            *lista = nodo->next;
        }

   }

   if(nodo->back)
   {
      nodo->back->next = nodo->next;
   }

   if(nodo->next)
   {
      nodo->next->back = nodo->back;
   }

   free(nodo);
}

/*Funcion para mostrar la lista*/

void mostrarLista(Lista lista)
{
   pNodo nodo = lista;

   if(!lista)
   {
        printf("\nLa Lista esta Vacia");
   }
   else{
      while(nodo->back)
      {

            nodo = nodo->back;
      }
      printf("\n     Elementos de la Lista      \n");
      printf("_____________________________________\n");
      while(nodo)
      {
         printf("-> %c", nodo->elemento);
         nodo = nodo->next;
      }

   }

   printf("\n");
}

