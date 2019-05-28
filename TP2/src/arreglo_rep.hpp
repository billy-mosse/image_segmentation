#ifndef _arreglo_rep 
#define _arreglo_rep

#include <vector>

using namespace std;


class ArregloRep
{
	vector<int> arreglorep;
public:
	
	ArregloRep(int n);
	ArregloRep();
	int find(int i);
	void unite(int A, int B);
};

#endif