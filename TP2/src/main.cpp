#include <vector>
#include <tuple>
#include "arreglo_rep.hpp"

#include "disjoint_set.hpp"
#include "arbol_rep.hpp"
#include "arbol_comp.hpp"
#include "arreglo_rep.hpp"

#include <utility>
#include <vector>
#include <iostream>
#include <algorithm> //for max
#include <map> // map
#include <math.h> // pow

#include <iostream>


//UNION FIND, ARREGLO DE REPRESENTACIÓN

using namespace std;


//Represento el grafo como lista de aristas, siendo estas triplas <int, int, int>
//en que los primeros dos valores son los vértices que evaluamos y el último es
//el peso del vértice.

//Necesito un arreglo que represente las componentes, para guardar allí su Int(C)
//y su tamaño (el tamaño, salvo en el arreglo de representación, ya lo tengo almacenado)
//en la raíz del árbol.

vector<tuple<int, int, int>> listaAristas; // asumo que esta es la
//lista de aristas que mencioné.

typedef vector<tuple<int, int>> infoComponentes;
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

int main()
{
	return 0;
}


vector<vector<int>> algoritmo(int k, int n, int estructura){ //quizás una referencia a la lista de aristas, no sé
	/*
	El parámetro estructura determina cómo se implementa la estructura disjoint set:
	0-> Arreglo de representación
	1-> Arbol de representación sin compresión
	otherwise -> Arbol de representación con compresión 
	*/

	//EL ALGORITMO SUPONE UNA VARIABLE GLOBAL listaAristas. HAY QUE MODIFICARLO PARA QUE TOME NUESTRA
	//ESTRUCTURA GRAFO. -> CÓMO SE LE PASA POR PARÁMETRO AL ALGORITMO, CÓMO SE IMPLEMENTA LA FUNCIÓN ORDENAR,
	//Y CÓMO SE ACCEDE AL ELEMENTO i DE LA LISTA UNA VEZ ORDENADA (línea 86)

	DisjointSet disjset;

	if(estructura == 0){
		ArregloRep disjset(n);
	} else if (estructura == 1){
		ArbolRep disjset(n);
	} else {
		ArbolComp disjset(n); //HAY QUE VER EL TEMA DEL SCOPE Y LAS DEPENDENCIAS ACÁ
	}


	infoComponentes info = inicializarinfoComponentes(n);

	for(int i = 0; i < listaAristas.size(); i++){
		tuple<int, int, int> elem = listaAristas[i];
		int v1 = get<0>(elem);
		int v2 = get<1>(elem);
		int c1 = disjset.find(v1); //Acá find es algún find de union find.
		int c2 = disjset.find(v2);
		if(c1 == c2)
			continue;
		int w = get<2>(elem);
		int MinC1 = get<1>(info[c1]) + k/get<0>(info[c1]);
		int MinC2 = get<1>(info[c2]) + k/get<0>(info[c2]);
		if(w <= MinC1 && w <= MinC2){
			//en este caso debemos unir las componentes.
			get<0>(info[c1]) += get<0>(info[c2]);
			get<0>(info[c2]) = get<0>(info[c1]);// la componente en
			//que queden tras el unite tendrá el tamaño de la nueva (suma de ambas)
			get<1>(info[c2]) = w;
			get<1>(info[c1]) = w; //la componente en que queden tendrá a w como arista de máximo peso.
			disjset.unite(c1, c2); //con la estructura unite.
		}
	}

	
	//devolve la bolsa
	int width = -1;
	int height = -1;

	vector<vector<int>> res;
	for(int i = 0; i < width; i++){
		vector<int> fila;
		for(int j = 0; j < height; j++){
 			fila.push_back(disjset.find(i*width + j));
		}
		res.push_back(fila);
	}
	return res;
}