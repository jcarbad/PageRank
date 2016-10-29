#pragma once
#include <string>
using namespace std;

class Vertice
{
protected:
	string nombre;
	int numVertice;
public:
	Vertice();
	Vertice(string);
	Vertice(string, int);
	string getNombre();
	int getNumVertice();
	void setNombre(string);
	void setNumVertice(int);
	bool esIgualA(Vertice);
	~Vertice();
};

