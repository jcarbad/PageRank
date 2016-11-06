#pragma once
#include <string>
#include <vector>
using namespace std;

class Vertice
{
protected:
	string nombre;
	int numVertice;
	float pageRank;
public:
	Vertice();
	Vertice(string);
	Vertice(string, int);
	string getNombre();
	int getNumVertice();
	void setNombre(string);
	void setPageRank(float);
	float miPageRank();
	bool esIgualA(Vertice);
	~Vertice();
};

