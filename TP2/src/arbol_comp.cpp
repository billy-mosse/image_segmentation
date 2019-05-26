#include "arbol_comp.hpp"

//UNION FIND, ARBOL DE REPRESENTACIÓN, PATH COMPRESSION
#include <iostream>

vector<int> arbolcomp;

ArbolComp::ArbolComp(int n)
{
	arbolcomp = vector<int>(n, -1);//inicializa n en -1
//(en primer momento, son todos padres)
}

//invariante, que en la raíz tenga en valor negativo la cantidad de elementos
//que hay en el arbol (empieza en -1)
//La idea es usar el tamaño para agregar siempre el árbol más chico al más grande.

int ArbolComp::find(int i){

	int pos = i;
	int it = i;

	//para que al buscar un root no termine apuntando a -1
	if(arbolcomp[it] < 0)
		return it;

	while(arbolcomp[it] >= 0){
		it = arbolcomp[it];
	}
	arbolcomp[pos] = it;

	return it;
}

void ArbolComp::unite(int A, int B)
{
	int it1 = find(A);
	int it2 = find(B);

	//el root del arbol mas chico ahora apunta al grande
	if(arbolcomp[it1] < arbolcomp[it2]){ //se fija cuál tiene más elementos
		//para hacer el union by rank

		//en este caso el arbol de it1 tiene MAS elementos que el de it2
		//recordar que la info esta negativa
		//asi que hay que hacer que el root de it2 apunte al de it1
		arbolcomp[it1] += arbolcomp[it2];
		arbolcomp[it2] = it1;
	} else {
		arbolcomp[it2] += arbolcomp[it1];
		arbolcomp[it1] = it2;
	}
}
