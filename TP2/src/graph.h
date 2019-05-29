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
    
    void validateVertices(int src, int dst);

    public:
        Graph(int N);
        
        Graph();

        void addEdge(int src, int dst, double w);
        void addEdgeIfNotAlready(int src, int dst, double w);

        void showGraphEdges();
        int getSizeEdges();

        void order();

        int getAmountNodes();

        int getAmountEdges();

        vector<edge> getEdges() const;

};

#endif