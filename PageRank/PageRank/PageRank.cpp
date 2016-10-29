#include "stdafx.h"
#include "GrafoMatriz.h"
using namespace std;

int main() {
	GrafoMatriz *grafo = new GrafoMatriz("matAd.mat");
	grafo->mostrarMatAdy();
	cout << endl;
	/*
	vector<Vertice*> vecIncid = grafo->getIncidentesEn(grafo->getVertice(grafo->numVertice("B")));
	for (int i = 0; i < vecIncid.size(); i++)
		cout << vecIncid[i]->getNombre() << "-> ";
	
	cout << endl;
	cout.precision(10);
	cout << "\t PageRank de A:  " << fixed << grafo->getPageRank(grafo->getVertice(grafo->numVertice("A")));
	*/
	cin.get();
    return 0;
}

