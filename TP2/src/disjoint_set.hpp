#ifndef _disjoint_set 
#define _disjoint_set

#include "arreglo_rep.hpp"
#include "arbol_rep.hpp"
#include "arbol_comp.hpp"


class DisjointSet{
	ArregloRep arreglorep;
	ArbolRep arbolrep;
	ArbolComp arbolcomp;

	public:
	DisjointSet(int n, int estructura);
	int find(int i, int estructura);
	void unite(int A, int B, int estructura);
};

#endif