#include <cmath>
#include <iostream>
#include <fstream>
#include "Graph.hpp"

const std::unordered_map<std::string, std::unordered_map<std::string, unsigned int>>& Graph::GetWeighOrientGraph() const
{
	return WeighOrientGraph;
}

void Graph::AddEdge(const std::string& from, const std::string& to, const unsigned int& weight)
{
	WeighOrientGraph[from][to] = weight;
}
