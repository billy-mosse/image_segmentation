#pragma once

#include <vector>
using namespace std;


class ArbolComp
{
	vector<int> arbolcomp;
public:

	ArbolComp(int n);
	ArbolComp();
	int find(int i);
	void unite(int A, int B);
};