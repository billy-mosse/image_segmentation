#include "arbol_rep.hpp"

//UNION FIND, ARBOL DE REPRESENTACIÓN


ArbolRep::ArbolRep(int n)
{
	arbolrep = vector<int>(n, -1);//inicializa n en -1
//(en primer momento, son todos padres)

}

//invariante, que en la raíz tenga en valor negativo la cantidad de elementos
//que hay en el arbol (empieza en -1)
//La idea es usar el tamaño para agregar siempre el árbol más chico al más grande.

int ArbolRep::find(int i){
	int it = i;
	while(arbolrep[it] >= 0){
		it = arbolrep[it];
	}
	return it;
}

void ArbolRep::unite(int A, int B)
{
	int it1 = find(A);
	int it2 = find(B);
	if(it1 == it2){return;} // si están en la misma, no hace nada.
	if(arbolrep[it1] < arbolrep[it2]){ //se fija cuál tiene más elementos,
		//para hacer el union by rank
		arbolrep[it1] += arbolrep[it2];
		arbolrep[it2] = it1;
	} else {
		arbolrep[it2] += arbolrep[it1];
		arbolrep[it1] = it2;
	}
}
