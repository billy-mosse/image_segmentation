#ifndef _image_to_graph_converter 
#define _image_to_graph_converter

#include <iostream>
#include <fstream>
#include <vector>
#include <utility> //for pair.
#include "graph.h"

using namespace std;

Graph converter8neighbors(vector<vector<int> > & image, int width, int height);

Graph converterEuclidean(vector<vector<int> > & image, int width, int height);

#endif