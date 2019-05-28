#include <vector>
#include <iostream>
#include "disjoint_set.hpp"

DisjointSet::DisjointSet(int n, int estructura)
{

	if(estructura == 0)
	{
		arreglorep = ArregloRep(n);
	}
	else
	{
		if(estructura == 1)
		{
			arbolrep = ArbolRep(n);
		}
		else
		{
			arbolcomp = ArbolComp(n);
		}
	}
}


int DisjointSet::find(int i, int estructura)
{
	if(estructura == 0)
	{
		return arreglorep.find(i);
	}
	else
	{
		if(estructura == 1)
		{
			return arbolrep.find(i);
		}
		else
		{
			return arbolcomp.find(i);
		}
	}
}

void DisjointSet::unite(int A, int B, int estructura)
{
	if(estructura == 0)
	{
		return arreglorep.unite(A, B);
	}
	else
	{
		if(estructura == 1)
		{
			return arbolrep.unite(A, B);
		}
		else
		{
			return arbolcomp.unite(A, B);
		}
	}
}