#ifndef _arreglo_rep 
#define _arreglo_rep

#include <vector>
#include "disjoint_set.hpp"

using namespace std;


class ArregloRep: public DisjointSet
{
	vector<int> arreglorep;
public:
	
	ArregloRep(int n);
	int find(int i);
	void unite(int A, int B);
};

#endif