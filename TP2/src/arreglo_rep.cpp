#include "arreglo_rep.hpp"
#include <vector>
#include <iostream>

//arreglo de representación de n elementos,
// a continuación se inicializan las regiones. El índice representa el vértice,
// el valor su región asociada.
ArregloRep::ArregloRep(int n)
{
	arreglorep = vector<int>(n);
	for(int i = 0; i < n; i++)
	{
		//comienzan todos en distintas regiones
		arreglorep[i] = i;
	}
}


int ArregloRep::find(int i)
{
	return arreglorep[i];
}

void ArregloRep::unite(int A, int B)
{
	for(int i = 0; i < arreglorep.size(); i++){
		if(arreglorep[i] == A){arreglorep[i] = B;}
	}
}
