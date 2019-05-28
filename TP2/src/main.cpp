#include <vector>
#include <tuple>

#include <utility>
#include <vector>
#include <iostream>
#include <algorithm> //for max
#include <map> // map
#include <math.h> // pow
#include <iostream>

#include "arreglo_rep.hpp"
#include "disjoint_set.hpp"
#include "arbol_rep.hpp"
#include "arbol_comp.hpp"
#include "arreglo_rep.hpp"
#include "inputHandler.h"

#include "image_to_graph_converter.h"

#include "graph.h"


//UNION FIND, ARREGLO DE REPRESENTACIÓN

using namespace std;


//Represento el grafo como lista de aristas, siendo estas triplas <int, int, double>
//en que los primeros dos valores son los vértices que evaluamos y el último es
//el peso del vértice.

//Necesito un arreglo que represente las componentes, para guardar allí su Int(C)
//y su tamaño (el tamaño, salvo en el arreglo de representación, ya lo tengo almacenado)
//en la raíz del árbol.

vector<tuple<int, int, double>> listaAristas; // asumo que esta es la
//lista de aristas que mencioné.

typedef vector<tuple<int, double>> infoComponentes;
//Infocomponentes almacena dos valores. Cada índice identifica una componente.
//De las componentes que todavía existen, infoComponentes almacena en su primer valor
//su tamaño, y en el segundo elemento almacena Int(C) -es decir, maximo peso en su AGM.

infoComponentes inicializarinfoComponentes(int n){ //Acá hay una duda, cómo se inicializa INT(c) cuando no hay ejes?
	//asumo que empieza en 0 y que k hace que las componentes no estén eparadas.
	infoComponentes res;
	for(int i = 0; i < n; i++){
		//El tamaño de las componentes es información redundante para 2 de los experimentos,
		//pero no cambia el orden de complejidad espacial ni temporal de los algoritmos.
		res.push_back(tuple<int, int>(1,0));
	}
	return res;
}


vector<vector<int>> algoritmo(double k, int n, int estructura, Graph & graph, int width, int height){ //quizás una referencia a la lista de aristas, no sé
	/*
	El parámetro estructura determina cómo se implementa la estructura disjoint set:
	0-> Arreglo de representación
	1-> Arbol de representación sin compresión
	otherwise -> Arbol de representación con compresión 
	*/

	//EL ALGORITMO SUPONE UNA VARIABLE GLOBAL listaAristas. HAY QUE MODIFICARLO PARA QUE TOME NUESTRA
	//ESTRUCTURA GRAFO. -> CÓMO SE LE PASA POR PARÁMETRO AL ALGORITMO, CÓMO SE IMPLEMENTA LA FUNCIÓN ORDENAR,
	//Y CÓMO SE ACCEDE AL ELEMENTO i DE LA LISTA UNA VEZ ORDENADA (línea 86)


	listaAristas = graph.getEdges();

	//estan ordenados

	DisjointSet disjset(n, estructura);

	infoComponentes info = inicializarinfoComponentes(n);

	//k = 330;
	int cont = 0;
	//esta de menor a mayor, por eso hay tantos ceros
	for(int i = 0; i < listaAristas.size(); i++){
		cont = cont + 1;
		if(cont % 10000 == 0)
		{
			cout<<cont<<endl;
		}
		tuple<int, int, double> elem = listaAristas[i];
		int v1 = get<0>(elem);
		int v2 = get<1>(elem);
		int c1 = disjset.find(v1, estructura); //Acá find es algún find de union find.
		int c2 = disjset.find(v2, estructura);
		//cout<<"for"<<endl;

		if(c1 == c2)
			continue;

		//cout<<"for2"<<endl;
		double w = get<2>(elem);
		//cout<<w<<endl;
		double MinC1 = 1.0* get<1>(info[c1]) + k/ (1.0 *get<0>(info[c1]));
		double MinC2 = 1.0* get<1>(info[c2]) + k/(1.0*get<0>(info[c2]));
		
		if(w <= MinC1 && w <= MinC2){
			//cout<<"for3"<<endl;
			//en este caso debemos unir las componentes.
			get<0>(info[c1]) += get<0>(info[c2]);
			get<0>(info[c2]) = get<0>(info[c1]);// la componente en
			//que queden tras el unite tendrá el tamaño de la nueva (suma de ambas)
			get<1>(info[c2]) = w;
			get<1>(info[c1]) = w; //la componente en que queden tendrá a w como arista de máximo peso.
			disjset.unite(c1, c2, estructura); //con la estructura unite.
		}
	}
	
	vector<vector<int>> res;
	for(int i = 0; i < height; i++){
		vector<int> fila;
		for(int j = 0; j < width; j++){
 			fila.push_back(disjset.find(i*width + j, estructura));
		}
		res.push_back(fila);
	}
	return res;
}


int main()
{

	/*int width;
    int height;
    cin >> width;
    cin >> height;


	cout<<"hola1"<<endl;*/

	//HACK
	int width = 321;
	int height = 481;

	vector<vector<int>> image = imageFromFile("../images/hombre_blur.txt");

	Graph graph = converter8neighbors(image, width, height);

	double k = 20.0;
	if(width*height >= 10000)
	{
		k = 200.0;
	}
	else
	{
		if(width*height >= 60000)
		{
			k = 300.0;
		}
	}

	cout<<k<<endl;
	vector<vector<int>> result = algoritmo(k, graph.getAmountEdges(), 0, graph, width, height);
	for(auto vec : result)
	{
		bool first = true;
		for(auto elt : vec)
		{
			if(!first)
				cout<<" ";

			cout<<elt;

			first=false;
		}
		cout<<endl;
	}

	return 0;
}