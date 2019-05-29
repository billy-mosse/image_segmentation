#include "utils.h"

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

int main()
{

	vector<int> numbers = numbersFromInput();

	int width = numbers[0];
	int height = numbers[1];
	
	vector<vector<int>> image = imageFromInput(numbers);

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