#pragma once

#include <vector>
#include "disjoint_set.hpp"
using namespace std;


class ArbolComp: public DisjointSet
{
	vector<int> arbolcomp;
public:

	ArbolComp(int n);
	int find(int i);
	void unite(int A, int B);
};