#ifndef _input_handler 
#define _input_handler

#include <iostream>
#include <fstream>
#include <vector>
#include <utility> //for pair.
#include "graph.h"

using namespace std;

typedef unsigned int pixel;
typedef vector<vector<pixel> > image;

Graph converter8neighbors(vector<vector<int> > & image, int width, int height);

Graph converterEuclidean(vector<vector<int> > & image, int width, int height);

#endif