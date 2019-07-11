#include  "graph.h"
#include <bits/stdc++.h> 

Graph::Graph(int N){
	n = N;
    vector<tuple<int, int, double> > edges;
    //set<tuple<int, int> > edges_set;
}

Graph::Graph()
{
	
}

void Graph::validateVertices(int src, int dst){
    assert(src < n && dst < n && dst >= 0 && src >= 0);
}

void Graph::addEdge(int src, int dst, double w){
	validateVertices(src, dst);

	//cout<<w<<endl;
	//cout<<"about to add..."<<endl;

	tuple<int, int, double> toAdd = make_tuple(src, dst, w);
	//cout<<get<2>(toAdd)<<" edge"<<endl;

	edges.push_back(toAdd);

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

	edge new_edge = make_tuple(src, dst, w);
	tuple<int, int> new_edge_without_weight = make_tuple(src, dst);
	//tuple<int, int> new_edge_without_weight_swapped = make_tuple(src, dst);

	bool found=false;
	for(edge an_edge : edges)
	{
		if((get<0>(an_edge) == get<0>(new_edge))
		 && (get<1>(an_edge) == get<1>(new_edge)))
		{
			found=true;
		}
			
		if((get<0>(an_edge) == get<1>(new_edge))
		 && (get<1>(an_edge) == get<0>(new_edge)))
		{
			found=true;
		}
	}

	//edges_set.find(new_edge_without_weight) == edges_set.end()
	//&& edges_set.find(new_edge_without_weight_swapped) == edges_set.end()
	if(!found)
	{
		edges.push_back(new_edge);
		//edges_set.insert(new_edge_without_weight);
	}
}



int Graph::getSizeEdges()
{
	return edges.size();
}

vector<edge>  Graph::getEdges() const
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

bool orderByWeight(edge a, edge b){
	return (get<2>(a) < get<2>(b));
}

void Graph::order()
{
	sort(edges.begin(), edges.end(), orderByWeight);
}