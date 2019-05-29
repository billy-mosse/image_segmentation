#ifndef _input_handler 
#define _input_handler

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> parseInputFile(char* inputPath);

vector<vector<int> > separateValues(const vector<int> & numbers);

vector<vector<int> > imageFromFile(char* inputPath);

vector<int> numbersFromInput();

vector<vector<int> > imageFromInput(vector<int> numbers);
#endif