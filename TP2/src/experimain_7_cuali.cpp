#include <vector>
#include <tuple>

#include <utility>
#include <vector>
#include <iostream>
#include <algorithm> //for max
#include <map> // map
#include <math.h> // pow
#include <iostream>
#include <chrono>


#include "arreglo_rep.hpp"
#include "disjoint_set.hpp"
#include "arbol_rep.hpp"
#include "arbol_comp.hpp"
#include "arreglo_rep.hpp"
#include "inputHandler.h"

#include "image_to_graph_converter.h"

#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <bits/stdc++.h> 
#include "utils.h"


//UNION FIND, ARREGLO DE REPRESENTACIÓN

using namespace std;


//Represento el grafo como lista de aristas, siendo estas triplas <int, int, double>
//en que los primeros dos valores son los vértices que evaluamos y el último es
//el peso del vértice.

//Necesito un arreglo que represente las componentes, para guardar allí su Int(C)
//y su tamaño (el tamaño, salvo en el arreglo de representación, ya lo tengo almacenado)
//en la raíz del árbol.


int main(int argc, char *argv[])
{
	auto start = std::chrono::system_clock::now();

	int use8Neighbors =  stoi(argv[1]);

	//int structureType = stoi(argv[2]);

	/*int width;
    int height;
    cin >> width;
    cin >> height;


	cout<<"hola1"<<endl;*/

	//HACK
	int width;
	int height;
	double kk = -40.0;

	cerr << "kk,use8neighors,structure,size,index,load_image,load_graph,process,whole"<<endl;
	for(int use8Neighbors = 0; use8Neighbors <= 1 ; use8Neighbors++)
	{
		for(int i = 10; i <= 1; i++)
		{
			for(int j = 1; j <= 1; j++)
			{
				for(int structure_exp = 2; structure_exp <=2; structure_exp++)
				{
					for(int k = 1; k <= 10; k++)
					{
						kk = kk + 50;
						width = 321;
						height = 481;
						
						string folder = "experiments/experiment7_cuali/";
						string filename = "../images/hombre_blur.txt";

						string s = folder + filename;

					    int n = s.length(); 
				  
					    // declaring character array 
					    char char_array[n + 1]; 
					  
					    // copying the contents of the 
					    // string to char array 
					    strcpy(char_array, s.c_str()); 

						vector<vector<int>> image = imageFromFile(char_array);

						auto end = std::chrono::system_clock::now();
						auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
					    cerr << kk << "," << use8Neighbors << "," << structure_exp << "," << i << "," << j << "," << elapsed.count() << ",";

						Graph graph;

						if(use8Neighbors == 1)
							graph = converter8neighbors(image, width, height);
						else
							graph = converterEuclidean(image, width, height);


						auto end_2 = std::chrono::system_clock::now();
						elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_2 - end);
						cerr << elapsed.count() << ",";
						
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


						vector<vector<int>> result = algoritmo(kk, graph.getAmountEdges(), structure_exp, graph, width, height);

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


						auto end_3 = std::chrono::system_clock::now();
						elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_3 - end_2);
						cerr << elapsed.count() << ",";
						elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_3 - start);

						cerr << elapsed.count() << endl;
					}

				}
			}
		}
	}

	return 0;
}