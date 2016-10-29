#include "stdafx.h"
#include "GrafoMatriz.h"

int main() {
	GrafoMatriz *grafo = new GrafoMatriz("matAd.mat");
	grafo->mostrarMatAdy();
	/*
	grafo->nuevoVertice("A");
	grafo->nuevoVertice("B");
	grafo->nuevoVertice("C");
	grafo->nuevoVertice("D");
	grafo->nuevoVertice("E");
	grafo->nuevoVertice("F");
	grafo->nuevoVertice("G");
	grafo->nuevoVertice("H");
	grafo->nuevoVertice("I");
	grafo->nuevoVertice("J");
	grafo->nuevoArco("A","B");
	grafo->nuevoArco("A", "C");
	grafo->nuevoArco("A", "F");
	grafo->nuevoArco("E", "C");
	grafo->nuevoArco("D", "F");
	grafo->mostrarVecVerts();
	system("pause");
	system("cls");
	cout << "\n\tDeberia ser A->B, A->C, A->F, E->C, D->F\n\n";
	grafo->mostrarMatAdy();
	*/
	//grafo->cargarArchivo();

	cin.get();
    return 0;
}

