#ifndef _input_handler 
#define _input_handler

#include <iostream>
#include <fstream>
#include <vector>
#include <utility> //for pair.

using namespace std;

typedef unsigned int pixel;
typedef vector<vector<pixel> > image;

vector<int> parseInputFile(char* inputPath);

vector<vector<int> > separateValues(vector<int> numbers);

vector<vector<int> > itemsFromFile(char* inputPath);

#endif