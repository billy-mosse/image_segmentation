#include <cmath>
#include "image_to_graph_converter.h"
void addIfValid(Graph & graph, int src_i, int src_j, int target_i,
 int target_j, vector<vector<int> > & image, int width, int n)
{
	int src = src_i * width + src_j;
	
	if(target_i >= 0 && target_j >= 0 && target_j < width)
	{
		int target = target_i*width + target_j;
		int intensity_src = image.at(src_i).at(src_j);
		int intensity_target = image.at(target_i).at(target_j);
		int w = abs(intensity_src - intensity_target);
		graph.addEdge(src, target, w);
	}
}


//TODO no hacen falta realmente width y height
Graph converter8neighbors(vector<vector<int> > & image, int width, int height){
	//El pixel (i,j) se representa con el id i*width + j
	
	int n = width*height;
	Graph graph(n);
	
	//graph.addEdge(1,1,1);
	//graph.addEdge(1,2,1);
	//graph.showGraphEdges();
	//cout<<"_________________" << endl;
	
	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < height; j++)
		{
			//chequear
			addIfValid(graph, i, j, i-1, j, image, width, n);
			addIfValid(graph, i, j, i-1, j-1, image, width, n);
			addIfValid(graph, i, j, i, j-1, image, width, n);
			addIfValid(graph, i, j, i-1, j+1, image, width, n);

			graph.showGraphEdges();
		}
	}
	cout << "Ordenando..." << endl;

	graph.ordenar();
	cout << "Ordenado." << endl;
	return graph;
}

int euclidean_distance(int src_i, int src_j, int src_intensity, int target_i, \
	int target_j, int target_intensity)
{
	return sqrt(pow(src_i-target_i, 2) + pow(src_j-target_j, 2) + pow(src_intensity-target_intensity, 2));
}


int intensity(vector<vector<int> > image, int p_i, int p_j)
{
	return image.at(p_i).at(p_j);
}

vector<tuple<int, int, int>> addNeighbors(vector<vector<int> > & image, int width, 
	int height, int src_i, int src_j, int k, int max_distance)
{
	int src = src_i * width + src_j;
	//lista ordenada de aristas, de menor a mayor
	vector<tuple<int, int, int>> res(k, make_tuple(-1, -1, max_distance)); //LLENARLO CON K ELEMENTOS QUE PESEN MUCHO

	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++)
		{
			int w = euclidean_distance(src_i, src_j, intensity(image, src_i, src_j),
				i, j, intensity(image, i, j));

			if(w < get<2>(res[0]))
			{
				int target = i * width + j;
				//creo una tupla con la info
				tuple<int, int, int> t = make_tuple(src, target, w);
				res.at(0) = t;
				for(int l = 1 ; l<k; l++)
				{
					if(get<2>(res.at(l-1)) < get<2>(res.at(l)))
					{
						swap(res.at(l-1), res.at(l));
					}
					else
						break;
				}
			}
		}
	}
}

int amount_neighbors = 4; //que sea parametro del programa
Graph converterEuclidean(vector<vector<int> > & image, int width, int height){

	int k = 4;//PARAMETRO FIJO QUE DEBERIAMOS CAMBIAR PARA LOS EXPERIMENTOS
	int max_distance = width + height + 255;

	int n = width*height;
	Graph graph(n);

	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < height; j++)
		{
			vector<edge> vecinos = addNeighbors(image, width,
				height, i, j, k, max_distance);
			
			for(auto edge: vecinos)
				graph.addEdgeIfNotAlready(get<0>(edge), get<1>(edge), get<2>(edge)); 
		}
	}	
	graph.ordenar();
}