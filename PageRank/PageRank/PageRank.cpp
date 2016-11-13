#include "stdafx.h"
#include "PageRanker.h"

using namespace std;

int main() {
	GrafoMatriz *G = new GrafoMatriz("Archivos/matAdyacencia.txt");
	PageRanker *PR = new PageRanker(G);
	PR->calculaPageRanks();
	PR->mostrarGrafo();
	G->guardar("Archivos/salida.txt");
	system("Pause");
	return 0;
}

