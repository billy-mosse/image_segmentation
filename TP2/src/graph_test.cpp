#include <iostream>
#include <cassert>
#include "graph.h"
using namespace std;

/*Graph generate_Kn(int n, int w){
	Graph Kn = Graph(n);
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			Kn.addNeighbor(i,j,w);
		}
	}
	return Kn;
}*/


int main(){
    assert(true);
    /*cout << "hello graph world" << endl ;
    Graph K3 = generate_Kn(3,1);
    Graph K10 = generate_Kn(10,2);

    K3.showGraph();
    K10.showGraph();
    
    int w = K3.weight(1,0);
    assert(w==1);
    
    assert(K10.weight(1,0)==2);
    assert((*K10.getNeighbors(1).find(0)).second==2);
    cout << "weights work fine!" << endl;
    return 0;*/
}
