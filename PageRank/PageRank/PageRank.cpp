#include "stdafx.h"
#include "PageRanker.h"
using namespace std;

int main() {
	GrafoMatriz *G = new GrafoMatriz("matAd.mat");
	PageRanker *PR = new PageRanker(G);
	PR->inicializaPageRanks();
	PR->calculaPageRanks();
	PR->mostrarGrafo();
	G->guardar("salida.txt");
	cin.get();
    return 0;
}

