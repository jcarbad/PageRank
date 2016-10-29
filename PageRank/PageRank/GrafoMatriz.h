#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Vertice.h"

class GrafoMatriz {
protected:
	int maxVerts;
	int numVerts;
	Vertice *verts;
	int **matAd;
public:
	GrafoMatriz();
	GrafoMatriz(int);
	GrafoMatriz(string);
	int getNumVerts();
	void setNumVerts(int);
	void nuevoVertice(string nom);
	int numVertice(string);
	void nuevoArco(string, string);
	void nuevoArco(int, int);
	bool adyacente(string, string);
	bool adyacente(int, int);
	int getValor(string a, string b);
	int getValor(int, int);
	void setValor(int,int,int);
	void setValor(char*, char*, int);
	Vertice getVertice(int);
	Vertice getVertice(string);
	void setVertice(int va, Vertice vert);
	void mostrarVecVerts();
	void mostrarMatAdy();
	vector<Vertice*> getAdyacentesA(Vertice);
	vector<Vertice*> getIncidentesEn(Vertice);
	float getPageRank(Vertice);
	~GrafoMatriz();
};

