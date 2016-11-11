#include "stdafx.h"
#include "GrafoMatriz.h"
#include <iomanip>

typedef int *pint; // Para el dimensionamiento de la matriz.

GrafoMatriz::GrafoMatriz() {
	maxVerts = 1;
	GrafoMatriz(maxVerts);
}

GrafoMatriz::GrafoMatriz(int mx) {
	maxVerts = mx;
	verts = new Vertice[mx]; // vector de vertices
	matAd = new pint[mx]; // vector de punteros
	numVerts = 0;
	for (int i = 0; i < mx; i++)
		matAd[i] = new int[mx];
	for (int i = 0; i < mx; i++)
		for (int j = 0; j < mx; j++)
			matAd[i][j] = 0;
}

GrafoMatriz::GrafoMatriz(string inputFile) {
	string data;
	vector<string> res;
	vector<int> enteros;
	ifstream readFile;
	readFile.open(inputFile, ios::in);
	// -------- Carga renglón por renglón
	while (!readFile.eof()) {
		getline(readFile, data);
		res.push_back(data);
		//cout << "DATA leida:  " << data << "\n";
	}
	readFile.close();
	// ----- Reconoce 1s o 0s y convierte a enteros
	vector<string>::iterator vk;
	for (vk = res.begin(); vk != res.end(); vk++) {
		string actual = *vk;
		for (int i = 0; i < actual.length(); i++) {
			if ((int)actual.at(i) == 49) // ASCII para 1
				enteros.push_back(1);
			if ((int)actual.at(i) == 48) // ASCII para 0
				enteros.push_back(0);
		}
	}
	// --- Construye grafo con longitud de la matriz -------
	int mx = res.size();
	maxVerts = mx;
	verts = new Vertice[mx]; // vector de vertices
	matAd = new pint[mx]; // vector de punteros
	numVerts = 0;
	for (int i = 0; i < mx; i++)
		matAd[i] = new int[mx];
	for (int i = 0; i < mx; i++)
		for (int j = 0; j < mx; j++)
			matAd[i][j] = 0;
	// ----- "Interpreta" los datos del archivo
	char letra = 'A';
	for (int i = 0; i < enteros.size(); i++) {
		char fila = (char)(letra + i / res.size());
		char columna = (char)(letra + (i % res.size()));
		// Convierte chars en strings
		stringstream s, c;
		string strFila, strCol;
		s << fila;
		s >> strFila;
		c << columna;
		c >> strCol;
		// Agrega vertice a grafo
		this->nuevoVertice(strCol);
		// Agregar un arco a grafo
		if (enteros[i] == 1)
			this->nuevoArco(strFila, strCol);
	}
}


void GrafoMatriz::guardar(string outputFile){
	ofstream salida(outputFile);
	char letra=65;
	double value;
	vector<Vertice*> V = getVerts();
	vector<Vertice*>::iterator itVerts;
	salida<<"PageRanks resultantes \n";
	for (itVerts = V.begin(); itVerts != V.end(); itVerts++){
		value = (*itVerts)->miPageRank();
		salida<<letra;
		salida<<" = ";
		salida<<setprecision(10)<<value;
		salida<<"\n";
		letra++;
	}

	salida<<"Desarrollado por:\nJoan A. Carballo Badilla\nSergio I. Vargas Urena";
	salida.close();
}
int GrafoMatriz::getNumVerts() {
	return numVerts;
}

void GrafoMatriz::setNumVerts(int n) {
	numVerts = n;
}

GrafoMatriz::~GrafoMatriz()
{
}

void GrafoMatriz::nuevoVertice(string nom) {
	bool yaEsta = numVertice(nom) >= 0;
	if (!yaEsta) {
		Vertice v = Vertice(nom, numVerts);
		verts[numVerts++] = v;
	}
}

int GrafoMatriz::numVertice(string v) {
	int i;
	bool encontrado = false;
	for (i = 0; (i < numVerts) && !encontrado;) {
		encontrado = verts[i].esIgualA(v);
		if (!encontrado) i++;
	}
	return (i < numVerts) ? i : -1;
}

void GrafoMatriz::nuevoArco(string a, string b) {
	int va, vb;
	va = numVertice(a);
	vb = numVertice(b);
	if (va < 0 || vb < 0) throw "Vertice no existe";
	matAd[va][vb] = 1;
}

void GrafoMatriz::nuevoArco(int va, int vb) {
	if (va < 0 || vb < 0 || va > numVerts || vb > numVerts)
		throw "Vertice no existe";
	matAd[va][vb] = 1;
}

bool GrafoMatriz::adyacente(string a, string b) {
	int va, vb;
	va = numVertice(a);
	vb = numVertice(b);
	if (va < 0 || vb < 0) throw "Vertice no existe";
	return matAd[va][vb] == 1;
}

bool GrafoMatriz::adyacente(int va, int vb) {
	if (va < 0 || vb < 0 || va >= numVerts || vb >= numVerts)
		throw "Vertice no existe";
	return matAd[va][vb] == 1;
}

int GrafoMatriz::getValor(string a, string b) {
	int va, vb;
	va = numVertice(a);
	vb = numVertice(b);
	if (va < 0 || vb < 0 || va >= numVerts || vb >= numVerts)
		throw "Vertice no existe";
	return matAd[va][vb];
}

int GrafoMatriz::getValor(int va, int vb) {
	if (va < 0 || va < 0 || va >= numVerts || vb >= numVerts)
		throw "Vertice no existe";
	return matAd[va][vb];
}

void GrafoMatriz::setValor(int va, int vb, int v) {
	if (va < 0 || vb < 0 || va >= numVerts || vb >= numVerts)
		throw "Vertice no encontrado";
	matAd[va][vb] = v;
}

void GrafoMatriz::setValor(char *a, char *b, int v) {
	int va, vb;
	va = numVertice(a);
	vb = numVertice(b);
	if (va < 0 || vb < 0) throw "Vertice no existe";
	matAd[va][vb] = v;
}

Vertice GrafoMatriz::getVertice(int va) {
	if (va < 0 || va >= numVerts)
		throw "Vertice no existe";
	else return verts[va];
}

Vertice GrafoMatriz::getVertice(string nom) {
	return getVertice(numVertice(nom));
}

void GrafoMatriz::setVertice(int va, Vertice vert) {
	if (va < 0 || va >= numVerts)
		throw "Vertice no existe";
	else verts[va] = vert;
}

void GrafoMatriz::mostrarVecVerts() {
	for (int i = 0; i < maxVerts; i++) {
		cout.precision(10);
		cout << "V[" << i << "] = " << verts[i].getNombre() << " con PageRank: " << fixed << verts[i].miPageRank() << "\n";
	}
}

void GrafoMatriz::mostrarMatAdy() {
	char letra = 'A';
	for (int i = 0; i < maxVerts; i++) {
		if (i != 0)
			cout << getVertice(i).getNombre() << " ";
		for (int j = 0; j < maxVerts; j++) {
			if (i == 0 && j == 0) {
				cout << " ";
				for (int i = 0; i < maxVerts; i++, letra++)
					cout << " " << letra;
				cout << endl;
			}
			if (i == 0 && j == 0)
				cout << "A ";
			cout << matAd[i][j] << " ";
		}
		cout << "\n";
	}
}

//// A es adyacente con X si A->X existe.
//// NO IMPLICA que X es adayacente con A (X->A).
vector<Vertice*> GrafoMatriz::getAdyacentesA(Vertice V) {
	vector<Vertice*> vecAdyacentes;
	for (int i = 0; i < maxVerts; i++)
		if (adyacente(V.getNombre(), verts[i].getNombre()))
			vecAdyacentes.push_back(&verts[i]);
	return vecAdyacentes;
}

//// X es incidente en A si X->A existe.
vector<Vertice*> GrafoMatriz::getIncidentesEn(Vertice V) {
	vector<Vertice*> vecIncidentes;
	for (int i = 0; i < maxVerts; i++)
		if (adyacente(verts[i].getNombre(), V.getNombre()))
			vecIncidentes.push_back(&verts[i]);
	return vecIncidentes;
}

vector<Vertice*> GrafoMatriz::getVerts(){
	vector<Vertice*> _verts;
	for (int i = 0; i < maxVerts; i++)
		_verts.push_back(&verts[i]);
	return _verts;

}


