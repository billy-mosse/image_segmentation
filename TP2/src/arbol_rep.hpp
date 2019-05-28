#pragma once

#include <vector>

using namespace std;


class ArbolRep
{
	vector<int> arbolrep;
public:
	
	ArbolRep(int n);
	ArbolRep();
	int find(int i);
	void unite(int A, int B);
};