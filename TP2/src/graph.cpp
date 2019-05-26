#include  "graph.h"
#include <bits/stdc++.h> 

Graph::Graph(int N){
	n = N;
	is_digraph = false;
    vector<tuple<int, int, double> > edges;
}


Graph::Graph(int N, bool digraph){
	n = N;
	neighbors = unordered_map<int, neighborhood>();
	is_digraph = digraph;
}

Graph::Graph(int N, unordered_map<int, neighborhood> hood){
	n = N;
	neighbors = hood;
	is_digraph = false;
}

Graph::Graph(int N, unordered_map<int, neighborhood> hood, bool digraph){
	n = N;
	neighbors = hood;
	is_digraph = digraph;
}

void Graph::validateVertices(int src, int dst){
    assert(src < n && dst < n && dst >= 0 && src >= 0);
}

const neighborhood Graph::getNeighbors(int src){
	return neighbors[src];
}

void Graph::addEdge(int src, int dst, double w){
	validateVertices(src, dst);

	edges.push_back(make_tuple(src, dst, w));

}

int Graph::getAmountNodes(){
	return n;
}

int Graph::getAmountEdges(){
	return edges.size();
}

void Graph::addEdgeIfNotAlready(int src, int dst, double w){

	//cout << src << endl;
	//cout << dst << endl;
	//cout << w << endl;
	//cout << n << endl;

	validateVertices(src, dst);

	bool found = false;
	edge new_edge = make_tuple(src, dst, w);
	for(edge an_edge : edges)
	{
		if(an_edge == new_edge)
			found=true;
	}
	if(found==false)
	{
		edges.push_back(make_tuple(src, dst, w));
	}
}


int Graph::weight(int src, int dst){
	validateVertices(src, dst);
	neighborhood hood = neighbors[src];
	auto it = hood.find(dst);
	double w = (*it).second;
	return w;
}

void Graph::showGraph(){
	cout << "showing graph with "<< n << " vertices:\n";
	for(auto it = neighbors.begin(); it!=neighbors.end(); it++){
		cout << (*it).first << ": ";
		neighborhood hood = (*it).second;
		for(auto it_n = hood.begin(); it_n!=hood.end(); it_n++){
			cout <<"("<< (*it_n).first << ", " << (*it_n).second << ") ";
		}
		cout << endl;
	}
}

int Graph::getSizeEdges()
{
	return edges.size();
}

vector<edge> Graph::getEdges()
{
	return edges;
}


void Graph::showGraphEdges(){


	cout << edges.size() << endl;
	cout << "showing graph with "<< n << " vertices:\n";
	for(auto it = edges.begin(); it!=edges.end(); it++){
		cout << get<0>(*it) << "-> " << get<1>(*it) << ", with weight: " << get<2>(*it);
		cout << endl;
	}
}

bool ordenPorPeso(edge a, edge b){
	return (get<2>(a) < get<2>(b));
}

void Graph::ordenar()
{
	sort(edges.begin(), edges.end(), ordenPorPeso);
}