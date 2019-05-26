#include <cassert>
#include <vector>
#include <utility>
#include <iostream>
#include <stdio.h>
#include "arreglo_rep.hpp"
#include "arbol_rep.hpp"
#include "arbol_comp.hpp"
#include "graph.h"

#include "image_to_graph_converter.h"


#include <string>
#include <numeric>

using namespace std;


ArregloRep getArregloRep1()
{
	//[0,1,2,3,4]
	ArregloRep arregloRep(5);
	return arregloRep;
}

ArbolRep getArbolRep1()
{
    ArbolRep arbolRep(5);
    return arbolRep;
}

ArbolComp getArbolComp1()
{
    ArbolComp arbolComp(5);
    return arbolComp;
}


void testArbolComp(){
    cout << "testing ArbolComp unite..." << endl;
    ArbolComp arbolComp = getArbolComp1();


    for(int i = 0; i < 5;i++)
    {
        //son todos root y cada arbol tiene un solo elemento
        assert(arbolComp.find(i) == i);
    }
    
    arbolComp.unite(2,4);
    assert(arbolComp.find(2)==arbolComp.find(4));
    cout << "ArbolComp OK." << endl;
}

void testArbolRep(){
    cout << "testing ArbolRep unite..." << endl;
    ArbolRep arbolRep = getArbolRep1();

    for(int i = 0; i < 5;i++)
    {
        //son todos root y cada arbol tiene un solo elemento
        assert(arbolRep.find(i) == i);
    }
    
    arbolRep.unite(2,4);
    assert(arbolRep.find(2)==arbolRep.find(4));
    cout << "ArbolRep OK." << endl;
}

void testArregloRep(){
    cout << "testing ArregloRep unite..." << endl;
    ArregloRep arregloRep = getArregloRep1();

    for(int i = 0; i < 5;i++)
    {
    	assert(arregloRep.find(i) == i);
    }
    
    arregloRep.unite(2,4);
   	assert(arregloRep.find(2)==arregloRep.find(4));
    cout << "ArregloRep OK." << endl;
}

void testConverter8neighbors()
{
    cout << "testing converter 8 neighbors..." << endl;

    vector<vector<int> > image(3,vector<int>(3,-1));

    int width = 3;
    int height = 3;

    Graph graph = converter8neighbors(image, width, height);

    //X X X
    //X X X
    //X X X

    //1+1+2+4+3+2+4+3 = 20

    assert(graph.getSizeEdges() == 20);

    graph.showGraphEdges();

    cout << "converter 8 neighbors OK" << endl;
}

void testGraph()
{
    Graph graph(3);
    graph.addEdge(0,1,3);
    graph.addEdge(1,2,3);

    assert(graph.getSizeEdges() == 2);

}

int main(){
    testArregloRep();
    testArbolRep();
    testArbolComp();
    testGraph();
    testConverter8neighbors();
	cout<<"all ok"<<endl;
}