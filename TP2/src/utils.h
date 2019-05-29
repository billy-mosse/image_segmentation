#ifndef _utils 
#define _utils


#include "disjoint_set.hpp"


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
#include "arbol_rep.hpp"
#include "arbol_comp.hpp"
#include "arreglo_rep.hpp"
#include "inputHandler.h"

#include "image_to_graph_converter.h"

#include "graph.h"

typedef vector<tuple<int, double>> infoComponentes;
vector<vector<int>> algoritmo(double k, int n, int estructura, const Graph & graph, int width, int height); //quizás una referencia a la lista de aristas, no sé

infoComponentes inicializarinfoComponentes(int n); //Acá hay una duda, cómo se inicializa INT(c) cuando no hay ejes?

#endif