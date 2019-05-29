#include "utils.h"


//Infocomponentes almacena dos valores. Cada indice identifica una componente.
//De las componentes que todavia existen, infoComponentes almacena en su primer valor
//su tamanio, y en el segundo elemento almacena Int(C) -es decir, maximo peso en su AGM.

infoComponentes inicializarinfoComponentes(int n){ //Aca hay una duda, como se inicializa INT(c) cuando no hay ejes?
	//asumo que empieza en 0 y que k hace que las componentes no esten eparadas.
	infoComponentes res;
	for(int i = 0; i < n; i++){
		//El tamanio de las componentes es informacion redundante para 2 de los experimentos,
		//pero no cambia el orden de complejidad espacial ni temporal de los algoritmos.
		res.push_back(tuple<int, int>(1,0));
	}
	return res;
}



vector<vector<int>> algoritmo(double k, int n, int estructura, const Graph & graph, int width, int height){ //quizas una referencia a la lista de aristas, no se
	
	//El parametro estructura determina como se implementa la estructura disjoint set:
	//0-> Arreglo de representacion
	//1-> Arbol de representacion sin compresion
	//otherwise -> Arbol de representacion con compresion 
	

	//EL ALGORITMO SUPONE UNA VARIABLE GLOBAL listaAristas. HAY QUE MODIFICARLO PARA QUE TOME NUESTRA
	//ESTRUCTURA GRAFO. -> CÓMO SE LE PASA POR PARÁMETRO AL ALGORITMO, CÓMO SE IMPLEMENTA LA FUNCIÓN ORDENAR,
	//Y CÓMO SE ACCEDE AL ELEMENTO i DE LA LISTA UNA VEZ ORDENADA (linea 86)

	vector<tuple<int, int, double>> listaAristas = graph.getEdges();
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
		int c1 = disjset.find(v1, estructura); //Aca find es algún find de union find.
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
			//que queden tras el unite tendra el tamanio de la nueva (suma de ambas)
			get<1>(info[c2]) = w;
			get<1>(info[c1]) = w; //la componente en que queden tendra a w como arista de maximo peso.
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