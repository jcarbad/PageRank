#include "stdafx.h"
#include "PageRanker.h"

PageRanker::PageRanker(string rutaArchivo) {
	Grafo = new GrafoMatriz(rutaArchivo);
}

PageRanker::PageRanker(GrafoMatriz *graph) {
	Grafo = graph;
}

bool PageRanker::fueVisitado(Vertice *V) {
	list<Vertice*>::iterator visIter;
	for (visIter = visitados.begin(); visIter != visitados.end(); visIter++) 
		if (*visIter == V)
			return true;
	return false;
}

void PageRanker::inicializaPageRanks() {
	vector<Vertice*> V = Grafo->getVerts();
	vector<Vertice*>::iterator itVerts;
	float incialPR = (float) 1/(float)V.size();
	for (itVerts = V.begin(); itVerts != V.end(); itVerts++) 
		(*itVerts)->setPageRank(incialPR);
}

void PageRanker::calculaPageRanks() {
	inicializaPageRanks();
	vector<Vertice*> V = Grafo->getVerts();
	vector<Vertice*>::iterator itVerts;
	for (itVerts = V.begin(); itVerts != V.end(); itVerts++)
		(*itVerts)->setPageRank(getPageRank(*itVerts, 0));
}

float PageRanker::getPageRank(Vertice *V, float acum){
	vector<Vertice*> In = Grafo->getIncidentesEn(*V); // Todos los que apuntan a V.
	if (In.size() == 0) {
		acum = V->miPageRank();
		return acum;
	}
	else {
		for (unsigned int i = 0; i < In.size(); i++) {
			if (fueVisitado(In[i])) {
				acum = In[i]->miPageRank();
				return acum;
			}
			else {
				visitados.push_back(In[i]);
				//Partes de PR
				float PRi = getPageRank(In[i], acum);
				float Ci = (float)Grafo->getAdyacentesA(*In[i]).size(); // Cantidad de salientes de i
				acum += (ND + D * (PRi / Ci));
				In[i]->setPageRank(acum);
				return acum;
			}
		}
	}
	return acum;
}

void PageRanker::mostrarGrafo() {
	Grafo->mostrarMatAdy();
	cout << endl;
	Grafo->mostrarVecVerts();
}



PageRanker::~PageRanker()
{
}
