#pragma once

#include <vector>
#include "disjoint_set.hpp"

using namespace std;


class ArbolRep: public DisjointSet
{
	vector<int> arbolrep;
public:
	
	ArbolRep(int n);
	int find(int i);
	void unite(int A, int B);
};