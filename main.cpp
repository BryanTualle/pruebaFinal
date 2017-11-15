#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef struct Nodo
{
	int dato;	
	Nodo *siguiente;
	Nodo *anterior;
}TLista;

typedef struct Temporal
{
	int tamanio;	
	Temporal *inicio;
	Temporal *fin;
}aux_TLista;

void inicializar(aux_TLista *);
int insElemListaVacia(aux_TLista *, int dato);
int insElemInicio(aux_TLista *, int dato);
int insElemFin(aux_TLista *, int );


int main(int argc, char** argv) 
{
	
	
	return 0;
}


void inicializar(aux_TLista *lista)
{
	lista->inicio = NULL;
	lista->fin = NULL;
	lista->tamanio =0;
}

int insElemListaVacia(aux_TLista *lista, int dato)
{
	TLista *nuevoElemento = new TLista();
	
	if(nuevoElemento == NULL)
	{
		return -1;
	}
	else
	{
		nuevoElemento->dato = dato;
		nuevoElemento->anterior = lista->inicio;
		nuevoElemento->siguiente = lista->fin;
		lista->fin = nuevoElemento;
		lista->inicio = nuevoElemento;
		lista->tamanio++;
		return 0;
	}
	
}

int insElemInicio(aux_TLista *lista, int dato)
{
	TLista *nuevoElemento = new TLista();
	
	if(nuevoElemento == NULL)
	{
		return -1;
	}
	else
	{
		nuevoElemento->dato = dato;
		nuevoElemento->siguiente = lista->fin;
		nuevoElemento->anterior = NULL;
		lista->inicio = nuevoElemento->anterior;
		lista->fin = nuevoElemento->siguiente;
		lista->tamanio++;
		
		return 0;
	}
}

int insElemFin(aux_TLista *lista, int dato)
{
	TLista *nuevoElemento = new TLista();
	
	if(nuevoElemento == NULL)
	{
		return -1;
	}
	else
	{
		nuevoElemento->dato = dato;
		nuevoElemento->siguiente = lista->fin;
		nuevoElemento->anterior = NULL;
		lista->inicio = nuevoElemento->anterior;
		lista->fin = nuevoElemento->siguiente;
		lista->tamanio++;
		
		return 0;
	}
}


