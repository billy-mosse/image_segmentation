#ifndef _graph
#define _graph

#include <iostream>
#include <vector>
#include <utility>
#include <cassert>
#include <tuple>
#include <unordered_map>
#include <algorithm>

using namespace std;


typedef unordered_map<int,int> neighborhood;

typedef tuple<int, int, double> edge;

class Graph {

    //an edge is a vector (origin, target, weight)
    vector<edge> edges;

    unordered_map<int, neighborhood > neighbors;
    int n;
    bool is_digraph;
    
    void validateVertices(int src, int dst);

    public:
        Graph(int N);

        Graph(int N, bool digraph);

        Graph(int N, unordered_map<int, neighborhood> hood);

        Graph(int N, unordered_map<int, neighborhood> hood, bool digraph);

        const neighborhood getNeighbors(int src);

        void addEdge(int src, int dst, double w);
        void addEdgeIfNotAlready(int src, int dst, double w);

        int weight(int src, int dst);

        void showGraph();
        void showGraphEdges();
        int getSizeEdges();

        void ordenar();

        int getAmountNodes();

        int getAmountEdges();


        vector<edge> getEdges();

};

#endif