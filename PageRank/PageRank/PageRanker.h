#include  "GrafoMatriz.h"
#include <list>

#define D 0.85f // Damping Factor: Probabilidad de que el surfer utilice un link (arco).
#define ND 0.15f // 1- D: Probabilidad de que suceda lo contrario, o sea, typear un URL.

class PageRanker {
private:
	GrafoMatriz *Grafo;
	list<Vertice*> visitados;
public:
	PageRanker(string);
	PageRanker(GrafoMatriz*);
	bool fueVisitado(Vertice*);
	void inicializaPageRanks();
	void calculaPageRanks();
	float getPageRank(Vertice*, float);
	float getPageRank(Vertice*);
	void mostrarGrafo();
	~PageRanker();
};

