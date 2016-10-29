#include "stdafx.h"
#include "Vertice.h"


Vertice::Vertice()
{
}

Vertice::Vertice(string x)
{
	nombre = x;
	numVertice = -1;
}

Vertice::Vertice(string x, int num)
{
	nombre = x;
	numVertice = num;
}

string Vertice::getNombre() {
	return nombre;
}

int Vertice::getNumVertice() {
	return numVertice;
}

bool Vertice::esIgualA(Vertice V) {
	return nombre == V.nombre;
}

Vertice::~Vertice()
{
}
