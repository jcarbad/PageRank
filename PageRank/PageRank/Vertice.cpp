#include "stdafx.h"
#include "Vertice.h"


Vertice::Vertice()
{
}

Vertice::Vertice(string x)
{
	nombre = x;
	numVertice = -1;
	pageRank = 0;
}

Vertice::Vertice(string x, int num)
{
	nombre = x;
	numVertice = num;
	pageRank = 0;
}

string Vertice::getNombre() {
	return nombre;
}

int Vertice::getNumVertice() {
	return numVertice;
}

void Vertice::setNombre(string nom)
{
	nombre = nom;
}

void Vertice::setPageRank(float pr)
{
	pageRank = pr;
}

float Vertice::miPageRank()
{
	return pageRank;
}

bool Vertice::esIgualA(Vertice V) {
	return nombre == V.nombre;
}

Vertice::~Vertice()
{
}
